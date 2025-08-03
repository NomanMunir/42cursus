#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_runner.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Generated for minishell                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 00:00:00                      #+#    #+#              #
#    Updated: 2025/08/03 00:00:00                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Professional Test Suite for Minishell
# Usage: ./tests/test_runner.sh [category] [options]

# Start simple - no strict error handling for now

# ================================ CONFIGURATION ============================= #

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
MINISHELL="$PROJECT_DIR/minishell"
TEST_DIR="$SCRIPT_DIR"
TEMP_DIR="$TEST_DIR/temp"
LOG_DIR="$TEST_DIR/logs"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Test counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
SKIPPED_TESTS=0

# Test configuration
TIMEOUT=10
VERBOSE=false
CLEANUP=true
SAVE_LOGS=false

# ================================== SETUP =================================== #

setup_test_environment() {
    echo -e "${BLUE}🔧 Setting up test environment...${NC}"
    
    # Create necessary directories - simple approach
    mkdir -p "$TEMP_DIR" "$LOG_DIR" 2>/dev/null || true
    
    # Check if minishell exists
    if [[ ! -f "$MINISHELL" ]]; then
        echo -e "${RED}❌ Error: $MINISHELL not found. Please run 'make' first.${NC}"
        exit 1
    fi
    
    echo -e "${GREEN}✅ Test environment ready${NC}"
}

cleanup_test_environment() {
    if [[ "$CLEANUP" == true ]]; then
        echo -e "${BLUE}🧹 Cleaning up test environment...${NC}"
        rm -rf "$TEMP_DIR" 2>/dev/null || true
        [[ "$SAVE_LOGS" == false ]] && rm -rf "$LOG_DIR" 2>/dev/null || true
    fi
}

# ================================ TEST UTILITIES ============================ #

log_test() {
    local test_name="$1"
    local status="$2"
    local message="${3:-}"
    local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    
    echo "[$timestamp] [$status] $test_name: $message" >> "$LOG_DIR/test.log"
}

run_minishell_test() {
    local test_name="$1"
    local input="$2"
    local expected_pattern="$3"
    local should_succeed="${4:-true}"
    
    ((TOTAL_TESTS++))
    
    echo -n "  Testing: $test_name... "
    
    # Simple test - just run the command and check basic output
    local output=""
    local exit_code=0
    
    # Use a simple approach first
    output=$(echo "$input" | timeout 5 "$MINISHELL" 2>&1 || true)
    exit_code=$?
    
    # Simple pattern matching
    if [[ "$output" =~ $expected_pattern ]] || [[ "$expected_pattern" == "" ]]; then
        echo -e "${GREEN}✅ PASS${NC}"
        ((PASSED_TESTS++))
    else
        echo -e "${RED}❌ FAIL${NC}"
        if [[ "$VERBOSE" == true ]]; then
            echo "    Expected: $expected_pattern"
            echo "    Got: $output"
        fi
        ((FAILED_TESTS++))
    fi
}

run_comparison_test() {
    local test_name="$1"
    local input="$2"
    
    ((TOTAL_TESTS++))
    
    local temp_input="$TEMP_DIR/input_comp_$TOTAL_TESTS.txt"
    local bash_output="$TEMP_DIR/bash_output_$TOTAL_TESTS.txt"
    local mini_output="$TEMP_DIR/mini_output_$TOTAL_TESTS.txt"
    
    echo "$input" > "$temp_input"
    
    # Run with bash
    local bash_exit=0
    timeout "$TIMEOUT" bash -c "cd '$TEMP_DIR' && echo '$input' | bash" \
        > "$bash_output" 2>&1 || bash_exit=$?
    
    # Run with minishell
    local mini_exit=0
    timeout "$TIMEOUT" bash -c "cd '$TEMP_DIR' && echo '$input' | '$MINISHELL'" \
        > "$mini_output" 2>&1 || mini_exit=$?
    
    local bash_out=$(cat "$bash_output" 2>/dev/null || echo "")
    local mini_out=$(cat "$mini_output" 2>/dev/null || echo "")
    
    # Compare outputs (allowing for minor differences)
    if [[ "$bash_out" == "$mini_out" ]] || [[ "$mini_out" =~ $(echo "$bash_out" | head -1) ]]; then
        echo -e "  ${GREEN}✅ PASS${NC}: $test_name"
        ((PASSED_TESTS++))
        log_test "$test_name" "PASS" "Output matches bash"
    else
        echo -e "  ${RED}❌ FAIL${NC}: $test_name"
        if [[ "$VERBOSE" == true ]]; then
            echo -e "    ${YELLOW}Input:${NC} $input"
            echo -e "    ${YELLOW}Bash:${NC} $bash_out"
            echo -e "    ${YELLOW}Mini:${NC} $mini_out"
        fi
        ((FAILED_TESTS++))
        log_test "$test_name" "FAIL" "Output differs from bash"
    fi
}

