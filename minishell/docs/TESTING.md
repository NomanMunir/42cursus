# 🧪 Minishell Testing Guide

This document provides comprehensive testing procedures and guidelines for the minishell project.

## 📋 Testing Overview

Testing minishell requires validating multiple components:
- Command execution
- Built-in commands
- Pipes and redirections
- Environment variable handling
- Error conditions
- Memory management
- Signal handling

## 🛠️ Testing Setup

### Prerequisites
```bash
# Ensure minishell is compiled
make

# Install testing tools (optional)
sudo apt-get install valgrind   # For memory testing
sudo apt-get install strace     # For system call tracing
```

### Test Environment
```bash
# Create test directory
mkdir -p tests
cd tests

# Create test files
echo "test content" > test_input.txt
echo "line 1" > multiline.txt
echo "line 2" >> multiline.txt
```

## 🎯 Manual Testing Procedures

### 1. Basic Command Execution
```bash
# Test basic commands
./minishell
minishell$ echo hello world
minishell$ pwd
minishell$ ls -la
minishell$ whoami
minishell$ date

# Expected: Commands execute normally, output matches bash
```

### 2. Built-in Commands Testing

#### Echo Command
```bash
minishell$ echo hello
minishell$ echo -n hello
minishell$ echo "quoted string"
minishell$ echo 'single quotes'
minishell$ echo $HOME
minishell$ echo "$HOME"
minishell$ echo '$HOME'

# Expected: Behavior matches bash echo
```

#### PWD Command
```bash
minishell$ pwd
minishell$ cd /tmp
minishell$ pwd
minishell$ cd -  # Should return to previous directory

# Expected: Current directory displayed correctly
```

#### CD Command
```bash
minishell$ cd /tmp
minishell$ cd ..
minishell$ cd ~
minishell$ cd
minishell$ cd /nonexistent  # Should show error

# Expected: Directory changes work, errors handled
```

#### Export/Unset/Env
```bash
minishell$ export TEST_VAR="hello world"
minishell$ echo $TEST_VAR
minishell$ env | grep TEST_VAR
minishell$ export
minishell$ unset TEST_VAR
minishell$ echo $TEST_VAR

# Expected: Variables set/unset correctly
```

#### Exit Command
```bash
minishell$ exit
minishell$ exit 42
minishell$ exit invalid_number  # Should show error

# Expected: Shell exits with correct code
```

### 3. Pipes Testing
```bash
minishell$ ls | wc -l
minishell$ cat /etc/passwd | head -5
minishell$ echo "hello world" | wc -w
minishell$ ls -la | grep test | wc -l
minishell$ cat file.txt | sort | uniq

# Expected: Pipes work correctly, data flows between commands
```

### 4. Redirections Testing

#### Input Redirection
```bash
minishell$ wc -l < test_input.txt
minishell$ cat < multiline.txt
minishell$ sort < /etc/passwd

# Expected: Commands read from files correctly
```

#### Output Redirection
```bash
minishell$ echo "test" > output.txt
minishell$ ls -la > listing.txt
minishell$ cat output.txt
minishell$ cat listing.txt

# Expected: Output written to files, files created/overwritten
```

#### Append Redirection
```bash
minishell$ echo "line 1" > append_test.txt
minishell$ echo "line 2" >> append_test.txt
minishell$ cat append_test.txt

# Expected: Second line appended, not overwritten
```

#### Here-Documents
```bash
minishell$ cat << EOF
> This is line 1
> This is line 2
> EOF

minishell$ wc -l << END
> line 1
> line 2
> line 3
> END

# Expected: Here-doc content processed correctly
```

### 5. Complex Command Testing
```bash
minishell$ ls | grep .c | wc -l
minishell$ cat file.txt | grep pattern | sort | uniq > result.txt
minishell$ echo "test" | cat > output.txt && cat output.txt
minishell$ < input.txt cat | grep pattern > output.txt

# Expected: Complex combinations work correctly
```

