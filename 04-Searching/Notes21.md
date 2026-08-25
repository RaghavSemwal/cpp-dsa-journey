# Complete Lecture Notes: Book Allocation Problem

*(DSA Series by Shradha Khapra Ma'am - Apna College, Lecture 21)*

---

## 📌 Section 1: Problem Overview & Core Concepts

### 1. Problem Statement

You are given an array `arr` of integer numbers where `arr[i]` represents the number of pages in the $i^{\text{th}}$ book. There are $n$ books and $m$ students. The books must be allocated among all $m$ students such that:

1. **Every book is allocated** to exactly one student.
2. **Every student gets at least one book**.
3. **Contiguous Allocation:** Books allocated to any student must be in contiguous order (e.g., a student cannot receive book 1 and book 3 while skipping book 2).
4. **Objective:** **Minimize the maximum pages** allocated to any single student ("Min-Max optimization problem").

* If a valid allocation is impossible (e.g., $m > n$), return `-1`.

---

### 2. Paradigm Shift: "Binary Search on Answer Range"

In traditional binary search, we search over the **indices** of a sorted input array. Here, the array of book pages might not be sorted.

Instead, we apply **Binary Search on the Search Space of all possible answer values (pages)**:

1. What is the minimum possible maximum pages any student could get? $\longrightarrow \text{st} = 0$ (or $\max(\text{arr})$).
2. What is the maximum possible maximum pages any student could get? $\longrightarrow \text{end} = \sum_{i=0}^{n-1} \text{arr}[i]$ (one student gets all books).
3. The answer range $[0, \sum \text{arr}]$ is **naturally sorted and monotonic**!

```text
Answer Range (Search Space):
[ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, ... sum(arr) ]
  ^                                                ^
 st = 0                                       end = sum(arr)

```

---

### 3. Decision Framework & Monotonic Property

For any test value $\text{mid}$ (which represents the **maximum allowed pages per student**):

* We check feasibility using a helper function: `isValid(arr, n, m, maxAllowedPages = mid)`.

#### Two Search Space Decisions:

1. **If `isValid(...) == true`:**
* It is possible to distribute all books such that no student exceeds `mid` pages.
* `mid` is a valid candidate $\implies \text{ans} = \text{mid}$.
* Since we want the **minimum possible maximum**, check if an even smaller value is feasible on the left $\implies \text{end} = \text{mid} - 1$.


2. **If `isValid(...) == false`:**
* The page limit `mid` is too tight (requires $> m$ students to complete allocation).
* We must allow more pages per student $\implies$ Search the right half $\implies \text{st} = \text{mid} + 1$.



---

### 4. Feasibility Logic (`isValid` Helper Function)

1. Iterate through books sequentially (to enforce contiguous order).
2. Maintain `students = 1` and `currentPages = 0`.
3. **Corner Case Check:** If any single book has pages $> \text{maxAllowedPages}$, return `false` immediately.
4. If `currentPages + arr[i] <= maxAllowedPages`:
* Assign book to the current student $\implies \text{currentPages} += \text{arr}[i]$.


5. Else:
* Current student's capacity is full. Allocate to the next student:

$$\text{students}++$$


$$\text{currentPages} = \text{arr}[i]$$




6. After checking all books:
* If $\text{students} > m \implies$ return `false`.
* Else $\implies$ return `true`.



---

### 5. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n \cdot \log(\sum \text{arr}))$
* Range size $= \sum \text{arr}$. The binary search loop runs $\log_2(\sum \text{arr})$ times.
* Inside each step, `isValid` scans $n$ books in $\mathcal{O}(n)$ time.


* **Space Complexity:** $\mathcal{O}(1)$ — No extra arrays/data structures used.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Feasibility Distribution Trace (`arr = [2, 1, 3, 4]`, $m = 2$)

```text
Attempt 1: maxAllowedPages = mid = 5
  - Book 0 (2): student 1 gets 2 pages. (currentPages = 2)
  - Book 1 (1): 2 + 1 <= 5 -> student 1 gets 1 page. (currentPages = 3)
  - Book 2 (3): 3 + 3 = 6 > 5 -> Student 1 full! 
                Switch to student 2: student 2 gets 3 pages. (currentPages = 3)
  - Book 3 (4): 3 + 4 = 7 > 5 -> Student 2 full!
                Switch to student 3: student 3 gets 4 pages.
  -> Total students needed = 3 > m (2) ===> INVALID (False) -> st = mid + 1

Attempt 2: maxAllowedPages = mid = 8
  - student 1 gets [2, 1, 3] = 6 pages (<= 8)
  - student 2 gets [4]       = 4 pages (<= 8)
  -> Total students needed = 2 <= m (2) ===> VALID (True) -> ans = 8, end = mid - 1

Attempt 3: maxAllowedPages = mid = 6
  - student 1 gets [2, 1, 3] = 6 pages (<= 6)
  - student 2 gets [4]       = 4 pages (<= 6)
  -> Total students needed = 2 <= m (2) ===> VALID (True) -> ans = 6, end = mid - 1

Final Minimum Maximum Pages = 6

```

---

### Visual 2: Binary Search on Answer Space Mechanics

```text
Initial Search Space: [ 0 ... 10 ] (sum = 10)

Iteration 1: st = 0,  end = 10 -> mid = 5  -> isValid(5) = False -> st = 6
Iteration 2: st = 6,  end = 10 -> mid = 8  -> isValid(8) = True  -> ans = 8, end = 7
Iteration 3: st = 6,  end = 7  -> mid = 6  -> isValid(6) = True  -> ans = 6, end = 5
Loop Terminates (st > end).

Optimal Answer = 6

```


---

## 📝 Section 4: Homework Challenge

### Exercise: Painter's Partition Problem & Split Array Largest Sum

Both **Painter's Partition Problem** and **LeetCode #410 (Split Array Largest Sum)** share the exact same mathematical structure as Book Allocation.

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Exact same logic applied to Split Array Largest Sum (LeetCode #410)
int splitArray(vector<int>& nums, int k) {
    return allocateBooks(nums, nums.size(), k);
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << "Split Array Largest Sum (k=2): " << splitArray(nums, k) << endl; // Output: 18
    return 0;
}
