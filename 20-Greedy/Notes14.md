# Complete Lecture Notes: Container With Most Water (LeetCode #11)



---

## 📌 Section 1: Problem Statement & Algorithmic Concepts

### 1. Problem Overview

You are given an integer array `height` of length $n$. There are $n$ vertical lines drawn such that the two endpoints of the $i^{\text{th}}$ line are $(i, 0)$ and $(i, \text{height}[i])$.

* **Goal:** Find two lines that together with the x-axis form a container, such that the container contains the **maximum amount of water**.
* **Return:** The maximum area of water a container can store.
* **Constraint Note:** You may not slant the container (the water surface is parallel to the x-axis).

---

### 2. Mathematical Modeling of the Container

For any two vertical lines chosen at index $i$ (left boundary) and index $j$ (right boundary, where $j > i$):

1. **Width ($\text{Width}$):**

$$\text{Width} = j - i$$


2. **Height ($\text{Height}$):**
Water cannot overflow the shorter bar, so the effective height is governed by the **minimum of the two boundary heights**:

$$\text{Height} = \min(\text{height}[i], \text{height}[j])$$


3. **Water Volume / 2D Area ($\text{Area}$):**

$$\text{Water Area} = \text{Width} \times \text{Height} = (j - i) \times \min(\text{height}[i], \text{height}[j])$$



---

### 3. Approach 1: Brute Force Approach $\mathcal{O}(n^2)$

#### Strategy:

* Generate all possible pairs of vertical lines using two nested loops:
* Outer loop selects left boundary `lp` from `0` to `n - 1`.
* Inner loop selects right boundary `rp` from `lp + 1` to `n - 1`.


* For every pair, compute `currentWater = (rp - lp) * min(height[lp], height[rp])` and update `maxWater`.

#### Complexity & Why it Fails:

* **Time Complexity:** $\mathcal{O}(n^2)$
* **Space Complexity:** $\mathcal{O}(1)$
* **TLE Analysis:** Constraints give $n \le 10^5$. For $n = 10^5$, $\mathcal{O}(n^2) = (10^5)^2 = 10^{10}$ operations. Since online platforms enforce a limit of $\approx 10^8$ operations per second, this approach results in a **Time Limit Exceeded (TLE)** error.

---

### 4. Approach 2: Optimal Two-Pointer Technique $\mathcal{O}(n)$

#### Core Intuition:

1. **Initial State (Maximize Width):** Start with the widest possible container by placing `lp = 0` (leftmost bar) and `rp = n - 1` (rightmost bar).
2. **The Decision Rule (Which Pointer to Move?):**
* As we move pointers inward, the container width **always decreases** by 1 ($\text{Width} \to \text{Width} - 1$).
* To have any chance of finding a container with a **larger area**, the **height must increase** to compensate for the lost width.
* Since height is bottlenecked by the **shorter line** ($\min(\text{height}[lp], \text{height}[rp])$):
* If we move the taller line inward, the height is still constrained by the shorter line, and width is smaller $\implies$ Area **strictly decreases** or remains smaller.
* Therefore, to find a potentially taller boundary, we **must discard the shorter line**:
* If `height[lp] < height[rp]`: Move left pointer $\implies$ `lp++`.
* Else (`height[rp] <= height[lp]`): Move right pointer $\implies$ `rp--`.







---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Container Dimensions & Water Bottleneck

```text
Height
  8 |          [rp = 8]  |===================|  (Water line = min(6, 8) = 6)
  7 |                    |~~~~~~~~~~~~~~~~~~~|
  6 | [lp = 6] |=========|~~~~~~~~~~~~~~~~~~~|
  5 |          |         |~~~~~~~~~~~~~~~~~~~|
  4 |          |         |~~~~~~~~~~~~~~~~~~~|
  3 |          |         |~~~~~~~~~~~~~~~~~~~|
  2 |          |         |~~~~~~~~~~~~~~~~~~~|
  1 |          |         |~~~~~~~~~~~~~~~~~~~|
  0 +----------+---------+-------------------+--------
             Index 1   Index 2             Index 4

   Width = 4 - 1 = 3
   Height = min(6, 8) = 6
   Water Area = 3 * 6 = 18 units^2

```

---

### Visual 2: Step-by-Step Two-Pointer Trace (`height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`)

