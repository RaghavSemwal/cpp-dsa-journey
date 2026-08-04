//## 💻 Section 3: C++ Code Implementation



#include <iostream>
using namespace std;

// ==========================================
// 1. DECIMAL TO BINARY CONVERSION
// Time Complexity: O(log2(N))
// Space Complexity: O(1)
// ==========================================
int decToBinary(int decNum) {
    int ans = 0;
    int pow10 = 1; // Represents 10^0, 10^1, 10^2...

    while (decNum > 0) {
        int rem = decNum % 2;  // Extract binary remainder (0 or 1)
        decNum = decNum / 2;    // Reduce decimal number
        
        ans += (rem * pow10);  // Construct binary number positionally
        pow10 *= 10;           // Shift position in base-10 integer representation
    }

    return ans;
}

// ==========================================
// 2. BINARY TO DECIMAL CONVERSION
// Time Complexity: O(log10(N))
// Space Complexity: O(1)
// ==========================================
int binToDecimal(int binNum) {
    int ans = 0;
    int pow2 = 1; // Represents 2^0, 2^1, 2^2...

    while (binNum > 0) {
        int rem = binNum % 10; // Extract last binary digit
        binNum = binNum / 10;  // Remove last digit
        
        ans += (rem * pow2);   // Multiply bit by positional power of 2
        pow2 *= 2;             // Increase power of 2
    }

    return ans;
}

// ==========================================
// MAIN FUNCTION (Entry Point)
// ==========================================
int main() {
    cout << "========================================" << endl;
    cout << "--- 1. DECIMAL TO BINARY CONVERSION ---" << endl;
    cout << "========================================" << endl;
    
    int dec1 = 42;
    int dec2 = 50;
    cout << "Decimal " << dec1 << " -> Binary: " << decToBinary(dec1) << endl;
    cout << "Decimal " << dec2 << " -> Binary: " << decToBinary(dec2) << endl;

    cout << "\nBinary equivalent of numbers from 1 to 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << " : " << decToBinary(i) << endl;
    }

    cout << "\n========================================" << endl;
    cout << "--- 2. BINARY TO DECIMAL CONVERSION ---" << endl;
    cout << "========================================" << endl;
    
    int bin1 = 101010;
    int bin2 = 110010;
    cout << "Binary " << bin1 << " -> Decimal: " << binToDecimal(bin1) << endl;
    cout << "Binary " << bin2 << " -> Decimal: " << binToDecimal(bin2) << endl;

    return 0;
}


