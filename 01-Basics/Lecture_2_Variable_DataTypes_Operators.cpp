#include <iostream>
using namespace std;

int main() {
    // ==========================================
    // 1. BASIC OUTPUT & NEWLINE CHARACTERS
    // ==========================================
    cout << "--- 1. BASIC OUTPUT & NEWLINES ---" << endl;
    cout << "Hello World!" << "\n";
    cout << "Welcome to C++ Programming" << endl;


    // ==========================================
    // 2. VARIABLES & PRIMITIVE DATA TYPES
    // ==========================================
    cout << "\n--- 2. DATA TYPES & SIZEOF ---" << endl;
    int age = 25;
    char grade = 'A';
    float pi = 3.14f;
    double price = 99.99;
    bool isSafe = true;

    cout << "Age (int): " << age << " | Size: " << sizeof(age) << " bytes" << endl;
    cout << "Grade (char): " << grade << " | Size: " << sizeof(grade) << " byte" << endl;
    cout << "PI (float): " << pi << " | Size: " << sizeof(pi) << " bytes" << endl;
    cout << "Price (double): " << price << " | Size: " << sizeof(price) << " bytes" << endl;
    cout << "IsSafe (bool): " << isSafe << " | Size: " << sizeof(isSafe) << " byte" << endl;


    // ==========================================
    // 3. TYPE CONVERSION & TYPE CASTING
    // ==========================================
    cout << "\n--- 3. TYPE CONVERSION & CASTING ---" << endl;
    
    // Implicit Conversion (char -> int using ASCII)
    char ch = 'A';
    int asciiValue = ch; 
    cout << "Implicit Conversion: ASCII of '" << ch << "' = " << asciiValue << endl;

    // Explicit Type Casting (double -> int)
    double itemPrice = 100.99;
    int truncatedPrice = (int)itemPrice; // Truncates decimal part (.99)
    cout << "Explicit Casting: (int)" << itemPrice << " = " << truncatedPrice << endl;


    // ==========================================
    // 4. INPUT USING CIN
    // ==========================================
    cout << "\n--- 4. INPUT OPERATION ---" << endl;
    int userInputAge;
    cout << "Enter your age: ";
    // Uncomment the line below during execution to accept input:
    // cin >> userInputAge; 
    userInputAge = 20; // Default assigned for demonstration
    cout << "Your Age is: " << userInputAge << endl;


    // ==========================================
    // 5. ARITHMETIC OPERATORS & DIVISION BEHAVIOR
    // ==========================================
    cout << "\n--- 5. ARITHMETIC OPERATORS ---" << endl;
    int num1 = 10, num2 = 5;

    cout << "Addition (10 + 5): " << (num1 + num2) << endl;
    cout << "Subtraction (10 - 5): " << (num1 - num2) << endl;
    cout << "Multiplication (10 * 5): " << (num1 * num2) << endl;
    cout << "Division (10 / 5): " << (num1 / num2) << endl;
    cout << "Modulo/Remainder (11 % 5): " << (11 % 5) << endl;

    // Integer Division vs Floating-point Division
    cout << "Int Division (5 / 2): " << (5 / 2) << endl; // Result: 2
    cout << "Float Division (5.0 / 2): " << (5.0 / 2) << endl; // Result: 2.5
    cout << "Typecast Division ((double)5 / 2): " << ((double)5 / 2) << endl; // Result: 2.5


    // ==========================================
    // 6. RELATIONAL OPERATORS
    // ==========================================
    cout << "\n--- 6. RELATIONAL OPERATORS ---" << endl;
    cout << "(3 < 5): " << (3 < 5) << " (True = 1)" << endl;
    cout << "(3 > 5): " << (3 > 5) << " (False = 0)" << endl;
    cout << "(3 == 3): " << (3 == 3) << endl;
    cout << "(3 != 5): " << (3 != 5) << endl;


    // ==========================================
    // 7. LOGICAL OPERATORS
    // ==========================================
    cout << "\n--- 7. LOGICAL OPERATORS ---" << endl;
    // Logical NOT (!)
    cout << "!(3 > 1): " << (!(3 > 1)) << endl; // Inverts True to False (0)

    // Logical OR (||) -> True if at least one condition is true
    cout << "(3 < 1 || 3 < 5): " << ((3 < 1) || (3 < 5)) << endl; 

    // Logical AND (&&) -> True only if both conditions are true
    cout << "(3 > 1 && 3 > 2): " << ((3 > 1) && (3 > 2)) << endl;


    // ==========================================
    // 8. UNARY OPERATORS (INCREMENT & DECREMENT)
    // ==========================================
    cout << "\n--- 8. UNARY OPERATORS ---" << endl;
    
    // Post-Increment vs Pre-Increment
    int a = 10;
    int b = a++; // Post-increment: Assign 'a' to 'b' first (10), then increment 'a' (11)
    cout << "Post-Increment (b = a++): b = " << b << ", a = " << a << endl;

    int x = 10;
    int y = ++x; // Pre-increment: Increment 'x' first (11), then assign to 'y' (11)
    cout << "Pre-Increment  (y = ++x): y = " << y << ", x = " << x << endl;

    // Post-Decrement vs Pre-Decrement
    int p = 10;
    int q = p--; // Post-decrement: Assign first (10), then decrement 'p' (9)
    cout << "Post-Decrement (q = p--): q = " << q << ", p = " << p << endl;

    int m = 10;
    int n = --m; // Pre-decrement: Decrement first (9), then assign to 'n' (9)
    cout << "Pre-Decrement  (n = --m): n = " << n << ", m = " << m << endl;


    // ==========================================
    // 9. PRACTICAL EXAMPLE: SUM OF 2 NUMBERS
    // ==========================================
    cout << "\n--- 9. PRACTICAL EXERCISE: SUM OF TWO NUMBERS ---" << endl;
    int val1 = 15, val2 = 25;
    int sum = val1 + val2;
    cout << "Sum of " << val1 << " and " << val2 << " = " << sum << endl;

    return 0; // Indicates successful execution
}