# ================================ TEST SUITES =============================== #

test_basic_commands() {
    echo -e "${PURPLE}🔧 Testing Basic Commands${NC}"
    
    run_minishell_test "Echo simple" "echo hello" "hello"
    run_minishell_test "Echo with quotes" "echo \"hello world\"" "hello world" 
    run_minishell_test "Exit command" "exit" ""
}

test_builtins() {
    echo -e "${PURPLE}🏗️ Testing Built-in Commands${NC}"
    
    run_minishell_test "Echo with -n" "echo -n hello" "hello"
    run_minishell_test "PWD command" "pwd" "/"
}

test_pipes() {
    echo -e "${PURPLE}🔗 Testing Pipes${NC}"
    
    run_minishell_test "Simple pipe" "echo hello | cat" "hello"
}

test_redirections() {
    echo -e "${PURPLE}➡️ Testing Redirections${NC}"
    
    echo -e "  ${YELLOW}⚠️ SKIP${NC}: Redirection tests (will add later)"
    ((SKIPPED_TESTS++))
}

test_environment_variables() {
    echo -e "${PURPLE}🌍 Testing Environment Variables${NC}"
    
    run_minishell_test "Simple variable" "export TEST=hello; echo \$TEST" "hello"
}

test_quotes() {
    echo -e "${PURPLE}💭 Testing Quote Handling${NC}"
    
    run_minishell_test "Single quotes" "echo 'hello world'" "hello world"
    run_minishell_test "Double quotes" "echo \"hello world\"" "hello world"
}

test_error_handling() {
    echo -e "${PURPLE}⚠️ Testing Error Handling${NC}"
    
    echo -e "  ${YELLOW}⚠️ SKIP${NC}: Error handling tests (will add later)"
    ((SKIPPED_TESTS++))
}

test_signal_handling() {
    echo -e "${PURPLE}🚦 Testing Signal Handling${NC}"
    
    echo -e "  ${YELLOW}⚠️ SKIP${NC}: Signal tests (will add later)"
    ((SKIPPED_TESTS++))
}

test_memory_leaks() {
    echo -e "${PURPLE}🧠 Testing Memory Management${NC}"
    
    echo -e "  ${YELLOW}⚠️ SKIP${NC}: Memory tests (will add later)"
    ((SKIPPED_TESTS++))
}

test_performance() {
    echo -e "${PURPLE}📊 Testing Performance${NC}"
    
    echo -e "  ${YELLOW}⚠️ SKIP${NC}: Performance tests (will add later)"
    ((SKIPPED_TESTS++))
}

test_bash_compatibility() {
    echo -e "${PURPLE}🐚 Testing Bash Compatibility${NC}"
    
    echo -e "  ${YELLOW}⚠️ SKIP${NC}: Compatibility tests (will add later)"
    ((SKIPPED_TESTS++))
}

# ================================ TEST EXECUTION ============================ #

run_test_suite() {
    local category="$1"
    
    case "$category" in
        "basic")
            test_basic_commands
            ;;
        "builtins")
            test_builtins
            ;;
        "pipes")
            test_pipes
            ;;
        "redirections")
            test_redirections
            ;;
        "env"|"environment")
            test_environment_variables
            ;;
        "quotes")
            test_quotes
            ;;
        "errors")
            test_error_handling
            ;;
        "signals")
            test_signal_handling
            ;;
        "memory")
            test_memory_leaks
            ;;
        "performance")
            test_performance
            ;;
        "compatibility")
            test_bash_compatibility
            ;;
        *)
            echo -e "${RED}❌ Unknown test category: $category${NC}"
            echo "Available categories: basic, builtins, pipes, redirections, env, quotes, errors, signals, memory, performance, compatibility, all"
            exit 1
            ;;
    esac
}

