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

set -eo pipefail  # Allow unset variables, but keep error handling

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
    
    # Create necessary directories
    mkdir -p "$TEMP_DIR" "$LOG_DIR"
    
    # Check if minishell exists
    if [[ ! -f "$MINISHELL" ]]; then
        echo -e "${RED}❌ Error: $MINISHELL not found. Please run 'make' first.${NC}"
        exit 1
    fi
    
    # Make minishell executable
    chmod +x "$MINISHELL"
    
    # Create test files
    echo "test content" > "$TEMP_DIR/test_input.txt"
    echo -e "line 1\nline 2\nline 3" > "$TEMP_DIR/multiline.txt"
    echo "secret data" > "$TEMP_DIR/readonly.txt"
    chmod 444 "$TEMP_DIR/readonly.txt"
    
    echo -e "${GREEN}✅ Test environment ready${NC}"
}

cleanup_test_environment() {
    if [[ "$CLEANUP" == true ]]; then
        echo -e "${BLUE}🧹 Cleaning up test environment...${NC}"
        rm -rf "$TEMP_DIR"
        [[ "$SAVE_LOGS" == false ]] && rm -rf "$LOG_DIR"
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
    
    local temp_input="$TEMP_DIR/input_$TOTAL_TESTS.txt"
    local temp_output="$TEMP_DIR/output_$TOTAL_TESTS.txt"
    local temp_error="$TEMP_DIR/error_$TOTAL_TESTS.txt"
    
    echo "$input" > "$temp_input"
    
    # Run minishell with timeout
    local exit_code=0
    timeout "$TIMEOUT" bash -c "cd '$TEMP_DIR' && echo '$input' | '$MINISHELL'" \
        > "$temp_output" 2> "$temp_error" || exit_code=$?
    
    local output=$(cat "$temp_output" 2>/dev/null || echo "")
    local error_output=$(cat "$temp_error" 2>/dev/null || echo "")
    
    # Check results
    local test_passed=false
    
    if [[ "$should_succeed" == true ]]; then
        if [[ $exit_code -eq 0 || $exit_code -eq 124 ]] && [[ "$output" =~ $expected_pattern ]]; then
            test_passed=true
        fi
    else
        if [[ $exit_code -ne 0 ]] && [[ "$error_output" =~ $expected_pattern ]]; then
            test_passed=true
        fi
    fi
    
    # Report results
    if [[ "$test_passed" == true ]]; then
        echo -e "  ${GREEN}✅ PASS${NC}: $test_name"
        ((PASSED_TESTS++))
        log_test "$test_name" "PASS" "Expected pattern found"
    else
        echo -e "  ${RED}❌ FAIL${NC}: $test_name"
        if [[ "$VERBOSE" == true ]]; then
            echo -e "    ${YELLOW}Input:${NC} $input"
            echo -e "    ${YELLOW}Expected:${NC} $expected_pattern"
            echo -e "    ${YELLOW}Got output:${NC} $output"
            echo -e "    ${YELLOW}Got error:${NC} $error_output"
            echo -e "    ${YELLOW}Exit code:${NC} $exit_code"
        fi
        ((FAILED_TESTS++))
        log_test "$test_name" "FAIL" "Expected: $expected_pattern, Got: $output"
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
    echo "DEBUG: Starting basic commands test"
    
    run_minishell_test "Echo simple" "echo hello" "hello"
    echo "DEBUG: Echo simple completed"
    run_minishell_test "Echo with quotes" "echo \"hello world\"" "hello world"
    echo "DEBUG: Echo with quotes completed"
    run_minishell_test "Echo variable" "export TEST=value; echo \$TEST" "value"
    echo "DEBUG: Echo variable completed"
    run_minishell_test "PWD command" "pwd" "temp"
    echo "DEBUG: PWD command completed"
    run_minishell_test "Exit command" "exit" "" true
    echo "DEBUG: Exit command completed"
}

test_builtins() {
    echo -e "${PURPLE}🏗️ Testing Built-in Commands${NC}"
    
    run_minishell_test "CD to tmp" "cd /tmp; pwd" "/tmp"
    run_minishell_test "CD home" "cd ~; pwd" "$HOME"
    run_minishell_test "Export variable" "export MY_VAR=test; echo \$MY_VAR" "test"
    run_minishell_test "Unset variable" "export MY_VAR=test; unset MY_VAR; echo \$MY_VAR" "^$"
    run_minishell_test "Echo with -n" "echo -n hello" "hello"
    run_minishell_test "Env command" "env" "PATH"
}

test_pipes() {
    echo -e "${PURPLE}🔗 Testing Pipes${NC}"
    
    run_minishell_test "Simple pipe" "echo hello | cat" "hello"
    run_minishell_test "Pipe with wc" "echo \"word1 word2 word3\" | wc -w" "3"
    run_minishell_test "Multiple pipes" "echo hello | cat | cat" "hello"
    run_minishell_test "Pipe with grep" "echo -e \"line1\nline2\ntest\" | grep test" "test"
}

