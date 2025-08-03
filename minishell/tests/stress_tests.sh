#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stress_tests.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Generated for minishell                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 00:00:00                      #+#    #+#              #
#    Updated: 2025/08/03 00:00:00                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Stress Tests for Minishell
# These tests push the limits of the shell implementation

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
MINISHELL="$PROJECT_DIR/minishell"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'

TOTAL_STRESS_TESTS=0
PASSED_STRESS_TESTS=0
FAILED_STRESS_TESTS=0

run_stress_test() {
    local test_name="$1"
    local test_command="$2"
    local timeout_duration="${3:-30}"
    
    ((TOTAL_STRESS_TESTS++))
    
    echo -e "  ${BLUE}Testing${NC}: $test_name"
    
    # Run the test with timeout
    local start_time=$(date +%s)
    local exit_code=0
    
    timeout "$timeout_duration" bash -c "$test_command" >/dev/null 2>&1 || exit_code=$?
    
    local end_time=$(date +%s)
    local duration=$((end_time - start_time))
    
    if [[ $exit_code -eq 0 ]]; then
        echo -e "    ${GREEN}✅ PASS${NC} (${duration}s)"
        ((PASSED_STRESS_TESTS++))
    elif [[ $exit_code -eq 124 ]]; then
        echo -e "    ${YELLOW}⏰ TIMEOUT${NC} (${timeout_duration}s)"
        ((FAILED_STRESS_TESTS++))
    else
        echo -e "    ${RED}❌ FAIL${NC} (exit code: $exit_code)"
        ((FAILED_STRESS_TESTS++))
    fi
}

test_large_commands() {
    echo -e "${PURPLE}📏 Testing Large Commands${NC}"
    
    # Very long echo command
    local long_echo="echo"
    for i in {1..1000}; do
        long_echo+=" word$i"
    done
    
    run_stress_test "1000 word echo command" "echo '$long_echo' | '$MINISHELL' -c 'cat'" 15
    
    # Long pipe chain
    local pipe_chain="echo hello"
    for i in {1..100}; do
        pipe_chain+=" | cat"
    done
    
    run_stress_test "100 pipe chain" "echo '$pipe_chain' | '$MINISHELL'" 20
    
    # Many arguments
    local many_args="echo"
    for i in {1..500}; do
        many_args+=" arg$i"
    done
    
    run_stress_test "500 arguments to echo" "echo '$many_args' | '$MINISHELL'" 10
}

test_many_variables() {
    echo -e "${PURPLE}🔢 Testing Many Variables${NC}"
    
    # Create script with many variable exports
    local var_script="/tmp/many_vars.sh"
    echo "#!/bin/bash" > "$var_script"
    for i in {1..1000}; do
        echo "export VAR$i=value$i" >> "$var_script"
    done
    echo "echo \$VAR500" >> "$var_script"
    echo "exit" >> "$var_script"
    
    run_stress_test "1000 environment variables" "'$MINISHELL' < '$var_script'" 30
    
    rm -f "$var_script"
    
    # Variable expansion stress test
    local expand_test="/tmp/expand_test.sh"
    echo "export BASE=test" > "$expand_test"
    for i in {1..100}; do
        echo "export VAR$i=\$BASE$i" >> "$expand_test"
    done
    echo "echo \$VAR50" >> "$expand_test"
    echo "exit" >> "$expand_test"
    
    run_stress_test "100 variable expansions" "'$MINISHELL' < '$expand_test'" 15
    
    rm -f "$expand_test"
}

test_deep_nesting() {
    echo -e "${PURPLE}🕳️ Testing Deep Nesting${NC}"
    
    # Deep quote nesting
    local nested_quotes="echo"
    for i in {1..50}; do
        nested_quotes+=" \"nested$i"
    done
    for i in {1..50}; do
        nested_quotes+="\""
    done
    
    run_stress_test "50 level quote nesting" "echo '$nested_quotes' | '$MINISHELL'" 10
    
    # Deep parentheses (if supported)
    local nested_parens="echo"
    for i in {1..20}; do
        nested_parens+=" \$(echo"
    done
    nested_parens+=" hello"
    for i in {1..20}; do
        nested_parens+=")"
    done
    
    run_stress_test "20 level command substitution" "echo '$nested_parens' | '$MINISHELL'" 15
}

