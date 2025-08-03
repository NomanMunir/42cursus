# 42cursus - 42 Abu Dhabi

Welcome to my 42 Abu Dhabi curriculum journey! This repository contains all the projects I've completed as part of the 42 school program. Each project builds upon previous knowledge and introduces new concepts in systems programming, algorithms, and software engineering.

## 🎯 About 42

42 is a tuition-free computer programming school that uses peer-to-peer learning and project-based methodology. The curriculum is designed to develop strong programming fundamentals and problem-solving skills through hands-on projects.

## 📚 Curriculum Overview

### Core Projects (C Programming)

#### **libft** - Custom C Library
- **Description**: Implementation of standard C library functions from scratch
- **Skills**: Memory management, string manipulation, linked lists
- **Key Functions**: `ft_strlen`, `ft_strcpy`, `ft_atoi`, `ft_split`, and many more
- **Status**: ✅ Completed

#### **ft_printf** - Custom Printf Implementation
- **Description**: Recreation of the printf function with support for various format specifiers
- **Skills**: Variadic functions, string formatting, type conversion
- **Format Specifiers**: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- **Status**: ✅ Completed

#### **get_next_line** - File Reading Function
- **Description**: Function that reads a file line by line, including bonus version for multiple file descriptors
- **Skills**: File I/O, static variables, memory management
- **Bonus**: Support for multiple file descriptors simultaneously
- **Status**: ✅ Completed

#### **Push_swap** - Sorting Algorithm
- **Description**: Sorting data on a stack with a limited set of instructions, using the lowest number of operations
- **Skills**: Algorithm optimization, stack operations, complexity analysis
- **Operations**: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- **Bonus**: Checker program to validate sorting operations
- **Status**: ✅ Completed

#### **pipex** - UNIX Pipes Implementation
- **Description**: Recreation of shell pipe behavior (`< file1 cmd1 | cmd2 > file2`)
- **Skills**: Process management, pipes, file descriptors, UNIX system calls
- **System Calls**: `fork`, `pipe`, `execve`, `dup2`, `wait`
- **Bonus**: Support for multiple pipes
- **Status**: ✅ Completed

#### **so_long** - 2D Game
- **Description**: Simple 2D game using MiniLibX graphics library
- **Skills**: Graphics programming, event handling, game logic
- **Features**: Player movement, collectibles, exit conditions, sprite rendering
- **Controls**: WASD/Arrow keys for movement, ESC to exit
- **Status**: ✅ Completed

#### **philosophers** - Threading and Synchronization
- **Description**: Solution to the classic dining philosophers problem
- **Skills**: Multithreading, mutexes, deadlock prevention, race conditions
- **Versions**: 
  - **philo**: Using threads and mutexes
  - **philo_bonus**: Using processes and semaphores
- **Status**: ✅ Completed

#### **cub3D** - 3D Raycasting Engine
- **Description**: 3D graphical representation using raycasting (inspired by Wolfenstein 3D)
- **Skills**: Raycasting, 3D graphics, mathematical projections, parsing
- **Features**: 
  - Wall texture mapping
  - Player movement and rotation
  - Map parsing from .cub files
  - Floor and ceiling color customization
- **Controls**: WASD for movement, arrow keys for rotation
- **Status**: ✅ Completed

### Advanced Projects

#### **minishell** - Custom Shell Implementation
- **Description**: Recreation of bash shell with command parsing, execution, and built-in functions
- **Skills**: Process management, signal handling, environment variables, command parsing
- **Features**: 
  - Command execution with absolute/relative paths
  - Built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
  - Pipes and redirections (`|`, `<`, `>`, `>>`)
  - Environment variable expansion (`$USER`, `$?`)
  - Signal handling (Ctrl+C, Ctrl+D, Ctrl+\\)
  - Quote handling (single and double quotes)
- **Status**: ✅ Completed

#### **NetPractice** - Network Configuration
- **Description**: Network administration and TCP/IP configuration exercises
- **Skills**: Subnetting, IP addressing, routing, network troubleshooting
- **Levels**: 10 configuration levels with increasing complexity
- **Topics**: CIDR notation, subnet masks, default gateways, routing tables
- **Status**: ✅ Completed

#### **Webserv** - HTTP Web Server
- **Description**: HTTP/1.1 compliant web server implementation from scratch
- **Skills**: Network programming, HTTP protocol, I/O multiplexing, CGI
- **Features**:
  - HTTP/1.1 protocol support
  - GET, POST, DELETE methods
  - Static file serving
  - CGI script execution
  - Virtual hosts support
  - Configuration file parsing
  - Non-blocking I/O with poll/epoll
- **Status**: ✅ Completed

#### **ft_transcendence** - Full-Stack Web Application
- **Description**: Complete web-based Pong game platform with microservices architecture
- **Skills**: Full-stack development, microservices, containerization, real-time gaming
- **Architecture**:
  - **Backend**: Django REST API for user management
  - **Tournament Service**: Django REST API for tournament handling
  - **Frontend**: Vanilla JavaScript SPA with Bootstrap
  - **Database**: PostgreSQL with Docker containers
  - **Infrastructure**: Docker Compose orchestration
