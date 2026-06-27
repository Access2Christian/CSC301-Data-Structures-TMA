
# CSC 301 - Data Structures: Tutor-Marked Assessment

**Student:** Christian Nnaji  
**Matric No:** 2024/B/SENG/0246  
**Student ID:** 30037606  
**Institution:** Miva Open University  

---

## Project Overview

This repository contains my solutions for the CSC 301 Data Structures TMA. The project is a practical implementation of two core computer science concepts:
1. **Dynamic Data Structures** (Custom Singly Linked List)
2. **Algorithmic Logic** (Recursive Problem Solving)

---

## Question 1: Singly Linked List Implementation

**File:** `Question1_LinkedList.cpp`

I implemented a custom Singly Linked List that manages memory dynamically on the heap. This program demonstrates full CRUD (Create, Read, Update, Delete) capabilities with a focus on manual memory management.

### Features & Operations:
- **Insertion Logic:** Add nodes at the beginning, end, and middle (specific positions).
- **Deletion Logic:** Remove nodes by value OR by position.
- **Error Handling:** Robust checks for empty lists, out-of-range positions, and non-existent values.
- **Memory Management:** Uses `new` and `delete` operators with a dedicated destructor to prevent memory leaks.

### How to Compile & Run:
```bash
g++ -o linkedlist Question1_LinkedList.cpp
./linkedlist
```

---

## Question 2: Solving Problems Using Recursion

**File:** `Question2_Recursion.cpp`

This section explores recursive logic across four different mathematical and search problems. Each function is designed with a clear base case to ensure stack safety.

### Algorithms Included:
- **Factorial calculation:** Computes $n!$ recursively.
- **Fibonacci sequence:** Generates the $n^{th}$ number in the sequence.
- **String reversal:** Reverses strings character-by-character.
- **Binary search:** An efficient $O(\log n)$ search on a sorted array.

### How to Compile & Run:
```bash
g++ -o recursion Question2_Recursion.cpp
./recursion
```

---

## Written Documentation

The following summaries are included in the submission files:
- **Memory Management Explanation:** A 147-word analysis of how pointers and the heap work together in linked lists.
- **Recursion vs. Iteration Summary:** A 178-word comparison focusing on memory efficiency and code readability.

---

## Environment Details
- **Language:** C++ (C++11 Standard)
- **Compiler:** g++ (GCC)
- **IDE:** Visual Studio Code
- **Testing:** Verified via OnlineGDB and local MinGW environment.

---

### Academic Integrity
This project is submitted as part of the academic requirements for the CSC 301 course at Miva Open University. All implementations and written explanations represent my original work.