```text
Step |  lp  |  rp  | height[lp] | height[rp] | Width (rp - lp) | Min Height | Water Area | Max Water | Action / Shift
-----+------+------+------------+------------+-----------------+------------+------------+-----------+-----------------------
  1  |  0   |  8   |     1      |     7      |    8 - 0 = 8    |     1      |   8*1 = 8  |     8     | height[0] < height[8] -> lp++
  2  |  1   |  8   |     8      |     7      |    8 - 1 = 7    |     7      |  7*7 = 49  |    49     | height[8] < height[1] -> rp--
  3  |  1   |  7   |     8      |     3      |    7 - 1 = 6    |     3      |  6*3 = 18  |    49     | height[7] < height[1] -> rp--
  4  |  1   |  6   |     8      |     8      |    6 - 1 = 5    |     8      |  5*8 = 40  |    49     | Equal heights -> rp-- (or lp++)
  5  |  1   |  5   |     8      |     4      |    5 - 1 = 4    |     4      |  4*4 = 16  |    49     | height[5] < height[1] -> rp--
  6  |  1   |  4   |     8      |     5      |    4 - 1 = 3    |     5      |  3*5 = 15  |    49     | height[4] < height[1] -> rp--
  7  |  1   |  3   |     8      |     2      |    3 - 1 = 2    |     2      |   2*2 = 4  |    49     | height[3] < height[1] -> rp--
  8  |  1   |  2   |     8      |     6      |    2 - 1 = 1    |     6      |   1*6 = 6  |    49     | height[2] < height[1] -> rp--
  9  |  1   |  1   |    ---     |    ---     |       ---       |    ---     |    ---     |    49     | lp == rp -> Terminate loop!

Final Maximum Water Capacity = 49 (Formed between index 1 and index 8)

```

---

### Visual 3: Two-Pointer Convergence Mechanics

```text
Start:  [ 1 ][ 8 ][ 6 ][ 2 ][ 5 ][ 4 ][ 8 ][ 3 ][ 7 ]
          ^                                       ^
         lp=0 (1) < rp=8 (7) -> Move lp         rp=8

Shift:  [ 1 ][ 8 ][ 6 ][ 2 ][ 5 ][ 4 ][ 8 ][ 3 ][ 7 ]
               ^                                  ^
              lp=1 (8) > rp=8 (7) -> Move rp    rp=8

Shift:  [ 1 ][ 8 ][ 6 ][ 2 ][ 5 ][ 4 ][ 8 ][ 3 ][ 7 ]
               ^                              ^
              lp=1                            rp=7 (3)
              ...
              ... Converges inward in O(n) steps

```

---

## 📝 Section 4: Homework Exercises & Related Practice

### Exercise 1: Trapping Rain Water vs. Container With Most Water (Conceptual Comparison)

| Dimension | Container With Most Water (LeetCode #11) | Trapping Rain Water (LeetCode #42) |
| --- | --- | --- |
| **Objective** | Find **two single lines** that maximize a single 2D rectangular water container. | Calculate total water trapped **across all intermediate cavities** between bars after rainfall. |
| **Geometry** | 1 single large bounding container. | Sum of multiple local height differences ($\min(\text{leftMax}, \text{rightMax}) - \text{height}[i]$). |
| **Technique** | Two-Pointer converging inward. | Two-Pointer / Stack / Prefix-Suffix arrays. |

---

### Exercise 2: Return the Exact Indices of the Max Container

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> getMaxContainerIndices(const vector<int>& height) {
    int maxWater = 0;
    int lp = 0, rp = height.size() - 1;
    int bestL = 0, bestR = 0;

    while (lp < rp) {
        int width = rp - lp;
        int h = min(height[lp], height[rp]);
        int currentWater = width * h;

        if (currentWater > maxWater) {
            maxWater = currentWater;
            bestL = lp;
            bestR = rp;
        }

        if (height[lp] < height[rp]) {
            lp++;
        } else {
            rp--;
        }
    }

    return {bestL, bestR};
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto indices = getMaxContainerIndices(height);

    cout << "Best Container Left Index  : " << indices.first << " (Height: " << height[indices.first] << ")" << endl;
    cout << "Best Container Right Index : " << indices.second << " (Height: " << height[indices.second] << ")" << endl;
    cout << "Max Water Capacity         : " << (indices.second - indices.first) * min(height[indices.first], height[indices.second]) << endl;

    return 0;
}

```