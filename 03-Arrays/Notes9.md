# Complete Lecture Notes: Vectors in C++ (Arrays Part 2)



---

## 📌 Section 1: Detailed Chapter Notes & Concepts

### 1. Introduction to C++ STL & Vectors

* **Standard Template Library (STL):** A powerful collection of pre-written C++ template classes and algorithms providing ready-to-use data structures (containers) like `vector`, `stack`, `queue`, `set`, etc.
* **Vector:** A dynamic array container provided by C++ STL (`#include <vector>`).
* **Analogy:** Just like a standard array, it stores elements in contiguous memory blocks with 0-based indexing.
* **Key Advantage:** Unlike standard arrays, vectors are **dynamic in nature**; they resize automatically at runtime when elements are inserted or deleted.



---

### 2. Declaration & Initialization Syntax

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. Empty vector declaration (Size = 0)
vector<int> vec1;

// 2. Initialization with values (Size = 3)
vector<int> vec2 = {1, 2, 3};

// 3. Initialization with size and default value (Size = 5, filled with 0s)
vector<int> vec3(5, 0); 

```

---

### 3. Iterating Over Vectors (For-Each Loop)

A clean, modern C++ syntax to iterate directly over elements (values) instead of indices:

```cpp
vector<char> vec = {'a', 'b', 'c', 'd'};

for (char val : vec) { // 'val' holds the actual element, not the index
    cout << val << " ";
}

```

---

### 4. Important Vector Member Functions

| Function | Syntax | Description | Time Complexity |
| --- | --- | --- | --- |
| **`size()`** | `vec.size()` | Returns current number of elements in the vector. | $\mathcal{O}(1)$ |
| **`capacity()`** | `vec.capacity()` | Returns total storage capacity allocated in RAM. | $\mathcal{O}(1)$ |
| **`push_back(val)`** | `vec.push_back(10)` | Inserts `val` at the end of the vector. | Amortized $\mathcal{O}(1)$ |
| **`pop_back()`** | `vec.pop_back()` | Removes the last element from the vector. | $\mathcal{O}(1)$ |
| **`front()`** | `vec.front()` | Returns the first element (`vec[0]`). | $\mathcal{O}(1)$ |
| **`back()`** | `vec.back()` | Returns the last element (`vec[size - 1]`). | $\mathcal{O}(1)$ |
| **`at(idx)`** | `vec.at(idx)` | Returns element at index `idx` with bounds checking. | $\mathcal{O}(1)$ |

---

### 5. Static vs. Dynamic Memory Allocation

#### A. Static Allocation (Standard Arrays)

* Allocated in **Stack Memory** at compile time.
* Fixed size: Cannot be resized once declared.

#### B. Dynamic Allocation (Vectors)

* Allocated in **Heap Memory** at runtime.
* Resizable: Doubles capacity automatically when filled.

---

### 6. Internal Working of Vector Growth Mechanics

When a vector exceeds its current capacity during `push_back()`:

1. A new internal array with **double the capacity** ($2 \times \text{old capacity}$) is allocated in Heap memory.
2. All existing elements are copied to the new memory block.
3. The new element is appended.
4. The old memory block is deallocated (freed).

> **Key Rule:** **Size** is the number of elements currently stored. **Capacity** is the total allocated memory space (always $\ge$ size).

---

### 7. Problem Analysis: Single Number (LeetCode #136)

#### Problem Statement:

Given a non-empty array/vector of integers where every element appears **twice** except for one unique element, find that unique element in $\mathcal{O}(N)$ time and $\mathcal{O}(1)$ extra space.

#### Optimal Approach: Bitwise XOR (`^`)

* **Properties of XOR:**
1. $X \mathbin{\hat{}} X = 0$ (XORing two identical numbers yields $0$).
2. $X \mathbin{\hat{}} 0 = X$ (XORing any number with $0$ leaves it unchanged).
3. Associative & Commutative: Order of elements does not matter.


* **Algorithm:** XOR all elements together. Paired duplicate numbers cancel out to $0$, leaving only the single unique number.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Vector Memory Structure & Indexing

```text
Vector: vector<int> vec = {10, 20, 30, 40}

Index:         [0]        [1]        [2]        [3]
           +----------+----------+----------+----------+
Value:     |    10    |    20    |    30    |    40    |
           +----------+----------+----------+----------+
Address:      2000       2004       2008       2012
           (Contiguous Heap Allocation, 4 Bytes each)

```

---

### Visual 2: Vector Dynamic Growth Mechanics (Pushing Elements)

```text
Step 1: push_back(10)
        Size = 1, Capacity = 1
        Heap: [ 10 ]

Step 2: push_back(20)  ---> Capacity doubles (1 -> 2)
        Size = 2, Capacity = 2
        Heap: [ 10 ][ 20 ]

Step 3: push_back(30)  ---> Capacity doubles (2 -> 4)
        Size = 3, Capacity = 4
        Heap: [ 10 ][ 20 ][ 30 ][  _  ]
                                  ^ (Unused Allocated Capacity)

```

---

### Visual 3: LeetCode #136 - Bitwise XOR Cancellation

```text
Input Array: [ 4, 1, 2, 1, 2 ]

Step-by-step XOR Evaluation:
  ans = 0
  ans = 0 ^ 4  => 4
  ans = 4 ^ 1  => (4 ^ 1)
  ans = (4 ^ 1) ^ 2 => (4 ^ 1 ^ 2)
  ans = (4 ^ 1 ^ 2) ^ 1 => 4 ^ (1 ^ 1) ^ 2 => 4 ^ 0 ^ 2 => 4 ^ 2
  ans = (4 ^ 2) ^ 2 => 4 ^ (2 ^ 2) => 4 ^ 0 => 4

Final Unique Result = 4

```


