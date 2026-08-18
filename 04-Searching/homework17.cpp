

// ## 📝 Section 4: Homework Exercises & Practice Questions

// ### Exercise 1: Dry Run Practice

// Perform a manual trace on paper for:

// * **Array:** `arr = [2, 4, 6, 8, 10, 12, 14, 16]
// * **Target:** `14`
// * Write down values of `st`, `end`, and `mid` for every step.



// ### Exercise 2: Binary Search in a Reverse (Descending) Sorted Array

// **Problem:** Implement Binary Search on an array sorted in descending order (e.g., `[20, 17, 15, 11, 9, 4, 1]`).


#include <iostream>
#include <vector>
using namespace std;

int binarySearchDescending(const vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (target < arr[mid]) {
            // For descending order, smaller elements lie in the RIGHT half
            st = mid + 1;
        } else {
            // Larger elements lie in the LEFT half
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> descArr = {20, 17, 15, 11, 9, 4, 1};
    int target = 11;
    cout << "Index of " << target << " in descending array: " 
         << binarySearchDescending(descArr, target) << endl; // Output: 3
    return 0;
}





// ### Exercise 3: First and Last Occurrence of an Element (LeetCode #34 Teaser)

// Given a sorted array with duplicate elements (e.g., `[1, 2, 2, 2, 3, 4]`), find the first index of `target = 2`.


#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target) {
            ans = mid;      // Candidate found
            end = mid - 1;  // Keep looking leftward for earlier occurrence
        } else if (target > arr[mid]) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    cout << "First occurrence index of 2: " << findFirstOccurrence(arr, 2) << endl; // Output: 1
    return 0;
}

