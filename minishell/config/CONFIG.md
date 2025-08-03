# 🔧 Configuration Files

This directory contains configuration files for development tools and utilities.

## 📋 Files

### `minishell.supp`
Valgrind suppression file for minishell project.

**Purpose**: Suppresses known false positives from external libraries like readline and ncurses that are not actual memory leaks in our code.

**Usage**: Automatically used by `make valgrind` target.

**Content**: Suppression rules for:
- Readline library allocations
- Termcap/Curses library leaks
- GLIBC system allocations
- macOS-specific library leaks
- Thread-local storage allocations

## 🚀 Usage

The configuration files in this directory are automatically used by the appropriate Makefile targets:

```bash
# Run valgrind with suppressions
make valgrind

# This automatically uses config/minishell.supp
```

## 📝 Customization

You can add custom suppression rules to `minishell.supp` if you encounter new false positives from external libraries.

Example suppression format:
```
{
   custom_leak_name
   Memcheck:Leak
   match-leak-kinds: definite,indirect,possible,reachable
   fun:malloc
   fun:your_function_name
}
```
