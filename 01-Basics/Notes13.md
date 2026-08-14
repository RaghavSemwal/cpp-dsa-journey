# Complete Lecture Notes: Binary Exponentiation `pow(x, n)` & Best Time to Buy and Sell Stock



---

## 📌 Section 1: Detailed Chapter Notes & Algorithmic Concepts

### 1. Problem 1: Compute $x^n$ (LeetCode #50 - Pow(x, n))

#### A. Problem Statement & Constraints:

Calculate $x$ raised to the power $n$ ($x^n$).

* Input: `double x`, `int n`
* Constraints: $-100.0 < x < 100.0$, $-2^{31} \le n \le 2^{31}-1$ ($n$ is a signed 32-bit integer).

---

#### B. Why Naive Multiplication $\mathcal{O}(n)$ Fails:

* **Naive Approach:** Multiplying $x$ by itself $n$ times using a loop takes $\mathcal{O}(n)$ operations.
* **Why it causes TLE (Time Limit Exceeded):** The maximum value of $n$ is $2^{31}-1 \approx 2.14 \times 10^9$. Since online judges only allow $\approx 10^8$ operations per second, an $\mathcal{O}(n)$ algorithm will time out.

---

#### C. Optimal Approach: Binary Exponentiation $\mathcal{O}(\log n)$

##### Mathematical Foundation:

Every decimal integer $n$ can be represented in binary with at most $\lfloor \log_2 n \rfloor + 1$ bits.

* For example, $n = 5 = 101_2 = 2^2 + 2^0 = 4 + 1$.
* Therefore:

$$x^5 = x^{(101)_2} = x^4 \cdot x^0 \cdot x^1 = x^4 \cdot 1 \cdot x^1 = x^5$$



##### Key Idea (Repeated Squaring):

Instead of computing powers one by one, we compute successive squares of $x$:

* Step 0: $x^1 = x$
* Step 1: $x^2 = x^1 \cdot x^1$
* Step 2: $x^4 = x^2 \cdot x^2$
* Step 3: $x^8 = x^4 \cdot x^4$

Whenever the current binary bit of $n$ is `1` (i.e., `n % 2 == 1`), we multiply the running `ans` by the current power of $x$. In every step, we square $x$ (`x *= x`) and shift the binary power rightward (`n /= 2`).

##### Handling Negative Powers ($n < 0$) & Edge Cases:

1. If $n < 0$: $x^{-n} = \left(\frac{1}{x}\right)^n$. We invert $x \to \frac{1}{x}$ and negate $n \to -n$.
2. **Integer Overflow on Negation:** When $n = -2^{31}$, $-n = 2^{31}$, which overflows a 32-bit signed `int` (max value $2^{31}-1$). Store $n$ in a `long long` to prevent overflow.
3. Special Cases:
* $n = 0 \implies 1.0$
* $x = 0.0 \implies 0.0$
* $x = 1.0 \implies 1.0$
* $x = -1.0 \implies +1.0$ if $n$ is even, $-1.0$ if $n$ is odd.



---

### 2. Problem 2: Best Time to Buy and Sell Stock (LeetCode #121)

#### A. Problem Statement:

You are given an array `prices` where `prices[i]` is the price of a given stock on the $i^{\text{th}}$ day. You want to maximize your profit by choosing a **single day to buy** one stock and choosing a **different day in the future to sell** that stock. Return the maximum profit. If no profit can be achieved, return `0`.

---

#### B. Dynamic Min-Tracking (Single-Pass Greedy Approach):

* **Core Insight:** "Imagine every day as a potential selling day."
* To maximize profit when selling on day $i$, you must have bought the stock on the day with the **minimum price prior to day $i$** (the `bestBuy` price).
* **Algorithm Steps:**
1. Initialize `maxProfit = 0` and `bestBuy = prices[0]`.
2. Iterate through each day starting from day 1 (`i = 1` to `n - 1`):
* If `prices[i] > bestBuy`: Potential profit is `prices[i] - bestBuy`. Update `maxProfit = max(maxProfit, prices[i] - bestBuy)`.
* Update `bestBuy` for future days: `bestBuy = min(bestBuy, prices[i])`.


3. Return `maxProfit`.


* **Time Complexity:** $\mathcal{O}(n)$ — Single pass through array.
* **Space Complexity:** $\mathcal{O}(1)$ — Constant auxiliary variables.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Binary Exponentiation Execution ($3^5 \implies 3^{(101)_2}$)

```text
n = 5  --> Binary representation: [ 1 ][ 0 ][ 1 ]
                                    ^    ^    ^
Bit Weight:                        2^2  2^1  2^0
Power of Base (x):                 x^4  x^2  x^1
                                  (81)  (9)  (3)

Step-by-Step State:
Initial: ans = 1.0,  x = 3,  binForm = 5 (101_2)

Iteration 1:
  - Last Bit = 5 % 2 = 1 (Odd)  --> ans = ans * x = 1 * 3 = 3
  - Square Base: x = x * x = 3 * 3 = 9 (x^2)
  - Shift Power: binForm = 5 / 2 = 2 (010_2)

Iteration 2:
  - Last Bit = 2 % 2 = 0 (Even) --> ans unchanged (3)
  - Square Base: x = x * x = 9 * 9 = 81 (x^4)
  - Shift Power: binForm = 2 / 2 = 1 (001_2)

Iteration 3:
  - Last Bit = 1 % 2 = 1 (Odd)  --> ans = ans * x = 3 * 81 = 243
  - Square Base: x = 81 * 81 = 6561
  - Shift Power: binForm = 1 / 2 = 0 (Terminates)

Final Result = 243 (Computed in 3 iterations instead of 5!)

```

---

### Visual 2: Buy & Sell Stock Tracking (`prices = [7, 1, 5, 3, 6, 4]`)

```text
Day (i) | Price | bestBuy (Before) | Today's Profit (Price - bestBuy) | maxProfit | bestBuy (Updated)
--------+-------+------------------+----------------------------------+-----------+-------------------
   0    |   7   |        -         |                -                 |     0     |         7
   1    |   1   |        7         |          1 - 7 = -6 (No Sell)    |     0     | min(7, 1) = 1
   2    |   5   |        1         |          5 - 1 = +4              |     4     | min(1, 5) = 1
   3    |   3   |        1         |          3 - 1 = +2              |     4     | min(1, 3) = 1
   4    |   6   |        1         |          6 - 1 = +5              |     5     | min(1, 6) = 1
   5    |   4   |        1         |          4 - 1 = +3              |     5     | min(1, 4) = 1

Maximum Profit Achieved = 5 (Buy at Day 1 [Price 1], Sell at Day 4 [Price 6])

```

---

### Visual 3: Stock Price Trajectory Graph

```text
Price
  8 |   (Day 0: 7)
  7 |    *
  6 |                   * (Day 4: 6 - SELL HERE)
  5 |             *
  4 |                             *
  3 |                   *
  2 |
  1 |         * (Day 1: 1 - BUY HERE)
  0 +---------------------------------
       Day 0  Day 1 Day 2 Day 3 Day 4 Day 5
       
       Profit = Peak (6) - Trough (1) = +5

```

