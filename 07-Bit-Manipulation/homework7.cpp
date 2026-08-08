---

## 📝 Section 4: Homework Exercises & Solutions

### Exercise 1: Check if a Number is a Power of 2 (Using Bitwise Trick)

#### Logic:

If a number $n$ is a power of 2, its binary representation contains **exactly one set bit** (e.g., $8 = 1000_2$). Subtracting $1$ flips all bits after the set bit (e.g., $7 = 0111_2$).
Therefore, $n \ \& \ (n - 1) == 0$ for all powers of 2.

```cpp
#include <iostream>
using namespace std;

bool isPowerOfTwoBitwise(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    int n1 = 32;
    int n2 = 34;

    cout << n1 << " is Power of 2? " << (isPowerOfTwoBitwise(n1) ? "True" : "False") << endl; // True
    cout << n2 << " is Power of 2? " << (isPowerOfTwoBitwise(n2) ? "True" : "False") << endl; // False

    return 0;
}

```

---

### Exercise 2: Reverse an Integer Number

```cpp
#include <iostream>
using namespace std;

int reverseInteger(int n) {
    int reversedNum = 0;

    while (n > 0) {
        int lastDigit = n % 10;
        reversedNum = (reversedNum * 10) + lastDigit; // Shift previous digits left and append
        n /= 10;
    }

    return reversedNum;
}

int main() {
    int num = 125;
    cout << "Original Number : " << num << endl;
    cout << "Reversed Number : " << reverseInteger(num) << endl; // Output: 521

    return 0;
}

```