
# Complete Lecture Notes: Sorting Algorithms



---

## 📌 Section 1: Detailed Chapter Notes & Algorithmic Concepts

### 1. What is Sorting?

**Sorting** is the process of arranging data in a specific sequential order:

* **Ascending Order (Non-decreasing):** Elements increase or remain equal ($a_0 \le a_1 \le a_2 \le \dots$).
* **Descending Order (Non-increasing):** Elements decrease or remain equal ($a_0 \ge a_1 \ge a_2 \ge \dots$).

The three fundamental comparison-based sorting algorithms covered in this lecture run in $\mathcal{O}(n^2)$ time in the worst case. While advanced algorithms like Merge Sort and Quick Sort ($\mathcal{O}(n \log n)$) are preferred in competitive programming, these three are classic interview questions.

---

### 2. Algorithm 1: Bubble Sort

#### Core Intuition:

Repeatedly step through the list, compare **adjacent pairs**, and swap them if they are in the wrong order.

* In each complete pass $i$, the largest unsorted element "bubbles up" to its correct position at the end of the array.
* Total passes required: $n - 1$.

#### Optimized Early-Exit Mechanism:

If an entire pass completes with **zero swaps**, the array is already sorted. We can exit early using a boolean flag `isSwap`, reducing the **best-case time complexity to $\mathcal{O}(n)$**.

* **Time Complexity:**
* Worst Case: $\mathcal{O}(n^2)$
* Average Case: $\mathcal{O}(n^2)$
* Best Case (Optimized): $\mathcal{O}(n)$


* **Space Complexity:** $\mathcal{O}(1)$ auxiliary.

---

### 3. Algorithm 2: Selection Sort

#### Core Intuition:

Divide the array conceptually into two subarrays:

1. **Sorted part** on the left.
2. **Unsorted part** on the right.

In each iteration $i$, find the index of the **minimum element** in the unsorted subarray and swap it with the element at index $i$ (the start of the unsorted part).

* Total passes required: $n - 1$.
* **Time Complexity:** $\mathcal{O}(n^2)$ in all cases (Best, Average, and Worst), because finding the minimum always requires scanning the entire unsorted portion.
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary.

---

### 4. Algorithm 3: Insertion Sort

#### Core Intuition (The Playing Cards Analogy):

Like arranging playing cards in your hand:

* Assume the first element (`arr[0]`) is already sorted.
* Pick the next unsorted element (`curr = arr[i]`).
* Compare `curr` backwards through the sorted portion (`prev = i - 1` down to `0`).
* **Shift** all elements greater than `curr` one position to the right to create an empty slot.
* Insert `curr` into its correct sorted position: `arr[prev + 1] = curr`.
* **Time Complexity:**
* Worst Case: $\mathcal{O}(n^2)$ (Array sorted in reverse).
* Best Case: $\mathcal{O}(n)$ (Array already sorted, inner `while` condition fails immediately).


* **Space Complexity:** $\mathcal{O}(1)$ auxiliary.

---

### 5. Algorithm Comparison Matrix

| Property | Bubble Sort | Selection Sort | Insertion Sort |
| --- | --- | --- | --- |
| **Worst-Case Time** | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ |
| **Best-Case Time** | $\mathcal{O}(n)$ (with flag) | $\mathcal{O}(n^2)$ | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Swaps per Pass** | Multiple adjacent swaps | Exactly 1 swap per pass | No full swaps (element shifts) |
| **Stability** | Stable | Unstable (by default) | Stable |

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Bubble Sort Step-by-Step (Pass 1 of `[4, 1, 5, 2, 3]`)

```text
Initial Array: [ 4,  1,  5,  2,  3 ]

Step 1: Compare (4, 1) -> 4 > 1 -> Swap!
        [ 1,  4,  5,  2,  3 ]

Step 2: Compare (4, 5) -> 4 < 5 -> No Swap
        [ 1,  4,  5,  2,  3 ]

Step 3: Compare (5, 2) -> 5 > 2 -> Swap!
        [ 1,  4,  2,  5,  3 ]

Step 4: Compare (5, 3) -> 5 > 3 -> Swap!
        [ 1,  4,  2,  3, | 5 | ]  <-- 5 is now at its correct final position!

```

---

### Visual 2: Selection Sort Partition Progression (`[4, 1, 5, 2, 3]`)

```text
Pass 0: Unsorted: [ 4,  1,  5,  2,  3 ] -> Min is 1 (index 1) -> Swap with arr[0]
        Sorted: [ 1 ] | Unsorted: [ 4,  5,  2,  3 ]

Pass 1: Unsorted: [ 4,  5,  2,  3 ]     -> Min is 2 (index 3) -> Swap with arr[1]
        Sorted: [ 1,  2 ] | Unsorted: [ 5,  4,  3 ]

Pass 2: Unsorted: [ 5,  4,  3 ]         -> Min is 3 (index 4) -> Swap with arr[2]
        Sorted: [ 1,  2,  3 ] | Unsorted: [ 4,  5 ]

Pass 3: Unsorted: [ 4,  5 ]             -> Min is 4 (index 3) -> Already in place
        Sorted: [ 1,  2,  3,  4,  5 ]

```

---

### Visual 3: Insertion Sort Card Insertion Mechanism (`curr = 2`)

```text
Current State: Sorted = [ 1, 4, 5 ], Unsorted = [ 2, 3 ]
               curr = 2, prev points to 5

Step 1: 5 > 2 -> Shift 5 to the right:
        [ 1,  4,  _ ,  5,  3 ]   (prev moves to 4)

Step 2: 4 > 2 -> Shift 4 to the right:
        [ 1,  _ ,  4,  5,  3 ]   (prev moves to 1)

Step 3: 1 < 2 -> Stop shifting!
        Insert curr (2) at prev + 1 (index 1):
        [ 1,  2,  4,  5,  3 ]

```

---


---

## 📝 Section 4: Homework Exercises & Practice Questions

### Exercise 1: Sort in Descending Order

Modify all three algorithms to sort an array in **descending (decreasing) order** without writing new functions from scratch.

* **Rule change for Bubble Sort:** In `arr[j] > arr[j + 1]`, change `>` to `<`.
* **Rule change for Selection Sort:** In `arr[j] < arr[smallestIdx]`, change `<` to `>`.
* **Rule change for Insertion Sort:** In `arr[prev] > curr`, change `>` to `<`.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSortDescending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        // Shift elements smaller than curr
        while (prev >= 0 && arr[prev] < curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

int main() {
    int arr[] = {4, 1, 5, 2, 3};
    int n = 5;
    insertionSortDescending(arr, n);

    cout << "Descending Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl; // Output: 5 4 3 2 1
    return 0;
}

```

---

### Exercise 2: Sort an Array of Characters

Demonstrate that these sorting algorithms work on character arrays/strings using their ASCII order.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortCharacters(vector<char>& chArr) {
    int n = chArr.size();
    for (int i = 1; i < n; i++) {
        char curr = chArr[i];
        int prev = i - 1;

        while (prev >= 0 && chArr[prev] > curr) {
            chArr[prev + 1] = chArr[prev];
            prev--;
        }
        chArr[prev + 1] = curr;
    }
}

int main() {
    vector<char> chArr = {'f', 'b', 'a', 'e', 'c', 'd'};
    sortCharacters(chArr);

    cout << "Sorted Characters: ";
    for (char c : chArr) cout << c << " ";
    cout << endl; // Output: a b c d e f
    return 0;
}

```
