#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    unit_tests.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Generated for minishell                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 00:00:00                      #+#    #+#              #
#    Updated: 2025/08/03 00:00:00                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Focused Unit Tests for Core Functionality
# These tests target specific functions and edge cases

source "$(dirname "$0")/test_runner.sh" 2>/dev/null || {
    echo "Error: Cannot source test_runner.sh"
    exit 1
}

# ================================ UNIT TESTS ================================ #

test_parsing_edge_cases() {
    echo -e "${PURPLE}🔍 Testing Parsing Edge Cases${NC}"
    
    # Empty command
    run_minishell_test "Empty command" "" "" true
    
    # Multiple spaces
    run_minishell_test "Multiple spaces" "echo     hello     world" "hello world"
    
    # Trailing spaces
    run_minishell_test "Trailing spaces" "echo hello   " "hello"
    
    # Leading spaces
    run_minishell_test "Leading spaces" "   echo hello" "hello"
    
    # Tab characters
    run_minishell_test "Tab characters" $'echo\thello\tworld' "hello world"
    
    # Mixed whitespace
    run_minishell_test "Mixed whitespace" $'  echo \t hello  \t world  ' "hello world"
}

test_quote_edge_cases() {
    echo -e "${PURPLE}📝 Testing Quote Edge Cases${NC}"
    
    # Empty quotes
    run_minishell_test "Empty double quotes" 'echo ""' "^$"
    run_minishell_test "Empty single quotes" "echo ''" "^$"
    
    # Nested quotes
    run_minishell_test "Single in double" 'echo "he'\''llo"' "he'llo"
    run_minishell_test "Double in single" "echo 'he\"llo'" 'he"llo'
    
    # Unclosed quotes (should fail)
    run_minishell_test "Unclosed double quote" 'echo "hello' "syntax error" false
    run_minishell_test "Unclosed single quote" "echo 'hello" "syntax error" false
    
    # Special characters in quotes
    run_minishell_test "Pipe in quotes" 'echo "hello | world"' "hello | world"
    run_minishell_test "Redirect in quotes" 'echo "hello > world"' "hello > world"
}

test_variable_edge_cases() {
    echo -e "${PURPLE}💲 Testing Variable Edge Cases${NC}"
    
    # Variable with special characters
    run_minishell_test "Variable with underscore" "export VAR_NAME=test; echo \$VAR_NAME" "test"
    run_minishell_test "Variable with numbers" "export VAR123=test; echo \$VAR123" "test"
    
    # Empty variable
    run_minishell_test "Empty variable" "export EMPTY=; echo [\$EMPTY]" "\\[\\]"
    
    # Variable concatenation
    run_minishell_test "Variable concatenation" "export A=hello; export B=world; echo \$A\$B" "helloworld"
    
    # Variable in the middle
    run_minishell_test "Variable in middle" "export VAR=test; echo pre\${VAR}post" "pretestpost"
    
    # Question mark variable (exit status)
    run_minishell_test "Exit status variable" "true; echo \$?" "0"
    run_minishell_test "Exit status after false" "false; echo \$?" "1"
}

test_pipe_edge_cases() {
    echo -e "${PURPLE}🔀 Testing Pipe Edge Cases${NC}"
    
    # Multiple consecutive pipes
    run_minishell_test "Double pipe" "echo hello || echo world" "hello"
    
    # Pipe with empty command
    run_minishell_test "Pipe with empty right" "echo hello |" "syntax error" false
    run_minishell_test "Pipe with empty left" "| cat" "syntax error" false
    
    # Long pipe chain
    run_minishell_test "Long pipe chain" "echo hello | cat | cat | cat | cat" "hello"
    
    # Pipe with built-ins
    run_minishell_test "Pipe with echo" "echo test | echo built-in" "built-in"
    
    # Pipe stderr
    run_minishell_test "Pipe with stderr" "ls /nonexistent 2>&1 | grep 'No such file'" "No such file"
}

test_redirection_edge_cases() {
    echo -e "${PURPLE}↗️ Testing Redirection Edge Cases${NC}"
    
    # Multiple redirections
    run_minishell_test "Multiple output redirects" "echo test > file1.txt > file2.txt; cat file2.txt" "test"
    
    # Redirect to existing file
    run_minishell_test "Redirect overwrite" "echo first > file.txt; echo second > file.txt; cat file.txt" "second"
    
    # Redirect with quotes
    run_minishell_test "Redirect quoted filename" 'echo test > "quoted file.txt"; cat "quoted file.txt"' "test"
    
    # Here-document edge cases
    run_minishell_test "Here-doc empty" "cat << EOF\nEOF" "^$"
    run_minishell_test "Here-doc with variables" "export VAR=test; cat << EOF\n\$VAR\nEOF" "test"
    
    # Permission tests
    run_minishell_test "Redirect to readonly" "echo test > readonly.txt" "Permission denied" false
}

