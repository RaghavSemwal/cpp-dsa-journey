# Complete Lecture Notes: Merge Sorted Arrays & Next Permutation

---

## 📌 Section 1: Detailed Chapter Notes & Algorithmic Concepts

---

### Part A: Problem 1 — Merge Sorted Array (LeetCode 88)

#### 1. Problem Statement 

You are given two integer arrays `nums1` (or $A$) and `nums2` (or $B$), sorted in non-decreasing order, and two integers $m$ and $n$, representing the number of initial valid elements in $A$ and $B$ respectively.

* $A$ has a total length of $m + n$, where the first $m$ elements denote the valid data, and the last $n$ elements are initialized to $0$ as placeholder space.
* **Goal:** Merge $A$ and $B$ into a single array sorted in non-decreasing order **in-place** inside $A$.

---

#### 2. Approach 1: Auxiliary Array (Extra Space)
* **Idea:** Standard 2-pointer merge step from Merge Sort.
* Allocate a temporary buffer $C$ of size $m + n$.
* Use two pointers starting at the beginning ($i = 0$ for $A$, $j = 0$ for $B$) and push the smaller element into $C$.
* Copy back all $m + n$ elements from $C$ into $A$.


* **Time Complexity:** $\mathcal{O}(m + n)$
* **Space Complexity:** $\mathcal{O}(m + n)$ auxiliary space.
* **Limitation:** Fails the in-place $\mathcal{O}(1)$ space requirement.

---

#### 3. Approach 2: Backward 3-Pointer Merge (Optimal In-Place) 

* **Key Insight:** If we fill $A$ starting from the front, we risk overwriting valid elements in $A$ before inspecting them. However, the empty/placeholder space ($0$s) is located at the **end** of $A$ (indices $m$ to $m + n - 1$).
* **Strategy:** Traverse **backwards** from the largest elements to the smallest
* `idx = m + n - 1`: Tracks where the next largest element will be placed.
* `i = m - 1`: Tracks the current largest unprocessed element in $A$.
* `j = n - 1`: Tracks the current largest unprocessed element in $B$.


* **Loop Logic:** While $i \ge 0$ and $j \ge 0$:
* If $A[i] \ge B[j]$, place $A[i]$ at $A[\text{idx}]$ and decrement `i` and `idx`.
* Otherwise, place $B[j]$ at $A[\text{idx}]$ and decrement `j` and `idx`.


* **Handling Remaining Elements 
* If $i < 0$ first but $j \ge 0$, copy the remaining elements of $B$ into $A$ backwards (`while (j >= 0)`).
* If $j < 0$ first, any remaining elements of $A$ are already in their correct sorted slots—no action needed!


* **Time Complexity:** $\mathcal{O}(m + n)$ (at most $m + n$ comparisons).
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary (pure in-place).

---

### Part B: Problem 2 — Next Permutation (LeetCode 31)

#### 1. What is Lexicographical Order? 
A **permutation** is an arrangement of members of a sequence. Lexicographical order is dictionary order (e.g., for digits `[1, 2, 3]`: `123 < 132 < 213 < 231 < 312 < 321`).

* **Goal:** Find the next lexicographically greater permutation in-place. If no greater permutation exists (i.e., array is descending: `3, 2, 1`), rearrange to the lowest possible order (`1, 2, 3`).

---

#### 2. Approach 1: Brute Force (Recursion) 

* **Idea:**
1. Generate all $n!$ permutations using recursion/backtracking.
2. Sort them lexicographically.
3. Locate the given array and pick the next configuration.


* **Time Complexity:** $\mathcal{O}(n! \times n)$
* **Space Complexity:** $\mathcal{O}(n! \times n)$
* **Limitation:** Extremely slow; causes Time Limit Exceeded (TLE) for even $n \ge 12$.

---

#### 3. Approach 2: Built-in C++ STL Function 

```cpp
next_permutation(nums.begin(), nums.end());

```

* Works internally using the exact optimal algorithm in $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space, but **not allowed** in technical interviews.

---

#### 4. Approach 3: Optimal 3-Step Pivot Algorithm 

To find the next permutation with the smallest increase:

* **Step 1: Find the Pivot Index (`pivot`) 
* Scan backwards from right to left (`i = n - 2` down to `0`).
* Find the first index $i$ such that $A[i] < A[i + 1]$.
* The subarray to the right of `pivot` ($A[\text{pivot} + 1 \dots n - 1]$) is in strict non-increasing (descending) order.
* **Edge Case  If no such index exists (`pivot == -1`), the entire array is sorted in descending order (the largest possible permutation). Reverse the whole array to get the smallest order, and terminate.


