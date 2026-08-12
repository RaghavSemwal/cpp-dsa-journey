# Complete Lecture Notes: Kadane's Algorithm & Maximum Subarray Sum

*(DSA Series by Shradha Khapra Ma'am - Apna College, Lecture 10)*

---

## 📌 Section 1: Detailed Chapter Notes & Concepts

### 1. What is a Subarray?

A **subarray** is a **contiguous** (unbroken/continuous) part of an array.

* For an array of size $n$, the total number of non-empty subarrays is given by the formula:

$$\text{Total Subarrays} = \frac{n \times (n + 1)}{2}$$


* **Example:** For $arr = [1, 2, 3, 4, 5]$ ($n=5$):

$$\text{Total} = \frac{5 \times 6}{2} = 15 \text{ subarrays}$$



#### Subarray vs Subsequence vs Subset:

* **Subarray:** Contiguous & maintains order (e.g., `[2, 3, 4]` in `[1, 2, 3, 4, 5]`).
* **Subsequence:** Not necessarily contiguous, but maintains relative order.
* **Subset:** Any selection of elements, order does not matter.

---

### 2. Maximum Subarray Sum Problem

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the **largest sum**, and return its sum.

---

### 3. Approach Breakdown & Evolution

#### Approach 1: Brute Force (Generating All Subarrays)

* **Logic:** Use 3 nested loops.
* Loop 1 (`start`): Defines the start index.
* Loop 2 (`end`): Defines the end index.
* Loop 3 (`i`): Iterates from `start` to `end` to compute the sum of that specific subarray.


* **Time Complexity:** $\mathcal{O}(n^3)$
* **Space Complexity:** $\mathcal{O}(1)$

#### Approach 2: Slightly Optimized Brute Force

* **Logic:** Eliminate the 3rd loop! As `end` increments, add `nums[end]` to the running `currentSum` accumulated from `start`.
* **Time Complexity:** $\mathcal{O}(n^2)$
* **Space Complexity:** $\mathcal{O}(1)$

---

### 4. Approach 3: Kadane's Algorithm (Optimal $\mathcal{O}(n)$)

#### Core Intuition:

Adding a negative cumulative sum to any subsequent element will only **decrease** the potential maximum sum. Therefore, whenever the running cumulative sum (`currentSum`) drops below $0$, **reset `currentSum` to $0$** and start a new subarray fresh from the next element.

#### Algorithm Steps:

1. Initialize `currentSum = 0` and `maxSum = INT_MIN`.
2. Iterate through each element `val` in `nums`:
* Add `val` to `currentSum`: `currentSum += val`.
* Update `maxSum`: `maxSum = max(currentSum, maxSum)`.
* **Kadane's Reset Step:** If `currentSum < 0`, reset `currentSum = 0`.


3. Return `maxSum`.

#### Edge Case Handling (All Negative Numbers):

* **Why update `maxSum` before resetting `currentSum`?**
* If all array elements are negative (e.g., `[-5, -2, -3]`), the correct answer is the largest single negative element (`-2`).
* Updating `maxSum` **before** the reset step ensures that `maxSum` captures negative values correctly before `currentSum` is reset to $0$.



---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Subarray Contiguity Concept

```text
Array:  [ 1,  2,  3,  4,  5 ]

Valid Subarrays (Contiguous):
  [1]           (Length 1)
  [2, 3, 4]     (Length 3)
  [1, 2, 3, 4, 5] (Length 5)

Invalid Subarray (Non-Contiguous):
  [1, 3, 5]     (X - Gaps exist between elements)

```

---

### Visual 2: Kadane's Algorithm Execution Trace

```text
Array: [ 3, -4, 5, 4, -1, 7, -8 ]

Index | Val | CurrentSum (Before) | CurrentSum + Val | MaxSum | Action
------+-----+---------------------+------------------+--------+--------------------------
  0   |  3  |          0          |        3         |   3    | Keep Sum
  1   | -4  |          3          |       -1         |   3    | Sum < 0 -> Reset to 0
  2   |  5  |          0          |        5         |   5    | Keep Sum
  3   |  4  |          5          |        9         |   9    | Keep Sum
  4   | -1  |          9          |        8         |   9    | Keep Sum
  5   |  7  |          8          |       15         |  15    | Keep Sum (Max Updated!)
  6   | -8  |         15          |        7         |  15    | Keep Sum

Final Maximum Subarray Sum = 15 (Subarray: [5, 4, -1, 7])

```

---

### Visual 3: All-Negative Edge Case Handling

```text
Array: [ -5, -2, -3 ]

Step 1: val = -5 -> currentSum = -5 -> maxSum = max(INT_MIN, -5) = -5
        currentSum < 0 -> currentSum reset to 0

Step 2: val = -2 -> currentSum = -2 -> maxSum = max(-5, -2) = -2
        currentSum < 0 -> currentSum reset to 0

Step 3: val = -3 -> currentSum = -3 -> maxSum = max(-2, -3) = -2
        currentSum < 0 -> currentSum reset to 0

Result: maxSum = -2 (Correct!)

```

