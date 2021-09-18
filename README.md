# Dynamic Array Data Structure

## Definition

Dynamic array data structure is an implementation of the list abstract data type. It consists of a header structure that contains some metadata such as length, capacity, and a pointer to the underlying static array. Unlike a static array, a dynamic array can grow to accomodate new elements.

## Interface

The functions provided to interface with this dynamic array implementation are divided into three categories:

1. Constructor and Destructor
2. Common List Abstract Data Type Functions
3. Functions Unqiue to Dynamic Array

Read the comments in the header file (./includes/DynamicArray.h) to learn more.

## Usage

Clone this git repository, navigate to its root, and run make command.

This will generate two folders:

- bin
- build

bin contains a driver executable that is used for testing.
build contains a .a static library and a .so dynamic library.

