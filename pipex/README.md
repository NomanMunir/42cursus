# pipex - UNIX Pipes Implementation

## 📖 Description

pipex is a project where you recreate the behavior of shell pipes. The program takes four arguments and executes the equivalent of the shell command: `< file1 cmd1 | cmd2 > file2`. This project teaches UNIX system programming, process management, and inter-process communication.

## 🎯 Objectives

- Understand UNIX pipes and file descriptors
- Learn process creation and management with `fork()`
- Master file redirection and the `execve()` system call
- Practice inter-process communication (IPC)
- Handle multiple processes and wait for their completion

## 🔧 How It Works

### Shell Command Equivalent
```bash
# This shell command:
< file1 cmd1 | cmd2 > file2

# Is equivalent to:
./pipex file1 cmd1 cmd2 file2
```

### Example Usage
```bash
# Count lines in input.txt and save to output.txt
./pipex input.txt "grep hello" "wc -l" output.txt

# Equivalent shell command:
< input.txt grep hello | wc -l > output.txt
```

## 🏗 Project Structure

```
pipex/
├── Makefile
├── main.c                  # Main program logic
├── README                  # Project description
├── include/
│   └── pipex.h            # Header file with prototypes
├── src/
│   ├── pipex.c            # Core pipex functionality  
│   ├── utils.c            # Utility functions
│   ├── path.c             # PATH resolution
│   └── error.c            # Error handling
├── libs/
│   └── libft/             # Custom library
└── bonus/
    └── pipex_bonus.c      # Multiple pipes implementation
```

## 🔄 Process Flow

### 1. Input Validation
- Check argument count (exactly 4 arguments + program name)
- Validate file1 exists and is readable
- Validate file2 can be created/written

### 2. Pipe Creation
```c
int pipefd[2];
if (pipe(pipefd) == -1)
    error_exit("Pipe creation failed");
```

### 3. Fork Processes
```c
pid_t pid1 = fork();
if (pid1 == 0) {
    // Child process 1: cmd1
    // Redirect stdin from file1
    // Redirect stdout to pipe write end
    // Execute cmd1
}

pid_t pid2 = fork();
if (pid2 == 0) {
    // Child process 2: cmd2
    // Redirect stdin from pipe read end
    // Redirect stdout to file2
    // Execute cmd2
}

// Parent process waits for children
```

### 4. File Redirection
- **Process 1**: `file1` → stdin, stdout → pipe
- **Process 2**: pipe → stdin, stdout → `file2`

## 🛠 System Calls Used

### Process Management
- `fork()` - Create child processes
- `execve()` - Execute commands
- `wait()` / `waitpid()` - Wait for child processes
- `exit()` - Terminate process

### File Operations
- `open()` - Open files with appropriate flags
- `close()` - Close file descriptors
- `dup2()` - Duplicate file descriptors for redirection
- `access()` - Check file permissions

### Inter-Process Communication
- `pipe()` - Create communication pipe between processes

## 📋 Implementation Details

### File Descriptor Management
```c
// Child process 1 (cmd1)
int infile = open(argv[1], O_RDONLY);
dup2(infile, STDIN_FILENO);        // Redirect stdin
dup2(pipefd[1], STDOUT_FILENO);    // Redirect stdout to pipe
close(pipefd[0]);                  // Close unused pipe end
close(pipefd[1]);                  // Close original pipe fd
close(infile);                     // Close original file fd
```

### Command Execution
```c
char **cmd_args = ft_split(argv[2], ' ');  // Parse command
char *cmd_path = find_command_path(cmd_args[0]);  // Find in PATH
execve(cmd_path, cmd_args, envp);          // Execute command
```

### PATH Resolution
```c
char *find_command_path(char *command, char **envp)
{
    char *path_env = get_env_var("PATH", envp);
    char **paths = ft_split(path_env, ':');
    
    // Try each PATH directory
    for (int i = 0; paths[i]; i++) {
        char *full_path = join_path(paths[i], command);
        if (access(full_path, X_OK) == 0)
            return (full_path);
        free(full_path);
    }
    return (NULL);
}
```

## 🧪 Testing

### Basic Tests
```bash
# Test basic functionality
echo "hello world" > input.txt
./pipex input.txt "cat" "wc -w" output.txt
cat output.txt  # Should show: 2

# Test with grep and wc
printf "apple\nbanana\napricot\nberry" > fruits.txt
./pipex fruits.txt "grep a" "wc -l" count.txt
cat count.txt  # Should show: 3
```

### Error Handling Tests
```bash
# Non-existent input file
./pipex nonexistent.txt "cat" "wc -l" output.txt

# Invalid command
./pipex input.txt "invalidcmd" "wc -l" output.txt

# Permission denied
touch readonly.txt
chmod 000 readonly.txt
./pipex readonly.txt "cat" "wc -l" output.txt
```

### Advanced Tests
```bash
# Test with complex commands
./pipex /etc/passwd "grep root" "cut -d: -f1" output.txt

# Test with multiple arguments
./pipex input.txt "grep -v empty" "sort -r" output.txt

# Compare with shell equivalent
< input.txt grep hello | wc -l > shell_output.txt
./pipex input.txt "grep hello" "wc -l" pipex_output.txt
diff shell_output.txt pipex_output.txt
```

## 🎁 Bonus Features

### Multiple Pipes
The bonus part handles multiple commands:
```bash
# Multiple pipe support
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

# Equivalent to:
< file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2
```

### Here_doc Support
```bash
# Here document support (like << in shell)
./pipex here_doc LIMITER cmd1 cmd2 file2

# Equivalent to:
<< LIMITER cmd1 | cmd2 > file2
```

## 📏 Technical Requirements

- **Language**: C
- **Norm**: 42 Coding Standard
- **External Functions**: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
- **Memory**: No memory leaks allowed
- **Error Handling**: Must handle all error cases appropriately

## ⚠️ Error Handling

### Common Error Cases
1. **File Errors**: Non-existent files, permission denied
2. **Command Errors**: Invalid commands, command not found
3. **System Errors**: Fork failure, pipe creation failure
4. **Memory Errors**: Malloc failures, memory leaks

### Error Messages
```c
// Examples of proper error handling
if (access(file1, R_OK) == -1)
    ft_error("pipex: permission denied: ", file1);

if (fork() == -1)
    ft_error("pipex: fork failed", NULL);

if (execve(cmd_path, cmd_args, envp) == -1)
    ft_error("pipex: command not found: ", cmd_args[0]);
```

## 💡 Key Learning Points

1. **Process Management**: Understanding how UNIX processes work
2. **File Descriptors**: Mastering file descriptor manipulation
3. **Inter-Process Communication**: Learning how processes communicate
4. **System Programming**: Working directly with system calls
5. **Shell Behavior**: Understanding how shells implement pipes
6. **Error Handling**: Robust error detection in system programming

## 🔗 Real-World Applications

This knowledge is fundamental for:
- Shell implementation
- Process monitoring tools
- Build systems and automation
- Server and daemon programming
- DevOps and system administration

---

*This project provides essential knowledge about UNIX system programming and prepares you for more advanced system-level projects.*