- **Features**:
  - Single-player vs AI with intelligent behavior
  - 8-player knockout tournaments with bracket visualization
  - Multiplayer support (3-4 players simultaneously)
  - Multi-language support (English, German, Arabic)
  - Responsive design for all devices
  - Real-time gameplay with 60 FPS canvas rendering
  - User authentication and game statistics
  - RESTful APIs for service communication
- **Live Demo**: [🕹️ Play Now](https://nomanmunir.github.io/ft_transcendence_frontend/)
- **Status**: ✅ Completed

### C++ Projects (Object-Oriented Programming)

#### **CPP Modules 00-09** - C++ Fundamentals to Advanced
- **Module 00**: Namespaces, classes, member functions, stdio streams, initialization lists, static, const
- **Module 01**: Memory allocation, pointers to members, references, switch statement
- **Module 02**: Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form
- **Module 03**: Inheritance
- **Module 04**: Subtype polymorphism, abstract classes, interfaces
- **Module 05**: Repetition and exceptions
- **Module 06**: C++ casts
- **Module 07**: C++ templates
- **Module 08**: Templated containers, iterators, algorithms
- **Module 09**: STL containers

**Skills Developed**: Object-oriented programming, inheritance, polymorphism, templates, STL, exception handling
**Status**: ✅ Completed

## 🛠 Technologies & Tools Used

- **Languages**: C, C++, JavaScript, Python
- **Frameworks**: Django, Django REST Framework, Bootstrap
- **Graphics**: MiniLibX, HTML5 Canvas
- **Web Technologies**: HTML5, CSS3, NGINX, HTTP/1.1
- **Databases**: PostgreSQL
- **DevOps**: Docker, Docker Compose
- **Build System**: Makefiles, npm
- **Version Control**: Git
- **Debugging**: GDB, Valgrind
- **Standards**: C89/C90, C++98

## 🏆 Skills Developed

### Technical Skills
- **Low-level Programming**: Memory management, pointers, system calls
- **Algorithm Design**: Sorting algorithms, optimization techniques
- **Systems Programming**: Process management, threading, IPC
- **Graphics Programming**: 2D/3D rendering, event handling
- **Network Programming**: TCP/IP, routing, HTTP protocol implementation
- **Web Development**: Full-stack development, REST APIs, microservices
- **Object-Oriented Programming**: Classes, inheritance, polymorphism
- **DevOps**: Containerization, service orchestration, CI/CD principles
- **Database Management**: PostgreSQL, database design, migrations

### Soft Skills
- **Problem Solving**: Breaking down complex problems into manageable parts
- **Peer Learning**: Collaborative debugging and code review
- **Project Management**: Time management and milestone planning
- **Documentation**: Writing clear and comprehensive documentation

## 📋 Project Status

| Project | Language/Tech | Status | Difficulty |
|---------|---------------|--------|------------|
| libft | C | ✅ | ⭐⭐ |
| ft_printf | C | ✅ | ⭐⭐ |
| get_next_line | C | ✅ | ⭐⭐ |
| Push_swap | C | ✅ | ⭐⭐⭐ |
| pipex | C | ✅ | ⭐⭐⭐ |
| so_long | C | ✅ | ⭐⭐⭐ |
| minishell | C | ✅ | ⭐⭐⭐⭐⭐⭐ |
| philosophers | C | ✅ | ⭐⭐⭐⭐ |
| cub3D | C | ✅ | ⭐⭐⭐⭐ |
| NetPractice | Config | ✅ | ⭐⭐⭐ |
| Webserv | C++ | ✅ | ⭐⭐⭐⭐⭐ |
| CPP Modules 00-09 | C++ | ✅ | ⭐⭐⭐⭐ |
| ft_transcendence | Full-Stack | ✅ | ⭐⭐⭐⭐⭐ |

## 🚀 Getting Started

Each project directory contains:
- Source code files
- Makefile for compilation
- Project-specific README or documentation
- Test files (where applicable)

To compile and run any project:
```bash
cd project_directory
make
./executable_name [arguments]
```

## 📖 Learning Path

The projects are designed to be completed in a specific order, with each building upon concepts from previous projects:

1. **Foundation**: libft → ft_printf → get_next_line
2. **Algorithms**: Push_swap
3. **System Programming**: pipex → minishell → philosophers
4. **Graphics**: so_long → cub3D
5. **Networking**: NetPractice → Webserv
6. **Object-Oriented Programming**: CPP Modules 00-09
7. **Full-Stack Development**: ft_transcendence (Final Project)

## 🤝 42 Abu Dhabi Community

This work is part of the 42 Abu Dhabi curriculum. The school promotes:
- Peer-to-peer learning
- Project-based education
- No teachers, no courses
- Gamified learning experience

## 📞 Contact

- **School**: 42 Abu Dhabi
- **GitHub**: [NomanMunir](https://github.com/NomanMunir)
- **Repository**: [42cursus](https://github.com/NomanMunir/42cursus)

---

*"The best way to learn is by doing, and 42 provides the perfect environment for hands-on learning."*