test_rapid_execution() {
    echo -e "${PURPLE}⚡ Testing Rapid Execution${NC}"
    
    # Rapid command execution
    local rapid_script="/tmp/rapid_test.sh"
    echo "#!/bin/bash" > "$rapid_script"
    for i in {1..1000}; do
        echo "echo test$i" >> "$rapid_script"
    done
    echo "exit" >> "$rapid_script"
    
    run_stress_test "1000 rapid commands" "'$MINISHELL' < '$rapid_script'" 60
    
    rm -f "$rapid_script"
    
    # Rapid pipe operations
    local pipe_script="/tmp/pipe_test.sh"
    echo "#!/bin/bash" > "$pipe_script"
    for i in {1..200}; do
        echo "echo line$i | cat | cat" >> "$pipe_script"
    done
    echo "exit" >> "$pipe_script"
    
    run_stress_test "200 rapid pipe operations" "'$MINISHELL' < '$pipe_script'" 45
    
    rm -f "$pipe_script"
}

test_memory_intensive() {
    echo -e "${PURPLE}🧠 Testing Memory Intensive Operations${NC}"
    
    # Large here-document
    local heredoc_script="/tmp/heredoc_test.sh"
    echo "cat << EOF" > "$heredoc_script"
    for i in {1..10000}; do
        echo "Line $i of large here-document with some content to make it bigger"
    done >> "$heredoc_script"
    echo "EOF" >> "$heredoc_script"
    echo "exit" >> "$heredoc_script"
    
    run_stress_test "Large here-document (10k lines)" "'$MINISHELL' < '$heredoc_script'" 30
    
    rm -f "$heredoc_script"
    
    # Memory leak test with many allocations
    local alloc_script="/tmp/alloc_test.sh"
    echo "#!/bin/bash" > "$alloc_script"
    for i in {1..500}; do
        echo "export LARGE_VAR$i=\"$(printf 'x%.0s' {1..1000})\"" >> "$alloc_script"
    done
    echo "unset \$(env | grep LARGE_VAR | cut -d= -f1)" >> "$alloc_script"
    echo "exit" >> "$alloc_script"
    
    run_stress_test "Memory allocation stress test" "'$MINISHELL' < '$alloc_script'" 40
    
    rm -f "$alloc_script"
}

test_file_operations() {
    echo -e "${PURPLE}📁 Testing File Operations Stress${NC}"
    
    # Create many temporary files
    local file_script="/tmp/file_test.sh"
    echo "#!/bin/bash" > "$file_script"
    for i in {1..100}; do
        echo "echo \"Content $i\" > /tmp/test_file_$i.txt" >> "$file_script"
        echo "cat /tmp/test_file_$i.txt" >> "$file_script"
        echo "rm /tmp/test_file_$i.txt" >> "$file_script"
    done
    echo "exit" >> "$file_script"
    
    run_stress_test "100 file create/read/delete operations" "'$MINISHELL' < '$file_script'" 25
    
    rm -f "$file_script"
    
    # Rapid redirections
    local redirect_script="/tmp/redirect_test.sh"
    echo "#!/bin/bash" > "$redirect_script"
    for i in {1..200}; do
        echo "echo test$i > /tmp/redirect_$i.txt" >> "$redirect_script"
    done
    echo "cat /tmp/redirect_*.txt | wc -l" >> "$redirect_script"
    echo "rm /tmp/redirect_*.txt" >> "$redirect_script"
    echo "exit" >> "$redirect_script"
    
    run_stress_test "200 rapid redirections" "'$MINISHELL' < '$redirect_script'" 30
    
    rm -f "$redirect_script"
}

test_concurrent_operations() {
    echo -e "${PURPLE}🔄 Testing Concurrent Operations${NC}"
    
    # Multiple background processes (if supported)
    local bg_script="/tmp/bg_test.sh"
    echo "#!/bin/bash" > "$bg_script"
    for i in {1..10}; do
        echo "sleep 1 &" >> "$bg_script"
    done
    echo "wait" >> "$bg_script"
    echo "exit" >> "$bg_script"
    
    run_stress_test "10 background processes" "'$MINISHELL' < '$bg_script'" 15
    
    rm -f "$bg_script"
    
    # Note: This test may not work if minishell doesn't support background processes
    echo -e "    ${YELLOW}ℹ️ INFO${NC}: Background process test may fail if not implemented"
}