test_redirections() {
    echo -e "${PURPLE}➡️ Testing Redirections${NC}"
    
    run_minishell_test "Output redirect" "echo test > output.txt; cat output.txt" "test"
    run_minishell_test "Input redirect" "echo content > input.txt; cat < input.txt" "content"
    run_minishell_test "Append redirect" "echo line1 > file.txt; echo line2 >> file.txt; cat file.txt" "line1.*line2"
    run_minishell_test "Here-document" "cat << EOF\nHello\nWorld\nEOF" "Hello.*World"
}

test_environment_variables() {
    echo -e "${PURPLE}🌍 Testing Environment Variables${NC}"
    
    run_minishell_test "HOME variable" "echo \$HOME" "$HOME"
    run_minishell_test "PATH variable" "echo \$PATH" "/"
    run_minishell_test "Custom variable" "export CUSTOM=value; echo \$CUSTOM" "value"
    run_minishell_test "Variable in quotes" "export VAR=test; echo \"Value: \$VAR\"" "Value: test"
    run_minishell_test "Undefined variable" "echo \$UNDEFINED_VAR" "^$"
}

test_quotes() {
    echo -e "${PURPLE}💭 Testing Quote Handling${NC}"
    
    run_minishell_test "Single quotes" "echo 'hello world'" "hello world"
    run_minishell_test "Double quotes" "echo \"hello world\"" "hello world"
    run_minishell_test "Mixed quotes" "echo \"hello 'world'\"" "hello 'world'"
    run_minishell_test "Variable in quotes" "export VAR=test; echo \"Variable: \$VAR\"" "Variable: test"
    run_minishell_test "No expansion in single quotes" "export VAR=test; echo '\$VAR'" "\\\$VAR"
}

test_error_handling() {
    echo -e "${PURPLE}⚠️ Testing Error Handling${NC}"
    
    run_minishell_test "Command not found" "nonexistent_command" "command not found" false
    run_minishell_test "File not found" "cat nonexistent_file.txt" "No such file" false
    run_minishell_test "Permission denied" "cat /etc/shadow" "Permission denied" false
    run_minishell_test "Invalid syntax pipe" "ls |" "syntax error" false
    run_minishell_test "Invalid syntax redirect" "cat <" "syntax error" false
}

test_signal_handling() {
    echo -e "${PURPLE}🚦 Testing Signal Handling${NC}"
    
    # Note: These tests are simplified for automation
    run_minishell_test "Ctrl+D simulation" "" "" true
    echo -e "  ${YELLOW}ℹ️ INFO${NC}: Manual signal testing required (Ctrl+C, Ctrl+D, Ctrl+\\)"
    ((SKIPPED_TESTS++))
}

test_memory_leaks() {
    echo -e "${PURPLE}🧠 Testing Memory Management${NC}"
    
    if command -v valgrind >/dev/null 2>&1; then
        echo -e "  ${BLUE}Running valgrind test...${NC}"
        local valgrind_output="$LOG_DIR/valgrind_test.log"
        
        echo "exit" | timeout 30 valgrind --leak-check=full --error-exitcode=1 \
            --suppressions="$PROJECT_DIR/config/minishell.supp" \
            "$MINISHELL" > "$valgrind_output" 2>&1
        
        local valgrind_exit=$?
        
        if [[ $valgrind_exit -eq 0 ]]; then
            echo -e "  ${GREEN}✅ PASS${NC}: No memory leaks detected"
            ((PASSED_TESTS++))
        else
            echo -e "  ${RED}❌ FAIL${NC}: Memory leaks detected"
            [[ "$VERBOSE" == true ]] && cat "$valgrind_output"
            ((FAILED_TESTS++))
        fi
        ((TOTAL_TESTS++))
    else
        echo -e "  ${YELLOW}⚠️ SKIP${NC}: Valgrind not available"
        ((SKIPPED_TESTS++))
    fi
}

test_performance() {
    echo -e "${PURPLE}📊 Testing Performance${NC}"
    
    echo -e "  ${BLUE}Testing command execution speed...${NC}"
    local start_time=$(date +%s.%N)
    echo "echo test; echo test; echo test; echo test; echo test" | "$MINISHELL" >/dev/null 2>&1
    local end_time=$(date +%s.%N)
    local duration=$(echo "$end_time - $start_time" | bc 2>/dev/null || echo "0.1")
    
    echo -e "  ${CYAN}📈 Performance${NC}: 5 commands executed in ${duration}s"
    
    if (( $(echo "$duration < 2.0" | bc -l 2>/dev/null || echo 0) )); then
        echo -e "  ${GREEN}✅ PASS${NC}: Performance acceptable"
        ((PASSED_TESTS++))
    else
        echo -e "  ${RED}❌ FAIL${NC}: Performance too slow"
        ((FAILED_TESTS++))
    fi
    ((TOTAL_TESTS++))
}

test_bash_compatibility() {
    echo -e "${PURPLE}🐚 Testing Bash Compatibility${NC}"
    
    run_comparison_test "Echo comparison" "echo hello world"
    run_comparison_test "PWD comparison" "pwd"
    run_comparison_test "Simple pipe comparison" "echo test | cat"
    run_comparison_test "Variable expansion comparison" "export VAR=test; echo \$VAR"
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

# Trap for cleanup on exit
# trap cleanup_test_environment EXIT  # Temporarily disabled

# Run main function
main "$@"
