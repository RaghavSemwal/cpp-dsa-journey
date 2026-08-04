 📝 Section 3: Homework Exercises & Solutions

### Exercise 1: Continuous Character Square

**Pattern:**

```text
A B C
D E F
G H I

```

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    char ch = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
    return 0;
}

```

---

### Exercise 2: Character Triangle Pattern

**Pattern:**

```text
A
B B
C C C
D D D D

```

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for (int i = 0; i < n; i++) {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}

```

---

### Exercise 3: Character Floyd's Triangle Pattern

**Pattern:**

```text
A
B C
D E F
G H I J

```

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    char ch = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
    return 0;
}

```

---

### Exercise 4: Reverse Character Triangle Pattern

**Pattern:**

```text
A
B A
C B A
D C B A

```

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for (int i = 0; i < n; i++) {
        char ch = 'A' + i;
        for (int j = i; j >= 0; j--) {
            cout << (char)('A' + j) << " ";
        }
        cout << endl;
    }
    return 0;
}

```

---

### Exercise 5: Inverted Character Triangle Pattern

**Pattern:**

```text
A A A A
  B B B
    C C
      D

```

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for (int i = 0; i < n; i++) {
        // Spaces
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        // Characters
        char ch = 'A' + i;
        for (int j = 0; j < n - i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}

```

---

### Exercise 6: Butterfly Pattern

**Pattern (for $n=4$):**

```text
*       *
**     **
***   ***
**** ****
**** ****
***   ***
**     **
*       *

```

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 4;

    // Top Half
    for (int i = 1; i <= n; i++) {
        // Left Stars
        for (int j = 1; j <= i; j++) cout << "*";
        // Spaces
        for (int j = 1; j <= 2 * (n - i); j++) cout << " ";
        // Right Stars
        for (int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }

    // Bottom Half
    for (int i = n; i >= 1; i--) {
        // Left Stars
        for (int j = 1; j <= i; j++) cout << "*";
        // Spaces
        for (int j = 1; j <= 2 * (n - i); j++) cout << " ";
        // Right Stars
        for (int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }

    return 0;
}

```