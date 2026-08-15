

#include <iostream>
#include <vector>
using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (O(N^2))
// Time Complexity: O(N^2), Space Complexity: O(1)
// ==========================================
vector<int> productExceptSelfBruteForce(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ans[i] *= nums[j];
            }
        }
    }
    return ans;
}

// ==========================================
// 2. PREFIX & SUFFIX ARRAYS APPROACH (O(N) Space)
// Time Complexity: O(N), Space Complexity: O(N)
// ==========================================
vector<int> productExceptSelfPrefixSuffix(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> ans(n, 1);

    // Compute Prefix Products
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Compute Suffix Products
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Combine Prefix and Suffix
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

// ==========================================
// 3. OPTIMAL SPACE-OPTIMIZED APPROACH (O(1) Extra Space)
// LeetCode #238: Product of Array Except Self
// Time Complexity: O(N), Space Complexity: O(1) Auxiliary
// ==========================================
vector<int> productExceptSelfOptimal(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    // Pass 1: Store Prefix Products directly in 'ans'
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // Pass 2: Multiply Suffix Products on the fly using a single variable
    int suffix = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix *= nums[i + 1]; // Running suffix product
        ans[i] *= suffix;      // Prefix * Suffix
    }

    return ans;
}

// ==========================================
// MAIN FUNCTION (Demonstration & Verification)
// ==========================================
int main() {
    cout << "--- PRODUCT OF ARRAY EXCEPT SELF (LEETCODE #238) ---" << endl;

    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Input Array 1: [ 1, 2, 3, 4 ]" << endl;

    vector<int> resBrute = productExceptSelfBruteForce(nums1);
    cout << "Brute Force O(N^2)    : ";
    for (int val : resBrute) cout << val << " ";
    cout << endl;

    vector<int> resPrefixSuffix = productExceptSelfPrefixSuffix(nums1);
    cout << "Prefix/Suffix O(N) Sp : ";
    for (int val : resPrefixSuffix) cout << val << " ";
    cout << endl;

    vector<int> resOptimal = productExceptSelfOptimal(nums1);
    cout << "Optimal O(1) Space    : ";
    for (int val : resOptimal) cout << val << " ";
    cout << endl;

    // Test with zero in array
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "\nInput Array 2 (With 0): [ -1, 1, 0, -3, 3 ]" << endl;
    vector<int> resZero = productExceptSelfOptimal(nums2);
    cout << "Optimal Result        : ";
    for (int val : resZero) cout << val << " ";
    cout << endl;

    return 0;
}

