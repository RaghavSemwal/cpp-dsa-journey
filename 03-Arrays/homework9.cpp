---

## 📝 Section 4: Homework Exercises & Solutions

### Exercise 1: Linear Search on a Vector

```cpp
#include <iostream>
#include <vector>
using namespace std;

int linearSearchVector(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    int target = 30;
    int index = linearSearchVector(vec, target);

    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}

```

---

### Exercise 2: Reverse a Vector In-Place (Pass by Reference)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseVector(vector<int>& vec) { // Pass by reference using &
    int start = 0;
    int end = vec.size() - 1;

    while (start < end) {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << "Original Vector : ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    reverseVector(vec); // Modifies original vector in-place

    cout << "Reversed Vector : ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    return 0;
}

```