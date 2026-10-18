

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// HELPER: PRINT VECTOR
// ==========================================
void printVector(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";
}

// ==========================================
// PROBLEM 1: MERGE SORTED ARRAY (LeetCode 88)
// Approach: Backward 3-Pointer (Optimal In-Place)
// Time Complexity : O(m + n)
// Space Complexity: O(1) auxiliary
// ==========================================
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1; // Position to fill backwards
    int i = m - 1;       // Pointer for nums1 valid data
    int j = n - 1;       // Pointer for nums2

    // Compare and place the larger element at the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[idx--] = nums1[i--];
        } else {
            nums1[idx--] = nums2[j--];
        }
    }

    // If nums2 still has leftover elements, copy them over
    while (j >= 0) {
        nums1[idx--] = nums2[j--];
    }
    // Note: If i >= 0 and j < 0, elements in nums1 are already in place!
}

// ==========================================
// PROBLEM 2: NEXT PERMUTATION (LeetCode 31)
// Approach 1: STL Built-in (For Reference)
// ==========================================
void nextPermutationSTL(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

// ==========================================
// PROBLEM 2: NEXT PERMUTATION (LeetCode 31)
// Approach 2: Optimal 3-Step Pivot Algorithm
// Time Complexity : O(N)
// Space Complexity: O(1) auxiliary
// ==========================================
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;

    // Step 1: Find the rightmost pivot where nums[i] < nums[i + 1]
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    // Edge Case: Entire array is descending (e.g., 5, 4, 3, 2, 1)
    if (pivot == -1) {
        // Reverse whole array to get the lowest possible permutation
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 2: Find rightmost element greater than nums[pivot] and swap
    for (int i = n - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Step 3: Reverse the suffix from (pivot + 1) to (n - 1)
    // Using manual two-pointer reversal (as taught in the video)
    int left = pivot + 1;
    int right = n - 1;
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

// ==========================================
// MAIN FUNCTION (Demonstration & Verification)
// ==========================================
int main() {
    cout << "========================================\n";
    cout << "--- 1. MERGE SORTED ARRAYS (LC 88) ---\n";
    cout << "========================================\n";
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    cout << "nums1 before: ";
    printVector(nums1);
    cout << "nums2       : ";
    printVector(nums2);

    merge(nums1, m, nums2, n);

    cout << "Merged nums1: ";
    printVector(nums1); // Output: 1 2 2 3 5 6
    cout << "\n";

    cout << "========================================\n";
    cout << "--- 2. NEXT PERMUTATION (LC 31) -------\n";
    cout << "========================================\n";
    
    // Test Case A: Standard case with pivot in middle
    vector<int> perm1 = {1, 2, 3, 6, 5, 4};
    cout << "Original Array: ";
    printVector(perm1);
    nextPermutation(perm1);
    cout << "Next Perm     : ";
    printVector(perm1); // Output: 1 2 4 3 5 6
    cout << "\n";

    // Test Case B: Edge case (fully descending)
    vector<int> perm2 = {3, 2, 1};
    cout << "Original Array: ";
    printVector(perm2);
    nextPermutation(perm2);
    cout << "Next Perm     : ";
    printVector(perm2); // Output: 1 2 3
    cout << "\n";

    return 0;
}