### 6. Environment Variables
```bash
minishell$ echo $HOME
minishell$ echo $PATH
minishell$ echo $USER
minishell$ export MY_VAR="test"
minishell$ echo $MY_VAR
minishell$ echo "$MY_VAR and $HOME"

# Expected: Variables expand correctly in all contexts
```

### 7. Quote Handling
```bash
minishell$ echo "hello world"
minishell$ echo 'hello world'
minishell$ echo "hello 'world'"
minishell$ echo 'hello "world"'
minishell$ echo "Variable: $HOME"
minishell$ echo 'Variable: $HOME'

# Expected: Quotes handled according to bash rules
```

### 8. Signal Handling
```bash
# Start minishell and test signals
./minishell
minishell$ sleep 10
# Press Ctrl+C (should interrupt)

minishell$ cat
# Press Ctrl+D (should exit cat)

minishell$ sleep 10
# Press Ctrl+\ (should be ignored)

# Expected: Signals handled correctly
```

## 🔍 Error Testing

### 1. Syntax Errors
```bash
minishell$ ls |
minishell$ cat <
minishell$ echo >
minishell$ ls | | cat
minishell$ echo "unclosed quote

# Expected: Appropriate error messages, no crashes
```

### 2. Runtime Errors
```bash
minishell$ /nonexistent/command
minishell$ cat nonexistent_file.txt
minishell$ cd /nonexistent/directory
minishell$ export =invalid
minishell$ unset

# Expected: Error messages similar to bash
```

### 3. Permission Errors
```bash
# Create files with different permissions
touch readonly.txt
chmod 000 readonly.txt

minishell$ cat readonly.txt
minishell$ echo "test" > readonly.txt

# Expected: Permission errors handled gracefully
```

## 🧠 Memory Testing

### Valgrind Testing
```bash
# Test for memory leaks
make valgrind

# Or run manually
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./minishell

# Test specific scenarios
echo "exit" | valgrind ./minishell
echo "ls | wc -l" | valgrind ./minishell
```

### AddressSanitizer Testing
```bash
# Compile with debug flags
make debug

# Run tests
./minishell
# Test various commands and exit
```

## 🤖 Automated Testing

### Test Script Template
```bash
#!/bin/bash

# test_minishell.sh
MINISHELL="./minishell"
PASSED=0
FAILED=0

test_command() {
    local cmd="$1"
    local expected="$2"
    local description="$3"
    
    echo "Testing: $description"
    result=$(echo "$cmd" | $MINISHELL 2>&1)
    
    if [[ "$result" == *"$expected"* ]]; then
        echo "✅ PASS: $description"
        ((PASSED++))
    else
        echo "❌ FAIL: $description"
        echo "  Expected: $expected"
        echo "  Got: $result"
        ((FAILED++))
    fi
    echo
}

# Basic command tests
test_command "echo hello" "hello" "Basic echo command"
test_command "pwd" "/home" "PWD command"

# Built-in tests
test_command "export TEST=value; echo \$TEST" "value" "Export and variable expansion"

# Error tests
test_command "nonexistent_command" "command not found" "Command not found error"

echo "Tests completed: $PASSED passed, $FAILED failed"
```

### Comparison Testing
```bash
#!/bin/bash

# compare_with_bash.sh
test_comparison() {
    local cmd="$1"
    
    echo "Command: $cmd"
    
    # Run with bash
    bash_output=$(echo "$cmd" | bash 2>&1)
    bash_exit=$?
    
    # Run with minishell
    mini_output=$(echo "$cmd" | ./minishell 2>&1)
    mini_exit=$?
    
    if [[ "$bash_output" == "$mini_output" ]] && [[ $bash_exit -eq $mini_exit ]]; then
        echo "✅ MATCH"
    else
        echo "❌ DIFFER"
        echo "Bash: $bash_output (exit: $bash_exit)"
        echo "Mini: $mini_output (exit: $mini_exit)"
    fi
    echo
}

# Test cases
test_comparison "echo hello"
test_comparison "ls | wc -l"
test_comparison "echo \$HOME"
```

