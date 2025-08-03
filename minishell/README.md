# 🐚 Minishell

A simple shell implementation written in C as part of the 42 curriculum. This project recreates the basic functionality of a Unix shell, providing command execution, built-in commands, pipes, redirections, and environment variable handling.

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Operators](#operators)
- [Project Structure](#project-structure)
- [Documentation](#documentation)
- [Testing](#testing)
- [Contributing](#contributing)
- [Authors](#authors)

## 🎯 About

Minishell is a simplified version of bash that demonstrates understanding of:
- Process creation and management
- Signal handling
- File descriptor manipulation
- Parsing and lexical analysis
- Memory management
- Inter-process communication

This implementation follows the 42 School norm and coding standards.

## ✨ Features

### Core Functionality
- ✅ **Command Execution**: Execute programs from PATH and absolute/relative paths
- ✅ **Built-in Commands**: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- ✅ **Pipes**: Chain commands with `|` operator
- ✅ **Redirections**: Input `<`, output `>`, append `>>`, here-document `<<`
- ✅ **Environment Variables**: Full support for environment variable expansion
- ✅ **Signal Handling**: Proper handling of `Ctrl+C`, `Ctrl+D`, and `Ctrl+\`
- ✅ **Quote Handling**: Single and double quote parsing
- ✅ **History**: Command history using readline library

### Advanced Features
- 🔧 **Error Handling**: Comprehensive error messages and exit codes
- 🎨 **Prompt**: Interactive prompt display
- 🛡️ **Memory Management**: No memory leaks
- ⚡ **Performance**: Efficient parsing and execution

## 📦 Requirements

### System Requirements
- **OS**: Linux or macOS
- **Compiler**: gcc or clang with C99 support
- **Libraries**: readline library for input handling

### Dependencies
- `libreadline-dev` (on Ubuntu/Debian)
- `readline` (on macOS with Homebrew)

## 🚀 Installation

### 1. Clone the Repository
```bash
git clone https://github.com/NomanMunir/42cursus.git
cd 42cursus/minishell
```

### 2. Install Dependencies

**On Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install libreadline-dev
```

**On macOS:**
```bash
brew install readline
```

### 3. Compile the Project
```bash
make
```

### 4. Run Minishell
```bash
./minishell
```

## 💡 Usage

### Basic Commands
```bash
# Execute simple commands
minishell$ ls -la
minishell$ pwd
minishell$ echo "Hello, World!"

# Use pipes
minishell$ ls | grep .c | wc -l

# Redirections
minishell$ echo "test" > output.txt
minishell$ cat < input.txt
minishell$ ls >> log.txt

# Here-document
minishell$ cat << EOF
> This is a test
> EOF

# Environment variables
minishell$ echo $HOME
minishell$ export MY_VAR="Hello"
minishell$ echo $MY_VAR
```

### Advanced Usage
```bash
# Complex piping
minishell$ cat file.txt | grep "pattern" | sort | uniq

# Mixed quotes
minishell$ echo 'Single quotes: $HOME' "Double quotes: $HOME"

# Command substitution with environment variables
minishell$ export PATH="$PATH:/new/path"
```

## 🔧 Built-in Commands

| Command | Description | Usage |
|---------|-------------|-------|
| `echo` | Display text | `echo [-n] [text...]` |
| `cd` | Change directory | `cd [directory]` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variable | `export [VAR=value]` |
| `unset` | Unset environment variable | `unset [VAR]` |
| `env` | Display environment variables | `env` |
| `exit` | Exit the shell | `exit [code]` |

### Detailed Command Examples

#### echo
```bash
minishell$ echo Hello World
Hello World
minishell$ echo -n "No newline"
No newline
```

#### cd
```bash
minishell$ cd /tmp
minishell$ cd ..
minishell$ cd ~
minishell$ cd
```

#### export/unset
```bash
minishell$ export MY_VAR="test value"
minishell$ echo $MY_VAR
test value
minishell$ unset MY_VAR
minishell$ echo $MY_VAR

```

## 🔀 Operators

### Pipes (`|`)
Chain command output to input:
```bash
minishell$ command1 | command2 | command3
```

### Redirections
- **Input redirection** (`<`): `command < file`
- **Output redirection** (`>`): `command > file`
- **Append redirection** (`>>`): `command >> file`
- **Here-document** (`<<`): `command << delimiter`

### Examples
```bash
# Redirect output to file
minishell$ ls > files.txt

# Append to file
minishell$ echo "new line" >> files.txt

# Read from file
minishell$ wc -l < files.txt

# Here-document
minishell$ cat << END
> Line 1
> Line 2
> END
```

## 📁 Project Structure

```
minishell/
├── Makefile                    # Build configuration
├── README.md                   # Project documentation
├── docs/                       # Additional documentation
│   ├── ARCHITECTURE.md         # System architecture
│   ├── PARSING.md              # Parsing algorithm details
│   └── TESTING.md              # Testing guidelines
├── src/                        # Source code
│   ├── include/                # Header files
│   │   ├── minishell.h         # Main header
│   │   └── structs.h           # Structure definitions
│   ├── libs/                   # External libraries
│   │   ├── libft/              # Custom C library
│   │   └── gnl/                # Get Next Line
│   ├── main.c                  # Entry point
│   ├── builtins/               # Built-in commands
│   ├── execution/              # Command execution
│   ├── parsing/                # Input parsing
│   ├── tokenization/           # Token handling
│   ├── syntax/                 # Syntax checking
│   ├── handling_env/           # Environment handling
│   └── utils/                  # Utility functions
└── obj/                        # Object files (generated)
```

## 📚 Documentation

Detailed documentation is available in the `docs/` directory:

- **[Architecture](docs/ARCHITECTURE.md)**: System design and component interaction
- **[Parsing](docs/PARSING.md)**: Lexical analysis and parsing algorithms
- **[Testing](docs/TESTING.md)**: Testing procedures and test cases

## 🧪 Testing

### Professional Test Suite
```bash
# Run comprehensive test suite
make test

# Run specific test categories  
make test-unit         # Unit tests for edge cases
make test-stress       # Performance and stress tests
make test-memory       # Memory leak detection
make test-all          # All test categories

# Manual test runner
./tests/test_runner.sh all --verbose
```

### Manual Testing
```bash
# Basic functionality
./minishell
minishell$ echo "test"
minishell$ pwd
minishell$ exit

# Test with complex commands
minishell$ export TEST="hello world"
minishell$ echo $TEST | wc -w
```

### Debug Mode
```bash
# Compile with debug flags
make debug

# Run with AddressSanitizer
./minishell
```

## 🛠️ Development

### Build Targets
```bash
make            # Build the project
make clean      # Remove object files
make fclean     # Remove all generated files
make re         # Rebuild everything
make debug      # Build with debug flags
make valgrind   # Run with valgrind
make norm       # Check coding standards
make help       # Show all available targets
```

### Code Standards
- Follows 42 School norm
- No global variables (except for signal handling)
- Functions limited to 25 lines
- Maximum 5 functions per file
- Comprehensive error handling

## 🐛 Known Issues

- Limited command line editing capabilities compared to bash
- Some advanced bash features are not implemented
- Signal handling in heredoc may differ from bash behavior

## 🔮 Future Improvements

- [ ] Command completion
- [ ] Advanced globbing
- [ ] Job control
- [ ] Command history persistence
- [ ] Configuration file support

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Follow the 42 norm
4. Test your changes
5. Submit a pull request

## 👥 Authors

- **[abashir](https://github.com/alaabashir123)** - Co-developer
- **[nmunir](https://github.com/NomanMunir)** - Co-developer

## 📄 License

This project is part of the 42 curriculum and is intended for educational purposes.

## 📞 Support

If you encounter any issues or have questions:
1. Check the documentation in the `docs/` folder
2. Review the test cases
3. Open an issue on the repository

---

*Made with ❤️ at 42AbuDhabi School*

## 📈 Project Statistics

- **Lines of Code**: ~2000+
- **Functions**: 80+
- **Files**: 30+
- **Features Implemented**: 15+
- **Test Cases**: 50+

---

**Happy coding! 🚀**
