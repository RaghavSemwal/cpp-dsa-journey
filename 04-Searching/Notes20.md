# Complete Lecture Notes: Single Element in a Sorted Array (LeetCode #540)


---

## 📌 Section 1: Detailed Chapter Notes & Concepts

### 1. Problem Statement

You are given a sorted integer array `nums` consisting of $n$ integers where **every element appears exactly twice**, except for **one single element** that appears exactly once.

* **Goal:** Find and return the single element that appears only once.
* **Constraints:**
* The solution must run in **$\mathcal{O}(\log n)$ time complexity**.
* The solution must use **$\mathcal{O}(1)$ space complexity**.
* Array length $n$ is always **odd** ($1, 3, 5, 7, \dots$).



---

### 2. Why Linear Search $\mathcal{O}(n)$ & Bitwise XOR $\mathcal{O}(n)$ Are Insufficient

1. **Linear Search:** Iterate index by index checking if `arr[i] != arr[i-1] && arr[i] != arr[i+1]`. Takes $\mathcal{O}(n)$ time.
2. **Bitwise XOR ($\mathcal{O}(n)$):** XOR all elements together (`ans ^= num`). Duplicate pairs cancel out to `0`, leaving the unique element. While this works in $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space, it does not utilize the **sorted** property and fails the $\mathcal{O}(\log n)$ time requirement.

---

### 3. Core Intuition: Parity & Index Pairing Pattern

In an undisturbed array with only pairs (no single element):

* First occurrence of a pair is at an **EVEN index** (`0, 2, 4, 6, \dots`).
* Second occurrence of a pair is at an **ODD index** (`1, 3, 5, 7, \dots`).

```text
Normal Pair Structure (Even-Odd Index Pattern):
Index:   0    1      2    3      4    5
Array: [ 1,   1 ]  [ 3,   3 ]  [ 7,   7 ]
         ^    ^      ^    ^      ^    ^
        Even Odd    Even Odd    Even Odd

```

Once a **single element** is inserted:

* **Before Single Element (Left Side):** Pairs follow the standard pattern: `(Even, Odd)` $\implies$ First at `Even`, Second at `Odd`.
* **The Single Element:** Appears at an **Even Index** and breaks the pattern.
* **After Single Element (Right Side):** The pair pattern shifts to: `(Odd, Even)` $\implies$ First at `Odd`, Second at `Even`.

---

### 4. Binary Search Decision Rules Based on Mid Index Parity

Calculate midpoint safely:


$$\text{mid} = \text{st} + \frac{\text{end} - \text{st}}{2}$$

#### Step 1: Check if `mid` is the Single Element

If `nums[mid]` does not match its neighbors, it is the unique element:


$$\text{nums}[\text{mid}] \neq \text{nums}[\text{mid}-1] \quad \text{AND} \quad \text{nums}[\text{mid}] \neq \text{nums}[\text{mid}+1]$$

---

#### Step 2: Determine Which Half to Search

#### Case A: When `mid` is an EVEN Index (`mid % 2 == 0`)

* Both the left and right subarrays contain an **even** number of elements.
* **If `nums[mid] == nums[mid - 1]`:**
* The pair starts at an odd index (`mid - 1`) and ends at an even index (`mid`).
* The shift has already occurred $\implies$ The unique element is in the **LEFT half** $\implies \text{end} = \text{mid} - 1$.


* **Else (which implies `nums[mid] == nums[mid + 1]`):**
* The pair follows the normal `(Even, Odd)` pattern at `mid` and `mid + 1`.
* The left side is valid and undisturbed $\implies$ The unique element is in the **RIGHT half** $\implies \text{st} = \text{mid} + 1$.



#### Case B: When `mid` is an ODD Index (`mid % 2 != 0`)

* Both the left and right subarrays contain an **odd** number of elements.
* **If `nums[mid] == nums[mid - 1]`:**
* The pair starts at `Even` (`mid - 1`) and ends at `Odd` (`mid`) $\implies$ Normal pairing pattern.
* The left side is undisturbed $\implies$ The unique element is in the **RIGHT half** $\implies \text{st} = \text{mid} + 1$.


