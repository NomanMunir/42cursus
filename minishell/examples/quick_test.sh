#!/bin/bash

# Quick test script for minishell functionality
# Usage: ./examples/quick_test.sh

MINISHELL="./minishell"
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}🧪 Minishell Quick Test Script${NC}"
echo "=================================="

# Check if minishell exists
if [ ! -f "$MINISHELL" ]; then
    echo -e "${RED}❌ Error: minishell executable not found${NC}"
    echo "Please run 'make' first"
    exit 1
fi

test_count=0
pass_count=0

# Function to run a test
run_test() {
    local test_name="$1"
    local command="$2"
    local expected_pattern="$3"
    
    ((test_count++))
    echo -n "Testing $test_name... "
    
    # Run the command and capture output
    result=$(echo "$command" | timeout 5 $MINISHELL 2>&1)
    exit_code=$?
    
    # Check if the test passed
    if [[ $exit_code -eq 0 ]] && [[ $result =~ $expected_pattern ]]; then
        echo -e "${GREEN}✅ PASS${NC}"
        ((pass_count++))
    else
        echo -e "${RED}❌ FAIL${NC}"
        echo "  Command: $command"
        echo "  Expected pattern: $expected_pattern"
        echo "  Got: $result"
    fi
}

# Basic functionality tests
echo -e "\n${YELLOW}📋 Basic Command Tests${NC}"
run_test "Echo command" "echo hello; exit" "hello"
run_test "PWD command" "pwd; exit" "/"
run_test "Environment variable" "echo \$HOME; exit" "/"

# Built-in command tests
echo -e "\n${YELLOW}🔧 Built-in Command Tests${NC}"
run_test "Export and echo" "export TEST=value; echo \$TEST; exit" "value"
run_test "Echo with -n flag" "echo -n hello; exit" "hello"

# Pipe tests
echo -e "\n${YELLOW}🔗 Pipe Tests${NC}"
run_test "Simple pipe" "echo hello | cat; exit" "hello"
run_test "Word count pipe" "echo 'word1 word2 word3' | wc -w; exit" "3"

# Redirection tests
echo -e "\n${YELLOW}➡️ Redirection Tests${NC}"
run_test "Output redirection" "echo test > /tmp/minishell_test.txt; cat /tmp/minishell_test.txt; rm -f /tmp/minishell_test.txt; exit" "test"

# Quote tests
echo -e "\n${YELLOW}💭 Quote Tests${NC}"
run_test "Double quotes" "echo \"hello world\"; exit" "hello world"
run_test "Single quotes" "echo 'hello world'; exit" "hello world"

# Error handling tests
echo -e "\n${YELLOW}⚠️ Error Handling Tests${NC}"
run_test "Command not found" "nonexistent_command; exit" "command not found"

# Memory test (basic)
echo -e "\n${YELLOW}🧠 Memory Test${NC}"
if command -v valgrind >/dev/null 2>&1; then
    echo -n "Memory leak test... "
    if echo "exit" | valgrind --leak-check=full --error-exitcode=1 $MINISHELL >/dev/null 2>&1; then
        echo -e "${GREEN}✅ PASS (No leaks)${NC}"
        ((pass_count++))
    else
        echo -e "${RED}❌ FAIL (Memory leaks detected)${NC}"
    fi
    ((test_count++))
else
    echo "Valgrind not available, skipping memory test"
fi

# Summary
echo -e "\n${YELLOW}📊 Test Summary${NC}"
echo "=================================="
echo "Tests run: $test_count"
echo -e "Passed: ${GREEN}$pass_count${NC}"
echo -e "Failed: ${RED}$((test_count - pass_count))${NC}"

if [ $pass_count -eq $test_count ]; then
    echo -e "\n${GREEN}🎉 All tests passed!${NC}"
    exit 0
else
    echo -e "\n${RED}❌ Some tests failed${NC}"
    exit 1
fi
