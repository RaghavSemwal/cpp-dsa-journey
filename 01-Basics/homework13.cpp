---

## 📝 Section 4: Homework Exercises & Practice Questions

### Exercise 1: Modular Exponentiation $(x^n \pmod M)$

When calculating large powers, values often exceed standard integer ranges. Calculate $(x^n) \pmod M$ in $\mathcal{O}(\log n)$ time using properties of modular arithmetic:


$$(A \cdot B) \pmod M = \bigl((A \pmod M) \cdot (B \pmod M)\bigr) \pmod M$$

```cpp
#include <iostream>
using namespace std;

long long modularPow(long long x, long long n, long long M) {
    long long ans = 1;
    x = x % M; // Update x if it is more than or equal to M

    while (n > 0) {
        if (n & 1) { // If n is odd
            ans = (ans * x) % M;
        }
        x = (x * x) % M; // Square base modulo M
        n >>= 1;         // Divide n by 2
    }
    return ans;
}

int main() {
    long long x = 2, n = 10, M = 1000000007;
    cout << "2^10 % (10^9 + 7) = " << modularPow(x, n, M) << endl;
    return 0;
}

```

---

### Exercise 2: Best Time to Buy and Sell Stock II (LeetCode #122)

**Problem:** You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times on different days). Find the maximum profit.

#### Strategy:

Capture every positive daily price difference: if `prices[i] > prices[i-1]`, add `prices[i] - prices[i-1]` to profit.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int maxProfitMultipleTransactions(const vector<int>& prices) {
    int totalProfit = 0;
    for (size_t i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            totalProfit += (prices[i] - prices[i - 1]);
        }
    }
    return totalProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit with Multiple Transactions: " 
         << maxProfitMultipleTransactions(prices) << endl; 
    // Expected: (5-1) + (6-3) = 4 + 3 = 7
    return 0;
}

