# 🤝 Contributing to Minishell

Thank you for your interest in contributing to minishell! This document provides guidelines and information for contributors.

## 📋 Table of Contents

- [Getting Started](#getting-started)
- [Development Process](#development-process)
- [Coding Standards](#coding-standards)
- [Testing Requirements](#testing-requirements)
- [Submitting Changes](#submitting-changes)
- [Issue Guidelines](#issue-guidelines)
- [Code Review Process](#code-review-process)

## 🚀 Getting Started

### Prerequisites
- GCC or Clang compiler
- Make build system
- Git version control
- libreadline-dev (Linux) or readline (macOS)
- Basic understanding of C programming and Unix systems

### Setting Up Development Environment

1. **Fork the repository**
   ```bash
   # Click "Fork" on GitHub, then clone your fork
   git clone https://github.com/YOUR_USERNAME/42cursus.git
   cd 42cursus/minishell
   ```

2. **Set up upstream remote**
   ```bash
   git remote add upstream https://github.com/NomanMunir/42cursus.git
   ```

3. **Create development branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

4. **Build and test**
   ```bash
   make
   ./minishell
   ```

## 🔄 Development Process

### Workflow
1. **Issue First**: Create or find an issue before starting work
2. **Branch**: Create a feature branch from `main`
3. **Develop**: Write code following our standards
4. **Test**: Ensure all tests pass
5. **Document**: Update documentation if needed
6. **Submit**: Create a pull request

### Branch Naming Convention
```
feature/description       # New features
bugfix/description       # Bug fixes
docs/description         # Documentation updates
refactor/description     # Code refactoring
test/description         # Test improvements
```

Examples:
- `feature/add-job-control`
- `bugfix/fix-pipe-memory-leak`
- `docs/update-readme`

## 📏 Coding Standards

### 42 School Norm Compliance
This project follows the [42 School Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf):

#### File Organization
- Maximum 25 lines per function
- Maximum 5 functions per file
- Maximum 80 characters per line
- Functions must be separated by exactly one empty line

#### Naming Conventions
```c
// Functions: lowercase with underscores
int ft_strlen(char *str);
void handle_pipe(t_cmd *cmd);

// Variables: lowercase with underscores
char *file_name;
int exit_code;

// Structures: prefix with 's_'
typedef struct s_shell
{
    char    *input;
    char    **env;
} t_shell;

// Enums: uppercase
typedef enum e_token_type
{
    TOKEN_WORD,
    TOKEN_PIPE
} t_token_type;
```

#### Header Files
```c
#ifndef MINISHELL_H
# define MINISHELL_H

// Includes
# include <stdio.h>
# include <stdlib.h>

// Macros
# define MAX_ARGS 100

// Function prototypes
int     main(int argc, char **argv);
void    cleanup(t_shell *shell);

#endif
```

#### Function Format
```c
/*
** Brief description of function
** @param param1: description
** @param param2: description
** @return: description
*/
int function_name(char *param1, int param2)
{
    // Variable declarations at top
    int     result;
    char    *temp;
    
    // Function body
    if (!param1)
        return (-1);
    
    return (result);
}
```

### Additional Guidelines

#### Error Handling
```c
// Always check malloc return values
char *str = malloc(size);
if (!str)
    return (handle_malloc_error());

// Use consistent error codes
#define SUCCESS     0
#define ERROR      -1
#define MALLOC_ERR -2
```

#### Memory Management
```c
// Free in reverse order of allocation
char **array = allocate_array();
if (!array)
    return (ERROR);

// Use cleanup functions
cleanup_array(array);
return (SUCCESS);
```

## 🧪 Testing Requirements

### Before Submitting
1. **Compilation**: Code must compile without warnings
   ```bash
   make
   ```

2. **Basic functionality**: Test core features
   ```bash
   echo "echo test; exit" | ./minishell
   ```

3. **Memory leaks**: No leaks allowed
   ```bash
   make valgrind
   ```

4. **Norm compliance**: Follow 42 standards
   ```bash
   make norm
   ```

### Test Categories
- **Unit Tests**: Individual function testing
- **Integration Tests**: Component interaction testing
- **System Tests**: End-to-end functionality
- **Performance Tests**: Memory and speed benchmarks

### Writing Tests
```c
// Test function template
int test_function_name(void)
{
    // Setup
    t_shell shell;
    init_shell(&shell);
    
    // Test
    int result = function_to_test(&shell);
    
    // Assert
    if (result != expected_value)
    {
        cleanup_shell(&shell);
        return (FAILURE);
    }
    
    // Cleanup
    cleanup_shell(&shell);
    return (SUCCESS);
}
```

## 📝 Submitting Changes

### Pull Request Process

1. **Update your branch**
   ```bash
   git fetch upstream
   git rebase upstream/main
   ```

2. **Run tests**
   ```bash
   make test
   make norm
   ```

3. **Commit changes**
   ```bash
   git add .
   git commit -m "feat: add pipe operator support"
   ```

4. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

5. **Create pull request** on GitHub

### Commit Message Format
```
type(scope): brief description

Detailed explanation of changes (if needed)

- Key change 1
- Key change 2

Fixes #issue_number
```

#### Types
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, etc.)
- `refactor`: Code refactoring
- `test`: Adding/updating tests
- `chore`: Maintenance tasks

#### Examples
```
feat(parsing): add here-document support

Implement << operator for here-documents with proper
delimiter handling and variable expansion.

- Add parse_heredoc function
- Update tokenizer for << operator
- Add tests for various delimiter types

Fixes #42
```

### Pull Request Template
```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Performance improvement

## Testing
- [ ] Tests pass locally
- [ ] No memory leaks
- [ ] Norm compliance verified

## Checklist
- [ ] Code follows project style
- [ ] Self-review completed
- [ ] Documentation updated
- [ ] Tests added/updated
```

## 🐛 Issue Guidelines

### Before Creating an Issue
1. Search existing issues for duplicates
2. Check if it's already fixed in latest version
3. Verify it's actually a bug (not expected behavior)

### Bug Report Template
```markdown
**Bug Description**
Clear description of the bug

**Steps to Reproduce**
1. Step one
2. Step two
3. Step three

**Expected Behavior**
What should happen

**Actual Behavior**
What actually happens

**Environment**
- OS: [e.g., Ubuntu 20.04]
- Compiler: [e.g., GCC 9.4.0]
- Shell: [e.g., bash 5.0.17]

**Additional Context**
Any other relevant information
```

### Feature Request Template
```markdown
**Feature Description**
Clear description of the proposed feature

**Use Case**
Why is this feature needed?

**Proposed Implementation**
How should it work?

**Alternatives Considered**
Other approaches you've thought about

**Additional Context**
Any other relevant information
```

## 👀 Code Review Process

### For Reviewers
1. **Check functionality**: Does it work as intended?
2. **Review code quality**: Is it readable and maintainable?
3. **Verify testing**: Are there adequate tests?
4. **Check documentation**: Is documentation updated?
5. **Norm compliance**: Does it follow 42 standards?

### Review Checklist
- [ ] Code compiles without warnings
- [ ] All tests pass
- [ ] No memory leaks
- [ ] Follows coding standards
- [ ] Documentation is updated
- [ ] Commit messages are clear
- [ ] No breaking changes (or properly documented)

### Review Comments
```markdown
// Approval
LGTM! Great implementation of the pipe operator.

// Request changes
The memory allocation in line 42 needs error checking.

// Suggestion
Consider using a switch statement instead of multiple if-else.

// Question
Why did you choose this approach over using recursion?
```

## 🎯 Areas for Contribution

### High Priority
- [ ] Memory leak fixes
- [ ] Performance optimizations
- [ ] Test coverage improvements
- [ ] Documentation updates

### Medium Priority
- [ ] Error message improvements
- [ ] Code refactoring
- [ ] Additional built-in commands
- [ ] Cross-platform compatibility

### Low Priority
- [ ] Code style improvements
- [ ] Comments and documentation
- [ ] Example scripts
- [ ] Tooling improvements

## 💡 Tips for Contributors

### Getting Familiar
1. Read the entire README.md
2. Study the architecture documentation
3. Run existing tests to understand behavior
4. Start with small bug fixes or documentation

### Best Practices
- Write self-documenting code
- Add comments for complex logic
- Test edge cases thoroughly
- Consider performance implications
- Follow the principle of least surprise

### Common Pitfalls
- Not checking return values from system calls
- Memory leaks in error paths
- Ignoring signal handling edge cases
- Not testing with various input combinations

## 📚 Resources

### Learning Materials
- [42 School Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)
- [C Programming Guidelines](https://www.kernel.org/doc/html/latest/process/coding-style.html)
- [Unix Programming](http://www.apuebook.com/)
- [Shell Implementation Guide](http://www.stephendiehl.com/posts/linker.html)

### Tools
- **Valgrind**: Memory debugging
- **GDB**: Debugging
- **Strace**: System call tracing
- **Norminette**: 42 norm checker

## 🙋 Getting Help

### Communication Channels
- **Issues**: For bugs and feature requests
- **Discussions**: For general questions
- **Pull Requests**: For code review

### When to Ask for Help
- Stuck on implementation details
- Unsure about design decisions
- Need clarification on requirements
- Having trouble with testing

---

Thank you for contributing to minishell! Your efforts help make this project better for everyone. 🚀
