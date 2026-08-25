
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// ==========================================
// 1. HELPER: CHECK IF ALLOCATION IS VALID
// Time Complexity: O(N)
// Space Complexity: O(1)
// ==========================================
bool isValid(const vector<int>& arr, int n, int m, int maxAllowedPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than allowed limit
        if (arr[i] > maxAllowedPages) {
            return false;
        }

        if (currentPages + arr[i] <= maxAllowedPages) {
            currentPages += arr[i]; // Allocate to current student
        } else {
            students++;             // Allocate to next student
            currentPages = arr[i];  // Reset pages for new student
        }
    }

    return (students <= m);
}

// ==========================================
// 2. BOOK ALLOCATION (BINARY SEARCH ON ANSWER)
// Time Complexity: O(N * log(Sum of Pages))
// Space Complexity: O(1)
// ==========================================
int allocateBooks(const vector<int>& arr, int n, int m) {
    // Impossible case: More students than books
    if (m > n) {
        return -1;
    }

    int sum = 0;
    for (int pages : arr) {
        sum += pages;
    }

    int st = 0;
    int end = sum;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2; // Mid represents candidate max pages

        if (isValid(arr, n, m, mid)) {
            ans = mid;      // Candidate found
            end = mid - 1;  // Try to find a smaller maximum on the left
        } else {
            st = mid + 1;   // Page limit too tight; search right
        }
    }

    return ans;
}

// ==========================================
// MAIN FUNCTION (Demonstration & Verification)
// ==========================================
int main() {
    cout << "--- BOOK ALLOCATION PROBLEM ---" << endl;

    // Test Case 1
    vector<int> books1 = {2, 1, 3, 4};
    int n1 = 4, m1 = 2;
    cout << "Books: [2, 1, 3, 4], Students: " << m1 << endl;
    cout << "Minimum Maximum Pages: " << allocateBooks(books1, n1, m1) << " (Expected: 6)" << endl;

    // Test Case 2
    vector<int> books2 = {15, 17, 20};
    int n2 = 3, m2 = 2;
    cout << "\nBooks: [15, 17, 20], Students: " << m2 << endl;
    cout << "Minimum Maximum Pages: " << allocateBooks(books2, n2, m2) << " (Expected: 32)" << endl;

    // Test Case 3: More students than books
    vector<int> books3 = {10, 20};
    int n3 = 2, m3 = 5;
    cout << "\nBooks: [10, 20], Students: " << m3 << endl;
    cout << "Allocation Result: " << allocateBooks(books3, n3, m3) << " (Expected: -1)" << endl;

    return 0;
}

