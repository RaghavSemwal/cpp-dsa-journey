# Complete Lecture Notes: Product of Array Except Self (LeetCode #238)



---

## 📌 Section 1: Problem Statement & Constraints

### 1. Problem Overview

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the **product of all the elements of `nums` except `nums[i]**`.

* **Constraints & Strict Rules:**
* You **MUST NOT use the division operation (`/`)**.
* Must run in **$\mathcal{O}(n)$ time complexity**.
* The solution must use **$\mathcal{O}(1)$ auxiliary space complexity** (the output array does not count as extra space for complexity analysis).
* The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.



---

### 2. Why the Naive Division Approach Fails

If division were allowed, we could compute the total product $P = \prod \text{nums}[i]$ and set $\text{answer}[i] = P / \text{nums}[i]$.

* **Failure Reasons:**
1. The problem explicitly forbids division.
2. If `nums` contains `0`, direct division results in a runtime **ZeroDivisionError** or requires special-case handling for zero counts.



---

### 3. Approach Evolution & Architectural Breakdown

#### Approach 1: Brute Force (Nested Loops)

* **Logic:** For each index $i$, iterate through every index $j$ ($0 \le j < n$). If $i \neq j$, multiply `nums[j]` into the product for index $i$.
* **Time Complexity:** $\mathcal{O}(n^2)$ $\implies$ **Causes TLE** for $n \le 10^5$.
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary.

---

#### Approach 2: Prefix & Suffix Arrays ($\mathcal{O}(n)$ Time, $\mathcal{O}(n)$ Space)

* **Core Insight:**

$$\text{answer}[i] = (\text{Product of elements before } i) \times (\text{Product of elements after } i) = \text{Prefix}[i] \times \text{Suffix}[i]$$


* **Steps:**
1. Construct a `prefix` array: $\text{prefix}[i] = \text{prefix}[i-1] \times \text{nums}[i-1]$, with $\text{prefix}[0] = 1$.
2. Construct a `suffix` array: $\text{suffix}[i] = \text{suffix}[i+1] \times \text{nums}[i+1]$, with $\text{suffix}[n-1] = 1$.
3. Combine: $\text{answer}[i] = \text{prefix}[i] \times \text{suffix}[i]$.


* **Time Complexity:** $\mathcal{O}(n)$ (3 linear passes).
* **Space Complexity:** $\mathcal{O}(n)$ auxiliary (due to separate prefix and suffix vectors).

---

#### Approach 3: Space-Optimized Prefix-Suffix Direct Computation ($\mathcal{O}(n)$ Time, $\mathcal{O}(1)$ Space)

* **Key Optimization:** Eliminate separate prefix and suffix arrays.
1. **Pass 1 (Prefix directly in `ans`):**
* Use the return vector `ans` to store the running prefix product directly.
* Set `ans[0] = 1`. For $i = 1 \to n-1$:

$$\text{ans}[i] = \text{ans}[i-1] \times \text{nums}[i-1]$$




2. **Pass 2 (Suffix on the fly using a scalar variable):**
* Maintain a single scalar variable `suffix = 1`.
* Traverse backwards from $i = n-2 \to 0$:
* Update running suffix with the element to its right: `suffix *= nums[i+1]`.
* Multiply into the existing prefix in `ans`: `ans[i] *= suffix`.






* **Time Complexity:** $\mathcal{O}(n)$ (2 linear passes).
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (modifying only the output array).

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Prefix & Suffix Partition Concept for Index $i=2$

```text
Array: [ 1,   2,   3,   4 ]
Index:   0    1    2    3
                   ^
                   Target Index i = 2 (Value = 3)

       [ 1 * 2 ]       3        [ 4 ]
       +-------+                +---+
        Prefix                 Suffix
        Product                Product
          = 2                    = 4

Answer[2] = Prefix Product * Suffix Product = 2 * 4 = 8

```

---

### Visual 2: Complete Dry Run Trace of Optimal $\mathcal{O}(1)$ Space Algorithm

Given `nums = [1, 2, 3, 4]`, $n = 4$:

```text
================================================================================
PASS 1: Prefix Pass (Left-to-Right into ans array)
================================================================================
  i = 0 : ans[0] = 1
  i = 1 : ans[1] = ans[0] * nums[0] = 1 * 1 = 1
  i = 2 : ans[2] = ans[1] * nums[1] = 1 * 2 = 2
  i = 3 : ans[3] = ans[2] * nums[2] = 2 * 3 = 6

  State of ans after Pass 1: [ 1, 1, 2, 6 ]

================================================================================
PASS 2: Suffix Pass (Right-to-Left using scalar suffix variable)
================================================================================
  Initialize: suffix = 1

  i = 2 : suffix = suffix * nums[3] = 1 * 4 = 4
          ans[2] = ans[2] * suffix  = 2 * 4 = 8

  i = 1 : suffix = suffix * nums[2] = 4 * 3 = 12
          ans[1] = ans[1] * suffix  = 1 * 12 = 12

  i = 0 : suffix = suffix * nums[1] = 12 * 2 = 24
          ans[0] = ans[0] * suffix  = 1 * 24 = 24

================================================================================
FINAL OUTPUT: ans = [ 24, 12, 8, 6 ]
================================================================================

```

---

### Visual 3: Space Complexity Comparison Matrix

```text
Approach 2 (O(N) Auxiliary Space):
  nums:     [ 1 ][ 2 ][ 3 ][ 4 ]
  prefix:   [ 1 ][ 1 ][ 2 ][ 6 ]   <-- Extra O(N) memory
  suffix:   [ 24][ 12][ 4 ][ 1 ]   <-- Extra O(N) memory
  ans:      [ 24][ 12][ 8 ][ 6 ]

Approach 3 (O(1) Auxiliary Space):
  nums:     [ 1 ][ 2 ][ 3 ][ 4 ]
  ans:      [ 1 ][ 1 ][ 2 ][ 6 ]   (After Pass 1 - Prefix)
  ans:      [ 24][ 12][ 8 ][ 6 ]   (After Pass 2 - In-place Suffix Multiplication)
  suffix:   Scalar variable (4 bytes only)

```

---

## 📝 Section 4: Homework Exercises & Practice Questions

### Exercise 1: Left and Right Sum Differences (LeetCode #2574)

**Problem:** Given a 0-indexed integer array `nums`, find a 0-indexed integer array `answer` where:


$$\text{answer}[i] = \vert{}\text{leftSum}[i] - \text{rightSum}[i]\vert{}$$

* `leftSum[i]` is the sum of elements to the left of index $i$.
* `rightSum[i]` is the sum of elements to the right of index $i$.

#### Optimal Solution in $\mathcal{O}(n)$ Time & $\mathcal{O}(1)$ Extra Space:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

vector<int> leftRightDifference(const vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for (int x : nums) totalSum += x;

    vector<int> ans(n, 0);
    int leftSum = 0;

    for (int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        ans[i] = abs(leftSum - rightSum);
        leftSum += nums[i];
    }

    return ans;
}

int main() {
    vector<int> nums = {10, 4, 8, 3};
    vector<int> result = leftRightDifference(nums);

    cout << "Left-Right Sum Differences: ";
    for (int val : result) cout << val << " ";
    cout << endl; // Output: 15 1 11 22
    return 0;
}

