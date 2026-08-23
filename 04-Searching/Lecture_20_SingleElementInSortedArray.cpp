

#include <iostream>
#include <vector>
using namespace std;

// =======================================================
// SINGLE ELEMENT IN A SORTED ARRAY (LEETCODE #540)
// Time Complexity: O(log N)
// Space Complexity: O(1)
// =======================================================
int singleNonDuplicate(const vector<int>& A) {
    int n = A.size();

    // Edge Case 1: Array with only one element
    if (n == 1) return A[0];

    int st = 0;
    int end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Edge Case 2: Boundary checks at start and end of array
        if (mid == 0 && A[0] != A[1]) return A[0];
        if (mid == n - 1 && A[n - 1] != A[n - 2]) return A[n - 1];

        // Condition 1: Check if mid itself is the single unique element
        if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1]) {
            return A[mid];
        }

        // Condition 2: Check based on mid index parity (Even vs Odd)
        if (mid % 2 == 0) { // EVEN index mid
            if (A[mid - 1] == A[mid]) {
                // Pair is (Odd, Even) -> Shift happened on left
                end = mid - 1;
            } else {
                // Pair is (Even, Odd) -> Normal, single element is on right
                st = mid + 1;
            }
        } else { // ODD index mid
            if (A[mid - 1] == A[mid]) {
                // Pair is (Even, Odd) -> Normal, single element is on right
                st = mid + 1;
            } else {
                // Pair is (Odd, Even) -> Shift happened on left
                end = mid - 1;
            }
        }
    }

    return -1; // Fallback
}

// ==========================================
// MAIN FUNCTION (Demonstration & Test Cases)
// ==========================================
int main() {
    cout << "--- SINGLE ELEMENT IN SORTED ARRAY (LEETCODE #540) ---" << endl;

    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Array 1: [1, 1, 2, 3, 3, 4, 4, 8, 8]" << endl;
    cout << "Single Element: " << singleNonDuplicate(nums1) << " (Expected: 2)" << endl;

    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "\nArray 2: [3, 3, 7, 7, 10, 11, 11]" << endl;
    cout << "Single Element: " << singleNonDuplicate(nums2) << " (Expected: 10)" << endl;

    vector<int> nums3 = {1};
    cout << "\nArray 3 (Single Element): [1]" << endl;
    cout << "Single Element: " << singleNonDuplicate(nums3) << " (Expected: 1)" << endl;

    return 0;
}


