


#include <iostream>
#include <vector>
using namespace std;

// ==========================================
// SEARCH IN ROTATED SORTED ARRAY (LEETCODE #33)
// Time Complexity: O(log N)
// Space Complexity: O(1)
// ==========================================
int searchInRotatedArray(const vector<int>& nums, int target) {
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Step 1: Check if element is at mid
        if (nums[mid] == target) {
            return mid;
        }

        // Step 2: Check if Left Half is sorted
        if (nums[st] <= nums[mid]) {
            // Check if target lies in the sorted left half
            if (nums[st] <= target && target <= nums[mid]) {
                end = mid - 1; // Search left
            } else {
                st = mid + 1;  // Search right
            }
        }
        // Step 3: Otherwise, Right Half MUST be sorted
        else {
            // Check if target lies in the sorted right half
            if (nums[mid] <= target && target <= nums[end]) {
                st = mid + 1;  // Search right
            } else {
                end = mid - 1; // Search left
            }
        }
    }

    return -1; // Target not found
}

// ==========================================
// MAIN FUNCTION (Test Cases & Verification)
// ==========================================
int main() {
    cout << "--- SEARCH IN ROTATED SORTED ARRAY (LEETCODE #33) ---" << endl;

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Array: [4, 5, 6, 7, 0, 1, 2], Target: " << target1 << endl;
    cout << "Index: " << searchInRotatedArray(nums1, target1) << " (Expected: 4)" << endl;

    int target2 = 3;
    cout << "\nArray: [4, 5, 6, 7, 0, 1, 2], Target: " << target2 << endl;
    cout << "Index: " << searchInRotatedArray(nums1, target2) << " (Expected: -1)" << endl;

    vector<int> nums2 = {6, 7, 0, 1, 2, 4, 5};
    int target3 = 7;
    cout << "\nArray: [6, 7, 0, 1, 2, 4, 5], Target: " << target3 << endl;
    cout << "Index: " << searchInRotatedArray(nums2, target3) << " (Expected: 1)" << endl;

    return 0;
}