test_error_flood() {
    echo -e "${PURPLE}🌊 Testing Error Flood Handling${NC}"
    
    # Many command not found errors
    local error_script="/tmp/error_test.sh"
    echo "#!/bin/bash" > "$error_script"
    for i in {1..200}; do
        echo "nonexistent_command_$i 2>/dev/null" >> "$error_script"
    done
    echo "echo \"Still working after errors\"" >> "$error_script"
    echo "exit" >> "$error_script"
    
    run_stress_test "200 command not found errors" "'$MINISHELL' < '$error_script'" 20
    
    rm -f "$error_script"
    
    # Many syntax errors
    local syntax_script="/tmp/syntax_test.sh"
    echo "#!/bin/bash" > "$syntax_script"
    for i in {1..100}; do
        echo "echo hello | 2>/dev/null" >> "$syntax_script"
    done
    echo "echo \"Still working after syntax errors\"" >> "$syntax_script"
    echo "exit" >> "$syntax_script"
    
    run_stress_test "100 syntax errors" "'$MINISHELL' < '$syntax_script'" 15
    
    rm -f "$syntax_script"
}

run_performance_benchmark() {
    echo -e "${PURPLE}📊 Performance Benchmarks${NC}"
    
    # Simple command benchmark
    echo -e "  ${BLUE}Benchmarking${NC}: Simple command execution"
    local start_time=$(date +%s.%N)
    for i in {1..100}; do
        echo "echo test" | "$MINISHELL" >/dev/null 2>&1
    done
    local end_time=$(date +%s.%N)
    local duration=$(echo "$end_time - $start_time" | bc 2>/dev/null || echo "N/A")
    echo -e "    ${CYAN}📈 Result${NC}: 100 commands in ${duration}s"
    
    # Pipe benchmark
    echo -e "  ${BLUE}Benchmarking${NC}: Pipe operations"
    start_time=$(date +%s.%N)
    for i in {1..50}; do
        echo "echo test | cat" | "$MINISHELL" >/dev/null 2>&1
    done
    end_time=$(date +%s.%N)
    duration=$(echo "$end_time - $start_time" | bc 2>/dev/null || echo "N/A")
    echo -e "    ${CYAN}📈 Result${NC}: 50 pipe operations in ${duration}s"
    
    # Variable expansion benchmark
    echo -e "  ${BLUE}Benchmarking${NC}: Variable expansion"
    start_time=$(date +%s.%N)
    for i in {1..100}; do
        echo "export VAR=test; echo \$VAR" | "$MINISHELL" >/dev/null 2>&1
    done
    end_time=$(date +%s.%N)
    duration=$(echo "$end_time - $start_time" | bc 2>/dev/null || echo "N/A")
    echo -e "    ${CYAN}📈 Result${NC}: 100 variable expansions in ${duration}s"
}

print_stress_summary() {
    echo
    echo -e "${BLUE}📊 Stress Test Summary${NC}"
    echo "=============================="
    echo -e "Total stress tests: ${TOTAL_STRESS_TESTS}"
    echo -e "Passed:            ${GREEN}${PASSED_STRESS_TESTS}${NC}"
    echo -e "Failed:            ${RED}${FAILED_STRESS_TESTS}${NC}"
    echo
    
    if [[ $FAILED_STRESS_TESTS -eq 0 ]]; then
        echo -e "${GREEN}💪 All stress tests passed!${NC}"
        return 0
    else
        echo -e "${RED}⚠️ Some stress tests failed${NC}"
        echo -e "This may indicate performance or stability issues"
        return 1
    fi
}

# ================================ MAIN FUNCTION ============================= #

main() {
    echo -e "${CYAN}💪 Minishell Stress Tests${NC}"
    echo "============================="
    echo
    
    # Check if minishell exists
    if [[ ! -f "$MINISHELL" ]]; then
        echo -e "${RED}❌ Error: $MINISHELL not found. Please run 'make' first.${NC}"
        exit 1
    fi
    
    echo -e "${YELLOW}⚠️ Warning: These tests may take several minutes to complete${NC}"
    echo -e "${YELLOW}⚠️ Warning: These tests will create temporary files in /tmp${NC}"
    echo
    
    test_large_commands
    echo
    test_many_variables
    echo
    test_deep_nesting
    echo
    test_rapid_execution
    echo
    test_memory_intensive
    echo
    test_file_operations
    echo
    test_concurrent_operations
    echo
    test_error_flood
    echo
    run_performance_benchmark
    
    local exit_code=0
    print_stress_summary || exit_code=1
    
    exit $exit_code
}

# Run main if script is executed directly
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
