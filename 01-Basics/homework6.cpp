
---

## 📝 Section 4: Homework Exercises & Solutions

### Homework Challenge 1: Convert -15 to Binary (2's Complement) using 8-bit Representation

#### Analytical Calculation:

1. **8-bit Representation of $+15$:** `0000 1111`
2. **1's Complement (Invert all bits):** `1111 0000`
3. **Add 1 to LSB:**

$$\begin{array}{rl}      11110000 \\    + 00000001 \\    \hline      11110001    \end{array}$$



**Result:** $-15$ in 8-bit 2's Complement is `11110001`.

---

### Homework Challenge 2: Convert Binary `11110001` back to Decimal

#### Analytical Calculation:

1. **Check MSB:** MSB is `1`, indicating a **negative number**.
2. **Apply 2's Complement to find magnitude:**
* **1's Complement:** Invert `11110001` $\rightarrow$ `00001110`
* **Add 1:** `00001110` $+ 1 =$ `00001111`


3. **Convert `00001111` to Decimal:**

$$0 \times 2^7 + \dots + 1 \times 2^3 + 1 \times 2^2 + 1 \times 2^1 + 1 \times 2^0 = 8 + 4 + 2 + 1 = 15$$


4. **Apply Sign Flag:** Since MSB was `1`, result is **$-15$**.

---

### Homework Challenge 3: C++ Program to Check if Binary LSB indicates Odd/Even

```cpp
#include <iostream>
using namespace std;

void checkOddEvenBinary(int binNum) {
    int lsb = binNum % 10;
    if (lsb == 1) {
        cout << "Binary " << binNum << " represents an ODD number." << endl;
    } else {
        cout << "Binary " << binNum << " represents an EVEN number." << endl;
    }
}

int main() {
    checkOddEvenBinary(101010); // 42 -> Even
    checkOddEvenBinary(100101); // 37 -> Odd
    return 0;
}

```