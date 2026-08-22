

---

# Complete Lecture Notes: Search in Rotated Sorted Array (LeetCode #33)



---

## 📌 Section 1: Problem Overview & Core Concepts

### 1. Problem Statement

Given an integer array `nums` sorted in ascending order with **distinct values**, which has been rotated at some unknown pivot index $k$ ($0 \le k < \text{nums.length}$), and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

* **Time Complexity Target:** Must be **$\mathcal{O}(\log n)$**.
* **Example:** `nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 0` $\implies$ Output: `4`.

---

### 2. Why Standard Binary Search Fails

In a normal sorted array, comparing `target` with `nums[mid]` tells us directly whether to go left or right. In a rotated sorted array, the rotation breakpoint (pivot) breaks this single global monotonic property:

* In `[4, 5, 6, 7, 0, 1, 2]`, if `mid = 3` (`nums[mid] = 7`) and `target = 0`:
* A standard binary search would see $0 < 7$ and search the **left half** (`[4, 5, 6]`), completely missing the target at index 4 in the right half.



---

### 3. The Core Invariant: One Half is ALWAYS Sorted

Whenever you compute `mid` in a rotated sorted array:

* **Either the Left Half (`st` to `mid`) is strictly sorted, OR the Right Half (`mid` to `end`) is strictly sorted.** Both halves can never be simultaneously broken.

```text
How to check which half is sorted:
  If arr[st] <= arr[mid]  -->  LEFT HALF is sorted [st ... mid]
  Else                    -->  RIGHT HALF is sorted [mid ... end]

```

---

### 4. Decision Framework (Modified Binary Search)

1. **Calculate Midpoint:**

$$\text{mid} = \text{st} + \frac{\text{end} - \text{st}}{2}$$


2. **Check Target at Mid:**
If `arr[mid] == target`, return `mid`.
3. **Branch 1: If Left Half is Sorted (`arr[st] <= arr[mid]`):**
Check if `target` falls inside this sorted range:

$$\text{arr}[\text{st}] \le \text{target} \le \text{arr}[\text{mid}]$$


* **If YES:** Target is in the left sorted portion $\implies \text{end} = \text{mid} - 1$.
* **If NO:** Target must be in the right half $\implies \text{st} = \text{mid} + 1$.


4. **Branch 2: If Right Half is Sorted (`arr[st] > arr[mid]`):**
Check if `target` falls inside this sorted range:

$$\text{arr}[\text{mid}] \le \text{target} \le \text{arr}[\text{end}]$$


* **If YES:** Target is in the right sorted portion $\implies \text{st} = \text{mid} + 1$.
* **If NO:** Target must be in the left half $\implies \text{end} = \text{mid} - 1$.


5. **Not Found:** If `st > end`, return `-1`.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Rotated Sorted Array Structure & Breakpoint

```text
Values
  7 |             [7]
  6 |         [6]/
  5 |     [5]/
  4 | [4]/
    |
  2 |                             [2]
  1 |                         [1]/
  0 |                     [0]/
----+-------------------------------------
      0    1   2   3       4   5   6  (Indices)
      [-- Left Sorted --]  [-- Right Sorted --]

```

---

### Visual 2: Step-by-Step Binary Search Trace (`nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 0`)

```text
Iteration 1:
  Indices:    [0]   [1]   [2]   [3]   [4]   [5]   [6]
  Values:      4     5     6     7     0     1     2
               ^                 ^                 ^
               st               mid               end
  mid = 0 + (6-0)/2 = 3 (nums[mid] = 7)
  1. nums[mid] == target? (7 == 0) -> False
  2. Is Left Half Sorted? (nums[st] <= nums[mid] -> 4 <= 7) -> TRUE!
  3. Does target lie in [4, 7]? (4 <= 0 <= 7) -> FALSE!
  -> Action: Eliminate Left Half! st = mid + 1 = 4.

Iteration 2:
  Indices:    [0]   [1]   [2]   [3]   [4]   [5]   [6]
  Values:      4     5     6     7     0     1     2
                                       ^     ^     ^
                                      st    mid   end
  mid = 4 + (6-4)/2 = 5 (nums[mid] = 1)
  1. nums[mid] == target? (1 == 0) -> False
  2. Is Left Half Sorted? (nums[st] <= nums[mid] -> 0 <= 1) -> TRUE!
  3. Does target lie in [0, 1]? (0 <= 0 <= 1) -> TRUE!
  -> Action: Target is in Left Portion! end = mid - 1 = 4.

Iteration 3:
  Indices:    [0]   [1]   [2]   [3]   [4]   [5]   [6]
  Values:      4     5     6     7     0     1     2
                                       ^
                                  st, mid, end
  mid = 4 + (4-4)/2 = 4 (nums[mid] = 0)
  nums[mid] == target (0 == 0) -> MATCH FOUND AT INDEX 4!

```


---

## 📝 Section 4: Homework Challenge

### Search in Rotated Sorted Array II (LeetCode #81 - With Duplicates)

When duplicates exist (e.g., `[1, 0, 1, 1, 1]`), `nums[st] == nums[mid] == nums[end]` can occur, making it impossible to know which half is sorted. In that scenario, increment `st++` and decrement `end--` to shrink the ambiguous search space.

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool searchWithDuplicates(const vector<int>& nums, int target) {
    int st = 0, end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target) return true;

        // Handle duplicates edge case
        if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
            st++;
            end--;
            continue;
        }

        // Left half is sorted
        if (nums[st] <= nums[mid]) {
            if (nums[st] <= target && target <= nums[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] <= target && target <= nums[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    cout << "Target 0 in array with duplicates: " 
         << (searchWithDuplicates(nums, 0) ? "Found" : "Not Found") << endl; // Found
    return 0;
}

```