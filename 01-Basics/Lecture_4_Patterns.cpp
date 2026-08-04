#include <iostream>
using namespace std;

int main() {
    int n = 4; // Standard grid size for demonstrations

    // ==========================================
    // PATTERN 1: SQUARE PATTERN (NUMBERS)
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // ==========================================
    cout << "--- 1. SQUARE PATTERN (NUMBERS) ---" << endl;
    for (int i = 0; i < n; i++) {           // Outer loop -> Rows
        for (int j = 1; j <= n; j++) {      // Inner loop -> Columns (1 to n)
            cout << j << " ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 2: SQUARE PATTERN (STARS)
    // * * * *
    // * * * *
    // * * * *
    // * * * *
    // ==========================================
    cout << "\n--- 2. SQUARE PATTERN (STARS) ---" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 3: SQUARE PATTERN (CHARACTERS)
    // A B C D
    // A B C D
    // A B C D
    // A B C D
    // ==========================================
    cout << "\n--- 3. SQUARE PATTERN (CHARACTERS) ---" << endl;
    for (int i = 0; i < n; i++) {
        char ch = 'A';                      // Reset character to 'A' at start of each line
        for (int j = 0; j < n; j++) {
            cout << ch << " ";
            ch = ch + 1;                    // Implicit conversion increments ASCII value
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 4: CONTINUOUS NUMBER SQUARE
    // 1  2  3  4
    // 5  6  7  8
    // 9  10 11 12
    // 13 14 15 16
    // ==========================================
    cout << "\n--- 4. CONTINUOUS NUMBER SQUARE ---" << endl;
    int num = 1;                            // State variable outside loops to prevent resetting
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 5: TRIANGLE PATTERN (STARS)
    // *
    // * *
    // * * *
    // * * * *
    // ==========================================
    cout << "\n--- 5. TRIANGLE PATTERN (STARS) ---" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {   // Row i prints (i + 1) stars
            cout << "* ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 6: TRIANGLE PATTERN (SAME ROW NUMBER)
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // ==========================================
    cout << "\n--- 6. TRIANGLE PATTERN (SAME ROW NUMBER) ---" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << (i + 1) << " ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 7: TRIANGLE PATTERN (INCREMENTING COLS)
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // ==========================================
    cout << "\n--- 7. TRIANGLE PATTERN (INCREMENTING COLS) ---" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 8: REVERSE TRIANGLE PATTERN
    // 1
    // 2 1
    // 3 2 1
    // 4 3 2 1
    // ==========================================
    cout << "\n--- 8. REVERSE TRIANGLE PATTERN ---" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j > 0; j--) {   // Backward inner loop
            cout << j << " ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 9: FLOYD'S TRIANGLE PATTERN
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // ==========================================
    cout << "\n--- 9. FLOYD'S TRIANGLE PATTERN ---" << endl;
    int floydNum = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << floydNum << " ";
            floydNum++;
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 10: INVERTED TRIANGLE PATTERN
    // 1 1 1 1
    //   2 2 2
    //     3 3
    //       4
    // ==========================================
    cout << "\n--- 10. INVERTED TRIANGLE PATTERN ---" << endl;
    for (int i = 0; i < n; i++) {
        // Spaces: i spaces per line
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        // Numbers: (n - i) numbers per line
        for (int j = 0; j < n - i; j++) {
            cout << (i + 1) << " ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 11: FULL PYRAMID PATTERN
    //       1
    //     1 2 1
    //   1 2 3 2 1
    // 1 2 3 4 3 2 1
    // ==========================================
    cout << "\n--- 11. FULL PYRAMID PATTERN ---" << endl;
    for (int i = 0; i < n; i++) {
        // 1. Spaces: (n - i - 1)
        for (int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }
        // 2. Set 1 Numbers: 1 to (i + 1)
        for (int j = 1; j <= i + 1; j++) {
            cout << j << " ";
        }
        // 3. Set 2 Numbers: i down to 1
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }


    // ==========================================
    // PATTERN 12: HOLLOW DIAMOND PATTERN
    //       *
    //     *   *
    //   *       *
    // *           *
    //   *       *
    //     *   *
    //       *
    // ==========================================
    cout << "\n--- 12. HOLLOW DIAMOND PATTERN ---" << endl;
    
    // Top Half (n lines)
    for (int i = 0; i < n; i++) {
        // Spaces outside
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // First star
        cout << "*";
        // Spaces inside: (2*i - 1)
        if (i != 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            // Second star
            cout << "*";
        }
        cout << endl;
    }

    // Bottom Half (n - 1 lines)
    for (int i = 0; i < n - 1; i++) {
        // Spaces outside
        for (int j = 0; j < i + 1; j++) {
            cout << " ";
        }
        // First star
        cout << "*";
        // Spaces inside
        if (i != n - 2) {
            for (int j = 0; j < 2 * (n - i - 2) - 1; j++) {
                cout << " ";
            }
            // Second star
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}