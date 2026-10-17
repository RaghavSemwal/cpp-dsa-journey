
---

## 📌 Section 1: Detailed Chapter Notes & Algorithmic Concepts

### 1. Problem Statement & Variants

Given an array or vector containing only three distinct integers—`0`, `1`, and `2`—rearrange the elements in-place in non-decreasing order so that all `0`s come first, followed by all `1`s, and then all `2`s.

Common interview problem aliases:

* **LeetCode 75:** Sort Colors (Red = 0, White = 1, Blue = 2)
* **Interview Variant:** Sort Balls by Color (e.g., White = 0, Pink = 1, Red = 2)

---

### 2. Strategy 1: Brute Force (Built-in Sort)

* **Concept:** Call the language standard library sorting algorithm (`std::sort` in C++).
* **Mechanism:** Uses IntroSort (a hybrid of QuickSort, HeapSort, and InsertionSort).
* **Time Complexity:** $\mathcal{O}(n \log n)$
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space ($\mathcal{O}(\log n)$ internal call stack).
* **Verdict:** Fails typical interview constraints where using built-in sorting primitives is explicitly forbidden.

---

### 3. Strategy 2: Frequency Counting (2-Pass Approach)

* **Concept:** Count the frequencies of each unique key (`0`, `1`, and `2`), then regenerate the array sequentially.
* **Mechanism:**
1. **Pass 1:** Run one loop from $i = 0$ to $n - 1$ maintaining `count0`, `count1`, and `count2`.
2. **Pass 2:** Run sequential loops overwriting the input array with `count0` zeros, `count1` ones, and `count2` twos.


* **Time Complexity:** $\mathcal{O}(n) + \mathcal{O}(n) = \mathcal{O}(2n) \approx \mathcal{O}(n)$
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
* **Verdict:** Valid linear-time solution, but requires **two complete passes** over the array.

---

### 4. Strategy 3: Dutch National Flag (DNF) Algorithm (Optimal 1-Pass)

Devised by Edsger W. Dijkstra, this algorithm segments the array into **four dynamic zones** using three pointers: `low`, `mid`, and `high`.

#### Pointer Invariants:

* `[0 ... low - 1]`: All `0`s (sorted extreme left)
* `[low ... mid - 1]`: All `1`s (sorted middle)
* `[mid ... high]`: Unknown / Unsorted window (elements yet to be inspected)
* `[high + 1 ... n - 1]`: All `2`s (sorted extreme right)

```text
[  0  0  ...  0  |  1  1  ...  1  |  ?  ?  ...  ?  |  2  2  ...  2  ]
0             low-1 low        mid-1 mid        high high+1        n-1

```

#### State Transition Logic:

While `mid <= high`:

1. **`nums[mid] == 0`**:
* Swap `nums[low]` and `nums[mid]`.
* Increment both `low++` and `mid++` (since `nums[low]` is guaranteed to be a `1` or the same index).


2. **`nums[mid] == 1`**:
* Element is in its designated middle partition.
* Simply increment `mid++`.


3. **`nums[mid] == 2`**:
* Swap `nums[mid]` and `nums[high]`.
* Decrement `high--`.
* **Do not increment `mid**` because the element swapped from index `high` into `mid` is uninspected and must be checked in the next step.



* **Time Complexity:** $\mathcal{O}(n)$ (strictly 1 pass; in every iteration either `mid` moves right or `high` moves left).
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.

---

### 5. Algorithm Comparison Matrix

| Metric | Approach 1: Brute Force | Approach 2: Counting | Approach 3: DNF Algorithm |
| --- | --- | --- | --- |
| **Array Passes** | Multiple ($\log n$) | Exactly 2 | Strictly 1 |
| **Time Complexity** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Space Complexity** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Number of Swaps** | $\mathcal{O}(n \log n)$ | 0 (Overwrites values) | At most $n$ swaps |
| **LeetCode Status** | Disallowed | Accepted | Optimal (Beats 100%) |

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Pointer Movement & Boundary Shrinking (DNF)

```text
Initial State:
 low, mid                                           high
    ▼                                                 ▼
  [ 2,         0,         2,         1,         1,    0 ]
  (mid points to 2 -> swap with high, high--)

After Step 1:
 low, mid                                  high
    ▼                                       ▼
  [ 0,         0,         2,         1,     1,      | 2 | ]
  (mid points to 0 -> swap with low, low++, mid++)

After Step 2:
              low, mid                     high
                 ▼                          ▼
  [ 0,         | 0 |,       2,       1,     1,      | 2 | ]
  (mid points to 0 -> swap with low, low++, mid++)

After Step 3:
                           low, mid        high
                              ▼             ▼
  [ 0,           0,         | 2 |,   1,     1,      | 2 | ]
  (mid points to 2 -> swap with high, high--)

After Step 4:
                           low, mid  high
                              ▼       ▼
  [ 0,           0,         | 1 |,    1,    | 2 |,    2   ]
  (mid points to 1 -> mid++)

After Step 5:
                           low       mid, high
                            ▼           ▼
  [ 0,           0,         1,        | 1 |, | 2 |,    2   ]
  (mid points to 1 -> mid++)

Final State:
                           low      high   mid
                            ▼        ▼      ▼
  [ 0,           0,         1,       1,   | 2,        2   ]
  (mid > high -> TERMINATE)

```



---

## 📝 Section 4: Practice Problems & Interview Extensions

### Exercise 1: Sort Array by Parity (0s and 1s only)

Sort an array containing only `0`s and `1`s in a single pass using a two-pointer approach:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortZeroesAndOnes(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] == 0) {
            left++;
        } else if (arr[right] == 1) {
            right--;
        } else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {1, 0, 1, 1, 0, 0, 1, 0};
    sortZeroesAndOnes(arr);
    for (int x : arr) cout << x << " ";
    cout << "\n"; // Output: 0 0 0 0 1 1 1 1
    return 0;
}

```

---

### Exercise 2: Move Zeroes to End (LeetCode 283)

Maintain the relative order of non-zero elements while moving all zeros to the end in $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int insertPos = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[insertPos], nums[i]);
            insertPos++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int x : nums) cout << x << " ";
    cout << "\n"; // Output: 1 3 12 0 0
    return 0;
}

```