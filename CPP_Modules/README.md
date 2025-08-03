# CPP Modules - C++ Object-Oriented Programming

## 📖 Description

The CPP Modules (00-09) are a comprehensive introduction to C++ programming and object-oriented programming concepts. Each module builds upon the previous one, progressing from basic C++ syntax to advanced topics like templates, STL, and design patterns.

## 🎯 Overall Objectives

- Transition from C to C++ programming
- Master object-oriented programming principles
- Understand C++ specific features and syntax
- Learn advanced programming concepts and patterns
- Practice modern C++ development techniques

## 📚 Module Breakdown

### **CPP Module 00** - Basics
**Topics**: Namespaces, classes, member functions, stdio streams, initialization lists, static, const

**Key Concepts**:
- C++ syntax and compilation
- Classes and objects
- Public/private access specifiers
- Constructor and destructor
- Member functions vs member variables
- Const correctness
- Static members

**Projects**:
- **Megaphone**: String manipulation and basic I/O
- **PhoneBook**: Contact management system with classes
- **Account**: Bank account simulation with static members

### **CPP Module 01** - Memory and References
**Topics**: Memory allocation, pointers to members, references, switch statement

**Key Concepts**:
- `new` and `delete` operators
- References vs pointers
- Pointers to member functions
- File I/O streams
- String manipulation

**Projects**:
- **Zombie**: Dynamic memory allocation
- **Zombie Horde**: Array allocation and initialization
- **Sed**: File manipulation and string replacement
- **Harl**: Switch statements and function pointers

### **CPP Module 02** - Polymorphism and Operators
**Topics**: Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form

**Key Concepts**:
- Operator overloading
- Copy constructor
- Assignment operator
- Orthodox Canonical Form
- Fixed-point arithmetic

**Projects**:
- **Fixed**: Fixed-point number class with operators
- **Towards a more useful fixed-point number class**: Enhanced operators

### **CPP Module 03** - Inheritance
**Topics**: Inheritance basics, access levels, virtual functions

**Key Concepts**:
- Base and derived classes
- Protected access specifier
- Virtual functions introduction
- Constructor/destructor order in inheritance

**Projects**:
- **ClapTrap**: Basic character class
- **ScavTrap**: Inheritance example
- **FragTrap**: Multiple inheritance concepts
- **DiamondTrap**: Diamond problem and virtual inheritance

### **CPP Module 04** - Subtype Polymorphism
**Topics**: Subtype polymorphism, abstract classes, interfaces

**Key Concepts**:
- Pure virtual functions
- Abstract base classes
- Polymorphism through inheritance
- Virtual destructors
- Deep vs shallow copy

**Projects**:
- **Animal**: Polymorphism basics
- **Brain**: Deep copy implementation
- **Abstract Animal**: Pure virtual functions
- **Interface & recap**: Interface design patterns

### **CPP Module 05** - Exceptions
**Topics**: Repetition and exceptions

**Key Concepts**:
- Exception handling (try, catch, throw)
- Standard exceptions
- Custom exception classes
- Exception safety
- RAII principle

**Projects**:
- **Bureaucrat**: Exception handling basics
- **Form**: Exception hierarchies
- **Concrete Forms**: Practical exception usage
- **Intern**: Exception propagation

### **CPP Module 06** - C++ Casts
**Topics**: C++ cast operators

**Key Concepts**:
- `static_cast<>`
- `dynamic_cast<>`
- `const_cast<>`
- `reinterpret_cast<>`
- Type identification

**Projects**:
- **Scalar Conversion**: Type conversion and casting
- **Serialization**: Object serialization
- **Real Type**: Dynamic type identification

### **CPP Module 07** - Templates
**Topics**: C++ templates

**Key Concepts**:
- Function templates
- Class templates
- Template specialization
- Template parameters
- Generic programming

**Projects**:
- **Function Templates**: Generic functions
- **Iter**: Template iteration
- **Array**: Template class implementation

### **CPP Module 08** - Containers and Iterators
**Topics**: Templated containers, iterators, algorithms

