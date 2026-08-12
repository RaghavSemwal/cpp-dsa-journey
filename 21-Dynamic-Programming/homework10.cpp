
// ---

// ## 📝 Section 4: Homework Exercises & Practice Problems

// ### Exercise 1: Print the Actual Subarray with Maximum Sum (Not Just the Sum)


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printMaxSubarrayIndices(const vector<int>& nums) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    int start = 0, bestStart = 0, bestEnd = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (currentSum == 0) {
            start = i; // Potential new subarray start
        }

        currentSum += nums[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            bestStart = start;
            bestEnd = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray Elements   : [ ";
    for (int i = bestStart; i <= bestEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {3, -4, 5, 4, -1, 7, -8};
    printMaxSubarrayIndices(nums); // Expected Subarray: [5, 4, -1, 7] with sum 15
    return 0;
}

