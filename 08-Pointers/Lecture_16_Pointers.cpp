

// ## 💻 Section 3: Comprehensive C++ Code Implementation

// Below is a single executable C++ file covering all pointer concepts taught in Lecture 16 with detailed inline comments.


#include <iostream>
using namespace std;

// ==========================================
// 1. BASIC POINTER & DEREFERENCING
// ==========================================
void demoPointersBasics() {
    cout << "--- 1. BASIC POINTERS & DEREFERENCING ---" << endl;
    int a = 10;
    int* ptr = &a; // 'ptr' holds address of 'a'

    cout << "Value of a            : " << a << endl;
    cout << "Address of a (&a)     : " << &a << endl;
    cout << "Value of ptr (Addr)   : " << ptr << endl;
    cout << "Address of ptr (&ptr) : " << &ptr << endl;
    cout << "Dereferenced (*ptr)   : " << *ptr << " (Value at address of a)" << endl;

    // In-place modification via pointer
    *ptr = 25;
    cout << "Updated value of a    : " << a << " (Modified via *ptr = 25)" << endl;
}

// ==========================================
// 2. POINTER-TO-POINTER (DOUBLE POINTER)
// ==========================================
void demoDoublePointer() {
    cout << "\n--- 2. POINTER TO POINTER ---" << endl;
    int val = 50;
    int* p = &val;   // Single Pointer
    int** q = &p;    // Double Pointer

    cout << "val   : " << val << endl;
    cout << "*p    : " << *p << " (Dereference 1 Level)" << endl;
    cout << "**q   : " << **q << " (Dereference 2 Levels)" << endl;
    cout << "p     : " << p << " (Address of val)" << endl;
    cout << "*q    : " << *q << " (Address of val via *q)" << endl;
    cout << "&p    : " << &p << " (Address of pointer p)" << endl;
    cout << "q     : " << q << " (Address of pointer p stored in q)" << endl;
}

// ==========================================
// 3. PASS BY REFERENCE DEMO
// ==========================================
void passByValue(int x) {
    x = 100;
}

void passByPointer(int* ptr) {
    *ptr = 200; // Modifies original variable
}

void passByReferenceAlias(int &ref) {
    ref = 300;  // Modifies original variable via alias
}

void demoPassByReference() {
    cout << "\n--- 3. PASS BY REFERENCE DEMO ---" << endl;
    int num = 10;

    passByValue(num);
    cout << "After passByValue()         : " << num << " (Unchanged)" << endl;

    passByPointer(&num);
    cout << "After passByPointer(&num)   : " << num << " (Updated to 200)" << endl;

    passByReferenceAlias(num);
    cout << "After passByRefAlias(num)   : " << num << " (Updated to 300)" << endl;
}

// ==========================================
// 4. ARRAY POINTERS & POINTER ARITHMETIC
// ==========================================
void demoPointerArithmetic() {
    cout << "\n--- 4. ARRAY POINTERS & ARITHMETIC ---" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr; // Same as ptr = &arr[0]

    cout << "Base address of arr   : " << arr << endl;
    cout << "*arr (arr[0])         : " << *arr << endl;
    cout << "*(arr + 1) (arr[1])   : " << *(arr + 1) << endl;
    cout << "*(arr + 2) (arr[2])   : " << *(arr + 2) << endl;

    // Pointer Addition / Subtraction
    cout << "\nPointer Address Traversals:" << endl;
    cout << "ptr at start  : " << ptr << " | Value: " << *ptr << endl;
    ptr++;
    cout << "ptr after ++  : " << ptr << " | Value: " << *ptr << " (+4 bytes)" << endl;
    ptr += 2;
    cout << "ptr after +=2 : " << ptr << " | Value: " << *ptr << " (+8 bytes)" << endl;

    // Pointer Subtraction (Distance in elements)
    int* ptr1 = &arr[4]; // Points to 50
    int* ptr2 = &arr[1]; // Points to 20
    cout << "\nptr1 - ptr2 = " << (ptr1 - ptr2) << " elements apart (Index 4 - Index 1)" << endl;

    // Pointer Comparison
    cout << "Is ptr1 > ptr2? " << (ptr1 > ptr2 ? "True" : "False") << endl;
}

// ==========================================
// 5. NULL POINTER DEMO
// ==========================================
void demoNullPointer() {
    cout << "\n--- 5. NULL POINTER DEMO ---" << endl;
    int* nullPtr = nullptr;
    cout << "Null pointer value: " << nullPtr << endl;
    // Note: Dereferencing nullPtr (*nullPtr) causes a runtime Segmentation Fault
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    demoPointersBasics();
    demoDoublePointer();
    demoPassByReference();
    demoPointerArithmetic();
    demoNullPointer();

    return 0; // Signals successful execution
}


