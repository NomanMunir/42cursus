#!/bin/bash

# =============================================================================
# Webserv Quick Start Script
# =============================================================================

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Configuration
WEBSERV_BINARY="./bin/webserv"
CONFIG_FILE="config/webserv.conf"
DEFAULT_PORT="8080"

# Print colored output
print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

# Print header
print_header() {
    echo -e "${MAGENTA}"
    echo "========================================"
    echo "          WEBSERV QUICK START"
    echo "========================================"
    echo -e "${NC}"
}

# Show usage
show_usage() {
    echo "Usage: $0 [OPTION]"
    echo ""
    echo "Options:"
    echo "  -h, --help      Show this help message"
    echo "  -b, --build     Build the project only"
    echo "  -r, --run       Build and run normally"
    echo "  -d, --debug     Build and run with debug mode"
    echo "  -v, --valgrind  Build and run with Valgrind"
    echo "  -t, --test      Build and run tests"
    echo "  -s, --stress    Build and run stress tests"
    echo "  -c, --clean     Clean build artifacts"
    echo ""
    echo "Examples:"
    echo "  $0 --run                 # Normal execution"
    echo "  $0 --debug              # Debug mode with sanitizers"
    echo "  $0 --valgrind           # Memory leak detection"
    echo "  $0 --test               # Run test suite"
}

# Build the project
build_project() {
    local build_type=${1:-"release"}
    
    print_info "Building webserv ($build_type mode)..."
    
    if [ "$build_type" = "debug" ]; then
        make debug
    else
        make
    fi
    
    if [ $? -eq 0 ]; then
        print_success "Build completed successfully!"
    else
        print_error "Build failed!"
        exit 1
    fi
}

# Run with valgrind
run_valgrind() {
    print_info "Starting webserv with Valgrind..."
    print_warning "This will be slower but will detect memory issues"
    
    valgrind \
        --track-origins=yes \
        --track-fds=yes \
        --leak-check=full \
        --show-leak-kinds=all \
        --suppressions=/dev/null \
        $WEBSERV_BINARY $CONFIG_FILE
}

# Run normally
run_normal() {
    print_info "Starting webserv normally..."
    print_info "Server will be available at: http://localhost:$DEFAULT_PORT"
    print_info "Press Ctrl+C to stop the server"
    
    $WEBSERV_BINARY $CONFIG_FILE
}

# Run debug mode
run_debug() {
    print_info "Starting webserv in debug mode..."
    print_warning "Debug mode includes address sanitizer"
    
    export ASAN_OPTIONS="abort_on_error=1:halt_on_error=1:print_stats=1"
    $WEBSERV_BINARY $CONFIG_FILE
}

# Run tests
run_tests() {
    print_info "Running test suite..."
    
    if [ -f "tests/run_tests.sh" ]; then
        chmod +x tests/run_tests.sh
        tests/run_tests.sh
    else
        print_error "Test script not found at tests/run_tests.sh"
        exit 1
    fi
}

# Run stress tests
run_stress_tests() {
    print_info "Running stress tests..."
    
    if [ -f "tests/stress_test.sh" ]; then
        chmod +x tests/stress_test.sh
        tests/stress_test.sh
    else
        print_error "Stress test script not found at tests/stress_test.sh"
        exit 1
    fi
}

# Clean build artifacts
clean_project() {
    print_info "Cleaning build artifacts..."
    make fclean
    print_success "Cleanup completed!"
}

# Check prerequisites
check_prerequisites() {
    # Check if we're in the right directory
    if [ ! -f "Makefile" ]; then
        print_error "Makefile not found. Please run this script from the project root."
        exit 1
    fi
    
    # Check if config file exists
    if [ ! -f "$CONFIG_FILE" ]; then
        print_warning "Configuration file not found at $CONFIG_FILE"
        print_info "Using default configuration..."
    fi
}

# Signal handler for clean shutdown
cleanup() {
    echo ""
    print_info "Shutting down webserv..."
    exit 0
}

# Main function
main() {
    print_header
    
    # Set up signal handler
    trap cleanup SIGINT SIGTERM
    
    # Check prerequisites
    check_prerequisites
    
    # Parse command line arguments
    case "${1:-}" in
        -h|--help)
            show_usage
            exit 0
            ;;
        -b|--build)
            build_project
            ;;
        -r|--run)
            build_project
            run_normal
            ;;
        -d|--debug)
            build_project "debug"
            run_debug
            ;;
        -v|--valgrind)
            build_project
            run_valgrind
            ;;
        -t|--test)
            build_project
            run_tests
            ;;
        -s|--stress)
            build_project
            run_stress_tests
            ;;
        -c|--clean)
            clean_project
            ;;
        "")
            # Default behavior: build and run with valgrind (original behavior)
            build_project
            run_valgrind
            ;;
        *)
            print_error "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
}

# Run main function with all arguments
main "$@"