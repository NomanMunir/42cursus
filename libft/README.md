# libft - Custom C Library

## 📖 Description

libft is the first project in the 42 curriculum where you implement your own version of standard C library functions. This project teaches fundamental programming concepts and serves as a foundation for all future 42 projects.

## 🎯 Objectives

- Understand how standard C library functions work internally
- Learn proper memory management in C
- Practice string manipulation and linked list operations
- Create a reusable library for future projects

## 📚 Functions Implemented

### Part 1 - Standard Library Functions

#### Character Classification & Conversion
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is numeric
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable
- `ft_toupper` - Convert character to uppercase
- `ft_tolower` - Convert character to lowercase

#### String Manipulation
- `ft_strlen` - Calculate string length
- `ft_strchr` - Locate character in string
- `ft_strrchr` - Locate character in string (from end)
- `ft_strncmp` - Compare strings up to n characters
- `ft_strlcpy` - Copy string with size limit
- `ft_strlcat` - Concatenate strings with size limit
- `ft_strnstr` - Locate substring in string

#### Memory Functions
- `ft_memset` - Fill memory with constant byte
- `ft_bzero` - Zero memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (handles overlap)
- `ft_memchr` - Scan memory for character
- `ft_memcmp` - Compare memory areas

#### Conversion & Allocation
- `ft_atoi` - Convert string to integer
- `ft_calloc` - Allocate and zero memory
- `ft_strdup` - Duplicate string

### Part 2 - Additional Functions

- `ft_substr` - Extract substring
- `ft_strjoin` - Concatenate strings
- `ft_strtrim` - Trim characters from string
- `ft_split` - Split string by delimiter
- `ft_itoa` - Convert integer to string
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function to each character with index
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output number to file descriptor

### Bonus Part - Linked Lists

- `ft_lstnew` - Create new list element
- `ft_lstadd_front` - Add element at beginning
- `ft_lstsize` - Count elements in list
- `ft_lstlast` - Get last element
- `ft_lstadd_back` - Add element at end
- `ft_lstdelone` - Delete element
- `ft_lstclear` - Delete and free list
- `ft_lstiter` - Apply function to each element
- `ft_lstmap` - Apply function and create new list

## 🛠 Compilation

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
make bonus  # Compile with bonus functions
```

## 📋 Usage

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    char **split = ft_split(str, ' ');
    
    ft_putstr_fd(str, 1);
    ft_putchar_fd('\n', 1);
    
    // Don't forget to free allocated memory
    free(str);
    // Free split array...
    
    return (0);
}
```

Compile with your project:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft
```

## 📏 Technical Requirements

- **Language**: C
- **Norm**: 42 Coding Standard
- **Functions**: No banned functions
- **Memory**: No memory leaks allowed
- **Error handling**: Functions must not crash

## 🧪 Testing

While not included in this repository, you can test libft with:
- [libft-unit-test](https://github.com/alelievr/libft-unit-test)
- [Francinette](https://github.com/xicodomingues/francinette)
- Custom test programs

## 💡 Key Learning Points

1. **Memory Management**: Understanding malloc, free, and avoiding leaks
2. **Pointer Manipulation**: Working with pointers and pointer arithmetic
3. **String Handling**: Safe string operations and boundary checking
4. **Linked Lists**: Dynamic data structures and memory allocation
5. **Code Organization**: Creating a clean, reusable library

## 🔗 Usage in Other Projects

This library is used as a foundation in most other 42 projects:
- ft_printf
- get_next_line
- push_swap
- pipex
- so_long
- philosophers
- cub3D

---

*This project establishes the foundation for all C programming at 42. Every function is implemented from scratch to ensure deep understanding of the underlying mechanisms.*
