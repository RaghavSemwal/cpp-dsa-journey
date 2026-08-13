# Complete Lecture Notes: Time & Space Complexity



---

## 📌 Section 1: Comprehensive Theoretical Notes & Mathematical Foundations

### 1. What is Time Complexity?

**Time Complexity** is **NOT** the actual physical execution time taken by a program (e.g., $0.05$ seconds). Physical time depends on machine hardware, CPU load, and server specifications.

* **Definition:** Time Complexity measures the **amount of time/operations taken by an algorithm as a function of the input size ($n$)**.
* **Primary Goal:** It evaluates how an algorithm's performance scales when the input size $n$ grows very large ($n \to \infty$).

---

### 2. Asymptotic Notations

#### A. Big-O Notation ($\mathcal{O}$) — Worst Case / Upper Bound

* Represents the maximum number of operations an algorithm will perform in the **worst-case scenario**.
* **Definition:** $f(n) = \mathcal{O}(g(n))$ if there exist positive constants $c$ and $n_0$ such that:

$$0 \le f(n) \le c \cdot g(n) \quad \text{for all } n \ge n_0$$


* **Primary Focus:** $99\%$ of coding assessments, platforms (LeetCode, CodeChef), and technical interviews focus exclusively on Big-O Notation.

#### B. Big-Omega Notation ($\Omega$) — Best Case / Lower Bound

* Represents the minimum number of operations an algorithm will perform.
* **Definition:** $f(n) = \Omega(g(n))$ if $0 \le c \cdot g(n) \le f(n)$ for all $n \ge n_0$.

#### C. Big-Theta Notation ($\Theta$) — Average Case / Tight Bound

* Represents the exact/average bound of an algorithm.
* **Definition:** $f(n) = \Theta(g(n))$ if $c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n)$ for all $n \ge n_0$.

---

### 3. Simplified Rules for Calculating Big-O

1. **Drop Low-Order Terms:** Ignore less significant terms as $n \to \infty$.

$$\mathcal{O}(n^2 + n + 5) \longrightarrow \mathcal{O}(n^2)$$


2. **Drop Constant Factors:** Multiplicative and additive constants do not affect asymptotic growth.

$$\mathcal{O}(4n^3 + 100n) \longrightarrow \mathcal{O}(n^3)$$



---

### 4. What is Space Complexity?

Space Complexity measures the **total memory allocated by an algorithm as a function of the input size ($n$)**.

$$\text{Space Complexity} = \text{Input Space} + \text{Auxiliary Space}$$

* **Auxiliary Space:** The extra/temporary memory used by the algorithm (e.g., dynamic vectors, call stacks) excluding the input data structure itself.
* **In-Place Algorithms:** Algorithms that operate directly on the input structure using $\mathcal{O}(1)$ auxiliary space (e.g., Two-Pointer Array Reversal).

---

### 5. Hierarchy of Time Complexities

Ordered from **Most Efficient (Fastest)** to **Least Efficient (Slowest)**:

$$\mathcal{O}(1) < \mathcal{O}(\log n) < \mathcal{O}(\sqrt{n}) < \mathcal{O}(n) < \mathcal{O}(n \log n) < \mathcal{O}(n^2) < \mathcal{O}(n^3) < \mathcal{O}(2^n) < \mathcal{O}(n!)$$

---

### 6. Time Complexity in Recursion

To analyze recursive functions, use one of two primary methods:

#### Method 1: Recursive Tree Approach

$$\text{Total Time Complexity} = (\text{Total Number of Recursive Nodes/Calls}) \times (\text{Work Done per Call})$$

#### Method 2: Recurrence Relations

Express the total running time $T(n)$ in terms of subproblems:

