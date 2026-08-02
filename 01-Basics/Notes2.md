# Complete Lecture Notes: Variables, Data Types & Operators in C++

*(DSA Series by Shradha Ma'am - Apna College, Lecture 2)*

---

## 📌 Section 1: Overview & Key Concepts

### 1. Boilerplate Code & Basic Output

* **Case Sensitivity:** C++ is a strictly case-sensitive language (e.g., `cout` is valid, but `Cout` or `COUT` will throw a compilation error).
* **`cout`**: Used for sending output to the standard output stream.
* **Header Files & Namespace:**
* `#include <iostream>`: Preprocessor directive that includes the input-output stream library containing definitions for `cout`, `cin`, etc.
* `using namespace std;`: Allows using standard library entities (like `cout`, `cin`) without prefixing them with `std::`.


* **Main Function:** `int main()` is the entry point of every C++ program.
* **Terminators & Newlines:**
* `;` (Semicolon): Terminating character for statements (like a period in English).
* `endl` or `\n`: Used to insert a newline. (`\n` is slightly faster as it avoids flushing the buffer explicitly).



---

### 2. Variables & Memory Allocation

* **Variables:** Named storage containers in memory to store data values (e.g., `int age = 25;`).
* **Identifiers Rules:**
* Variable names can start with letters (`a-z`, `A-Z`) or an underscore (`_`).
* Variable names **cannot** start with numbers (e.g., `9age` is invalid).


* **Memory Concept:** Variables reserve specific bytes in RAM. Data is stored internally in binary format (`0`s and `1`s).

---

### 3. Primitive Data Types & Sizes

| Data Type | Keyword | Size in Memory | Example Values | Notes / Behavior |
| --- | --- | --- | --- | --- |
| **Integer** | `int` | 4 Bytes (32 bits) | `25`, `-10`, `0` | Whole numbers without decimals. |
| **Character** | `char` | 1 Byte (8 bits) | `'A'`, `'a'`, `'@'` | Stored internally using ASCII values (e.g., `'A'` = 65, `'a'` = 97). |
| **Float** | `float` | 4 Bytes (32 bits) | `3.14f`, `1.99f` | Floating-point (decimal) numbers. Suffix `f` is recommended. |
| **Double** | `double` | 8 Bytes (64 bits) | `3.14159265` | Double precision decimal numbers (default for decimals). |
| **Boolean** | `bool` | 1 Byte | `true` (1), `false` (0) | Represents logical binary state. Output prints as `1` or `0`. |

---

### 4. Type Casting & Conversion

* **Type Conversion (Implicit):**
* Automatic conversion by the compiler.
* Occurs when converting a smaller type to a larger type (e.g., `char` to `int`).
* No data loss (e.g., `'A'` automatically becomes `65`).


* **Type Casting (Explicit):**
* Manual conversion forced by the programmer: `(type) value`.
* Converting a larger type to a smaller type (e.g., `double` to `int`).
* Truncates decimal values (e.g., `(int)100.99` becomes `100`, not rounded to `101`).



---

### 5. Input Operations

* **`cin`**: Global input object used to read data from standard input (keyboard) using the extraction operator `>>`.
* Syntax: `cin >> variableName;`



---

### 6. Operators Summary

1. **Arithmetic Operators:**
* `+` (Add), `-` (Subtract), `*` (Multiply), `/` (Divide), `%` (Modulo / Remainder).
* **Note on Division:** `int / int` yields an `int` (truncates decimal). To get a decimal output, at least one operand must be a `float` or `double`.


2. **Relational Operators:**
* `<`, `<=`, `>`, `>=`, `==` (Equal check), `!=` (Not equal).
* Returns boolean output (`1` for true, `0` for false).


3. **Logical Operators:**
* `&&` (Logical AND): True if **all** conditions are true.
* `||` (Logical OR): True if **at least one** condition is true.
* `!` (Logical NOT): Inverts the boolean result (True → False, False → True).


4. **Unary Operators (Increment & Decrement):**
* **Post-Increment (`a++`):** Uses current value first, then updates (`a = a + 1`).
* **Pre-Increment (`++a`):** Updates value first (`a = a + 1`), then uses updated value.
* **Post-Decrement (`a--`):** Uses current value first, then decrements.
* **Pre-Decrement (`--a`):** Decrements first, then uses updated value.



---

