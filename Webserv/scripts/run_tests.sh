#!/bin/bash

# =============================================================================
# Webserv Test Suite
# =============================================================================

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Test configuration
WEBSERV_BINARY="../bin/webserv"
CONFIG_FILE="../config/webserv.conf"
TEST_HOST="localhost"
TEST_PORT="8080"
TEST_URL="http://${TEST_HOST}:${TEST_PORT}"

# Print colored output
print_status() {
    echo -e "${BLUE}[TEST]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[PASS]${NC} $1"
}

print_error() {
    echo -e "${RED}[FAIL]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

# Check if webserv binary exists
check_binary() {
    if [ ! -f "$WEBSERV_BINARY" ]; then
        print_error "Webserv binary not found at $WEBSERV_BINARY"
        print_status "Please run 'make' to build the project first"
        exit 1
    fi
}

# Check if configuration file exists
check_config() {
    if [ ! -f "$CONFIG_FILE" ]; then
        print_error "Configuration file not found at $CONFIG_FILE"
        exit 1
    fi
}

# Start webserv server in background
start_server() {
    print_status "Starting webserv server..."
    $WEBSERV_BINARY $CONFIG_FILE > /tmp/webserv_test.log 2>&1 &
    SERVER_PID=$!
    sleep 2
    
    # Check if server is running
    if ! kill -0 $SERVER_PID 2>/dev/null; then
        print_error "Failed to start webserv server"
        cat /tmp/webserv_test.log
        exit 1
    fi
    
    print_success "Server started with PID $SERVER_PID"
}

# Stop webserv server
stop_server() {
    if [ ! -z "$SERVER_PID" ]; then
        print_status "Stopping webserv server..."
        kill $SERVER_PID 2>/dev/null || true
        wait $SERVER_PID 2>/dev/null || true
        print_success "Server stopped"
    fi
}

# Test basic HTTP GET request
test_get_request() {
    print_status "Testing GET request..."
    
    response=$(curl -s -o /dev/null -w "%{http_code}" "$TEST_URL/")
    if [ "$response" = "200" ]; then
        print_success "GET request returned HTTP 200"
    else
        print_error "GET request failed, returned HTTP $response"
        return 1
    fi
}

# Test HTTP POST request
test_post_request() {
    print_status "Testing POST request..."
    
    response=$(curl -s -o /dev/null -w "%{http_code}" -X POST -d "test=data" "$TEST_URL/")
    if [ "$response" = "200" ] || [ "$response" = "405" ]; then
        print_success "POST request handled correctly (HTTP $response)"
    else
        print_error "POST request failed, returned HTTP $response"
        return 1
    fi
}

# Test HTTP DELETE request
test_delete_request() {
    print_status "Testing DELETE request..."
    
    response=$(curl -s -o /dev/null -w "%{http_code}" -X DELETE "$TEST_URL/test.txt")
    if [ "$response" = "200" ] || [ "$response" = "404" ] || [ "$response" = "405" ]; then
        print_success "DELETE request handled correctly (HTTP $response)"
    else
        print_error "DELETE request failed, returned HTTP $response"
        return 1
    fi
}

# Test 404 error handling
test_404_error() {
    print_status "Testing 404 error handling..."
    
    response=$(curl -s -o /dev/null -w "%{http_code}" "$TEST_URL/nonexistent.html")
    if [ "$response" = "404" ]; then
        print_success "404 error handled correctly"
    else
        print_error "Expected 404, got HTTP $response"
        return 1
    fi
}

# Test file upload
test_file_upload() {
    print_status "Testing file upload..."
    
    # Create a test file
    echo "Test file content" > /tmp/test_upload.txt
    
    response=$(curl -s -o /dev/null -w "%{http_code}" -X POST -F "file=@/tmp/test_upload.txt" "$TEST_URL/upload")
    if [ "$response" = "200" ] || [ "$response" = "201" ] || [ "$response" = "404" ]; then
        print_success "File upload handled correctly (HTTP $response)"
    else
        print_error "File upload failed, returned HTTP $response"
        return 1
    fi
    
    # Clean up
    rm -f /tmp/test_upload.txt
}

# Test CGI execution
test_cgi() {
    print_status "Testing CGI execution..."
    
    response=$(curl -s -o /dev/null -w "%{http_code}" "$TEST_URL/cgi-bin/hello.py")
    if [ "$response" = "200" ] || [ "$response" = "404" ]; then
        print_success "CGI request handled correctly (HTTP $response)"
    else
        print_error "CGI request failed, returned HTTP $response"
        return 1
    fi
}

# Test concurrent connections
test_concurrent_connections() {
    print_status "Testing concurrent connections..."
    
    # Run 10 concurrent requests
    for i in {1..10}; do
        curl -s "$TEST_URL/" > /dev/null &
    done
    
    # Wait for all requests to complete
    wait
    
    print_success "Concurrent connections test completed"
}

# Main test execution
main() {
    echo "========================================"
    echo "        Webserv Test Suite"
    echo "========================================"
    
    # Setup
    check_binary
    check_config
    
    # Trap to ensure server is stopped on exit
    trap stop_server EXIT
    
    # Start server
    start_server
    
    # Run tests
    FAILED_TESTS=0
    
    test_get_request || ((FAILED_TESTS++))
    test_post_request || ((FAILED_TESTS++))
    test_delete_request || ((FAILED_TESTS++))
    test_404_error || ((FAILED_TESTS++))
    test_file_upload || ((FAILED_TESTS++))
    test_cgi || ((FAILED_TESTS++))
    test_concurrent_connections || ((FAILED_TESTS++))
    
    # Results
    echo "========================================"
    if [ $FAILED_TESTS -eq 0 ]; then
        print_success "All tests passed!"
        exit 0
    else
        print_error "$FAILED_TESTS test(s) failed"
        exit 1
    fi
}

# Run main function
main "$@"