* **Factorial / Linear Search:** $T(n) = T(n-1) + \mathcal{O}(1) \implies \mathcal{O}(n)$
* **Binary Search:** $T(n) = T(n/2) + \mathcal{O}(1) \implies \mathcal{O}(\log n)$
* **Merge Sort:** $T(n) = 2T(n/2) + \mathcal{O}(n) \implies \mathcal{O}(n \log n)$
* **Fibonacci (Naive):** $T(n) = T(n-1) + T(n-2) + \mathcal{O}(1) \implies \mathcal{O}(2^n)$

#### Space Complexity in Recursion:

$$\text{Auxiliary Space} = (\text{Max Depth of Call Stack / Height of Tree}) \times (\text{Memory per Frame})$$

---

### 7. Practical Industry Guidelines: Constraints to Target Time Complexity

Online platforms (LeetCode, HackerRank) enforce a **1-second execution limit**, which allows approximately **$10^8$ operations per second**.

| Input Constraint ($n$) | Maximum Allowed Time Complexity | Typical Algorithms / Approaches |
| --- | --- | --- |
| $n \le 10$ or $n \le 12$ | $\mathcal{O}(n!)$ or $\mathcal{O}(n^2 \cdot 2^n)$ | Backtracking, Brute Force Permutations (N-Queens, Traveling Salesperson) |
| $n \le 20 \dots 25$ | $\mathcal{O}(2^n)$ | Recursion, Subset Generation, Bitmask DP |
| $n \le 500$ | $\mathcal{O}(n^3)$ | Floyd-Warshall, Matrix Multiplication, 3D Dynamic Programming |
| $n \le 5000$ | $\mathcal{O}(n^2)$ | Bubble/Selection Sort, Two-Pointer (Nested), 2D Dynamic Programming |
| $n \le 10^5 \dots 10^6$ | $\mathcal{O}(n \log n)$ or $\mathcal{O}(n)$ | Merge Sort, Quick Sort, Binary Search, Kadane's, Hash Maps |
| $n \le 10^8$ | $\mathcal{O}(n)$ | Single-Pass Loop, Linear Search |
| $n \le 10^{18}$ | $\mathcal{O}(\log n)$ or $\mathcal{O}(1)$ | Binary Search, Bit Manipulation, Math Formulas, Matrix Exponentiation |

---

## 📊 Section 2: Markdown Visual Diagrams & Charts

### Visual 1: Growth Rate Comparison (Operations vs Input Size $n$)

```text
Operations (Y-axis)
  |                                        . (n!)
  |                                     .  
  |                                  . (2^n)
  |                               . 
  |                            . (n^2)
  |                         .
  |                      . (n log n)
  |                   .
  |                . (n)
  |             . 
  |          . (sqrt(n))
  |       . (log n)
  |_______________________________________ (O(1) - Constant)
  +---------------------------------------------> Input Size 'n' (X-axis)

```

---

### Visual 2: Recursion Call Stack Depth vs. Width (Fibonacci $n=4$)

```text
                                  f(4)                  <-- Level 0 (2^0 = 1 node)
                                /      \
                             f(3)      f(2)             <-- Level 1 (2^1 = 2 nodes)
                            /    \    /    \
                         f(2)   f(1) f(1)  f(0)         <-- Level 2 (2^2 = 4 nodes)
                        /    \
                     f(1)   f(0)                        <-- Level 3 (Max Stack Depth = n)

  Tree Depth = n = 4  ====>  Space Complexity = O(n) (Call Stack Height)
  Total Nodes = 2^n - 1 ====> Time Complexity  = O(2^n) (Total Computations)

```

---

### Visual 3: Merge Sort Subdivision Mechanics ($n=8$)

