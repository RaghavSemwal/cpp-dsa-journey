
// ---

// ## 💻 Section 3: Comprehensive C++ Code Implementation

// Below is an executable C++ file containing complete implementations of both algorithms with full test cases and comments.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// 1. BINARY EXPONENTIATION: pow(x, n)
// LeetCode #50
// Time Complexity: O(log N)
// Space Complexity: O(1)
// ==========================================
double myPow(double x, int n) {
    // Corner Cases Optimization
    if (n == 0) return 1.0;
    if (x == 0.0) return 0.0;
    if (x == 1.0) return 1.0;
    if (x == -1.0 && n % 2 == 0) return 1.0;
    if (x == -1.0 && n % 2 != 0) return -1.0;

    // Use long long to avoid overflow when n = -2^31
    long long binForm = n;

    // Handle Negative Exponents: x^(-n) = (1/x)^n
    if (binForm < 0) {
        x = 1.0 / x;
        binForm = -binForm;
    }

    double ans = 1.0;

    while (binForm > 0) {
        if (binForm % 2 == 1) { // If current binary bit is 1
            ans *= x;
        }
        x *= x;           // Square the base: x^1 -> x^2 -> x^4 -> x^8 ...
        binForm /= 2;     // Right shift binary power (divide by 2)
    }

    return ans;
}

// ==========================================
// 2. BEST TIME TO BUY AND SELL STOCK
// LeetCode #121
// Time Complexity: O(N)
// Space Complexity: O(1)
// ==========================================
int maxProfit(const vector<int>& prices) {
    if (prices.empty()) return 0;

    int maxProf = 0;
    int bestBuy = prices[0]; // Minimum price seen so far

    for (size_t i = 1; i < prices.size(); i++) {
        if (prices[i] > bestBuy) {
            // If selling today yields a profit
            maxProf = max(maxProf, prices[i] - bestBuy);
        }
        // Update best buying price for future selling days
        bestBuy = min(bestBuy, prices[i]);
    }

    return maxProf;
}

// ==========================================
// MAIN FUNCTION (Demonstration & Verification)
// ==========================================
int main() {
    cout << "========================================" << endl;
    cout << "--- 1. BINARY EXPONENTIATION DEMO ---" << endl;
    cout << "========================================" << endl;

    cout << "3^5    = " << myPow(3.0, 5) << " (Expected: 243)" << endl;
    cout << "2^10   = " << myPow(2.0, 10) << " (Expected: 1024)" << endl;
    cout << "2^(-2) = " << myPow(2.0, -2) << " (Expected: 0.25)" << endl;
    cout << "(-2)^3 = " << myPow(-2.0, 3) << " (Expected: -8)" << endl;

    cout << "\n========================================" << endl;
    cout << "--- 2. BUY & SELL STOCK DEMO ---" << endl;
    cout << "========================================" << endl;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Prices: [7, 1, 5, 3, 6, 4]" << endl;
    cout << "Maximum Profit: " << maxProfit(prices1) << " (Expected: 5)" << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "\nPrices (Downward Trend): [7, 6, 4, 3, 1]" << endl;
    cout << "Maximum Profit: " << maxProfit(prices2) << " (Expected: 0)" << endl;

    return 0;
}

