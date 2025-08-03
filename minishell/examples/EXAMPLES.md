# 📝 Minishell Examples

This directory contains practical examples of using minishell features.

## 🔧 Basic Commands

### Simple Commands
```bash
# Display current directory
./minishell
minishell$ pwd

# List files
minishell$ ls -la

# Display environment variable
minishell$ echo $HOME
```

## 🔗 Pipes Examples

### Single Pipe
```bash
# Count files in current directory
minishell$ ls | wc -l

# Find C files
minishell$ ls | grep .c
```

### Multiple Pipes
```bash
# Complex pipeline
minishell$ ls -la | grep "^d" | wc -l

# Text processing
minishell$ cat /etc/passwd | head -10 | tail -5
```

## ➡️ Redirections Examples

### Input Redirection
```bash
# Read from file
minishell$ wc -l < /etc/passwd

# Sort file contents
minishell$ sort < names.txt
```

### Output Redirection
```bash
# Save output to file
minishell$ ls -la > files.txt

# Save error output
minishell$ ls /nonexistent 2> errors.txt
```

### Append Redirection
```bash
# Append to log file
minishell$ echo "$(date): System check" >> system.log

# Append command output
minishell$ ps aux >> process_list.txt
```

## 📄 Here-Documents

### Basic Here-Document
```bash
# Create multi-line input
minishell$ cat << EOF
This is line 1
This is line 2
This is line 3
EOF
```

### Here-Document with Variables
```bash
# Variable expansion in here-doc
minishell$ cat << END
Current user: $USER
Home directory: $HOME
Current date: $(date)
END
```

## 🌍 Environment Variables

### Setting and Using Variables
```bash
# Set environment variable
minishell$ export MY_VAR="Hello World"

# Use the variable
minishell$ echo $MY_VAR

# Use in commands
minishell$ echo "Message: $MY_VAR"
```

### PATH Manipulation
```bash
# Add to PATH
minishell$ export PATH="$PATH:/new/bin/directory"

# Check PATH
minishell$ echo $PATH
```

## 💭 Quote Handling

### Single vs Double Quotes
```bash
# Single quotes - literal
minishell$ echo 'The variable $HOME is not expanded'

# Double quotes - expansion
minishell$ echo "The variable $HOME is expanded"

# Mixed quotes
minishell$ echo "User's home: $HOME"
```

## 🔧 Built-in Commands

### Directory Navigation
```bash
# Change directory
minishell$ cd /tmp
minishell$ pwd

# Go to home
minishell$ cd ~
minishell$ pwd

# Go back
minishell$ cd -
```

### Environment Management
```bash
# List all environment variables
minishell$ env

# Export with assignment
minishell$ export DEBUG=1

# Remove variable
minishell$ unset DEBUG
```

### Echo Variations
```bash
# Basic echo
minishell$ echo Hello World

# Echo without newline
minishell$ echo -n "Enter your name: "

# Echo with variables
minishell$ echo "Welcome, $USER!"
```

## 🚀 Advanced Examples

### Complex Command Combinations
```bash
# Find and count C files
minishell$ find . -name "*.c" | wc -l

# Process log files
minishell$ cat access.log | grep "ERROR" | head -20 > recent_errors.txt

# System information
minishell$ ps aux | grep $USER | wc -l > user_processes.txt
```

### Data Processing Pipeline
```bash
# Text analysis pipeline
minishell$ cat document.txt | tr '[:upper:]' '[:lower:]' | sort | uniq -c | sort -nr
```

### File Operations
```bash
# Backup and process
minishell$ cp important.txt important.txt.bak
minishell$ cat important.txt | sed 's/old/new/g' > important.txt.new
```

## 🧪 Testing Examples

### Error Handling
```bash
# Test command not found
minishell$ nonexistent_command

# Test file not found
minishell$ cat missing_file.txt

# Test permission denied
minishell$ cat /etc/shadow
```

### Signal Testing
```bash
# Test Ctrl+C interrupt
minishell$ sleep 10
# Press Ctrl+C

# Test Ctrl+D (EOF)
minishell$ cat
# Press Ctrl+D
```

## 📊 Performance Examples

### Memory Usage
```bash
# Monitor memory while running
minishell$ ps aux | grep minishell

# Test with large output
minishell$ find / -type f 2>/dev/null | wc -l
```

### Stress Testing
```bash
# Many pipes
minishell$ echo "test" | cat | cat | cat | cat | wc -c

# Large environment
minishell$ export LARGE_VAR="$(printf 'x%.0s' {1..1000})"
minishell$ echo ${#LARGE_VAR}
```

## 🔍 Debugging Examples

### Using with External Tools
```bash
# Run with strace
strace -e trace=execve ./minishell

# Run with valgrind
valgrind --leak-check=full ./minishell

# Run with gdb
gdb ./minishell
```

### Debug Output
```bash
# Compile with debug
make debug

# Run debug version
./minishell
```

---

These examples demonstrate the capabilities of minishell and can be used for testing and learning purposes.
