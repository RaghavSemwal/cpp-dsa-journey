


//### Homework Challenge 3: C++ Program to Check if Binary LSB indicates Odd/Even


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

