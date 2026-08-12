
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ==========================================
// 1. PRINT ALL SUBARRAYS (O(N^3) Brute Force)
// ==========================================
void printAllSubarrays(const vector<int>& arr) {
    int n = arr.size();
    cout << "--- PRINTING ALL SUBARRAYS ---" << endl;

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            cout << "[ ";
            for (int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << "] ";
        }
        cout << endl;
    }
}

// ==========================================
// 2. BRUTE FORCE MAX SUBARRAY SUM (O(N^2))
// ==========================================
int maxSubarraySumBruteForce(const vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++) {
        int currentSum = 0;
        for (int end = start; end < n; end++) {
            currentSum += nums[end]; // Add element incrementally
            maxSum = max(currentSum, maxSum);
        }
    }
    return maxSum;
}

// ==========================================
// 3. KADANE'S ALGORITHM (O(N) Optimal)
// LeetCode #53: Maximum Subarray
// ==========================================
int maxSubarraySumKadane(const vector<int>& nums) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int val : nums) {
        currentSum += val;
        maxSum = max(currentSum, maxSum); // Update maxSum BEFORE reset

        // Kadane's Reset Step
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSum;
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    vector<int> sampleArr = {1, 2, 3, 4, 5};
    printAllSubarrays(sampleArr);

    vector<int> nums = {3, -4, 5, 4, -1, 7, -8};

    cout << "\n--- MAXIMUM SUBARRAY SUM ---" << endl;
    cout << "Input Array: [ 3, -4, 5, 4, -1, 7, -8 ]" << endl;

    cout << "Brute Force Result O(N^2) : " << maxSubarraySumBruteForce(nums) << endl;
    cout << "Kadane's Algo Result O(N) : " << maxSubarraySumKadane(nums) << endl;

    // Testing All-Negative Numbers Edge Case
    vector<int> allNegative = {-5, -2, -3, -8};
    cout << "\nInput Array (All Negative): [ -5, -2, -3, -8 ]" << endl;
    cout << "Kadane's Result (Edge Case) : " << maxSubarraySumKadane(allNegative) << endl;

    return 0; // Signals successful program completion
}

