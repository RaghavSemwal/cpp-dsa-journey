---

## 📝 Section 4: Homework Exercises & Solutions

### Exercise 1: Calculate Sum & Product of All Numbers in an Array

```cpp
#include <iostream>
using namespace std;

void sumAndProduct(int arr[], int size) {
    long long sum = 0;
    long long product = 1;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
        product *= arr[i];
    }

    cout << "Sum of elements     = " << sum << endl;
    cout << "Product of elements = " << product << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    sumAndProduct(arr, 5);
    return 0;
}

```

---

### Exercise 2: Swap the Minimum and Maximum Elements in an Array

```cpp
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void swapMinMax(int arr[], int size) {
    int minIdx = 0, maxIdx = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIdx]) minIdx = i;
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }

    swap(arr[minIdx], arr[maxIdx]);
}

int main() {
    int arr[] = {5, 15, 22, 1, -15, 24};
    int sz = 6;

    swapMinMax(arr, sz);

    cout << "Array after Swapping Min & Max: ";
    for (int i = 0; i < sz; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

```

---

### Exercise 3: Print All Unique Values in an Array

```cpp
#include <iostream>
using namespace std;

void printUnique(int arr[], int size) {
    cout << "Unique elements in array: ";
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 1, 2, 3, 4};
    printUnique(arr, 7); // Output: 4
    return 0;
}

```

---

### Exercise 4: Print Intersection of Two Arrays
#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Intersection of arrays: ";
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            if(arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                break; // avoid duplicates
            }
        }
    }
    return 0;
}

```