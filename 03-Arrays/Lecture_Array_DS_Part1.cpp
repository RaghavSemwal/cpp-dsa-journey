

#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
#include <algorithm> // For std::swap and std::min/max
using namespace std;

// ==========================================
// 1. ARRAY CREATION, INPUT, OUTPUT & SIZE
// ==========================================
void demoArrayBasics() {
    cout << "--- 1. ARRAY BASICS & SIZE CALCULATION ---" << endl;
    
    int marks[5] = {99, 100, 54, 36, 88};
    int sz = sizeof(marks) / sizeof(marks[0]);

    cout << "Total Array Size in Bytes : " << sizeof(marks) << endl;
    cout << "Single Element Size Bytes : " << sizeof(marks[0]) << endl;
    cout << "Number of Elements (Size) : " << sz << endl;

    cout << "Array Elements: ";
    for (int i = 0; i < sz; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

// ==========================================
// 2. FIND SMALLEST AND LARGEST ELEMENT
// ==========================================
void findMinMax(int arr[], int size) {
    cout << "\n--- 2. MIN & MAX IN ARRAY ---" << endl;

    int smallest = INT_MAX; // +Infinity placeholder
    int largest = INT_MIN;  // -Infinity placeholder

    for (int i = 0; i < size; i++) {
        smallest = min(arr[i], smallest); // Built-in helper
        largest = max(arr[i], largest);   // Built-in helper
    }

    cout << "Smallest Element = " << smallest << endl;
    cout << "Largest Element  = " << largest << endl;
}

// ==========================================
// 3. PASS BY REFERENCE DEMONSTRATION
// ==========================================
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2; // Doubles each value at memory location
    }
}

void demoPassByReference() {
    cout << "\n--- 3. PASS BY REFERENCE ---" << endl;
    int arr[3] = {1, 2, 3};

    cout << "Original Array in main() : ";
    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << endl;

    modifyArray(arr, 3); // Pass array (address) to function

    cout << "After modifyArray() call : ";
    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << " (Values modified in-place)" << endl;
}

// ==========================================
// 4. LINEAR SEARCH ALGORITHM
// Time Complexity: O(N), Space Complexity: O(1)
// ==========================================
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

// ==========================================
// 5. REVERSE AN ARRAY (TWO-POINTER APPROACH)
// Time Complexity: O(N), Space Complexity: O(1)
// ==========================================
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(arr[start], arr[end]); // Built-in C++ swap
        start++;
        end--;
    }
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    demoArrayBasics();

    int numbers[] = {5, 15, 22, 1, -15, 24};
    int sz = sizeof(numbers) / sizeof(numbers[0]);

    findMinMax(numbers, sz);

    demoPassByReference();

    cout << "\n--- 4. LINEAR SEARCH ---" << endl;
    int target = -15;
    int idx = linearSearch(numbers, sz, target);
    if (idx != -1) {
        cout << "Target " << target << " found at index: " << idx << endl;
    } else {
        cout << "Target " << target << " NOT found in array." << endl;
    }

    cout << "\n--- 5. REVERSE ARRAY ---" << endl;
    int arrToReverse[] = {4, 2, 7, 8, 1, 2, 5};
    int revSize = sizeof(arrToReverse) / sizeof(arrToReverse[0]);

    cout << "Before Reversing : ";
    for (int i = 0; i < revSize; i++) cout << arrToReverse[i] << " ";
    cout << endl;

    reverseArray(arrToReverse, revSize);

    cout << "After Reversing  : ";
    for (int i = 0; i < revSize; i++) cout << arrToReverse[i] << " ";
    cout << endl;

    return 0;
}



