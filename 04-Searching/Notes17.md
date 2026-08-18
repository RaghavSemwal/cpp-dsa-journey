# Complete Lecture Notes: Binary Search Algorithm (Iterative & Recursive)



---

## 📌 Section 1: Detailed Chapter Notes & Algorithmic Concepts

### 1. Introduction to Binary Search

**Binary Search** is an efficient divide-and-conquer search algorithm designed to find the index of a `target` element in a **sorted collection** (array/vector).

* **Real-Life Analogy (Dictionary Search):**
When searching for the word *"Dog"* in a physical dictionary, you don't read page-by-page from page 1 (Linear Search). You open a page near the middle (e.g., page with letter *"P"*). Since *"D"* comes before *"P"*, you completely discard the entire right half of the dictionary and repeat the search only in the left half.

---

### 2. Pre-condition for Binary Search

* The input array **MUST be sorted** (monotonic order: non-decreasing or non-increasing).
* If the array is unsorted, Linear Search ($\mathcal{O}(n)$) or sorting first ($\mathcal{O}(n \log n)$) is required.

---

### 3. Core Search Space Halving Mechanism

For a search space bounded by indices `st` (start) and `end`:

1. Calculate the midpoint: `mid`.
2. Compare `arr[mid]` with `target`:
* **Case 1: `arr[mid] == target**` $\longrightarrow$ Element found! Return `mid`.
* **Case 2: `target > arr[mid]**` $\longrightarrow$ Target lies in the **right (second) half**. Discard left half by setting:

$$\text{st} = \text{mid} + 1$$


* **Case 3: `target < arr[mid]**` $\longrightarrow$ Target lies in the **left (first) half**. Discard right half by setting:

$$\text{end} = \text{mid} - 1$$




3. If `st > end` and target is not found, return `-1`.

---

### 4. Critical Optimization: Preventing Integer Overflow

#### The Overflow Problem:

When `st` and `end` are large integers close to `INT_MAX` ($\approx 2 \times 10^9$):


$$\text{mid} = \frac{\text{st} + \text{end}}{2}$$


The addition $(\text{st} + \text{end})$ exceeds `INT_MAX` ($2^{31}-1$), wrapping into negative values and leading to incorrect index lookups or runtime crashes.

#### The Optimized Midpoint Formula:

$$\text{mid} = \text{st} + \frac{\text{end} - \text{st}}{2}$$

* **Mathematical Equivalence:**

$$\text{st} + \frac{\text{end} - \text{st}}{2} = \frac{2\text{st} + \text{end} - \text{st}}{2} = \frac{\text{st} + \text{end}}{2}$$


* **Safety:** Since $\text{end} \ge \text{st}$, $(\text{end} - \text{st})$ is strictly positive and bounded, completely preventing integer overflow.

---

### 5. Time & Space Complexity Analysis

#### A. Time Complexity Derivation ($\mathcal{O}(\log_2 n)$)

In each iteration, the search space $n$ is halved:


$$n \longrightarrow \frac{n}{2} \longrightarrow \frac{n}{4} \longrightarrow \frac{n}{8} \longrightarrow \dots \longrightarrow \frac{n}{2^k} = 1$$

Setting $\frac{n}{2^k} = 1 \implies n = 2^k \implies k = \log_2 n$.

* **Worst Case Time Complexity:** $\mathcal{O}(\log n)$
* **Best Case Time Complexity:** $\mathcal{O}(1)$ (when target is directly at the first midpoint).

#### B. Space Complexity Comparison:

| Implementation | Auxiliary Space Complexity | Reason |
| --- | --- | --- |
| **Iterative Method** | **$\mathcal{O}(1)$** | Modifies two pointer variables (`st`, `end`) in-place without memory allocation. |
| **Recursive Method** | **$\mathcal{O}(\log n)$** | Uses stack frames on the **Call Stack** proportional to the recursion depth ($\log n$). |

> **Best Practice:** Prefer the **Iterative Approach** in competitive programming and technical interviews because of its $\mathcal{O}(1)$ constant space efficiency.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Binary Search Range Halving (`arr = [-1, 0, 3, 4, 5, 9, 12]`, `target = 12`)

```text
Iteration 1:
  Indices:    [0]   [1]   [2]   [3]   [4]   [5]   [6]
  Values:     -1     0     3     4     5     9    12
              ^                  ^                 ^
              st                mid               end
  mid = 0 + (6-0)/2 = 3 (Value: 4)
  Target (12) > arr[3] (4)  --> Discard left half! st = mid + 1 = 4

Iteration 2:
  Indices:    [0]   [1]   [2]   [3]   [4]   [5]   [6]
  Values:     -1     0     3     4     5     9    12
                                       ^     ^     ^
                                      st    mid   end
  mid = 4 + (6-4)/2 = 5 (Value: 9)
  Target (12) > arr[5] (9)  --> Discard left half! st = mid + 1 = 6

Iteration 3:
  Indices:    [0]   [1]   [2]   [3]   [4]   [5]   [6]
  Values:     -1     0     3     4     5     9    12
                                                   ^
                                               st, mid, end
  mid = 6 + (6-6)/2 = 6 (Value: 12)
  Target (12) == arr[6] (12) --> MATCH FOUND AT INDEX 6!

```

---

### Visual 2: Search Space Reduction Comparison (Linear Search vs. Binary Search)

```text
Input Size (n = 16 elements):

Linear Search (O(n)):
[ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ][ * ]
  1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16  --> (16 steps)

Binary Search (O(log2 n)):
Step 1: [ .  .  .  .  .  .  .  . | *  *  *  *  *  *  *  * ]  (8 elements left)
Step 2:                          [ .  .  .  . | *  *  *  * ]  (4 elements left)
Step 3:                                       [ .  . | *  * ]  (2 elements left)
Step 4:                                              [ . | * ]  (1 element -> Found in 4 steps!)

```

---

### Visual 3: Recursive Call Stack Flow (`target = 0`)

```text
  Call Stack Frame Growth (Height = log2 n):

  +-----------------------------------------------------+
  | recBinarySearch(arr, target=0, st=1, end=1)         | -> mid=1 (arr[1]=0 == target) -> Returns 1
  +-----------------------------------------------------+
  | recBinarySearch(arr, target=0, st=0, end=1)         | -> mid=0 (arr[0]=-1 < target) -> st=mid+1
  +-----------------------------------------------------+
  | recBinarySearch(arr, target=0, st=0, end=5)         | -> mid=2 (arr[2]=3 > target)  -> end=mid-1
  +-----------------------------------------------------+
  | main()                                              |
  +-----------------------------------------------------+

```
