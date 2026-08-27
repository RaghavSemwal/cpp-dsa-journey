

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// 1. HELPER: CHECK IF DISTANCE IS FEASIBLE
// Time Complexity: O(N)
// Space Complexity: O(1)
// ==========================================
bool isPossible(const vector<int>& stalls, int n, int C, int minAllowedDist) {
    int cowsPlaced = 1;               // Place 1st cow in 1st stall
    int lastStallPos = stalls[0];     // Position of last placed cow

    for (int i = 1; i < n; i++) {
        // If distance from last placed cow is at least minAllowedDist
        if (stalls[i] - lastStallPos >= minAllowedDist) {
            cowsPlaced++;
            lastStallPos = stalls[i]; // Update placement position
        }

        // All cows placed successfully
        if (cowsPlaced == C) {
            return true;
        }
    }

    return false; // Could not place all C cows
}

// ==========================================
// 2. AGGRESSIVE COWS ALGORITHM
// Time Complexity: O(N log N + N * log(max_dist - min_dist))
// Space Complexity: O(1)
// ==========================================
int getDistance(vector<int>& stalls, int n, int C) {
    // Step 1: Sort the stalls coordinates
    sort(stalls.begin(), stalls.end());

    // Step 2: Define search space
    int st = 1;                          // Minimum possible distance
    int end = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = -1;

    // Step 3: Binary Search on Answer
    while (st <= end) {
        int mid = st + (end - st) / 2;   // Candidate minimum distance

        if (isPossible(stalls, n, C, mid)) {
            ans = mid;     // Feasible distance found
            st = mid + 1;  // Try to MAXIMIZE: search for a larger distance on the right
        } else {
            end = mid - 1; // Distance too large: search on the left
        }
    }

    return ans;
}

// ==========================================
// MAIN FUNCTION (Demonstration & Test Cases)
// ==========================================
int main() {
    cout << "--- AGGRESSIVE COWS PROBLEM ---" << endl;

    // Test Case 1
    vector<int> stalls1 = {1, 2, 8, 4, 9};
    int n1 = 5, C1 = 3;
    cout << "Stalls: [1, 2, 8, 4, 9], Cows: " << C1 << endl;
    cout << "Largest Minimum Distance: " << getDistance(stalls1, n1, C1) << " (Expected: 3)" << endl;

    // Test Case 2
    vector<int> stalls2 = {0, 3, 4, 7, 10, 9};
    int n2 = 6, C2 = 4;
    cout << "\nStalls: [0, 3, 4, 7, 10, 9], Cows: " << C2 << endl;
    cout << "Largest Minimum Distance: " << getDistance(stalls2, n2, C2) << " (Expected: 3)" << endl;

    // Test Case 3: 2 Cows placed at extreme ends
    vector<int> stalls3 = {1, 10, 20};
    int n3 = 3, C3 = 2;
    cout << "\nStalls: [1, 10, 20], Cows: " << C3 << endl;
    cout << "Largest Minimum Distance: " << getDistance(stalls3, n3, C3) << " (Expected: 19)" << endl;

    return 0;
}


