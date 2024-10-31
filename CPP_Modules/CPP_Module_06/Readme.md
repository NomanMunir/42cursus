# Chapter IV: Conversion of Scalar Types

## Exercise 00: Conversion of Scalar Types

In this exercise, you are required to create a class ScalarConverter that contains a static method convert. This method should take a string representation of a C++ literal and output its value in the following scalar types:

- char
- int
- float
- double

The class should not be instantiable by users. The method should handle conversion from string to the actual type and then convert it explicitly to the three other data types. If a conversion is not possible or overflows, it should display an informative message.

# Chapter V: Serialization

## Exercise 01: Serialization

In this exercise, you are required to implement a static class Serializer with the following methods:

- `uintptr_t serialize(Data* ptr);` - This method should take a pointer and convert it to the unsigned integer type `uintptr_t`.
- `Data* deserialize(uintptr_t raw);` - This method should take an unsigned integer parameter and convert it to a pointer to `Data`.

You should also create a non-empty `Data` structure and test the `Serializer` class.

# Chapter VI: Identify Real Type

## Exercise 02: Identify Real Type

In this exercise, you are required to implement a `Base` class with a public virtual destructor only. Then, create three empty classes `A`, `B`, and `C` that publicly inherit from `Base`.

You should also implement the following functions:

- `Base* generate(void);` - This function should randomly instantiate `A`, `B`, or `C` and return the instance as a `Base` pointer.
- `void identify(Base* p);` - This function should print the actual type of the object pointed to by `p`.
- `void identify(Base& p);` - This function should print the actual type of the object pointed to by `p`. Using a pointer inside this function is forbidden.

Including the `typeinfo` header is forbidden. You should write a program to test that everything works as expected.