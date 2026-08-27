# Complete Lecture Notes: Aggressive Cows Problem



---

## 📌 Section 1: Problem Overview & Core Concepts

### 1. Problem Statement (Classic SPOJ / GFG / CodeStudio Problem)

You are given an array of integers `stalls` of size $n$, representing the coordinates/positions of $n$ stalls along a straight line, and an integer $C$ (number of aggressive cows, $C \le n$).

* **Constraint:** Each stall can house at most one cow.
* **Aggressive Property:** The cows are aggressive and may fight if placed too close to one another.
* **Goal:** Assign stalls to all $C$ cows such that the **minimum distance between any two cows is as large as possible** (**Maximize the Minimum Distance**).
* **Return:** The **largest possible minimum distance**.

---

### 2. Paradigm: "Max-Min" Optimization via Binary Search on Answer Range

This problem completes the **Min-Max / Max-Min Triad** in Binary Search:

1. **Book Allocation (Lecture 21):** Minimize the Maximum Pages.
2. **Painter's Partition (Lecture 22):** Minimize the Maximum Time.
3. **Aggressive Cows (Lecture 23):** **Maximize the Minimum Distance**.

---

### 3. Step 1: Sorting the Stall Coordinates

Before applying any distance calculations, the `stalls` array **must be sorted in ascending order**:


$$\text{stalls} = [1, 2, 8, 4, 9] \xrightarrow{\text{Sort}} [1, 2, 4, 8, 9]$$

* **Why?** Placement must happen sequentially along the physical 1D number line so that contiguous distance differences $(\text{stalls}[i] - \text{lastStallPos})$ can be measured accurately.

---

### 4. Step 2: Defining the Search Space (Answer Range)

1. **Lower Bound (`st`):**
* The minimum conceivable distance between two cows placed in adjacent unit coordinates is:

$$\text{st} = 1$$




2. **Upper Bound (`end`):**
* The maximum conceivable distance occurs when 2 cows are placed at the extreme ends of the sorted stall line:

$$\text{end} = \text{stalls}[n-1] - \text{stalls}[0]$$



*(For $[1, 2, 4, 8, 9]$, $\text{end} = 9 - 1 = 8$)*



The answer range $[1, \text{stalls}[n-1] - \text{stalls}[0]]$ is **naturally sorted and monotonic**, allowing Binary Search.

---

### 5. Step 3: Feasibility Check (`isPossible` Greedy Function)

Given a candidate minimum distance `mid`:

1. Always place the **first cow in the very first stall**:

$$\text{cowsPlaced} = 1, \quad \text{lastStallPos} = \text{stalls}[0]$$


2. Iterate through stalls $i = 1 \to n - 1$:
* Check if the distance from the last placed cow satisfies the candidate minimum distance:

$$\text{stalls}[i] - \text{lastStallPos} \ge \text{mid}$$


* If satisfied:
* Place the next cow here: $\text{cowsPlaced}++$
* Update $\text{lastStallPos} = \text{stalls}[i]$


* If $\text{cowsPlaced} == C$ at any point, return `true` immediately.


3. If the loop finishes with $\text{cowsPlaced} < C$, return `false`.

---

### 6. Binary Search Decision Rules (Maximize Search)

* **If `isPossible(stalls, n, C, mid) == true`:**
* It is feasible to place all $C$ cows with at least `mid` distance apart.
* Record candidate answer: `ans = mid`.
* Since we want the **LARGEST minimum distance**, try for an even bigger distance on the **right** $\implies \text{st} = \text{mid} + 1$.


* **If `isPossible(stalls, n, C, mid) == false`:**
* Distance `mid` is too large to fit $C$ cows.
* Reduce the required distance by searching the **left** $\implies \text{end} = \text{mid} - 1$.



---

### 7. Complexity Analysis

* **Sorting Step:** $\mathcal{O}(n \log n)$
* **Binary Search Step:** $\mathcal{O}(n \cdot \log(\text{Range}))$, where $\text{Range} = \text{stalls}[n-1] - \text{stalls}[0]$.
* **Total Time Complexity:** $\mathcal{O}(n \log n + n \log(\text{Range}))$
* **Auxiliary Space Complexity:** $\mathcal{O}(1)$ (In-place search with scalar pointers).

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Number Line Stall Distribution (`stalls = [1, 2, 4, 8, 9]`, $C = 3$)