test_builtin_edge_cases() {
    echo -e "${PURPLE}🏗️ Testing Built-in Edge Cases${NC}"
    
    # CD edge cases
    run_minishell_test "CD no args" "cd; pwd" "$HOME"
    run_minishell_test "CD to nonexistent" "cd /nonexistent/path" "No such file" false
    run_minishell_test "CD with dash" "cd /tmp; cd -; pwd" "$(pwd)"
    
    # Echo edge cases
    run_minishell_test "Echo no args" "echo" "^$"
    run_minishell_test "Echo multiple -n" "echo -n -n hello" "hello"
    run_minishell_test "Echo invalid flag" "echo -x hello" "-x hello"
    
    # Export edge cases
    run_minishell_test "Export no args" "export" ".*="
    run_minishell_test "Export invalid name" "export 123VAR=test" "not a valid identifier" false
    run_minishell_test "Export with equal sign" "export VAR=val=ue; echo \$VAR" "val=ue"
    
    # Unset edge cases
    run_minishell_test "Unset nonexistent" "unset NONEXISTENT_VAR" "" true
    run_minishell_test "Unset readonly" "readonly READONLY_VAR=test; unset READONLY_VAR" "readonly" false
    
    # Exit edge cases
    run_minishell_test "Exit with code" "exit 42" "" true
    run_minishell_test "Exit invalid code" "exit abc" "numeric argument" false
}

test_signal_edge_cases() {
    echo -e "${PURPLE}🚦 Testing Signal Edge Cases${NC}"
    
    # Test signal handling during different operations
    echo -e "  ${YELLOW}ℹ️ INFO${NC}: Signal tests require manual verification"
    echo -e "  ${YELLOW}ℹ️ INFO${NC}: Test Ctrl+C during: command execution, pipe operations, here-document input"
    echo -e "  ${YELLOW}ℹ️ INFO${NC}: Test Ctrl+D: should exit gracefully"
    echo -e "  ${YELLOW}ℹ️ INFO${NC}: Test Ctrl+\\: should be ignored"
    
    ((SKIPPED_TESTS += 4))
}

test_memory_edge_cases() {
    echo -e "${PURPLE}🧠 Testing Memory Edge Cases${NC}"
    
    if command -v valgrind >/dev/null 2>&1; then
        # Test with long commands
        local long_input=$(printf 'echo %s ' {1..100})
        echo "$long_input" | timeout 30 valgrind --leak-check=full --error-exitcode=1 \
            --suppressions="$PROJECT_DIR/config/minishell.supp" \
            "$MINISHELL" >/dev/null 2>&1
        
        if [[ $? -eq 0 ]]; then
            echo -e "  ${GREEN}✅ PASS${NC}: Long command memory test"
            ((PASSED_TESTS++))
        else
            echo -e "  ${RED}❌ FAIL${NC}: Long command memory leak"
            ((FAILED_TESTS++))
        fi
        ((TOTAL_TESTS++))
        
        # Test with many variables
        local var_commands=""
        for i in {1..50}; do
            var_commands+="export VAR$i=value$i; "
        done
        var_commands+="exit"
        
        echo "$var_commands" | timeout 30 valgrind --leak-check=full --error-exitcode=1 \
            --suppressions="$PROJECT_DIR/config/minishell.supp" \
            "$MINISHELL" >/dev/null 2>&1
        
        if [[ $? -eq 0 ]]; then
            echo -e "  ${GREEN}✅ PASS${NC}: Many variables memory test"
            ((PASSED_TESTS++))
        else
            echo -e "  ${RED}❌ FAIL${NC}: Many variables memory leak"
            ((FAILED_TESTS++))
        fi
        ((TOTAL_TESTS++))
    else
        echo -e "  ${YELLOW}⚠️ SKIP${NC}: Valgrind not available"
        ((SKIPPED_TESTS += 2))
    fi
}

test_error_recovery() {
    echo -e "${PURPLE}🔄 Testing Error Recovery${NC}"
    
    # Test that shell continues after errors
    run_minishell_test "Continue after command error" "nonexistent_cmd; echo still_working" "still_working"
    run_minishell_test "Continue after syntax error" "echo hello |; echo still_working" "still_working"
    run_minishell_test "Continue after file error" "cat nonexistent.txt; echo still_working" "still_working"
    
    # Test error messages
    run_minishell_test "Clear error messages" "nonexistent_command" "command not found" false
    run_minishell_test "Syntax error message" "echo |" "syntax error" false
}

# ================================ MAIN FUNCTION ============================= #

run_unit_tests() {
    echo -e "${CYAN}🔬 Minishell Unit Tests${NC}"
    echo "========================="
    echo
    
    test_parsing_edge_cases
    echo
    test_quote_edge_cases
    echo
    test_variable_edge_cases
    echo
    test_pipe_edge_cases
    echo
    test_redirection_edge_cases
    echo
    test_builtin_edge_cases
    echo
    test_signal_edge_cases
    echo
    test_memory_edge_cases
    echo
    test_error_recovery
}

# Run unit tests if script is executed directly
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    setup_test_environment
    run_unit_tests
    print_summary
    cleanup_test_environment
fi
