#!/bin/bash

# =============================================================================
# Webserv Stress Test Script
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

# Stress test parameters
CONCURRENT_USERS=50
TEST_DURATION="30s"
REQUESTS_PER_SECOND=100

# Print colored output
print_status() {
    echo -e "${BLUE}[STRESS]${NC} $1"
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

# Check dependencies
check_dependencies() {
    print_status "Checking dependencies..."
    
    # Check for siege
    if ! command -v siege &> /dev/null; then
        print_warning "siege not found, using curl for basic load testing"
        USE_SIEGE=false
    else
        USE_SIEGE=true
        print_success "siege found"
    fi
    
    # Check for ab (Apache Bench)
    if ! command -v ab &> /dev/null; then
        print_warning "ab (Apache Bench) not found"
        USE_AB=false
    else
        USE_AB=true
        print_success "ab (Apache Bench) found"
    fi
}

# Start webserv server
start_server() {
    print_status "Starting webserv server for stress testing..."
    $WEBSERV_BINARY $CONFIG_FILE > /tmp/webserv_stress.log 2>&1 &
    SERVER_PID=$!
    sleep 3
    
    # Check if server is running
    if ! kill -0 $SERVER_PID 2>/dev/null; then
        print_error "Failed to start webserv server"
        cat /tmp/webserv_stress.log
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

# Siege stress test
run_siege_test() {
    print_status "Running siege stress test..."
    print_status "Concurrent users: $CONCURRENT_USERS"
    print_status "Duration: $TEST_DURATION"
    
    siege -c $CONCURRENT_USERS -t $TEST_DURATION "$TEST_URL/" --log=/tmp/siege.log
    
    if [ $? -eq 0 ]; then
        print_success "Siege test completed successfully"
        print_status "Check /tmp/siege.log for detailed results"
    else
        print_error "Siege test failed"
        return 1
    fi
}

# Apache Bench stress test
run_ab_test() {
    print_status "Running Apache Bench stress test..."
    
    local total_requests=1000
    local concurrent_requests=50
    
    print_status "Total requests: $total_requests"
    print_status "Concurrent requests: $concurrent_requests"
    
    ab -n $total_requests -c $concurrent_requests "$TEST_URL/" > /tmp/ab_results.txt
    
    if [ $? -eq 0 ]; then
        print_success "Apache Bench test completed successfully"
        print_status "Results:"
        grep -E "(Requests per second|Time per request|Transfer rate)" /tmp/ab_results.txt
    else
        print_error "Apache Bench test failed"
        return 1
    fi
}

# Basic curl load test
run_curl_test() {
    print_status "Running basic curl load test..."
    
    local num_requests=100
    local concurrent=10
    
    print_status "Sending $num_requests requests with $concurrent concurrent connections"
    
    # Function to make a request
    make_request() {
        local start_time=$(date +%s.%N)
        local response=$(curl -s -o /dev/null -w "%{http_code}:%{time_total}" "$TEST_URL/")
        local end_time=$(date +%s.%N)
        echo "$response"
    }
    
    # Run requests in background
    local pids=()
    local request_count=0
    
    while [ $request_count -lt $num_requests ]; do
        # Start concurrent requests
        for ((i=0; i<concurrent && request_count<num_requests; i++)); do
            make_request &
            pids+=($!)
            ((request_count++))
        done
        
        # Wait for this batch to complete
        for pid in "${pids[@]}"; do
            wait $pid
        done
        pids=()
    done
    
    print_success "Curl load test completed"
}

# Memory usage monitoring
monitor_memory() {
    print_status "Monitoring memory usage during stress test..."
    
    # Monitor for 30 seconds
    for i in {1..30}; do
        if kill -0 $SERVER_PID 2>/dev/null; then
            local mem_usage=$(ps -p $SERVER_PID -o rss= 2>/dev/null || echo "0")
            echo "$(date): Memory usage: ${mem_usage} KB" >> /tmp/memory_usage.log
        fi
        sleep 1
    done &
    
    MONITOR_PID=$!
}

# Check for memory leaks
check_memory_leaks() {
    if [ -f /tmp/memory_usage.log ]; then
        print_status "Memory usage analysis:"
        local max_memory=$(sort -n /tmp/memory_usage.log | tail -1 | awk '{print $4}')
        local min_memory=$(sort -n /tmp/memory_usage.log | head -1 | awk '{print $4}')
        
        print_status "Max memory usage: $max_memory KB"
        print_status "Min memory usage: $min_memory KB"
        
        # Simple leak detection (if memory usage grows significantly)
        local memory_diff=$((max_memory - min_memory))
        if [ $memory_diff -gt 10000 ]; then  # 10MB threshold
            print_warning "Potential memory leak detected (growth: ${memory_diff} KB)"
        else
            print_success "No significant memory leaks detected"
        fi
    fi
}

# Connection limit test
test_connection_limits() {
    print_status "Testing connection limits..."
    
    # Try to open many connections simultaneously
    local max_connections=200
    
    for i in $(seq 1 $max_connections); do
        (curl -s "$TEST_URL/" > /dev/null) &
        if [ $((i % 50)) -eq 0 ]; then
            print_status "Opened $i connections..."
        fi
    done
    
    # Wait for all connections to complete
    wait
    
    print_success "Connection limit test completed"
}

# Main stress test execution
main() {
    echo "========================================"
    echo "      Webserv Stress Test Suite"
    echo "========================================"
    
    # Setup
    check_dependencies
    
    # Trap to ensure server is stopped on exit
    trap 'stop_server; kill $MONITOR_PID 2>/dev/null || true' EXIT
    
    # Start server
    start_server
    
    # Start memory monitoring
    monitor_memory
    
    # Run stress tests
    local failed_tests=0
    
    if [ "$USE_SIEGE" = true ]; then
        run_siege_test || ((failed_tests++))
    fi
    
    if [ "$USE_AB" = true ]; then
        run_ab_test || ((failed_tests++))
    fi
    
    run_curl_test || ((failed_tests++))
    test_connection_limits || ((failed_tests++))
    
    # Stop monitoring
    kill $MONITOR_PID 2>/dev/null || true
    wait $MONITOR_PID 2>/dev/null || true
    
    # Check for memory issues
    check_memory_leaks
    
    # Results
    echo "========================================"
    if [ $failed_tests -eq 0 ]; then
        print_success "All stress tests passed!"
        exit 0
    else
        print_error "$failed_tests stress test(s) failed"
        exit 1
    fi
}

# Run main function
main "$@"
