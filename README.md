# Customized Data Structure Library

## Overview

This project is a customized data structure library implemented in C++ using templates for generic programming. The library provides implementations for various linear and circular linked lists, stacks, and queues. The primary goal of this library is to offer a versatile and reusable set of data structures that can be used with any data type.

## Data Structures Implemented

1. **Singly Linked List (SinglyLL)**
2. **Doubly Circular Linked List (DoublyCL)**
3. **Doubly Linked List (DoublyLL)**
4. **Singly Circular Linked List (SinglyCL)**
5. **Stack (Stack)**
6. **Queue (Queue)**

## 1. Singly Linked List (SinglyLL)

A singly linked list is a linear data structure where each element points to the next element, forming a sequence. This implementation includes the following functionalities:

### Methods

- **SinglyLL()**: Constructor to initialize the list.
- **void Display()**: Display all elements in the list.
- **int Count()**: Return the number of elements in the list.
- **void InsertFirst(T No)**: Insert an element at the beginning.
- **void InsertLast(T No)**: Insert an element at the end.
- **void InsertatPos(T No, int Pos)**: Insert an element at a specific position.
- **void DeleteFirst()**: Delete the first element.
- **void DeleteLast()**: Delete the last element.
- **void DeleteatPos(int iPos)**: Delete an element at a specific position.

## 2. Doubly Circular Linked List (DoublyCL)

A doubly circular linked list is a circular linked list where each node has two pointers, pointing to the next and the previous node. This implementation includes the following functionalities:

### Methods

- **DoublyCL()**: Constructor to initialize the list.
- **void Display()**: Display all elements in the list.
- **int Count()**: Return the number of elements in the list.
- **void InsertFirst(T No)**: Insert an element at the beginning.
- **void InsertLast(T No)**: Insert an element at the end.
- **void InsertAtPos(T No, int iPos)**: Insert an element at a specific position.
- **void DeleteFirst()**: Delete the first element.
- **void DeleteLast()**: Delete the last element.
- **void DeleteAtPos(int iPos)**: Delete an element at a specific position.

## 3. Doubly Linked List (DoublyLL)

A doubly linked list is a linear data structure where each element points to both the next and the previous elements. This implementation includes the following functionalities:

### Methods

- **DoublyLL()**: Constructor to initialize the list.
- **void InsertFirst(T iNo)**: Insert an element at the beginning.
- **void InsertLast(T iNo)**: Insert an element at the end.
- **void InsertAtPos(T iNo, int iPos)**: Insert an element at a specific position.
- **void DeleteFirst()**: Delete the first element.
- **void DeleteLast()**: Delete the last element.
- **void DeleteAtPos(int iPos)**: Delete an element at a specific position.
- **void Display()**: Display all elements in the list.
- **int Count()**: Return the number of elements in the list.

## 4. Singly Circular Linked List (SinglyCL)

A singly circular linked list is a circular linked list where each node points to the next node and the last node points back to the first node. This implementation includes the following functionalities:

### Methods

- **SinglyCL()**: Constructor to initialize the list.
- **void InsertFirst(T iNo)**: Insert an element at the beginning.
- **void InsertLast(T iNo)**: Insert an element at the end.
- **void InsertAtPos(T iNo, int iPos)**: Insert an element at a specific position.
- **void DeleteFirst()**: Delete the first element.
- **void DeleteLast()**: Delete the last element.
- **void DeleteAtPos(int iPos)**: Delete an element at a specific position.
- **void Display()**: Display all elements in the list.
- **int Count()**: Return the number of elements in the list.

## 5. Stack (Stack)

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. This implementation includes the following functionalities:

### Methods

- **Stack()**: Constructor to initialize the stack.
- **void Push(T iNo)**: Insert an element on top of the stack.
- **T Pop()**: Remove and return the top element of the stack.
- **void Display()**: Display all elements in the stack.
- **int Count()**: Return the number of elements in the stack.

## 6. Queue (Queue)

A queue is a linear data structure that follows the First In First Out (FIFO) principle. This implementation includes the following functionalities:

### Methods

- **Queue()**: Constructor to initialize the queue.
- **void Enqueue(T iNo)**: Insert an element at the end of the queue.
- **T Dequeue()**: Remove and return the front element of the queue.
- **void Display()**: Display all elements in the queue.
- **int Count()**: Return the number of elements in the queue.

## Usage

To use this library, include the appropriate header files and instantiate the desired data structure with the required data type. Here is an example of how to use the Singly Linked List:

```cpp
#include "SinglyLL.h" // Include the necessary header file

int main()
{
    SinglyLL<int> list;

    list.InsertFirst(10);
    list.InsertLast(20);
    list.InsertatPos(15, 2);

    list.Display(); // Output: 10->15->20->NULL

    list.DeleteFirst();
    list.Display(); // Output: 15->20->NULL

    return 0;
}
```

## Conclusion

This customized data structure library provides a flexible and efficient way to manage data using various linked lists, stacks, and queues. The use of templates allows for type-independent implementation, making the library reusable for different data types.