```text
 Level 0:               [ 8 | 4 | 2 | 1 | 7 | 6 | 3 | 5 ]         ---> Work = O(n)
                                  /            \
 Level 1:         [ 8 | 4 | 2 | 1 ]        [ 7 | 6 | 3 | 5 ]      ---> Work = O(n)
                     /         \              /         \
 Level 2:      [ 8 | 4 ]     [ 2 | 1 ]   [ 7 | 6 ]    [ 3 | 5 ]   ---> Work = O(n)
                /     \       /     \     /     \      /     \
 Level 3:     [8]    [4]     [2]    [1]  [7]    [6]   [3]    [5]  ---> Base Cases

  Height of Tree = log2(n) Levels
  Work per Level = O(n)
  Total Time Complexity = O(n * log2(n)) = O(n log n)

```

---

## 💻 Section 3: Comprehensive C++ Code Examples

Below are C++ examples demonstrating different time and space complexity classes, documented with inline explanations.


---

## 📝 Section 4: Homework Exercises & Practice Questions

### Exercise 1: Compare $\mathcal{O}(\sqrt{n})$ vs $\mathcal{O}(\log n)$

#### Question:

Which time complexity is asymptotically more efficient: $\mathcal{O}(\sqrt{n})$ or $\mathcal{O}(\log n)$? Prove mathematically using $n = 10^6$.

#### Mathematical Proof:

For $n = 10^6 = 1,000,000$:

* **$\mathcal{O}(\sqrt{n})$:**

$$\sqrt{10^6} = 10^3 = 1,000 \text{ operations}$$


* **$\mathcal{O}(\log_2 n)$:**

$$\log_2(10^6) = 6 \cdot \log_2(10) \approx 6 \times 3.32 = 19.92 \approx 20 \text{ operations}$$



**Conclusion:** $\mathcal{O}(\log n)$ is significantly more efficient than $\mathcal{O}(\sqrt{n})$.

---

### Exercise 2: Determine Complexities for Code Snippets

#### Code Snippet A:

```cpp
void snippetA(int n) {
    for (int i = 1; i <= n; i *= 2) {
        cout << i << " ";
    }
}

```

* **Analysis:** In each iteration, $i$ doubles ($1, 2, 4, 8, \dots, 2^k$). The loop terminates when $2^k > n \implies k = \log_2 n$.
* **Time Complexity:** $\mathcal{O}(\log n)$
* **Space Complexity:** $\mathcal{O}(1)$

---

#### Code Snippet B:

```cpp
void snippetB(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
    }
}

```

* **Analysis:** Total inner loop executions:

$$0 + 1 + 2 + 3 + \dots + (n - 1) = \frac{n(n - 1)}{2} = \frac{n^2 - n}{2}$$


* **Time Complexity:** $\mathcal{O}(n^2)$
* **Space Complexity:** $\mathcal{O}(1)$

---

#### Code Snippet C:

```cpp
void snippetC(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j *= 2) {
            cout << "*";
        }
    }
}

```

* **Analysis:**
* Outer loop runs $n$ times.
* Inner loop doubles $j$ each time, running $\log_2 n$ times.


* **Time Complexity:** $\mathcal{O}(n \log n)$
* **Space Complexity:** $\mathcal{O}(1)$

---

### Exercise 3: Target Complexity Identification from Constraints

Given a coding problem where the input array length constraint is **$N \le 2 \times 10^5$**:

1. Will a solution with time complexity $\mathcal{O}(N^2)$ pass within the $1$-second limit?
2. What is the maximum acceptable time complexity?

#### Solution:

1. For $N = 2 \times 10^5$, $N^2 = (2 \times 10^5)^2 = 4 \times 10^{10}$ operations. Since $4 \times 10^{10} \gg 10^8$, an $\mathcal{O}(N^2)$ solution will **Time Limit Exceeded (TLE)**.
2. An $\mathcal{O}(N \log N)$ solution will execute approximately:

$$2 \times 10^5 \times \log_2(2 \times 10^5) \approx 2 \times 10^5 \times 18 = 3.6 \times 10^6 \text{ operations}$$



Since $3.6 \times 10^6 \ll 10^8$, an **$\mathcal{O}(N \log N)$ or $\mathcal{O}(N)$ solution** is required.