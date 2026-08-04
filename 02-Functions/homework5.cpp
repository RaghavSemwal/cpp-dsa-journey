---

## 📝 Section 3: Homework Challenges (From Video)

### Challenge 1: Check if a Number is Prime


#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 17;
    if (isPrime(n)) {
        cout << n << " is a Prime Number." << endl;
    } else {
        cout << n << " is NOT a Prime Number." << endl;
    }
    return 0;
}



---

### Challenge 2: Print All Prime Numbers from 2 to N


#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrimesUpToN(int n) {
    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    printPrimesUpToN(20);
    return 0;
}

```

---

### Challenge 3: Fibonacci Series (N-th Term)

**Fibonacci Series:** `0, 1, 1, 2, 3, 5, 8, 13, ...`


#include <iostream>
using namespace std;

int nthFibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0;
    int prev1 = 1;
    int curr = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n = 7;
    cout << "The " << n << "-th Fibonacci number is: " << nthFibonacci(n) << endl;
    return 0;
}

```