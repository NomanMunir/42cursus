# C++ Module 07 Exercises

This repository contains my solutions to the exercises from Chapter III, IV, and V of the C++ Module 07.

## Exercise 00: Start with a few functions

In this exercise, I implemented three function templates: `swap`, `min`, and `max`. These functions can be called with any type of argument, as long as the two arguments have the same type and support all the comparison operators. The templates are defined in the header files.

To test the functions, I ran the provided code in the `main.cpp` file. The expected output is:

## Exercise 01: Iter
In this exercise, you will implement a function template called `iter`. This function takes three parameters and returns nothing. The parameters are:
- The address of an array.
- The length of the array.
- A function that will be called on every element of the array.

Your task is to write the implementation for the `iter` function template. It should work with any type of array, and the third parameter can be an instantiated function template.

You need to create the following files in the `ex01/` directory:
- `Makefile`
- `main.cpp`
- `iter.h` or `iter.hpp`

In the `main.cpp` file, provide enough code to generate a test executable. Test your `iter` function template with different types of arrays and functions.

Remember to turn in the `Makefile`, `main.cpp`, and `iter.h` or `iter.hpp` files.

## Exercise 02: Array
In this exercise, you will develop a class template called `Array` that contains elements of type `T` and implements the following behavior and functions:
- Construction with no parameter: Creates an empty array.
- Construction with an unsigned int `n` as a parameter: Creates an array of `n` elements initialized by default.
- Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying must not affect the other array.
- You must use the `operator new[]` to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access non-allocated memory.
- Elements can be accessed through the subscript operator: `[]`.
- When accessing an element with the `[]` operator, if its index is out of bounds, an `std::exception` is thrown.
- A member function `size()` that returns the number of elements in the array. This member function takes no parameter and must not modify the current instance.

You should create the following files in the `ex02/` directory:
- `Makefile`
- `main.cpp`
- `Array.h` or `Array.hpp`
- Optional file: `Array.tpp`