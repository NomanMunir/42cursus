# Contributing to Webserv

Thank you for your interest in contributing to the Webserv project! This document provides guidelines and information for contributors.

## 🎯 Project Overview

Webserv is an educational HTTP/1.1 web server implementation developed as part of the 42 School curriculum. The project focuses on:

- Deep understanding of HTTP/1.1 protocol
- Non-blocking I/O and event-driven programming
- Systems programming in C++98
- Network security and performance optimization

**Team Members:**
- **Noman Munir** - [NomanMunir](https://github.com/NomanMunir)
- **Alaa Bashir** - [alaabashir123](https://github.com/alaabashir123)
- **Abdullah Salem** - [absalem42](https://github.com/absalem42)

## 📋 Code of Conduct

This project follows the 42 School's academic integrity policies. Please ensure:

- Original work and understanding
- Proper attribution of any referenced materials
- Respect for educational purposes
- Collaborative learning while maintaining individual responsibility

## 🛠️ Development Setup

### Prerequisites

- C++98 compatible compiler (g++, clang++)
- Make build system
- POSIX-compliant operating system (Linux, macOS, *BSD)
- Git for version control

### Environment Setup

```bash
# Clone the repository
git clone https://github.com/NomanMunir/42cursus.git
cd 42cursus/Webserv

# Build the project
make

# Run tests
make test

# Start development server (uses config/config.conf by default)
./bin/webserv

# Start with custom configuration
./bin/webserv path/to/custom.conf
```

## 🎨 Coding Standards

### C++98 Compliance

- **Standard**: Strict C++98 compliance
- **Features**: No C++11 or later features
- **STL**: Use standard library containers and algorithms appropriately
- **Memory**: RAII principles, no raw pointers where avoidable

### Style Guidelines

#### Naming Conventions

```cpp
// Classes: PascalCase
class HttpServer {};
class RequestParser {};

// Functions: camelCase
void parseRequest();
std::string formatResponse();

// Variables: camelCase
int clientSocket;
std::string httpMethod;

// Constants: UPPER_SNAKE_CASE
const int MAX_CONNECTIONS = 1000;
const std::string HTTP_VERSION = "HTTP/1.1";

// Private members: underscore suffix
class Server {
private:
    int socket_;
    std::string config_;
};
```

#### File Organization

```cpp
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by login            #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by login           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

// Implementation
```

#### Code Structure

```cpp
// Class definition example
class HttpRequest {
public:
    // Constructors
    HttpRequest();
    HttpRequest(const std::string& rawRequest);
    HttpRequest(const HttpRequest& other);
    
    // Destructor
    ~HttpRequest();
    
    // Assignment operator
    HttpRequest& operator=(const HttpRequest& other);
    
    // Public methods
    bool parse(const std::string& rawRequest);
    std::string getMethod() const;
    std::string getPath() const;
    
private:
    // Private methods
    void parseRequestLine(const std::string& line);
    void parseHeaders(const std::vector<std::string>& lines);
    
    // Private members
    std::string method_;
    std::string path_;
    std::map<std::string, std::string> headers_;
};
```

### Error Handling

```cpp
// Use exceptions appropriately
class HttpException : public std::exception {
public:
    HttpException(const std::string& message) : message_(message) {}
    virtual const char* what() const throw() { return message_.c_str(); }
private:
    std::string message_;
};

// Check system calls
int result = socket(AF_INET, SOCK_STREAM, 0);
if (result == -1) {
    throw HttpException("Failed to create socket");
}
```

## 📝 Documentation Standards

### Header Comments

```cpp
/**
 * @brief Parses an HTTP request from raw string data
 * 
 * This function takes a raw HTTP request string and parses it into
 * its constituent parts (method, path, headers, body).
 * 
 * @param rawRequest The raw HTTP request string
 * @return true if parsing succeeded, false otherwise
 * @throws HttpException if the request format is invalid
 */
bool parseRequest(const std::string& rawRequest);
```

### Inline Comments

```cpp
// Parse the request line (method, path, version)
size_t firstLine = rawRequest.find("\r\n");
if (firstLine == std::string::npos) {
    throw HttpException("Invalid request format");
}

// Extract method, path, and version
std::istringstream requestLine(rawRequest.substr(0, firstLine));
requestLine >> method_ >> path_ >> version_;
```

## 🧪 Testing Guidelines

### Test Structure

```bash
tests/
├── run_tests.sh    # Main test execution script
└── stress_test.sh  # Performance and stress tests
```

**Note:** The project uses script-based testing rather than unit test frameworks to maintain C++98 compatibility.

### Writing Tests

```bash
# Test naming convention
test_<component>_<functionality>.sh

# Example test structure
#!/bin/bash
test_http_get_request() {
    # Setup
    start_test_server
    
    # Execute
    response=$(curl -s http://localhost:8080/)
    
    # Verify
    if [[ $response == *"200 OK"* ]]; then
        echo "PASS: GET request test"
        return 0
    else
        echo "FAIL: GET request test"
        return 1
    fi
    
    # Cleanup
    stop_test_server
}
```

## 🚀 Contribution Process

### 1. Issue Reporting

Before contributing, check if an issue already exists:

- **Bug Reports**: Include system info, reproduction steps, expected vs actual behavior
- **Feature Requests**: Describe the use case and proposed implementation
- **Documentation**: Note which sections need improvement

### 2. Development Workflow

```bash
# 1. Fork and clone
git clone https://github.com/yourusername/42cursus.git
cd 42cursus/Webserv

# 2. Create feature branch
git checkout -b feature/your-feature-name

# 3. Make changes and commit
git add .
git commit -m "feat: implement HTTP chunked transfer encoding"

# 4. Test your changes
make test
make stress

# 5. Push and create PR
git push origin feature/your-feature-name
```

### 3. Commit Message Format

```
type(scope): description

[optional body]

[optional footer]
```

Types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes
- `refactor`: Code refactoring
- `test`: Test additions or modifications
- `chore`: Build system or auxiliary tool changes

Examples:
```
feat(http): implement chunked transfer encoding
fix(parser): handle malformed request headers correctly
docs(readme): update installation instructions
test(integration): add CGI execution tests
```

### 4. Pull Request Guidelines

- **Title**: Clear, descriptive title
- **Description**: What changes were made and why
- **Testing**: Evidence that changes work correctly
- **Documentation**: Update relevant documentation
- **Code Review**: Address reviewer feedback promptly

## 🔧 Build System

### Makefile Targets

```bash
make                # Build release version
make debug          # Build with debug symbols
make test           # Run test suite
make stress         # Run performance tests
make clean          # Remove object files
make fclean         # Remove all build artifacts
make re             # Rebuild from scratch
make install        # Install to system
make docs           # Generate documentation
```

### Adding New Targets

```makefile
# Example: Adding a new utility target
format:
	@echo "$(CYAN)Formatting code...$(RESET)"
	@find src include -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i

.PHONY: format
```

## 📊 Performance Considerations

### Optimization Guidelines

- **Memory**: Minimize allocations in hot paths
- **I/O**: Use non-blocking I/O consistently
- **Algorithms**: Choose appropriate data structures
- **Profiling**: Use tools like `valgrind`, `gprof`, `perf`

### Benchmarking

```bash
# Memory usage
valgrind --tool=memcheck ./webserv

# Performance profiling
perf record -g ./webserv
perf report

# Load testing
siege -c 100 -t 30s http://localhost:8080/
```

## 🛡️ Security Considerations

### Common Vulnerabilities

- **Buffer Overflows**: Use safe string operations
- **Input Validation**: Sanitize all user input
- **Resource Limits**: Implement proper limits
- **Path Traversal**: Validate file paths
- **HTTP Injection**: Escape output properly

### Security Checklist

- [ ] Input validation on all user data
- [ ] Proper error handling without information leakage
- [ ] Resource limits (connections, memory, file sizes)
- [ ] Safe file operations
- [ ] HTTP header validation

## 📚 Learning Resources

### HTTP Protocol
- [RFC 7230](https://tools.ietf.org/html/rfc7230) - HTTP/1.1 Message Syntax and Routing
- [RFC 7231](https://tools.ietf.org/html/rfc7231) - HTTP/1.1 Semantics and Content
- [MDN HTTP Documentation](https://developer.mozilla.org/en-US/docs/Web/HTTP)

### C++ Programming
- [C++98 Standard](https://www.iso.org/standard/25845.html)
- [CPP Reference](https://en.cppreference.com/w/cpp/98)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

### Systems Programming
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- [The Linux Programming Interface](http://man7.org/tlpi/)
- [Advanced Programming in the UNIX Environment](http://www.apuebook.com/)

## 🤝 Getting Help

- **Documentation**: Check the `/docs` directory
- **Issues**: Search existing issues on GitHub
- **Code Review**: Ask for feedback on complex changes
- **42 Network**: Consult with peers and evaluators

## 📄 License

This project is developed for educational purposes as part of the 42 School curriculum. Please respect academic integrity policies when using this code.

---

Thank you for contributing to Webserv! Your efforts help make this a better learning resource for the 42 community.