print_summary() {
    echo
    echo -e "${BLUE}📊 Test Summary${NC}"
    echo "=================================="
    echo -e "Total tests:    ${TOTAL_TESTS}"
    echo -e "Passed:         ${GREEN}${PASSED_TESTS}${NC}"
    echo -e "Failed:         ${RED}${FAILED_TESTS}${NC}"
    echo -e "Skipped:        ${YELLOW}${SKIPPED_TESTS}${NC}"
    echo
    
    if [[ $FAILED_TESTS -eq 0 ]]; then
        echo -e "${GREEN}🎉 All tests passed!${NC}"
        return 0
    else
        echo -e "${RED}❌ Some tests failed${NC}"
        echo -e "Check logs in: $LOG_DIR/"
        return 1
    fi
}

show_help() {
    echo "Professional Test Suite for Minishell"
    echo
    echo "Usage: $0 [CATEGORY] [OPTIONS]"
    echo
    echo "Categories:"
    echo "  basic          Test basic command execution"
    echo "  builtins       Test built-in commands"
    echo "  pipes          Test pipe operations"
    echo "  redirections   Test input/output redirections"
    echo "  env            Test environment variables"
    echo "  quotes         Test quote handling"
    echo "  errors         Test error handling"
    echo "  signals        Test signal handling"
    echo "  memory         Test memory management"
    echo "  performance    Test performance"
    echo "  compatibility  Test bash compatibility"
    echo "  all            Run all tests (default)"
    echo
    echo "Options:"
    echo "  -v, --verbose  Show detailed output"
    echo "  -s, --save     Save log files"
    echo "  -t, --timeout N Set timeout in seconds (default: 10)"
    echo "  --no-cleanup   Don't clean up temporary files"
    echo "  -h, --help     Show this help"
    echo
    echo "Examples:"
    echo "  $0                    # Run all tests"
    echo "  $0 basic              # Run only basic tests"
    echo "  $0 all -v             # Run all tests with verbose output"
    echo "  $0 memory --save      # Run memory tests and save logs"
}

# ================================== MAIN ==================================== #

main() {
    local category="all"
    
    # Parse arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            -v|--verbose)
                VERBOSE=true
                shift
                ;;
            -s|--save)
                SAVE_LOGS=true
                shift
                ;;
            -t|--timeout)
                TIMEOUT="$2"
                shift 2
                ;;
            --no-cleanup)
                CLEANUP=false
                shift
                ;;
            -h|--help)
                show_help
                exit 0
                ;;
            -*)
                echo -e "${RED}❌ Unknown option: $1${NC}"
                exit 1
                ;;
            *)
                category="$1"
                shift
                ;;
        esac
    done
    
    # Header
    echo -e "${CYAN}🧪 Minishell Professional Test Suite${NC}"
    echo "======================================"
    echo -e "Category:  ${PURPLE}$category${NC}"
    echo -e "Timeout:   ${YELLOW}${TIMEOUT}s${NC}"
    echo -e "Verbose:   ${YELLOW}$VERBOSE${NC}"
    echo -e "Save logs: ${YELLOW}$SAVE_LOGS${NC}"
    echo
    
    # Setup
    setup_test_environment
    
    # Run tests
    echo -e "${BLUE}🚀 Starting tests...${NC}"
    echo
    
    if [[ "$category" == "all" ]]; then
        for cat in basic builtins pipes redirections env quotes errors signals memory performance compatibility; do
            run_test_suite "$cat"
            echo
        done
    else
        run_test_suite "$category"
    fi
    
    # Results
    local exit_code=0
    print_summary || exit_code=1
    
    # Cleanup
    cleanup_test_environment
    
    exit $exit_code
}

# Run main function
main "$@"
