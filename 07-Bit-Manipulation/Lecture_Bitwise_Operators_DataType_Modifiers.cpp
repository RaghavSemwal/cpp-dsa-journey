

#include <iostream>
using namespace std;

// Global Variable (Accessible throughout the entire file)
int globalVar = 100;

// ==========================================
// 1. BITWISE OPERATORS DEMONSTRATION
// ==========================================
void demoBitwiseOperators() {
    cout << "--- 1. BITWISE OPERATORS ---" << endl;
    int a = 4; // Binary: 0100
    int b = 8; // Binary: 1000

    cout << "a & b (4 & 8)   : " << (a & b) << endl; // Output: 0
    cout << "a | b (4 | 8)   : " << (a | b) << endl; // Output: 12
    cout << "a ^ b (4 ^ 8)   : " << (a ^ b) << endl; // Output: 12

    int x = 3; // Binary: 0011
    int y = 7; // Binary: 0111
    cout << "x ^ y (3 ^ 7)   : " << (x ^ y) << endl; // Output: 4

    // Shift Operators
    int num = 10; // Binary: 1010
    cout << "10 << 1 (Left)  : " << (num << 1) << " (10 * 2^1)" << endl; // Output: 20
    cout << "10 << 2 (Left)  : " << (num << 2) << " (10 * 2^2)" << endl; // Output: 40
    cout << "10 >> 1 (Right) : " << (num >> 1) << " (10 / 2^1)" << endl; // Output: 5
    cout << "8 >> 2  (Right) : " << (8 >> 2)   << " (8 / 2^2)"  << endl; // Output: 2
}

// ==========================================
// 2. OPERATOR PRECEDENCE & ASSOCIATIVITY
// ==========================================
void demoPrecedence() {
    cout << "\n--- 2. OPERATOR PRECEDENCE ---" << endl;
    
    // Multiplicative operators (*, /) have higher precedence than additive (-)
    int res1 = 5 - 2 * 6; // Evaluates as 5 - (2 * 6) = -7
    cout << "5 - 2 * 6 = " << res1 << endl;

    // Parentheses override precedence
    int res2 = (5 - 2) * 6; // Evaluates as (3) * 6 = 18
    cout << "(5 - 2) * 6 = " << res2 << endl;

    // Left-to-Right Associativity for equal precedence (* and %)
    int res3 = 4 * 5 % 2; // Evaluates as (4 * 5) % 2 = 20 % 2 = 0
    cout << "4 * 5 % 2 = " << res3 << endl;
}

// ==========================================
// 3. VARIABLE SCOPE DEMONSTRATION
// ==========================================
void demoScope() {
    cout << "\n--- 3. VARIABLE SCOPE ---" << endl;
    
    int localVar = 20; // Function-level local variable
    cout << "Global Var accessed inside function : " << globalVar << endl;
    cout << "Local Var accessed inside function  : " << localVar << endl;

    { // Independent Block Scope
        int blockVar = 50;
        cout << "Block Var inside its block         : " << blockVar << endl;
        cout << "Local Var accessed inside block     : " << localVar << endl;
    }
    // blockVar is inaccessible here (Memory freed)
}

// ==========================================
// 4. DATA TYPE MODIFIERS
// ==========================================
void demoModifiers() {
    cout << "\n--- 4. DATA TYPE MODIFIERS ---" << endl;
    
    cout << "Size of int          : " << sizeof(int) << " bytes" << endl;
    cout << "Size of long int     : " << sizeof(long int) << " bytes" << endl;
    cout << "Size of long long int: " << sizeof(long long int) << " bytes" << endl;
    cout << "Size of short int    : " << sizeof(short int) << " bytes" << endl;

    // Unsigned Data Type Behavior
    unsigned int unsignedNum = 10;
    cout << "Unsigned Int Value   : " << unsignedNum << endl;
    
    // Assigning negative to unsigned leads to large positive value (2's complement wrap-around)
    unsigned int negUnsigned = -10;
    cout << "Unsigned Int (-10)   : " << negUnsigned << " (Wrap-around output)" << endl;
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    demoBitwiseOperators();
    demoPrecedence();
    demoScope();
    demoModifiers();

    return 0;
}

