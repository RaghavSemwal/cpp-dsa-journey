

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (O(N^2))
// Time Complexity: O(N^2), Space Complexity: O(1)
// ==========================================
int maxAreaBruteForce(const vector<int>& height) {
    int maxWater = 0;
    int n = height.size();

    for (int lp = 0; lp < n; lp++) {
        for (int rp = lp + 1; rp < n; rp++) {
            int width = rp - lp;
            int h = min(height[lp], height[rp]);
            int currentWater = width * h;
            maxWater = max(maxWater, currentWater);
        }
    }

    return maxWater;
}

// ==========================================
// 2. OPTIMAL TWO-POINTER APPROACH (O(N))
// LeetCode #11: Container With Most Water
// Time Complexity: O(N), Space Complexity: O(1)
// ==========================================
int maxAreaTwoPointer(const vector<int>& height) {
    int maxWater = 0;
    int lp = 0;                      // Left Pointer
    int rp = height.size() - 1;      // Right Pointer

    while (lp < rp) {
        int width = rp - lp;
        int h = min(height[lp], height[rp]);
        int currentWater = width * h;
        maxWater = max(maxWater, currentWater);

        // Shift pointer pointing to the shorter bar
        if (height[lp] < height[rp]) {
            lp++;
        } else {
            rp--;
        }
    }

    return maxWater;
}

// ==========================================
// MAIN FUNCTION (Verification & Testing)
// ==========================================
int main() {
    cout << "--- CONTAINER WITH MOST WATER (LEETCODE #11) ---" << endl;

    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Input Heights: [1, 8, 6, 2, 5, 4, 8, 3, 7]" << endl;
    cout << "Brute Force Result O(N^2) : " << maxAreaBruteForce(height1) << endl; // 49
    cout << "Two-Pointer Result O(N)   : " << maxAreaTwoPointer(height1) << endl; // 49

    vector<int> height2 = {1, 1};
    cout << "\nInput Heights: [1, 1]" << endl;
    cout << "Two-Pointer Result O(N)   : " << maxAreaTwoPointer(height2) << endl; // 1

    return 0; // Signals successful program completion
}