```text
Stall Coordinates:
  1      2            4                        8      9
 (S1)   (S2)         (S3)                     (S4)   (S5)
--+------+------------+------------------------+------+----> (Position)

Feasible Assignment for min distance = 3:
  [Cow 1]             [Cow 2]                  [Cow 3]
  at 1                at 4                     at 8
  
  Dist(C1, C2) = 4 - 1 = 3 (>= 3)  [OK]
  Dist(C2, C3) = 8 - 4 = 4 (>= 3)  [OK]
  Min Distance = min(3, 4) = 3  <--- Optimal Max-Min Distance!

```

---

### Visual 2: Binary Search Answer Space Convergence

```text
Stalls = [1, 2, 4, 8, 9],  C = 3
Search Space: st = 1, end = 9 - 1 = 8

Iteration 1:
  st = 1, end = 8 -> mid = 1 + (8-1)/2 = 4
  isPossible(4):
    - Cow 1 at 1
    - Cow 2 at 8 (8 - 1 = 7 >= 4)
    - Cow 3 cannot be placed! (Only 2 cows placed < 3)
    -> Result: FALSE (Distance too large) -> end = mid - 1 = 3

Iteration 2:
  st = 1, end = 3 -> mid = 1 + (3-1)/2 = 2
  isPossible(2):
    - Cow 1 at 1
    - Cow 2 at 4 (4 - 1 = 3 >= 2)
    - Cow 3 at 8 (8 - 4 = 4 >= 2)
    -> 3 cows placed! -> Result: TRUE -> ans = 2, st = mid + 1 = 3

Iteration 3:
  st = 3, end = 3 -> mid = 3 + (3-3)/2 = 3
  isPossible(3):
    - Cow 1 at 1
    - Cow 2 at 4 (4 - 1 = 3 >= 3)
    - Cow 3 at 8 (8 - 4 = 4 >= 3)
    -> 3 cows placed! -> Result: TRUE -> ans = 3, st = mid + 1 = 4

Loop Terminates (st > end).
Optimal Answer = 3

```

---

### Visual 3: Summary of the 3 Classic BS on Answer Problems

```text
+-----------------------------------------------------------------------------------+
| Problem             | Search Space Range              | Feasibility | Move Condition     |
+---------------------+---------------------------------+-------------+--------------------+
| Book Allocation     | st = max(arr), end = sum(arr)   | isValid()   | True -> Go Left    |
| (Min-Max)           |                                 |             | (end = mid - 1)    |
+---------------------+---------------------------------+-------------+--------------------+
| Painter's Partition | st = max(arr), end = sum(arr)   | isPossible()| True -> Go Left    |
| (Min-Max)           |                                 |             | (end = mid - 1)    |
+---------------------+---------------------------------+-------------+--------------------+
| Aggressive Cows     | st = 1, end = (max_pos - min_pos)| isPossible()| True -> Go Right   |
| (Max-Min)           |                                 |             | (st = mid + 1)     |
+-----------------------------------------------------------------------------------+

```

---

## 📝 Section 4: Homework Exercises & Practice Problems

### Exercise 1: Magnetic Force Between Two Balls (LeetCode #1552)

**Problem:** In a universe with $n$ baskets at positions `position`, distribute $m$ balls such that the **minimum magnetic force between any two balls is maximized**.

* **Mapping:** Identical to Aggressive Cows.
* `position` $\longleftrightarrow$ `stalls`
* `m` $\longleftrightarrow$ `C` (cows)



```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceBalls(const vector<int>& position, int m, int force) {
    int count = 1;
    int last = position[0];
    for (size_t i = 1; i < position.size(); i++) {
        if (position[i] - last >= force) {
            count++;
            last = position[i];
        }
        if (count == m) return true;
    }
    return false;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int st = 1, end = position.back() - position.front();
    int ans = 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (canPlaceBalls(position, m, mid)) {
            ans = mid;
            st = mid + 1; // Try larger force
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;
    cout << "Max Magnetic Force: " << maxDistance(position, m) << endl; // Output: 3
    return 0;
}

```