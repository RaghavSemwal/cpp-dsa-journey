

//## 📝 Homework Challenge (From Lecture)

//**Task:** Build a Simple Calculator Program in C++ that takes two numbers as input and outputs their Addition, Subtraction, Multiplication, Division, and Modulo.

//```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    cout << "\n--- CALCULATOR RESULTS ---" << endl;
    cout << "Addition: " << (a + b) << endl;
    cout << "Subtraction: " << (a - b) << endl;
    cout << "Multiplication: " << (a * b) << endl;
    if (b != 0) {
        cout << "Division: " << (a / b) << endl;
        cout << "Modulo: " << ((int)a % (int)b) << endl; // Explicitly cast to int for modulo
    } else {
        cout << "Division by zero is not allowed!" << endl;
    }

    return 0;
}

//```