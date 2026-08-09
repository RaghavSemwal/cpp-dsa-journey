# Complete Lecture Notes: Array Data Structure (Part 1) in C++



---

## 📌 Section 1: Detailed Chapter Notes & Concepts

### 1. Introduction to Data Structures & Algorithms (DSA)

* **Data Structures (DS):** Organized structures used to store, manage, and retrieve data efficiently. Data is the "fuel" for real-world software applications (e.g., storing user profiles, transaction logs).
* **Algorithms (Algo):** Step-by-step processes or set of rules to perform operations on data structures (e.g., searching, sorting, insertion, deletion).

---

### 2. What is an Array?

An **Array** is a linear data structure used to store a fixed-size, sequential collection of elements of the **same data type** in **contiguous memory locations**.

#### Key Characteristics:

1. **Homogeneous Data:** All elements must be of the same type (e.g., all `int`, all `double`).
2. **Contiguous Allocation:** Memory blocks are allocated continuously side-by-side in RAM.
3. **0-indexed Access:** Elements are accessed using a zero-based index (`0` to `size - 1`).
4. **Pass by Reference:** When passed to functions, arrays decay into pointers (storing the starting memory address `0th` index).

---

### 3. Array Operations & Memory Mechanics

#### A. Declaration & Initialization

```cpp
int marks[5];                        // Uninitialized array of size 5 (contains garbage values)
int arr[5] = {99, 100, 54, 36, 88};  // Explicit initialization
int autoArr[] = {10, 20, 30};        // Automatic size inference (Size = 3)

```

#### B. Accessing & Modifying Elements

```cpp
arr[0] = 101;           // Modifies element at 0th index
cout << arr[3];         // Reads element at 3rd index (36)

```

#### C. Array Size Calculation Formula

```cpp
int totalBytes = sizeof(arr);               // Total memory taken by the entire array
int elementBytes = sizeof(arr[0]);          // Memory taken by a single element
int size = totalBytes / elementBytes;       // Number of elements in the array

```

#### D. Pass by Reference Mechanics

* When an array is passed into a function, its **base address** (the address of `arr[0]`) is passed.
* **Effect:** Any modifications made inside the function directly alter the original array in `main()`.

---

### 4. Search & Manipulation Algorithms

#### A. Linear Search Algorithm

* Iterates sequentially through the array from `index 0` to `size - 1` comparing each element against a `target` value.
* **Time Complexity:** $\mathcal{O}(N)$
* **Space Complexity:** $\mathcal{O}(1)$

#### B. Reversing an Array (Two-Pointer Approach)

* Uses two pointers: `start` initialized at `0` and `end` initialized at `size - 1`.
* Elements at `start` and `end` are swapped iteratively, then `start++` and `end--` are executed until `start >= end`.
* **Time Complexity:** $\mathcal{O}(N)$
* **Space Complexity:** $\mathcal{O}(1)$

---

## 📊 Section 2: Markdown Diagrams

### Visual 1: Array Contiguous Memory Allocation

```text
Array: int marks[5] = {99, 100, 54, 36, 88}

Index:         [0]        [1]        [2]        [3]        [4]
           +----------+----------+----------+----------+----------+
Value:     |    99    |   100    |    54    |    36    |    88    |
           +----------+----------+----------+----------+----------+
Address:      1000       1004       1008       1012       1016
           ( +4 bytes )  ( +4 bytes )  ( +4 bytes )  ( +4 bytes )

```

---

### Visual 2: Pass by Reference Workflow (Array vs Function)

```text
  main() Function Scope                     changeArray() Scope
+------------------------------------+    +----------------------------------+
| int arr[3] = {1, 2, 3};            |    | void changeArray(int arr[])      |
| Base Address = 0x1000              |    | Receives Address: 0x1000         |
+------------------------------------+    +----------------------------------+
                 |                                         |
                 +-----------------------------------------+
                                   |
                                   v
                      Directly Modifies Memory at 0x1000
                      Values become: {2, 4, 6} in main()

```

---

### Visual 3: Reverse Array (Two-Pointer Swap Execution)

```text
Initial Array: [ 4, 2, 7, 8, 1, 2, 5 ]
                 ^                 ^
               start              end

Step 1: Swap(arr[0], arr[6]) -> Array: [ 5, 2, 7, 8, 1, 2, 4 ]
                                            ^              ^
                                          start           end

Step 2: Swap(arr[1], arr[5]) -> Array: [ 5, 2, 7, 8, 1, 2, 4 ]
                                               ^       ^
                                             start    end

Step 3: Swap(arr[2], arr[4]) -> Array: [ 5, 2, 1, 8, 7, 2, 4 ]
                                                  ^
                                           start == end  ==> STOP

```

---
