
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// HELPER: PRINT VECTOR
// ==========================================
void printVector(const vector<int>& nums) {
    for (int val : nums) {
        cout << val << " ";
    }
    cout << "\n";
}

// ==========================================
// 1. BRUTE FORCE APPROACH (std::sort)
// Time Complexity: O(N log N)
// Space Complexity: O(1) auxiliary
// ==========================================
void sortColorsBruteForce(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

// ==========================================
// 2. OPTIMIZED 2-PASS APPROACH (Counting Sort)
// Time Complexity: O(N) (2 passes)
// Space Complexity: O(1) auxiliary
// ==========================================
void sortColorsCounting(vector<int>& nums) {
    int n = nums.size();
    int count0 = 0, count1 = 0, count2 = 0;

    // Pass 1: Count occurrences
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            count0++;
        } else if (nums[i] == 1) {
            count1++;
        } else {
            count2++;
        }
    }

    // Pass 2: Overwrite original array
    int idx = 0;
    for (int i = 0; i < count0; i++) {
        nums[idx++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        nums[idx++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        nums[idx++] = 2;
    }
}

// ==========================================
// 3. MOST OPTIMAL 1-PASS APPROACH (DNF Algorithm)
// Time Complexity: O(N) (Strictly 1 pass)
// Space Complexity: O(1) auxiliary
// ==========================================
void sortColorsDNF(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
            // Do not increment mid here: the swapped element from high must be inspected
        }
    }
}

// ==========================================
// MAIN FUNCTION (Demonstration & Verification)
// ==========================================
int main() {
    cout << "===============================================\n";
    cout << "--- SORT AN ARRAY OF 0s, 1s & 2s (LeetCode 75) ---\n";
    cout << "===============================================\n\n";

    // Test 1: Brute Force
    vector<int> test1 = {2, 0, 2, 1, 1, 0};
    cout << "Original Array: ";
    printVector(test1);
    sortColorsBruteForce(test1);
    cout << "Brute Force Output   : ";
    printVector(test1);
    cout << "\n";

    // Test 2: Counting Sort
    vector<int> test2 = {2, 0, 2, 1, 1, 0};
    sortColorsCounting(test2);
    cout << "Counting Sort Output : ";
    printVector(test2);
    cout << "\n";

    // Test 3: DNF Algorithm
    vector<int> test3 = {2, 0, 2, 1, 1, 0};
    sortColorsDNF(test3);
    cout << "DNF Algorithm Output : ";
    printVector(test3);
    cout << "\n";

    return 0;
}
