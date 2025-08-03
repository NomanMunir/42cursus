# ft_printf - Custom Printf Implementation

## 📖 Description

ft_printf is a project where you recreate the printf function from the C standard library. This project teaches you about variadic functions, string formatting, and type conversion while handling multiple format specifiers.

## 🎯 Objectives

- Understand how printf works internally
- Learn about variadic functions and parameter handling
- Master string manipulation and formatting
- Handle different data types and their conversions
- Practice buffer management and output optimization

## 🔧 Supported Format Specifiers

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Character | `ft_printf("%c", 'A')` → A |
| `%s` | String | `ft_printf("%s", "Hello")` → Hello |
| `%p` | Pointer | `ft_printf("%p", ptr)` → 0x7fff5c |
| `%d` | Decimal integer | `ft_printf("%d", 42)` → 42 |
| `%i` | Integer | `ft_printf("%i", -42)` → -42 |
| `%u` | Unsigned integer | `ft_printf("%u", 42U)` → 42 |
| `%x` | Hexadecimal lowercase | `ft_printf("%x", 255)` → ff |
| `%X` | Hexadecimal uppercase | `ft_printf("%X", 255)` → FF |
| `%%` | Literal percent | `ft_printf("%%")` → % |

## 🛠 Implementation Features

### Core Functionality
- **Variadic Arguments**: Uses `va_list`, `va_start`, `va_arg`, `va_end`
- **Type Detection**: Parses format string and identifies specifiers
- **Base Conversion**: Handles decimal, hexadecimal number systems
- **Pointer Formatting**: Converts memory addresses to readable format
- **Return Value**: Returns number of characters printed (like original printf)

### Technical Details
- **Memory Safe**: No buffer overflows or memory leaks
- **Null Handling**: Proper handling of NULL pointers and strings
- **Edge Cases**: Handles negative numbers, zero values, empty strings
- **Efficiency**: Optimized character output with minimal function calls

## 🏗 Project Structure

```
ft_printf/
├── Makefile
├── include/
│   └── ft_printf.h
└── src/
    ├── ft_printf.c          # Main printf function
    ├── ft_printf_utils.c    # Utility functions
    ├── ft_printf_char.c     # Character/string handling
    ├── ft_printf_num.c      # Number conversions
    └── ft_printf_hex.c      # Hexadecimal conversions
```

## 🛠 Compilation

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

## 📋 Usage

```c
#include "ft_printf.h"

int main(void)
{
    char *name = "42 Student";
    int age = 25;
    void *ptr = &age;
    
    ft_printf("Hello, %s!\n", name);
    ft_printf("You are %d years old.\n", age);
    ft_printf("Memory address: %p\n", ptr);
    ft_printf("Hex value: %x, %X\n", 255, 255);
    ft_printf("Progress: 100%% complete!\n");
    
    return (0);
}
```

Compile with your project:
```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lftprintf
```

## 🧮 Function Prototype

```c
int ft_printf(const char *format, ...);
```

**Parameters:**
- `format`: Format string containing text and format specifiers
- `...`: Variable number of arguments corresponding to format specifiers

**Return Value:**
- Number of characters printed
- -1 on error (implementation dependent)

## 📏 Technical Requirements

- **Language**: C
- **Norm**: 42 Coding Standard
- **External Functions**: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
- **Memory**: No memory leaks allowed
- **Error Handling**: Must handle edge cases gracefully

## 🧪 Testing Examples

```c
// Basic tests
ft_printf("Character: %c\n", 'A');                    // Character: A
ft_printf("String: %s\n", "Hello World");             // String: Hello World
ft_printf("Number: %d\n", 42);                        // Number: 42
ft_printf("Negative: %d\n", -42);                     // Negative: -42
ft_printf("Unsigned: %u\n", 4294967295U);             // Unsigned: 4294967295
ft_printf("Hex: %x %X\n", 255, 255);                  // Hex: ff FF
ft_printf("Pointer: %p\n", &main);                    // Pointer: 0x...

// Edge cases
ft_printf("Null string: %s\n", NULL);                 // Null string: (null)
ft_printf("Zero: %d\n", 0);                           // Zero: 0
ft_printf("Empty: %s\n", "");                         // Empty: 
ft_printf("Multiple: %d %c %s\n", 42, 'X', "test");   // Multiple: 42 X test
```

## 💡 Key Learning Points

1. **Variadic Functions**: Understanding how functions accept variable arguments
2. **Type Casting**: Converting between different data types safely
3. **String Building**: Constructing formatted output character by character
4. **Base Conversion**: Converting numbers between decimal and hexadecimal
5. **Memory Management**: Handling dynamic allocation in utility functions
6. **Edge Case Handling**: Dealing with NULL pointers, empty strings, and limits

## 🔗 Dependencies

- **libft**: Uses some utility functions from your custom library
- **Standard Libraries**: `<stdarg.h>` for variadic functions, `<unistd.h>` for write

## 🎯 Bonus Opportunities

While not required, you could extend ft_printf with:
- Field width specifiers (`%10d`)
- Precision specifiers (`%.2f`)
- Left-justify flag (`%-10s`)
- Zero-padding flag (`%05d`)
- Plus sign flag (`%+d`)
- Space flag (`% d`)

---

*This project deepens your understanding of C's type system and prepares you for more complex string manipulation tasks in future projects.*
