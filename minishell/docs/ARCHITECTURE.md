# 🏗️ Minishell Architecture

This document describes the overall architecture and design patterns used in the minishell implementation.

## 📐 System Overview

Minishell follows a modular architecture with clear separation of concerns:

```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   Input Layer   │ -> │  Parsing Layer  │ -> │ Execution Layer │
└─────────────────┘    └─────────────────┘    └─────────────────┘
        │                        │                        │
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│ Signal Handling │    │ Syntax Analysis │    │   Built-ins     │
└─────────────────┘    └─────────────────┘    └─────────────────┘
        │                        │                        │
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│  Environment    │    │  Tokenization   │    │ External Cmds   │
│    Management   │    │                 │    │                 │
└─────────────────┘    └─────────────────┘    └─────────────────┘
```

## 🧩 Core Components

### 1. Main Loop (`main.c`)
- **Purpose**: Entry point and main execution loop
- **Responsibilities**:
  - Initialize the shell environment
  - Set up signal handlers
  - Read user input with readline
  - Coordinate parsing and execution
  - Handle cleanup and exit

### 2. Input Processing
#### Tokenization (`tokenization/`)
- **Files**: `gettoken.c`, `token_utils.c`
- **Purpose**: Break input into meaningful tokens
- **Key Functions**:
  - `gettoken()`: Extract next token from input
  - `skip_spaces()`: Handle whitespace
  - `skip_char_token()`: Process special characters

#### Syntax Analysis (`syntax/`)
- **Files**: `check_syntax.c`, `check_input.c`, `syntax_utils.c`
- **Purpose**: Validate command syntax before parsing
- **Key Functions**:
  - `check_syntax()`: Main syntax validation
  - `is_quotes_closed()`: Quote validation
  - `syntax_error()`: Error reporting

### 3. Parsing Layer (`parsing/`)
- **Files**: `parsecmd.c`, `parse_*.c`
- **Purpose**: Convert tokens into executable command structures
- **Architecture**:
  ```
  parsecmd() 
      │
      ├── parseline()     # Handle ; operator
      │   └── parsepipe() # Handle | operator
      │       └── parseexec() # Handle command + redirections
      │           └── parseredirs() # Handle <, >, >>, <<
  ```

#### Command Tree Structure
```c
typedef enum {
    EXEC,     // Simple command
    REDIR,    // Redirection
    PIPE,     // Pipe
    HEREDOC   // Here-document
} t_cmd_type;

typedef struct s_cmd {
    t_cmd_type type;
} t_cmd;
```

### 4. Execution Engine (`execution/`)
- **Files**: `execution.c`, `handle_*.c`, `exe_utils.c`
- **Purpose**: Execute parsed command structures
- **Components**:
  - `handle_exec()`: Execute simple commands
  - `handle_pipe()`: Handle pipe operations
  - `handle_redir()`: Handle redirections
  - `handle_heredoc()`: Process here-documents

### 5. Built-in Commands (`builtins/`)
- **Files**: `ft_*.c`, `check_builtins.c`
- **Purpose**: Implement shell built-in commands
- **Commands**: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

### 6. Environment Management (`handling_env/`)
- **Files**: `init_env.c`, `env_utils.c`, `print_env.c`
- **Purpose**: Manage environment variables
- **Key Features**:
  - Environment variable expansion
  - Variable modification and access
  - PATH resolution

### 7. Utilities (`utils/`)
- **Files**: Various utility functions
- **Purpose**: Common functionality across modules
- **Includes**:
  - Memory management
  - String manipulation
  - Error handling
  - Signal processing

## 🔄 Data Flow

### 1. Input Processing Flow
```
User Input -> Readline -> Syntax Check -> Tokenization -> Parsing -> AST
```

### 2. Execution Flow
```
AST -> Command Type Check -> Handler Selection -> Execution -> Output
```

### 3. Error Handling Flow
```
Error Detection -> Error Classification -> Error Message -> Cleanup -> Recovery
```

## 🗃️ Data Structures

### Main Shell Structure
```c
typedef struct s_shell {
    char            *input;           // Current input line
    char            **env;            // Environment array
    bool            is_forked;        // Fork status
    bool            is_one_command;   // Single command flag
    bool            is_pipe;          // Pipe present flag
    bool            is_builtins;      // Built-in command flag
    long long       g_exit_code;      // Last exit code
    struct s_env    *env_list;        // Environment linked list
    t_cmd           *cmd;             // Parsed command tree
    t_cmd_list      *cmd_list;        // Command list
} t_shell;
```

