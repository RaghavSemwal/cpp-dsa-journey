
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// 1. HELPER: PRINT ARRAY
// ==========================================
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==========================================
// 2. BUBBLE SORT (WITH EARLY EXIT OPTIMIZATION)
// Time Complexity: O(N^2) Worst, O(N) Best
// Space Complexity: O(1)
// ==========================================
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSwap = false; // Tracks if any swap occurred in this pass

        for (int j = 0; j < n - i - 1; j++) {
            // For descending order, change '>' to '<'
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        // If no two elements were swapped, array is already sorted
        if (!isSwap) {
            break;
        }
    }
}

// ==========================================
// 3. SELECTION SORT
// Time Complexity: O(N^2) in all cases
// Space Complexity: O(1)
// ==========================================
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallestIdx = i; // Assume first element of unsorted part is smallest

        for (int j = i + 1; j < n; j++) {
            // For descending order, change '<' to '>'
            if (arr[j] < arr[smallestIdx]) {
                smallestIdx = j; // Update index of current minimum
            }
        }

        // Swap smallest element with the first unsorted position
        swap(arr[i], arr[smallestIdx]);
    }
}

// ==========================================
// 4. INSERTION SORT
// Time Complexity: O(N^2) Worst, O(N) Best
// Space Complexity: O(1)
// ==========================================
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        // Shift elements greater than curr to one position ahead
        // For descending order, change 'arr[prev] > curr' to 'arr[prev] < curr'
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Insert curr into its correct sorted slot
        arr[prev + 1] = curr;
    }
}

// ==========================================
// MAIN FUNCTION (Demonstration & Verification)
// ==========================================
int main() {
    cout << "========================================" << endl;
    cout << "--- SORTING ALGORITHMS DEMONSTRATION ---" << endl;
    cout << "========================================" << endl;

    // Test 1: Bubble Sort
    int arr1[] = {4, 1, 5, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original Array: ";
    printArray(arr1, n1);

    bubbleSort(arr1, n1);
    cout << "Bubble Sort Output   : ";
    printArray(arr1, n1);

    // Test 2: Selection Sort
    int arr2[] = {4, 1, 5, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    selectionSort(arr2, n2);
    cout << "Selection Sort Output: ";
    printArray(arr2, n2);

    // Test 3: Insertion Sort
    int arr3[] = {4, 1, 5, 2, 3};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, n3);
    cout << "Insertion Sort Output: ";
    printArray(arr3, n3);

    return 0;
}
