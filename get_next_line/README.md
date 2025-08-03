# get_next_line - File Reading Function

## 📖 Description

get_next_line is a function that reads a text file line by line, regardless of the size of the text or the size of one of its lines. This project teaches you about file descriptors, static variables, and memory management in a practical context.

## 🎯 Objectives

- Understand file descriptors and file I/O operations
- Learn about static variables and their persistence
- Master dynamic memory allocation and management
- Handle different buffer sizes efficiently
- Practice reading files without knowing their size in advance

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

**Parameters:**
- `fd`: File descriptor to read from

**Return Value:**
- A line read from the file descriptor (including the `\n` if present)
- `NULL` when there's nothing more to read or an error occurs

## 🏗 Project Structure

```
get_next_line/
├── get_next_line.c           # Main function implementation
├── get_next_line.h           # Header file with prototypes
├── get_next_line_utils.c     # Utility functions
├── get_next_line_bonus.c     # Bonus: multiple file descriptors
├── get_next_line_bonus.h     # Bonus header file
└── get_next_line_utils_bonus.c # Bonus utility functions
```

## ⚙️ Configuration

The function behavior can be configured with the `BUFFER_SIZE` macro:

```bash
# Compile with different buffer sizes
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c
```

## 🛠 Implementation Features

### Core Functionality
- **Static Variables**: Preserves buffer content between function calls
- **Dynamic Buffer**: Adapts to any buffer size specified at compile time
- **Line Detection**: Correctly identifies line endings (`\n`)
- **Memory Management**: Efficient allocation and deallocation
- **Error Handling**: Robust handling of read errors and invalid file descriptors

### Technical Details
- **File Reading**: Uses `read()` system call with specified buffer size
- **String Manipulation**: Builds lines character by character when needed
- **Memory Efficiency**: Minimizes unnecessary allocations
- **Edge Cases**: Handles files without final newline, empty files, large lines

## 📋 Usage Examples

### Basic Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Don't forget to free!
    }
    
    close(fd);
    return (0);
}
```

### Reading from Standard Input

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    
    printf("Enter lines (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)  // 0 = stdin
    {
        printf("You entered: %s", line);
        free(line);
    }
    
    return (0);
}
```

### Multiple Files (Bonus)

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line1, *line2;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    
    // Read alternately from both files
    while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
    {
        if (line1)
        {
            printf("File1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("File2: %s", line2);
            free(line2);
        }
    }
    
    close(fd1);
    close(fd2);
    return (0);
}
```

## 🧪 Testing Scenarios

### Test Files to Create

```bash
# Empty file
touch empty.txt

# Single line without newline
echo -n "Single line without newline" > no_newline.txt

# Single line with newline
echo "Single line with newline" > with_newline.txt

# Multiple lines
printf "Line 1\nLine 2\nLine 3\n" > multiple_lines.txt

# Very long line
python3 -c "print('x' * 10000)" > long_line.txt

# Mixed content
printf "Short\nVery long line that exceeds typical buffer sizes and should be handled correctly\nShort again\n" > mixed.txt
```

### Compilation Tests

```bash
# Test different buffer sizes
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 -o test1 main.c get_next_line.c get_next_line_utils.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -o test42 main.c get_next_line.c get_next_line_utils.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 -o test9999 main.c get_next_line.c get_next_line_utils.c
```

## 📏 Technical Requirements

- **Language**: C
- **Norm**: 42 Coding Standard
- **External Functions**: `read`, `malloc`, `free`
- **Memory**: No memory leaks allowed
- **Static Variables**: Only one static variable per function allowed
- **Buffer Size**: Must work with any buffer size (1, 42, 9999, etc.)

## 🎁 Bonus Features

The bonus part includes:
- **Multiple File Descriptors**: Handle multiple files simultaneously
- **Persistent State**: Maintain separate buffers for each file descriptor
- **Efficient Management**: Use data structures to track multiple file states

```c
// Bonus allows this usage:
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);
int fd3 = open("file3.txt", O_RDONLY);

char *line1 = get_next_line(fd1);  // Read from file1
char *line2 = get_next_line(fd2);  // Read from file2
char *line3 = get_next_line(fd1);  // Continue reading from file1
```

## 💡 Key Learning Points

1. **Static Variables**: Understanding variable lifetime and scope
2. **File I/O**: Working with file descriptors and the `read()` system call
3. **Memory Management**: Dynamic allocation for unknown-sized content
4. **Buffer Management**: Efficient handling of partial reads
5. **String Manipulation**: Building strings incrementally
6. **Error Handling**: Robust error detection and recovery

## 🔗 Applications

This function is useful for:
- Reading configuration files
- Processing log files
- Parsing input files line by line
- Building other file processing utilities
- Creating text-based games or applications

## ⚠️ Important Notes

- Always free the returned string after use
- Function returns `NULL` when reaching EOF or on error
- The returned line includes the `\n` character if present
- Works with any valid file descriptor (files, stdin, pipes, etc.)
- Must handle files larger than available memory

---

*This project is essential for understanding file I/O and will be invaluable in future projects that require file parsing and processing.*
