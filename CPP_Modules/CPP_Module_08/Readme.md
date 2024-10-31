# CPP_Module_08

This module introduces advanced C++ concepts with a focus on containers and algorithms. The module consists of three exercises, each designed to deepen understanding and proficiency in C++.

## Containers and Algorithms

### Containers
Containers are data structures that store collections of objects. The C++ Standard Library provides several container classes, each optimized for specific types of operations. The most commonly used containers include:

- **Vector**: A dynamic array that can grow in size.
- **Deque**: A double-ended queue that allows fast insertion and deletion at both ends.
- **List**: A doubly-linked list that allows fast insertion and deletion anywhere.
- **Set**: A collection of unique elements, typically implemented as a binary search tree.
- **Map**: A collection of key-value pairs, typically implemented as a binary search tree.
- **Stack**: A container adapter that provides LIFO (last-in, first-out) access.
- **Queue**: A container adapter that provides FIFO (first-in, first-out) access.

### Algorithms
Algorithms are functions provided by the C++ Standard Library that perform operations on containers. They are designed to be efficient and to work with any container that supports the necessary operations. Some common algorithms include:

- **std::find**: Searches for an element in a range.
- **std::sort**: Sorts elements in a range.
- **std::reverse**: Reverses the order of elements in a range.
- **std::copy**: Copies elements from one range to another.
- **std::accumulate**: Sums up elements in a range.

Using these containers and algorithms, you can write efficient and concise C++ code that handles a wide variety of data manipulation tasks.

## Exercise 00: easyfind

### Overview
This exercise implements a template function `easyfind` that searches for the first occurrence of an integer in a given container.

### easyfind.hpp

```cpp
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <class T>
int easyfind(T findFrom, int toFind) {
    typename T::iterator it = std::find(findFrom.begin(), findFrom.end(), toFind);
    if (it == findFrom.end()) {
        std::cout << toFind << " not found!" << std::endl;
        return 1;
    } else {
        std::cout << "First occurrence of " << toFind << " is at index " <<
            std::distance(findFrom.begin(), it) << std::endl;
        return 0;
    }
}

#endif
```

### Usage
To use the `easyfind` function, include the header file in your code and call the function with the appropriate container and value.

```cpp
#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    easyfind(vec, 3);
    easyfind(vec, 6);
    return 0;
}
```

## Exercise 01: Span

### Overview
This exercise creates a class `Span` that can store a specified number of integers and provides functionality to find the shortest and longest span between the numbers.

### span.hpp

```cpp
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <climits>
#include <limits>

class Span {
private:
    unsigned int _n;
    std::vector<int> _v;
    Span();

public:
    Span(const unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    class FullSpanException : public std::exception {
        virtual const char *what() const throw() { return "Span is full"; }
    };

    class RangeSpanException : public std::exception {
        virtual const char *what() const throw() { return "Out of range!"; }
    };

    class NoSpanException : public std::exception {
        virtual const char *what() const throw() { return "No span to find"; }
    };
};

#endif // SPAN_HPP
```

### Implementation

```cpp
#include "Span.hpp"

Span::Span(const unsigned int n) : _n(n) {}
Span::Span(const Span &other) : _n(other._n), _v(other._v) {}
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _n = other._n;
        _v = other._v;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n) {
    if (_v.size() >= _n)
        throw Span::FullSpanException();
    _v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t numToAdd = std::distance(begin, end);
    if (numToAdd > _n - _v.size())
        throw Span::RangeSpanException();
    _v.insert(_v.end(), begin, end);
}

unsigned int Span::shortestSpan() {
    if (_v.size() <= 1)
        throw NoSpanException();
    int min = std::numeric_limits<int>::max();
    std::sort(_v.begin(), _v.end());
    for (size_t i = 0; i < _v.size() - 1; ++i) {
        int span = _v[i + 1] - _v[i];
        if (span < min)
            min = span;
    }
    return min;
}

unsigned int Span::longestSpan() {
    if (_v.size() <= 1)
        throw NoSpanException();
    return *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
}
```

### Usage

```cpp
#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    return 0;
}
```

## Exercise 02: MutantStack

### Overview
This exercise implements a `MutantStack` class that inherits from `std::stack` and provides iterators to iterate through the elements.

### mutantstack.hpp

```cpp
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

template <class T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;

    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& rhs);
    
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::~MutantStack() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack& other) {
    *this = other;
}

template <class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs) {
    if (this != &rhs)
        std::stack<T>::operator=(rhs);
    return *this;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }

#endif // MUTANTSTACK_HPP
```

### Usage

```cpp
#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    return 0;
}
```