* **Else (which implies `nums[mid] == nums[mid + 1]`):**
* The pair starts at `Odd` (`mid`) and ends at `Even` (`mid + 1`) $\implies$ Shifted pattern.
* The unique element is in the **LEFT half** $\implies \text{end} = \text{mid} - 1$.



---

### 5. Handling Boundary Edge Cases

1. **Single-Element Array ($n = 1$):**
* If array length is `1` (`nums = [5]`), immediately return `nums[0]`.


2. **Single Element at Start ($i = 0$):**
* If `mid == 0` and `nums[0] != nums[1]`, return `nums[0]`.


3. **Single Element at End ($i = n - 1$):**
* If `mid == n - 1` and `nums[n - 1] != nums[n - 2]`, return `nums[n - 1]`.



---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Pair Index Shift Before & After Single Element

```text
Array: [ 1,  1,  2,  3,  3,  4,  4,  8,  8 ]
Index:   0   1   2   3   4   5   6   7   8
         -----   -   -----   -----   -----
Pair:    (1,1)  (2)  (3,3)   (4,4)   (8,8)
Type:   Normal Single Shifted Shifted Shifted
Indices: (E,O)   (E)   (O,E)   (O,E)   (O,E)
                   ^
            Single Element = 2 (Index 2)

```

---

### Visual 2: Complete Dry Run Trace (`nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]`)

```text
Initial Array:
Index:   [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]
Value:    1    1    2    3    3    4    4    8    8
          ^                   ^                   ^
         st                  mid                 end

Iteration 1:
  st = 0, end = 8, mid = 0 + (8 - 0)/2 = 4 (Even Index)
  nums[mid] = 3. Check neighbors:
  nums[4] == nums[3] (3 == 3) -> Matches previous element!
  Because mid (4) is EVEN and matches previous (3), the shift happened on the left.
  -> Action: Search Left Half! end = mid - 1 = 3.

Iteration 2:
Index:   [0]  [1]  [2]  [3]
Value:    1    1    2    3
          ^    ^         ^
         st   mid       end
  st = 0, end = 3, mid = 0 + (3 - 0)/2 = 1 (Odd Index)
  nums[mid] = 1. Check neighbors:
  nums[1] == nums[0] (1 == 1) -> Matches previous element!
  Because mid (1) is ODD and matches previous (0), pairing on left is normal.
  -> Action: Search Right Half! st = mid + 1 = 2.

Iteration 3:
Index:   [2]  [3]
Value:    2    3
          ^    ^
        st,mid end
  st = 2, end = 3, mid = 2 + (3 - 2)/2 = 2 (Even Index)
  nums[mid] = 2. Check neighbors:
  nums[2] != nums[1] (2 != 1) [TRUE]
  nums[2] != nums[3] (2 != 3) [TRUE]
  -> MATCH FOUND! Single element = nums[2] = 2.

```

---

## 📝 Section 4: Homework Exercises & Practice Questions

### Exercise 1: XOR Trick Formulation for Index Checking

In binary search, checking whether `mid` is even or odd can be simplified using the **XOR operation (`mid ^ 1`)**:

* If `mid` is even: `mid ^ 1 == mid + 1`
* If `mid` is odd: `mid ^ 1 == mid - 1`

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Compact formulation using mid ^ 1
int singleNonDuplicateXORIndex(const vector<int>& nums) {
    int st = 0, end = nums.size() - 1;

    while (st < end) {
        int mid = st + (end - st) / 2;
        // mid ^ 1 checks the partner index automatically:
        // If mid is even, mid^1 is mid+1. If mid is odd, mid^1 is mid-1.
        if (nums[mid] == nums[mid ^ 1]) {
            st = mid + 1; // Left side is correctly paired
        } else {
            end = mid;     // Single element is at mid or left
        }
    }
    return nums[st];
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single element (Compact version): " 
         << singleNonDuplicateXORIndex(nums) << endl; // Output: 2
    return 0;
}

