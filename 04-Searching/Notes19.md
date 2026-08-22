# Complete Lecture Notes: Peak Index in a Mountain Array (LeetCode #852)


---

## 📌 Section 1: Detailed Chapter Notes & Algorithmic Concepts

### 1. Problem Statement Overview

An array `arr` is a **mountain array** if the following properties hold:

* `arr.length >= 3`
* There exists some index $i$ ($0 < i < \text{arr.length} - 1$) such that:

$$\text{arr}[0] < \text{arr}[1] < \dots < \text{arr}[i - 1] < \text{arr}[i]$$


$$\text{arr}[i] > \text{arr}[i + 1] > \dots > \text{arr}[\text{arr.length} - 1]$$


* **Goal:** Return the index $i$ of the **peak element**.
* **Target Time Complexity:** $\mathcal{O}(\log n)$

---

### 2. Properties of a Mountain Array

```text
               Peak Index (p)
                   [arr[p]]
                    /\
   Increasing      /  \      Decreasing
     Slope        /    \       Slope
                 /      \
      arr[p-1]  /        \  arr[p+1]
               /          \
              /            \

```

1. **Left (Increasing) Slope:** $\text{arr}[i - 1] < \text{arr}[i]$
2. **Peak Element ($p$):** $\text{arr}[p - 1] < \text{arr}[p]$ **AND** $\text{arr}[p] > \text{arr}[p + 1]$
3. **Right (Decreasing) Slope:** $\text{arr}[i] > \text{arr}[i + 1]$ (or $\text{arr}[i - 1] > \text{arr}[i]$)

---

### 3. Why Binary Search Applies Here

Even though the entire array is not monotonically sorted in a single direction, it consists of **two sorted halves (increasing then decreasing)**. We can eliminate half of the search space at each step based on the slope of `mid`.

---

### 4. Search Space Boundary Optimization

* Since the problem guarantees that a mountain array of length $\ge 3$ exists, the peak **can never be at index $0$ or index $n - 1$**.
* **Key Insight:** Initialize $\text{st} = 1$ and $\text{end} = n - 2$.
* **Benefit 1:** Shrinks the initial search space directly to candidate indices.
* **Benefit 2:** Completely prevents out-of-bounds indexing when checking `mid - 1` and `mid + 1`.



---

### 5. Binary Search Decision Rules

For any computed `mid`:

1. **Condition 1 (Found Peak):**

$$\text{arr}[\text{mid} - 1] < \text{arr}[\text{mid}] \quad \text{and} \quad \text{arr}[\text{mid}] > \text{arr}[\text{mid} + 1]$$



$\implies$ `mid` is the peak. Return `mid`.
2. **Condition 2 (On Increasing Slope):**

$$\text{arr}[\text{mid} - 1] < \text{arr}[\text{mid}]$$



$\implies$ We are climbing up the left side. The peak lies to the **right** $\implies \text{st} = \text{mid} + 1$.
3. **Condition 3 (On Decreasing Slope):**

$$\text{arr}[\text{mid} - 1] > \text{arr}[\text{mid}]$$



$\implies$ We are sliding down the right side. The peak lies to the **left** $\implies \text{end} = \text{mid} - 1$.

---

### 6. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(\log n)$ — The search space is halved in each step.
* **Space Complexity:** $\mathcal{O}(1)$ — Only scalar pointers (`st`, `end`, `mid`) are used.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Mountain Array Structure & Slopes

```text
Values
  9 |                  [9] (Peak: arr[3])
  8 |              [8]/   \
  7 |                /     \
  6 |               /       \
  5 |              /         \[5]
  4 |             /           \
  3 |         [3]/             \
  2 |           /               \[2]
  1 |          /
  0 |      [0]/
----+-------------------------------------
      Index: 0   1   2   3    4   5
             [-- Left --]   [-- Right --]
              Increasing      Decreasing

```

---

### Visual 2: Step-by-Step Binary Search Trace (`arr = [0, 3, 8, 9, 5, 2]`)

```text
Indices:  [0]   [1]   [2]   [3]   [4]   [5]
Values:    0     3     8     9     5     2
                 ^                 ^
                 st               end

Initial State: st = 1, end = 4 (n - 2)

Step 1:
  - mid = 1 + (4 - 1) / 2 = 2 (Value: arr[2] = 8)
  - Check Peak: arr[1] (3) < arr[2] (8), but arr[2] (8) < arr[3] (9) -> Not Peak!
  - Slope Check: arr[1] (3) < arr[2] (8) -> On Increasing Slope.
  - Action: Peak must be to the right -> st = mid + 1 = 3.

Step 2:
  - Search Space: st = 3, end = 4
  - mid = 3 + (4 - 3) / 2 = 3 (Value: arr[3] = 9)
  - Check Peak:
      arr[2] (8) < arr[3] (9)  [TRUE]
      arr[3] (9) > arr[4] (5)  [TRUE]
  - Action: Peak Found at Index 3!

Output = 3

```

---

## 📝 Section 4: Homework Exercises & Practice Questions

### Exercise 1: Find Peak Element in a Multi-Peak Array (LeetCode #162)

In LeetCode #162, an array may contain multiple peaks and is not strictly a single mountain. Return the index of **any** one peak in $\mathcal{O}(\log n)$ time.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(const vector<int>& nums) {
    int st = 0, end = nums.size() - 1;

    while (st < end) {
        int mid = st + (end - st) / 2;
        if (nums[mid] < nums[mid + 1]) {
            // We are on an upward slope; a peak must exist to the right
            st = mid + 1;
        } else {
            // We are on a downward slope; mid itself could be the peak or peak is to the left
            end = mid;
        }
    }
    return st;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak Element Index: " << findPeakElement(nums) << endl; // Returns index 1 or 5
    return 0;
}

