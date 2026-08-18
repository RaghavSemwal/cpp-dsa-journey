


// ## 💻 Section 3: Comprehensive C++ Code Implementation

// Below is a single executable C++ file containing both Iterative and Recursive implementations with overflow-safe midpoint formulas and full comments.


#include <iostream>
#include <vector>
using namespace std;

// ==========================================
// 1. ITERATIVE BINARY SEARCH (OPTIMAL)
// Time Complexity: O(log N)
// Space Complexity: O(1)
// ==========================================
int binarySearchIterative(const vector<int>& arr, int target) {
    int st = 0;
    int end = arr.size() - 1;

    while (st <= end) {
        // Overflow-safe midpoint calculation
        int mid = st + (end - st) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (target > arr[mid]) {
            st = mid + 1; // Search right half
        } else {
            end = mid - 1; // Search left half
        }
    }

    return -1; // Target not found
}

// ==========================================
// 2. RECURSIVE BINARY SEARCH
// Time Complexity: O(log N)
// Space Complexity: O(log N) due to Call Stack
// ==========================================
int binarySearchRecursive(const vector<int>& arr, int target, int st, int end) {
    // Base Case: Search space exhausted
    if (st > end) {
        return -1;
    }

    // Overflow-safe midpoint
    int mid = st + (end - st) / 2;

    if (arr[mid] == target) {
        return mid; // Target found
    } else if (target > arr[mid]) {
        // Recurse on right half
        return binarySearchRecursive(arr, target, mid + 1, end);
    } else {
        // Recurse on left half
        return binarySearchRecursive(arr, target, st, mid - 1);
    }
}

// ==========================================
// MAIN FUNCTION (Verification & Test Cases)
// ==========================================
int main() {
    cout << "========================================" << endl;
    cout << "--- BINARY SEARCH ALGORITHM IN C++ ---" << endl;
    cout << "========================================" << endl;

    // Test Array 1: Odd Size
    vector<int> oddArr = {-1, 0, 3, 4, 5, 9, 12};
    int target1 = 12;

    cout << "Odd Array: [-1, 0, 3, 4, 5, 9, 12], Target = " << target1 << endl;
    cout << "Iterative Result : Index " << binarySearchIterative(oddArr, target1) << endl;
    cout << "Recursive Result : Index " << binarySearchRecursive(oddArr, target1, 0, oddArr.size() - 1) << endl;

    // Test Array 2: Even Size
    vector<int> evenArr = {-1, 0, 3, 5, 9, 12};
    int target2 = 0;

    cout << "\nEven Array: [-1, 0, 3, 5, 9, 12], Target = " << target2 << endl;
    cout << "Iterative Result : Index " << binarySearchIterative(evenArr, target2) << endl;
    cout << "Recursive Result : Index " << binarySearchRecursive(evenArr, target2, 0, evenArr.size() - 1) << endl;

    // Target Not Found Case
    int targetNotFound = 50;
    cout << "\nSearching for non-existent target (50):" << endl;
    cout << "Result: " << binarySearchIterative(oddArr, targetNotFound) << " (Expected: -1)" << endl;

    return 0;
}

