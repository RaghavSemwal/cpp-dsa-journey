# Complete Lecture Notes: Bitwise Operators, Data Type Modifiers & Scope in C++


---

## 📌 Section 1: Comprehensive Lecture Notes & Concepts

### 1. Bitwise Operators

Bitwise operators perform manipulations directly on the binary bit representations (0s and 1s) of integer operands.

#### A. Bitwise AND (`&`)

* Output bit is `1` **only if both** corresponding input bits are `1`. Otherwise, it evaluates to `0`.
* **Truth Table:**
* `0 & 0 = 0`
* `0 & 1 = 0`
* `1 & 0 = 0`
* `1 & 1 = 1`



#### B. Bitwise OR (`|`)

* Output bit is `1` if **at least one** corresponding input bit is `1`.
* **Truth Table:**
* `0 | 0 = 0`
* `0 | 1 = 1`
* `1 | 0 = 1`
* `1 | 1 = 1`



#### C. Bitwise XOR (`^` - Exclusive OR)

* Output bit is `1` if the corresponding input bits are **different** (opposite). If bits are the **same**, it evaluates to `0`.
* **Truth Table:**
* `0 ^ 0 = 0` (Same $\rightarrow$ 0)
* `0 ^ 1 = 1` (Different $\rightarrow$ 1)
* `1 ^ 0 = 1` (Different $\rightarrow$ 1)
* `1 ^ 1 = 0` (Same $\rightarrow$ 0)



#### D. Bitwise Left Shift (`<<`)

* Shifts all bits to the left by a specified number of positions (`b`).
* Vacated rightmost positions are filled with `0`s.
* **Mathematical Formula:**

$$a \ll b = a \times 2^b$$



*(e.g., $4 \ll 1 = 4 \times 2^1 = 8$)*

#### E. Bitwise Right Shift (`>>`)

* Shifts all bits to the right by a specified number of positions (`b`).
* Rightmost shifted-out bits are discarded; leftmost positions are filled with `0`s (for positive numbers).
* **Mathematical Formula:**

$$a \gg b = \left\lfloor \frac{a}{2^b} \right\rfloor$$



*(e.g., $8 \gg 1 = \frac{8}{2^1} = 4$)*

---

### 2. Operator Precedence & Associativity

Determines the evaluation order when multiple operators exist within a single expression.

* **High Level Hierarchy Rule-of-Thumb:**
1. Parentheses `()` $\rightarrow$ Highest Priority (Overrides default precedence).
2. Unary / Increment Operators (`++`, `--`, `!`).
3. Arithmetic Operators (`*`, `/`, `%` before `+`, `-`).
4. Bitwise Shift Operators (`<<`, `>>`).
5. Relational Operators (`<`, `>`, `<=`, `>=`).
6. Equality Operators (`==`, `!=`).
7. Bitwise Operators (`&`, `^`, `|`).
8. Logical Operators (`&&`, `||`).
9. Assignment Operators (`=`, `+=`, etc.) $\rightarrow$ Lowest Priority.


* **Associativity:** Specifies evaluation direction (Left-to-Right or Right-to-Left) when operators share equal precedence.
* Most binary operators evaluate **Left-to-Right** (e.g., `4 * 5 % 2` $\rightarrow$ `(4 * 5) % 2 = 0`).



---

### 3. Variable Scope

The scope defines the region of code where a declared variable remains valid and accessible in memory.

* **Local Scope:**
* Variables declared inside a specific code block `{}` (functions, loops, `if-else` blocks).
* Memory is allocated upon entering the block and destroyed as soon as execution leaves the block.


* **Global Scope:**
* Variables declared outside all functions (at file-level).
* Accessible from any part of the program throughout its execution life cycle.



---

### 4. Data Type Modifiers

Used to alter the storage size capacity or sign properties of standard primitive data types (primarily `int` and `double`).

* **`long`:** Increases storage capacity (minimum $\ge$ 4 bytes; typically 8 bytes on 64-bit systems).
* **`long long`:** Guarantees 8 bytes (64 bits) of storage.
* **`short`:** Decreases storage size to 2 bytes (16 bits) to conserve memory.
* **`signed`:** Default setting. Can store both negative and positive numbers (MSB acts as the sign flag). Range for 32-bit `int`: $[-2^{31}, 2^{31}-1]$.
* **`unsigned`:** Can store **only non-negative** numbers ($0$ and positive). Reclaims the MSB sign bit for magnitude, doubling the positive range ($[0, 2^{32}-1]$).

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Bitwise Operations Breakdown (4 = `0100`, 8 = `1000`)

```text
1. Bitwise AND (4 & 8)         2. Bitwise OR (4 | 8)          3. Bitwise XOR (3 ^ 7)
    0 1 0 0  (4)                   0 1 0 0  (4)                   0 0 1 1  (3)
  & 1 0 0 0  (8)                 | 1 0 0 0  (8)                 ^ 0 1 1 1  (7)
  ---------                     ---------                     ---------
    0 0 0 0  = 0 (Decimal)         1 1 0 0  = 12 (Decimal)        0 1 0 0  = 4 (Decimal)

```

---

### Visual 2: Bitwise Shift Mechanics

```text
LEFT SHIFT (n << 1) : 4 << 1
Initial (4):  [0][1][0][0]  
               /  /  /  
Shift Left:  [1][0][0][0]  <-- Append 0 at LSB
Result: 8

RIGHT SHIFT (n >> 1) : 10 >> 1
Initial (10): [1][0][1][0]  --> (LSB '0' Discarded)
               \  \  \ 
Shift Right: [0][1][0][1]  <-- Prepend 0 at MSB
Result: 5

```

---

### Visual 3: Memory Layout of Local Scope vs. Call Stack

```text
+-------------------------------------------------------+
| GLOBAL SCOPE (File Level)                             |
| int globalVar = 100; (Accessible everywhere)          |
|                                                       |
|   +-----------------------------------------------+   |
|   | FUNCTION / BLOCK SCOPE                        |   |
|   | void myFunction() {                           |   |
|   |     int localVar = 10; (Inside Stack Frame)   |   |
|   |                                               |   |
|   |     +-----------------------------------+     |   |
|   |     | IF-BLOCK SCOPE                    |     |   |
|   |     | if (...) {                        |     |   |
|   |     |     int blockVar = 5;             |     |   |
|   |     | } <-- blockVar Destroyed          |     |   |
|   |     +-----------------------------------+     |   |
|   |                                               |   |
|   | } <-- localVar Destroyed                      |   |
|   +-----------------------------------------------+   |
+-------------------------------------------------------+

```

---

