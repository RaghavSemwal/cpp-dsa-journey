---

## 📝 Homework Challenges (From Lecture)

### Exercise 1: Sum of all numbers from 1 to N divisible by 3

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            sum += i;
        }
    }

    cout << "Sum of numbers from 1 to " << n << " divisible by 3 = " << sum << endl;
    // Expected output for n = 10: 3 + 6 + 9 = 18
    return 0;
}

```

### Exercise 2: Factorial of a Number N

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    long long factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    cout << "Factorial of " << n << " (" << n << "!) = " << factorial << endl;
    // Expected output for n = 5: 1 * 2 * 3 * 4 * 5 = 120
    return 0;
}

```