
#include <iostream>
using namespace std;

// ==========================================
// 1. SIMPLE FUNCTION (VOID RETURN TYPE)
// ==========================================
void printHello() {
    cout << "Hello World!" << endl;
}

// ==========================================
// 2. FUNCTION WITH PARAMETERS & RETURN VALUE
// ==========================================
int calculateSum(int a, int b) {
    int s = a + b;
    return s;
}

// ==========================================
// 3. MINIMUM OF TWO NUMBERS
// ==========================================
int minOfTwo(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// ==========================================
// 4. SUM OF NUMBERS FROM 1 TO N
// ==========================================
int sumN(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// ==========================================
// 5. N FACTORIAL
// ==========================================
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// ==========================================
// 6. PASS BY VALUE DEMONSTRATION
// ==========================================
void changeX(int x) {
    x = 2 * x; // Modifies local copy of x
    cout << "Inside changeX(): x = " << x << endl;
}

// ==========================================
// 7. SUM OF DIGITS OF A NUMBER
// ==========================================
int sumOfDigits(int num) {
    int digitSum = 0;
    while (num > 0) {
        int lastDigit = num % 10; // Extract last digit
        digitSum += lastDigit;    // Add digit to sum
        num /= 10;               // Remove last digit
    }
    return digitSum;
}

// ==========================================
// 8. BINOMIAL COEFFICIENT nCr
// Formula: nCr = n! / (r! * (n - r)!)
// ==========================================
long long nCr(int n, int r) {
    long long fact_n = factorial(n);
    long long fact_r = factorial(r);
    long long fact_nmr = factorial(n - r);

    return fact_n / (fact_r * fact_nmr);
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    cout << "--- 1. BASIC FUNCTION CALL ---" << endl;
    printHello();

    cout << "\n--- 2. PARAMETERS & RETURN ---" << endl;
    cout << "Sum of 10 & 20: " << calculateSum(10, 20) << endl;

    cout << "\n--- 3. MINIMUM OF TWO ---" << endl;
    cout << "Min of 15 & 7: " << minOfTwo(15, 7) << endl;

    cout << "\n--- 4. SUM 1 TO N ---" << endl;
    cout << "Sum 1 to 5: " << sumN(5) << endl;

    cout << "\n--- 5. FACTORIAL ---" << endl;
    cout << "Factorial of 5 (5!): " << factorial(5) << endl;

    cout << "\n--- 6. PASS BY VALUE DEMO ---" << endl;
    int a = 5;
    cout << "Before changeX(): a = " << a << endl;
    changeX(a);
    cout << "After changeX():  a = " << a << " (Unchanged due to Pass By Value)" << endl;

    cout << "\n--- 7. SUM OF DIGITS ---" << endl;
    int num = 2356;
    cout << "Sum of digits of " << num << ": " << sumOfDigits(num) << endl;

    cout << "\n--- 8. BINOMIAL COEFFICIENT (nCr) ---" << endl;
    int n = 8, r = 2;
    cout << n << "C" << r << " = " << nCr(n, r) << endl;

    return 0; // Signals successful program completion
}



