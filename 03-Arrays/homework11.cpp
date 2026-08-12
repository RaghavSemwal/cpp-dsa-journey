
// ## 📝 Section 4: Homework Exercises & Solutions

// ### Exercise 1: Pair Sum Returning Values Instead of Indices


#include <iostream>
#include <vector>
using namespace std;

pair<int, int> pairSumValues(const vector<int>& nums, int target) {
    int st = 0, end = nums.size() - 1;
    while (st < end) {
        int sum = nums[st] + nums[end];
        if (sum > target) end--;
        else if (sum < target) st++;
        else return {nums[st], nums[end]};
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    auto res = pairSumValues(nums, 13); // 2 + 11 = 13
    cout << "Pair Values: " << res.first << " & " << res.second << endl;
    return 0;
}