## 📊 Performance Testing

### Stress Testing
```bash
#!/bin/bash

# stress_test.sh
echo "Running stress tests..."

# Test many pipes
echo "ls | cat | cat | cat | cat | cat | wc -l" | ./minishell

# Test large environment
for i in {1..100}; do
    echo "export VAR$i=value$i"
done | ./minishell

# Test long commands
echo "echo $(printf 'a%.0s' {1..1000})" | ./minishell
```

### Memory Stress Testing
```bash
#!/bin/bash

# memory_stress.sh
echo "Testing memory usage..."

# Monitor memory while running commands
(sleep 1; ps aux | grep minishell) &

echo "
export LARGE_VAR=\"$(printf 'x%.0s' {1..10000})\"
echo \$LARGE_VAR | wc -c
unset LARGE_VAR
exit
" | ./minishell
```

## 🐛 Debugging Tests

### GDB Testing
```bash
# Compile with debug symbols
make debug

# Run with GDB
gdb ./minishell
(gdb) run
(gdb) break main
(gdb) continue
```

### Strace Testing
```bash
# Trace system calls
strace -o trace.log ./minishell

# Analyze the trace
grep -E "(open|read|write|fork|exec)" trace.log
```

## ✅ Test Checklist

### Basic Functionality
- [ ] Simple command execution
- [ ] Built-in commands (echo, cd, pwd, export, unset, env, exit)
- [ ] Pipes (single and multiple)
- [ ] Input redirection (<)
- [ ] Output redirection (>)
- [ ] Append redirection (>>)
- [ ] Here-documents (<<)

### Advanced Features
- [ ] Environment variable expansion
- [ ] Quote handling (single and double)
- [ ] Complex command combinations
- [ ] Signal handling (Ctrl+C, Ctrl+D, Ctrl+\)
- [ ] Error handling and messages

### Edge Cases
- [ ] Empty input
- [ ] Only whitespace input
- [ ] Very long commands
- [ ] Special characters
- [ ] Invalid syntax
- [ ] Permission errors

### Memory and Performance
- [ ] No memory leaks (Valgrind)
- [ ] No buffer overflows (AddressSanitizer)
- [ ] Reasonable performance
- [ ] Proper cleanup on exit

### Compatibility
- [ ] Behavior matches bash where specified
- [ ] Exit codes match bash
- [ ] Error messages are reasonable

## 📈 Continuous Testing

### Pre-commit Testing
```bash
#!/bin/bash
# pre-commit.sh

echo "Running pre-commit tests..."

# Compile check
if ! make; then
    echo "❌ Compilation failed"
    exit 1
fi

# Basic functionality check
if ! echo "echo test; exit" | ./minishell | grep -q "test"; then
    echo "❌ Basic functionality test failed"
    exit 1
fi

# Memory leak check
if ! echo "exit" | valgrind --leak-check=full --error-exitcode=1 ./minishell > /dev/null 2>&1; then
    echo "❌ Memory leak detected"
    exit 1
fi

echo "✅ All pre-commit tests passed"
```

### Regression Testing
```bash
#!/bin/bash
# regression_test.sh

# Test previously fixed bugs to ensure they don't reappear
test_regression() {
    local test_name="$1"
    local cmd="$2"
    local expected_behavior="$3"
    
    echo "Regression test: $test_name"
    # Implementation depends on specific bug
}
```

## 📝 Test Documentation

### Test Case Format
```
Test ID: TC-001
Description: Basic echo command
Input: echo hello world
Expected Output: hello world
Expected Exit Code: 0
Category: Basic Commands
Priority: High
```

### Bug Report Template
```
Bug ID: BUG-001
Title: [Brief description]
Description: [Detailed description]
Steps to Reproduce: [Step by step]
Expected Behavior: [What should happen]
Actual Behavior: [What actually happens]
Environment: [OS, compiler version, etc.]
Severity: [Critical/High/Medium/Low]
```

---

Regular testing ensures minishell maintains high quality and reliability throughout development.