**Key Concepts**:
- STL containers overview
- Iterator types and usage
- Algorithm library
- Custom container implementation

**Projects**:
- **Easy find**: Container algorithms
- **Span**: Custom container with iterators
- **Mutated abomination**: Advanced container operations

### **CPP Module 09** - STL Containers
**Topics**: STL containers in depth

**Key Concepts**:
- std::vector, std::stack, std::map
- Container adaptors
- Performance characteristics
- Real-world applications

**Projects**:
- **Bitcoin Exchange**: File parsing with containers
- **Reverse Polish Notation**: Stack implementation
- **PmergeMe**: Advanced sorting algorithms

## 🛠 Common Project Structure

Each CPP module typically follows this structure:
```
CPP_Module_XX/
├── ex00/                   # Exercise 0
│   ├── Makefile
│   ├── main.cpp
│   ├── ClassName.hpp
│   └── ClassName.cpp
├── ex01/                   # Exercise 1
├── ex02/                   # Exercise 2
└── ex03/                   # Exercise 3 (if applicable)
```

## 📏 Technical Requirements

### General Requirements
- **Language**: C++98 standard
- **Compiler**: c++ with flags `-Wall -Wextra -Werror`
- **Norm**: 42 C++ coding standard
- **Memory**: No memory leaks allowed
- **Forbidden**: Most C standard library functions

### C++98 Compliance
The projects must compile with C++98 standard, meaning:
- No C++11 features (auto, nullptr, lambda, etc.)
- Use of classical STL containers
- Traditional function syntax
- Manual memory management

## 🔧 Compilation

Standard Makefile for each exercise:
```makefile
NAME = program_name
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClassName.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

## 🧪 Testing Approach

### Unit Testing
Each exercise should be tested with:
- Valid input cases
- Edge cases and boundary conditions
- Error conditions and exception handling
- Memory leak detection (valgrind)

### Example Test Structure
```cpp
int main(void)
{
    // Test basic functionality
    {
        ClassName obj("test");
        std::cout << "Basic test: " << obj.getValue() << std::endl;
    }
    
    // Test copy constructor
    {
        ClassName obj1("original");
        ClassName obj2(obj1);
        std::cout << "Copy test: " << obj2.getValue() << std::endl;
    }
    
    // Test assignment operator
    {
        ClassName obj1("first");
        ClassName obj2("second");
        obj2 = obj1;
        std::cout << "Assignment test: " << obj2.getValue() << std::endl;
    }
    
    return 0;
}
```

## 💡 Key Learning Outcomes

### Programming Concepts
1. **Object-Oriented Design**: Encapsulation, inheritance, polymorphism
2. **Memory Management**: RAII, smart pointer concepts
3. **Exception Safety**: Robust error handling
4. **Generic Programming**: Templates and type abstraction
5. **STL Proficiency**: Container and algorithm usage

### C++ Specific Skills
1. **Language Features**: Understanding C++ syntax and semantics
2. **Best Practices**: Writing maintainable and efficient C++ code
3. **Design Patterns**: Common OOP patterns and their implementation
4. **Performance**: Understanding performance implications of C++ features

## 🔗 Real-World Applications

The concepts learned in CPP modules apply to:
- **Game Development**: Object-oriented game engines
- **System Programming**: Operating systems and drivers
- **Financial Software**: High-performance trading systems
- **Embedded Systems**: Resource-constrained programming
- **Graphics Programming**: 3D engines and rendering
- **Scientific Computing**: Numerical simulations

## 📚 Recommended Reading

### Books
- "The C++ Programming Language" by Bjarne Stroustrup
- "Effective C++" by Scott Meyers
- "C++ Primer" by Stanley Lippman
- "Design Patterns" by Gang of Four

### Online Resources
- cppreference.com
- learncpp.com
- C++ Core Guidelines
- 42 subject PDFs for each module

---

*The CPP modules provide a solid foundation in C++ programming and prepare you for advanced software development in modern C++ environments.*
