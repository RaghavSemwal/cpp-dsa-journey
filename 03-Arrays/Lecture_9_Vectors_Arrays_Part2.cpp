

#include <iostream>
#include <vector>
using namespace std;

// ==========================================
// 1. VECTOR DECLARATION & FUNCTIONS DEMO
// ==========================================
void demoVectorFunctions() {
    cout << "--- 1. VECTOR MEMBER FUNCTIONS ---" << endl;

    vector<int> vec; // Empty vector declaration

    cout << "Initial Size     : " << vec.size() << endl;
    cout << "Initial Capacity : " << vec.capacity() << endl;

    // Pushing elements dynamically
    vec.push_back(25);
    vec.push_back(35);
    vec.push_back(45);

    cout << "\nAfter 3 push_back calls:" << endl;
    cout << "Size     : " << vec.size() << " (Elements: 25, 35, 45)" << endl;
    cout << "Capacity : " << vec.capacity() << " (Grown dynamically)" << endl;

    // Accessing elements
    cout << "Front Element : " << vec.front() << endl;
    cout << "Back Element  : " << vec.back() << endl;
    cout << "At Index 1    : " << vec.at(1) << endl;

    // Pop element
    vec.pop_back(); // Removes 45
    cout << "\nAfter pop_back():" << endl;
    cout << "Size          : " << vec.size() << endl;
    cout << "New Back      : " << vec.back() << endl;
}

// ==========================================
// 2. VECTOR FOR-EACH LOOP DEMO
// ==========================================
void demoForEachLoop() {
    cout << "\n--- 2. VECTOR FOR-EACH LOOP ---" << endl;

    vector<char> chars = {'a', 'b', 'c', 'd', 'e'};

    cout << "Vector Elements: ";
    for (char val : chars) { // 'val' copies each element sequentially
        cout << val << " ";
    }
    cout << endl;
}

// ==========================================
// 3. SIZE VS CAPACITY GROWTH MECHANICS
// ==========================================
void demoGrowthMechanics() {
    cout << "\n--- 3. SIZE VS CAPACITY MECHANICS ---" << endl;

    vector<int> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
        cout << "Added: " << i << " | Size: " << v.size() 
             << " | Capacity: " << v.capacity() << endl;
    }
}

// ==========================================
// 4. LEETCODE #136: SINGLE NUMBER (OPTIMAL)
// Time Complexity: O(N), Space Complexity: O(1)
// ==========================================
int singleNumber(const vector<int>& nums) {
    int ans = 0;
    for (int val : nums) {
        ans ^= val; // Cumulative XOR cancels duplicate pairs
    }
    return ans;
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    demoVectorFunctions();
    demoForEachLoop();
    demoGrowthMechanics();

    cout << "\n--- 4. LEETCODE #136: SINGLE NUMBER ---" << endl;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Input Vector : {4, 1, 2, 1, 2}" << endl;
    cout << "Single Unique Element : " << singleNumber(nums) << endl;

    return 0; // Signals successful program completion
}

