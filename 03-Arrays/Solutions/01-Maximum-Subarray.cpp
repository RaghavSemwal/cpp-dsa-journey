/*
 * Problem   : Maximum Subarray
 * Link      : https://leetcode.com/problems/maximum-subarray/
 * Approach  : Kadane's Algorithm — track best sum ending at current index,
 *             reset to current element when running sum would be worse.
 * Time      : O(n)
 * Space     : O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};

// Quick local test
int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(nums) << endl; // expected: 6
    return 0;
}
