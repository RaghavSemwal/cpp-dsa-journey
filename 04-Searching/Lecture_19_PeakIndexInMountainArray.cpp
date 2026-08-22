
#include <iostream>
#include <vector>
using namespace std;

// ==========================================
// 1. BRUTE FORCE LINEAR SEARCH (O(N))
// ==========================================
int peakIndexInMountainArrayLinear(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return i;
        }
    }
    return -1;
}

// ==========================================
// 2. OPTIMAL BINARY SEARCH (O(log N))
// LeetCode #852: Peak Index in a Mountain Array
// ==========================================
int peakIndexInMountainArray(const vector<int>& arr) {
    int n = arr.size();
    // Search space excludes first and last indices
    int st = 1;
    int end = n - 2;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Condition 1: Check if mid is the peak
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        // Condition 2: On increasing (left) slope -> Search right
        else if (arr[mid - 1] < arr[mid]) {
            st = mid + 1;
        }
        // Condition 3: On decreasing (right) slope -> Search left
        else {
            end = mid - 1;
        }
    }

    return -1;
}

// ==========================================
// MAIN FUNCTION (Verification & Test Cases)
// ==========================================
int main() {
    cout << "--- PEAK INDEX IN MOUNTAIN ARRAY (LEETCODE #852) ---" << endl;

    vector<int> arr1 = {0, 3, 8, 9, 5, 2};
    cout << "Array 1: [0, 3, 8, 9, 5, 2]" << endl;
    cout << "Linear Search Peak Index : " << peakIndexInMountainArrayLinear(arr1) << endl; // 3
    cout << "Binary Search Peak Index : " << peakIndexInMountainArray(arr1) << endl;       // 3

    vector<int> arr2 = {0, 10, 5, 2};
    cout << "\nArray 2: [0, 10, 5, 2]" << endl;
    cout << "Binary Search Peak Index : " << peakIndexInMountainArray(arr2) << endl;       // 1

    vector<int> arr3 = {0, 1, 2, 4, 2, 1};
    cout << "\nArray 3: [0, 1, 2, 4, 2, 1]" << endl;
    cout << "Binary Search Peak Index : " << peakIndexInMountainArray(arr3) << endl;       // 3

    return 0;
}


