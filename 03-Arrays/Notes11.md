# Complete Lecture Notes: Pair Sum, Majority Element & Moore's Voting Algorithm



---

## 📌 Section 1: Detailed Chapter Notes & Concepts

### 1. Problem 1: Pair Sum in a Sorted Array

#### Problem Statement:

Given a 0-indexed integer array `nums` sorted in **non-decreasing (ascending) order** and an integer `target`, return the indices of the two numbers such that they add up to `target`.

---

#### Approach 1: Brute Force (Nested Loops)

* **Logic:** Generate all possible unique pairs using two loops. Check if `nums[i] + nums[j] == target`.
* **Time Complexity:** $\mathcal{O}(n^2)$
* **Space Complexity:** $\mathcal{O}(1)$

---

#### Approach 2: Two-Pointer Approach (Optimal for Sorted Array)

##### Core Logic:

Since the array is **sorted**, smaller numbers lie on the left and larger numbers lie on the right.

* Place `st = 0` (leftmost element) and `end = n - 1` (rightmost element).
* Compute `pairSum = nums[st] + nums[end]`.

##### Three Decision Cases:

1. **Case 1: `pairSum > target**`
* The sum is too large. Reduce it by shifting the right pointer leftward: `end--`.


2. **Case 2: `pairSum < target**`
* The sum is too small. Increase it by shifting the left pointer rightward: `st++`.


3. **Case 3: `pairSum == target**`
* Target pair found! Return indices `{st, end}`.



* **Time Complexity:** $\mathcal{O}(n)$
* **Space Complexity:** $\mathcal{O}(1)$

---

### 2. Problem 2: Majority Element (LeetCode #169)

#### Problem Statement:

Given an array `nums` of size $n$, return the **majority element**. The majority element is the element that appears **more than $\lfloor n/2 \rfloor$ times**. Assume that a majority element always exists in the array.

---

#### Approach 1: Brute Force (Frequency Count per Element)

* **Logic:** Pick every element and count its frequency by scanning the entire array.
* **Time Complexity:** $\mathcal{O}(n^2)$
* **Space Complexity:** $\mathcal{O}(1)$

---

#### Approach 2: Sorting Approach

* **Logic 1 (Sorting & Frequency Counter):** Sort the array $\mathcal{O}(n \log n)$. Count consecutive duplicate frequencies in a single pass $\mathcal{O}(n)$.
* **Logic 2 (Direct Midpoint Insight):** Once sorted, if a majority element exists (appearing $> n/2$ times), it **must occupy the midpoint index** $\lfloor n/2 \rfloor$.
* **Time Complexity:** $\mathcal{O}(n \log n)$
* **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(n)$ depending on sort implementation.

---

#### Approach 3: Moore's Voting Algorithm (Optimal $\mathcal{O}(n)$ Time, $\mathcal{O}(1)$ Space)

##### Core Intuition:

If we pair up different elements and cancel them out, the majority element (which appears $> n/2$ times) will always be the last remaining candidate with a positive vote count.

##### Algorithm Workflow:

1. Initialize `freq = 0` and `ans = 0`.
2. Iterate through each element `val` in `nums`:
* If `freq == 0`, set candidate `ans = val`.
* If `val == ans`, increment vote: `freq++`.
* Else, decrement vote: `freq--`.


3. Return `ans`.

##### Verification Step (Required if Majority Element Existence is Not Guaranteed):

* Scan the array once more to explicitly count occurrences of `ans`. Return `ans` only if `count > n / 2`; otherwise return `-1`.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Pair Sum Two-Pointer Execution (`nums = [2, 7, 11, 15]`, `target = 26`)

```text
Step 1:  st = 0 (2),  end = 3 (15)
         pairSum = 2 + 15 = 17 < 26  --->  Need larger sum: st++
         
Step 2:  st = 1 (7),  end = 3 (15)
         pairSum = 7 + 15 = 22 < 26  --->  Need larger sum: st++

Step 3:  st = 2 (11), end = 3 (15)
         pairSum = 11 + 15 = 26 == 26 -->  TARGET MATCHED!

Result Indices: { 2, 3 }

```

---

### Visual 2: Moore's Voting Algorithm Trace (`nums = [2, 2, 1, 1, 1, 2, 2]`)

```text
Index | Val | Action                   | Candidate (ans) | Freq (Votes)
------+-----+--------------------------+-----------------+--------------
  0   |  2  | freq==0 -> ans = 2       |        2        |      1
  1   |  2  | val == ans -> freq++     |        2        |      2
  2   |  1  | val != ans -> freq--     |        2        |      1
  3   |  1  | val != ans -> freq--     |        2        |      0
  4   |  1  | freq==0 -> ans = 1       |        1        |      1
  5   |  2  | val != ans -> freq--     |        1        |      0
  6   |  2  | freq==0 -> ans = 2       |        2        |      1

Final Winner (Majority Candidate) = 2

```

---
