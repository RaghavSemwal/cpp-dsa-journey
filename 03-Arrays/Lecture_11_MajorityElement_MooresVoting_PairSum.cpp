

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// 1. PAIR SUM: BRUTE FORCE (O(N^2))
// ==========================================
vector<int> pairSumBruteForce(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// ==========================================
// 2. PAIR SUM: TWO-POINTER APPROACH (O(N))
// Requires array to be sorted
// ==========================================
vector<int> pairSumTwoPointer(const vector<int>& nums, int target) {
    int st = 0;
    int end = nums.size() - 1;

    while (st < end) {
        int pairSum = nums[st] + nums[end];
        if (pairSum > target) {
            end--; // Sum too large -> decrease right pointer
        } else if (pairSum < target) {
            st++;  // Sum too small -> increase left pointer
        } else {
            return {st, end}; // Target match
        }
    }
    return {};
}

// ==========================================
// 3. MAJORITY ELEMENT: BRUTE FORCE (O(N^2))
// ==========================================
int majorityElementBruteForce(const vector<int>& nums) {
    int n = nums.size();
    for (int val : nums) {
        int freq = 0;
        for (int el : nums) {
            if (el == val) freq++;
        }
        if (freq > n / 2) return val;
    }
    return -1;
}

// ==========================================
// 4. MAJORITY ELEMENT: SORTING APPROACH (O(N log N))
// ==========================================
int majorityElementSorting(vector<int> nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2]; // Midpoint element is guaranteed to be majority
}

// ==========================================
// 5. MAJORITY ELEMENT: MOORE'S VOTING ALGO (O(N))
// LeetCode #169
// ==========================================
int majorityElementMooreVoting(const vector<int>& nums) {
    int freq = 0;
    int ans = 0;

    // Phase 1: Candidate Selection
    for (int val : nums) {
        if (freq == 0) {
            ans = val;
        }
        if (val == ans) {
            freq++;
        } else {
            freq--;
        }
    }

    // Phase 2: Verification (Optional if existence guaranteed)
    int count = 0;
    for (int val : nums) {
        if (val == ans) count++;
    }

    if (count > nums.size() / 2) {
        return ans;
    }
    return -1;
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    cout << "--- 1. PAIR SUM DEMO ---" << endl;
    vector<int> sortedArr = {2, 7, 11, 15};
    int target = 26;

    vector<int> pairRes = pairSumTwoPointer(sortedArr, target);
    cout << "Sorted Array: [ 2, 7, 11, 15 ], Target = " << target << endl;
    if (!pairRes.empty()) {
        cout << "Indices found: [" << pairRes[0] << ", " << pairRes[1] << "]" << endl;
    }

    cout << "\n--- 2. MAJORITY ELEMENT DEMO ---" << endl;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Input Array: [ 2, 2, 1, 1, 1, 2, 2 ]" << endl;
    cout << "Brute Force Result       : " << majorityElementBruteForce(nums) << endl;
    cout << "Sorting Approach Result   : " << majorityElementSorting(nums) << endl;
    cout << "Moore's Voting Result O(N): " << majorityElementMooreVoting(nums) << endl;

    return 0;
}



