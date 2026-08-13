
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ==========================================
// 1. CONSTANT TIME: O(1)
// Space Complexity: O(1)
// ==========================================
int getFirstElement(const vector<int>& arr) {
    return arr[0]; // Execution takes 1 operation regardless of arr size
}

int sumNFormula(int n) {
    return n * (n + 1) / 2; // Fixed arithmetic operations
}

// ==========================================
// 2. LOGARITHMIC TIME: O(log n)
// Binary Search Example
// ==========================================
int binarySearch(const vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) st = mid + 1; // Halves the search space
        else end = mid - 1;
    }
    return -1;
}

// ==========================================
// 3. SQUARE ROOT TIME: O(sqrt(n))
// Optimized Prime Check
// ==========================================
bool isPrimeOptimized(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) { // Loop runs sqrt(n) times
        if (n % i == 0) return false;
    }
    return true;
}

// ==========================================
// 4. LINEAR TIME: O(n)
// Linear Search & Factorial
// ==========================================
long long factorialIterative(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) { // Loop runs n times
        fact *= i;
    }
    return fact;
}

// ==========================================
// 5. QUADRATIC TIME: O(n^2)
// Selection Sort Example
// ==========================================
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {         // Runs n times
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {     // Runs on average n/2 times
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    } // Overall: n * (n - 1) / 2 operations = O(n^2)
}

// ==========================================
// 6. EXPONENTIAL TIME RECURSION: O(2^n)
// Space Complexity: O(n) due to Call Stack
// ==========================================
int fibonacciNaive(int n) {
    if (n <= 1) return n;
    return fibonacciNaive(n - 1) + fibonacciNaive(n - 2); // 2 recursive calls per step
}

// ==========================================
// MAIN FUNCTION DEMONSTRATING COMPLEXITIES
// ==========================================
int main() {
    cout << "--- TIME & SPACE COMPLEXITY EXAMPLES ---" << endl;

    vector<int> sortedArr = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << "O(1) First Element      : " << getFirstElement(sortedArr) << endl;
    cout << "O(log n) Binary Search  : Index of 11 = " << binarySearch(sortedArr, 11) << endl;
    cout << "O(sqrt n) Prime Check   : Is 31 Prime? " << (isPrimeOptimized(31) ? "Yes" : "No") << endl;
    cout << "O(n) Factorial Iterative: 5! = " << factorialIterative(5) << endl;
    cout << "O(2^n) Fibonacci Recursive: Fib(6) = " << fibonacciNaive(6) << endl;

    return 0; // Signals successful completion
}