### Command Structures
```c
// Base command structure
typedef struct s_cmd {
    t_cmd_type type;
} t_cmd;

// Execution command
typedef struct s_execcmd {
    t_cmd       cmd;
    char        *argv[MAXARGS];
    char        *eargv[MAXARGS];
} t_execcmd;

// Redirection command
typedef struct s_redircmd {
    t_cmd       cmd;
    t_cmd       *subcmd;
    char        *file;
    char        *efile;
    int         mode;
    int         fd;
} t_redircmd;

// Pipe command
typedef struct s_pipecmd {
    t_cmd       cmd;
    t_cmd       *left;
    t_cmd       *right;
} t_pipecmd;
```

## 🎛️ Signal Handling

### Signal Architecture
- **Global Variable**: `g_signum` for signal communication
- **Handlers**:
  - `SIGINT` (Ctrl+C): Interrupt current operation
  - `SIGQUIT` (Ctrl+\): Ignored in interactive mode
  - `SIGPIPE`: Handle broken pipes

### Signal Flow
```
Signal Received -> Handler Function -> Global Flag Set -> Main Loop Check
```

## 🔧 Memory Management

### Allocation Strategy
- **Principle**: Allocate early, free systematically
- **Patterns**:
  - Constructor functions for complex structures
  - Cleanup functions for each module
  - Error-specific cleanup routines

### Memory Flow
```
Allocation -> Usage -> Error Check -> Cleanup -> Free
```

## 🚦 Error Handling Strategy

### Error Categories
1. **Syntax Errors**: Invalid command syntax
2. **Runtime Errors**: Execution failures
3. **System Errors**: System call failures
4. **Memory Errors**: Allocation failures

### Error Propagation
```
Error Detection -> Error Code -> Error Message -> Cleanup -> Recovery/Exit
```

## 🔍 Parsing Algorithm

### Recursive Descent Parser
The parser uses a recursive descent approach:

1. **parsecmd()**: Entry point
2. **parseline()**: Handle command sequences
3. **parsepipe()**: Handle pipe operators
4. **parseexec()**: Handle simple commands
5. **parseredirs()**: Handle redirections

### Grammar (Simplified BNF)
```
cmd      ::= line
line     ::= pipe
pipe     ::= exec ('|' exec)*
exec     ::= (redir)* WORD (WORD)*
redir    ::= '<' WORD | '>' WORD | '>>' WORD | '<<' WORD
```

## 🎯 Design Patterns

### 1. Command Pattern
- Commands are objects that encapsulate all information needed for execution
- Enables undo/redo functionality and command queuing

### 2. Strategy Pattern
- Different execution strategies for different command types
- Enables easy addition of new command types

### 3. Factory Pattern
- Command creation is centralized in parsing functions
- Ensures consistent command object creation

## 🔄 Process Management

### Fork Strategy
```c
if (shell->is_builtins && shell->is_one_command) {
    // Execute built-in directly (no fork)
    shell->is_forked = false;
} else {
    // Fork for external commands
    shell->is_forked = true;
    pid = fork();
}
```

### Pipe Implementation
```
Parent Process
    │
    ├── Fork Child 1 ──> Command 1 ──> Write to pipe
    │
    └── Fork Child 2 ──> Command 2 ──> Read from pipe
```

## 📊 Performance Considerations

### Optimization Strategies
1. **Early Validation**: Syntax check before expensive parsing
2. **Lazy Evaluation**: Parse only when needed
3. **Memory Pooling**: Reuse structures when possible
4. **Efficient Tokenization**: Single-pass tokenization

### Time Complexity
- **Parsing**: O(n) where n is input length
- **Execution**: O(1) for built-ins, variable for external commands
- **Environment Lookup**: O(n) where n is number of variables

## 🔒 Security Considerations

### Input Sanitization
- Quote handling prevents injection
- Path validation for command execution
- Environment variable validation

### Process Isolation
- Child processes for external commands
- Proper file descriptor management
- Signal isolation between processes

---

This architecture provides a solid foundation for a shell implementation while maintaining clarity and extensibility.
