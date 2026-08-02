# Complete Lecture Notes: Conditional Statements & Loops in C++

*(DSA Series by Shradha Ma'am - Apna College, Lecture 3)*

---

## 📌 Section 1: Detailed Chapter Notes & Concepts

### 1. Conditional Statements

Conditional statements allow executables to make decisions based on runtime conditions (evaluating to either `true` or `false`).

#### A. `if-else` Statement

* **Syntax:**
```cpp
if (condition) {
    // Code executes if condition is true
} else {
    // Code executes if condition is false
}

```


* **Key Concept:** Single statements do not strictly require curly braces `{}` in C++, but applying them is a standard practice to construct multi-line blocks and improve maintainability.

#### B. `else-if` Ladder

Used when evaluating multiple non-overlapping or sequential conditions.

* **Syntax:**
```cpp
if (condition1) {
    // Block 1
} else if (condition2) {
    // Block 2
} else {
    // Default Fallback Block
}

```



#### C. Ternary Operator

A shorthand syntax for simple `if-else` assignments/evaluations.

* **Syntax:** `condition ? expression1 : expression2;`
* **Behavior:** If `condition` evaluates to `true`, `expression1` executes; otherwise, `expression2` executes.

---

### 2. Character Checking & Implicit Type Casting

* Computers store characters using ASCII numerical values (e.g., `'a'` = `97`, `'z'` = `122`, `'A'` = `65`, `'Z'` = `90`).
* When comparing a `char` directly with integer ASCII values (e.g., `ch >= 65 && ch <= 90`), C++ performs **implicit type conversion** by evaluating the character's ASCII integer value automatically.

---

### 3. Iterative Statements (Loops)

Loops enable executing a block of code repeatedly while a specific boolean condition remains `true`.

#### A. `while` Loop

Evaluates the condition **before** entering the loop body (entry-controlled loop).

```cpp
while (condition) {
    // Loop body
    // Updation statement
}

```

#### B. `for` Loop

Combines Initialization, Condition, and Updation into a concise single line.

```cpp
for (initialization; condition; updation) {
    // Loop body
}

```

* **Execution Flow:**
1. Initialization (runs once at start).
2. Condition Evaluation.
3. Body execution (if condition is `true`).
4. Updation.
5. Repeat steps 2–4.



#### C. `do-while` Loop

Evaluates the condition **after** executing the loop body (exit-controlled loop). Guaranteed to execute **at least once**, even if the condition is initially `false`.

```cpp
do {
    // Loop body
} while (condition); // Note the semicolon

```

---

### 4. Control Flow & Optimization Keyword

* **`break` Keyword:** Immediately terminates the nearest enclosing loop and transfers control to the statement following the loop.

---

### 5. Prime Number Check Optimization

* **Naive Approach:** Iterating from `2` to `n - 1` to check if `n % i == 0`. Time Complexity: $\mathcal{O}(n)$.
* **Optimized Approach ($\mathcal{O}(\sqrt{n})$):**
* Factors of any number $n$ repeat after $\sqrt{n}$ (e.g., for $n=12$: $1 \times 12$, $2 \times 6$, $3 \times 4$, $4 \times 3$, $6 \times 2$, $12 \times 1$).
* Unique non-trivial factors exist only up to $\sqrt{n}$.
* **Loop Condition:** Instead of using the costly `sqrt(n)` function, express $\sqrt{n}$ as `i * i <= n`.



---

### 6. Introduction to Nested Loops

* A loop placed inside another loop.
* **Structure:**
* **Outer Loop:** Controls rows/lines (outer iterations).
* **Inner Loop:** Controls columns/actions per row (inner iterations).


* Best practice: Use distinct iteration variables for outer and inner loops (e.g., `i` for outer, `j` for inner).

---

## 💻 Section 2: Comprehensive Code Implementation

Below is a single C++ program containing all topics covered in Lecture 3, complete with modular sections and detailed inline comments.

```cpp
#include <iostream>
using namespace std;

int main() {
    // ==========================================
    // 1. IF-ELSE: POSITIVE / NEGATIVE CHECK
    // ==========================================
    cout << "--- 1. IF-ELSE (POSITIVE / NEGATIVE) ---" << endl;
    int num = -45;
    if (num >= 0) {
        cout << num << " is Positive." << endl;
    } else {
        cout << num << " is Negative." << endl;
    }

    // ==========================================
    // 2. IF-ELSE: EVEN / ODD CHECK
    // ==========================================
    cout << "\n--- 2. IF-ELSE (EVEN / ODD) ---" << endl;
    int number = 16;
    if (number % 2 == 0) {
        cout << number << " is Even." << endl;
    } else {
        cout << number << " is Odd." << endl;
    }

    // ==========================================
    // 3. ELSE-IF LADDER: STUDENT GRADING SYSTEM
    // ==========================================
    cout << "\n--- 3. ELSE-IF LADDER (GRADING SYSTEM) ---" << endl;
    int marks = 85;
    if (marks >= 90) {
        cout << "Grade: A" << endl;
    } else if (marks >= 80 && marks < 90) {
        cout << "Grade: B" << endl;
    } else {
        cout << "Grade: C" << endl;
    }

    // ==========================================
    // 4. CHARACTER CHECK (ASCII IMPLICIT CONVERSION)
    // ==========================================
    cout << "\n--- 4. CHARACTER CASE CHECK ---" << endl;
    char ch = 'b';
    
    // Direct Character Comparison
    if (ch >= 'a' && ch <= 'z') {
        cout << "'" << ch << "' is Lowercase." << endl;
    } else if (ch >= 'A' && ch <= 'Z') {
        cout << "'" << ch << "' is Uppercase." << endl;
    }

    // ASCII Numerical Comparison (Demonstrating Implicit Type Conversion)
    // 'A' = 65, 'Z' = 90
    if (ch >= 65 && ch <= 90) {
        cout << "ASCII Check: Uppercase" << endl;
    } else {
        cout << "ASCII Check: Lowercase" << endl;
    }

    // ==========================================
    // 5. TERNARY OPERATOR
    // ==========================================
    cout << "\n--- 5. TERNARY OPERATOR ---" << endl;
    int val = 20;
    bool isPositive = (val >= 0) ? true : false;
    cout << val << " is Positive? " << (isPositive ? "Yes" : "No") << endl;

    // ==========================================
    // 6. WHILE LOOP: PRINT 1 TO N
    // ==========================================
    cout << "\n--- 6. WHILE LOOP (1 TO 5) ---" << endl;
    int count = 1;
    int target = 5;
    while (count <= target) {
        cout << count << " ";
        count++; // Updation statement
    }
    cout << endl;

    // ==========================================
    // 7. FOR LOOP & SUM OF 1 TO N
    // ==========================================
    cout << "\n--- 7. FOR LOOP (SUM OF 1 TO N) ---" << endl;
    int n = 5;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i; // sum = sum + i
    }
    cout << "Sum from 1 to " << n << " = " << sum << endl;

    // ==========================================
    // 8. SUM OF ALL ODD NUMBERS FROM 1 TO N
    // ==========================================
    cout << "\n--- 8. SUM OF ODD NUMBERS (1 TO N) ---" << endl;
    int limit = 10;
    int oddSum = 0;
    for (int i = 1; i <= limit; i++) {
        if (i % 2 != 0) { // Check for odd
            oddSum += i;
        }
    }
    cout << "Sum of Odd numbers from 1 to " << limit << " = " << oddSum << endl;

    // ==========================================
    // 9. DO-WHILE LOOP
    // ==========================================
    cout << "\n--- 9. DO-WHILE LOOP ---" << endl;
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= 3);
    cout << endl;

    // Demonstration: Executes once even if condition is false
    int falseVar = 10;
    do {
        cout << "Do-While executed at least once despite false condition." << endl;
    } while (falseVar < 5);

    // ==========================================
    // 10. OPTIMIZED PRIME NUMBER CHECK O(sqrt(N))
    // ==========================================
    cout << "\n--- 10. OPTIMIZED PRIME NUMBER CHECK ---" << endl;
    int checkNum = 17;
    bool isPrime = true;

    // Checking factors up to sqrt(N) via i * i <= checkNum
    for (int i = 2; i * i <= checkNum; i++) {
        if (checkNum % i == 0) {
            isPrime = false;
            break; // Terminate loop early upon finding a factor
        }
    }

    if (isPrime && checkNum > 1) {
        cout << checkNum << " is a Prime Number." << endl;
    } else {
        cout << checkNum << " is NOT a Prime Number." << endl;
    }

    // ==========================================
    // 11. NESTED LOOPS (STAR RECTANGLE PATTERN)
    // ==========================================
    cout << "\n--- 11. NESTED LOOPS (4x5 STAR PATTERN) ---" << endl;
    int rows = 4;
    int cols = 5;

    for (int i = 1; i <= rows; i++) {        // Outer Loop -> Rows
        for (int j = 1; j <= cols; j++) {    // Inner Loop -> Columns
            cout << "* ";
        }
        cout << endl;                        // Move to next line after completing a row
    }

    return 0;
}

```