* **Step 2: Find the Rightmost Successor and Swap 
* Scan backwards from `n - 1` down to `pivot + 1`.
* Find the first element $A[i]$ that is strictly greater than $A[\text{pivot}]$ ($A[i] > A[\text{pivot}]$).
* Swap $A[\text{pivot}]$ with $A[i]$.


* **Step 3: Reverse the Suffix 
* The suffix starting at `pivot + 1` up to `n - 1` is still in non-increasing order.
* Reverse this entire suffix from `pivot + 1` to `n - 1` using a 2-pointer swap.
* Reversing descending order transforms it into ascending order (the minimum possible configuration), producing the next permutation.


* **Time Complexity:** $\mathcal{O}(n) + \mathcal{O}(n) + \mathcal{O}(n) = \mathcal{O}(n)$
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Backward Merge for LeetCode 88 (`nums1 = [1, 2, 3, 0, 0, 0]`, `nums2 = [2, 5, 6]`)

```text
Initial Setup:
              i = 2                 idx = 5
              ▼                       ▼
nums1: [  1,  2,  3,    0,   0,   0   ]
nums2: [  2,  5,  6  ]
                  ▲
                j = 2

Step 1: Compare nums1[i]=3 vs nums2[j]=6 -> 6 > 3 -> Put 6 at idx=5
nums1: [  1,  2,  3,    0,   0, | 6 | ]   (j--, idx--)

Step 2: Compare nums1[i]=3 vs nums2[j]=5 -> 5 > 3 -> Put 5 at idx=4
nums1: [  1,  2,  3,    0, | 5 |, 6   ]   (j--, idx--)

Step 3: Compare nums1[i]=3 vs nums2[j]=2 -> 3 > 2 -> Put 3 at idx=3
nums1: [  1,  2,  3,  | 3 |, 5,   6   ]   (i--, idx--)

Step 4: Compare nums1[i]=2 vs nums2[j]=2 -> Put 2 at idx=2
nums1: [  1,  2, | 2 |, 3,   5,   6   ]   (i--, idx--)

Step 5: Compare nums1[i]=1 vs nums2[j]=2 -> 2 > 1 -> Put 2 at idx=1
nums1: [  1, | 2 |, 2,  3,   5,   6   ]   (j becomes -1 -> Terminate!)

Result: [ 1, 2, 2, 3, 5, 6 ]  (In-place with zero extra memory!)

```

---

### Visual 2: Next Permutation 3-Step Walkthrough (`[1, 2, 3, 6, 5, 4]`)

```text
Input Array: [ 1,  2,  3,  6,  5,  4 ]
                       ▲   ─────────
                     pivot  Suffix in descending order

Step 1: Find Pivot (arr[i] < arr[i+1] from right)
        pivot = index 2 (value = 3)

Step 2: Find rightmost element > arr[pivot] and SWAP:
        Scan from right: 4 > 3 -> Swap index 2 and index 5:
        Array becomes: [ 1,  2, | 4 |,  6,  5, | 3 | ]

Step 3: Reverse the suffix from (pivot + 1) to (n - 1):
        Suffix to reverse: [ 6,  5,  3 ] -> becomes: [ 3,  5,  6 ]

Final Permutation: [ 1,  2,  4,  3,  5,  6 ]

```


---

## 📝 Section 4: Practice Problems & Interview Extensions

### Exercise 1: Previous Permutation with One Swap (LeetCode 1053)

Given an array of positive integers `arr`, return the lexicographically largest permutation that is smaller than `arr` using exactly **at most one swap**:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prevPermOpt1(vector<int>& arr) {
    int n = arr.size();
    int pivot = -1;

    // Step 1: Find largest i such that arr[i] > arr[i + 1]
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    if (pivot == -1) return arr; // Already minimum permutation

    // Step 2: Find largest arr[j] < arr[pivot] (and pick the first occurrence among duplicates)
    int targetIdx = -1;
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] < arr[pivot]) {
            // If duplicate values exist, choose the leftmost of identical maximums
            if (targetIdx == -1 || arr[i] >= arr[targetIdx]) {
                targetIdx = i;
            }
        }
    }

    swap(arr[pivot], arr[targetIdx]);
    return arr;
}

int main() {
    vector<int> arr = {3, 2, 1};
    prevPermOpt1(arr);
    printVector(arr); // Output: 3 1 2
    return 0;
}



---

### Exercise 2: Permutation Sequence (LeetCode 60)

Find the $k^{\text{th}}$ permutation sequence of numbers from $1$ to $n$ in $\mathcal{O}(n^2)$ time using factorial number representation rather than generating each permutation sequentially:

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    string ans = "";
    k = k - 1; // 0-based indexing

    while (true) {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + (k / fact));
        if (numbers.size() == 0) break;
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main() {
    cout << "4th permutation for n=3: " << getPermutation(3, 4) << "\n"; // Output: "231"
    return 0;
}

