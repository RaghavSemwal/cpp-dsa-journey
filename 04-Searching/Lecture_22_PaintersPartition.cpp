
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ==========================================
// 1. HELPER: CHECK IF TIME LIMIT IS FEASIBLE
// Time Complexity: O(N)
// Space Complexity: O(1)
// ==========================================
bool isPossible(const vector<int>& arr, int n, int m, int maxAllowedTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // If single board exceeds the maxAllowedTime limit
        if (arr[i] > maxAllowedTime) {
            return false;
        }

        if (currentTime + arr[i] <= maxAllowedTime) {
            currentTime += arr[i]; // Allocate board to current painter
        } else {
            painters++;            // Assign new painter
            currentTime = arr[i];  // Start counting time for new painter
        }
    }

    return (painters <= m);
}

// ==========================================
// 2. PAINTER'S PARTITION ALGORITHM
// Time Complexity: O(N * log(sum - max))
// Space Complexity: O(1)
// ==========================================
int minTimeToPaint(const vector<int>& arr, int n, int m) {
    int sum = 0;
    int maxVal = INT_MIN;

    for (int len : arr) {
        sum += len;
        maxVal = max(maxVal, len);
    }

    int st = maxVal; // Lower bound: Largest single board
    int end = sum;   // Upper Bound: Sum of all boards
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2; // Candidate maximum time

        if (isPossible(arr, n, m, mid)) {
            ans = mid;     // Valid candidate found
            end = mid - 1; // Try finding smaller maximum time on left
        } else {
            st = mid + 1;  // Time limit too tight, search right
        }
    }

    return ans;
}

// ==========================================
// MAIN FUNCTION (Test Cases & Verification)
// ==========================================
int main() {
    cout << "--- PAINTER'S PARTITION PROBLEM ---" << endl;

    // Test Case 1
    vector<int> boards1 = {40, 30, 10, 20};
    int n1 = 4, m1 = 2;
    cout << "Boards: [40, 30, 10, 20], Painters: " << m1 << endl;
    cout << "Minimum Time: " << minTimeToPaint(boards1, n1, m1) << " (Expected: 60)" << endl;

    // Test Case 2
    vector<int> boards2 = {10, 10, 10, 10};
    int n2 = 4, m2 = 2;
    cout << "\nBoards: [10, 10, 10, 10], Painters: " << m2 << endl;
    cout << "Minimum Time: " << minTimeToPaint(boards2, n2, m2) << " (Expected: 20)" << endl;

    // Test Case 3
    vector<int> boards3 = {10, 20, 30, 40};
    int n3 = 4, m3 = 2;
    cout << "\nBoards: [10, 20, 30, 40], Painters: " << m3 << endl;
    cout << "Minimum Time: " << minTimeToPaint(boards3, n3, m3) << " (Expected: 60)" << endl;

    return 0;
}

