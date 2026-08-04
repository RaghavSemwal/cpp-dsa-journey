# Complete Lecture Notes: Binary Number System in C++



---

## 📌 Section 1: Detailed Chapter Notes & Concepts

### 1. Introduction to Number Systems

A **Number System** defines how numerical values are represented using a specific set of digits.

* **Decimal Number System (Base 10):**
* Uses 10 digits: `0, 1, 2, 3, 4, 5, 6, 7, 8, 9`.
* Used in everyday human mathematics.


* **Binary Number System (Base 2):**
* Uses 2 digits: `0` and `1`.
* Used by computer systems because hardware transistors operate on two electrical states: **OFF (0)** and **ON (1)**.


* **Other Common Systems:**
* **Octal (Base 8):** Uses digits `0-7`.
* **Hexadecimal (Base 16):** Uses digits `0-9` and letters `A-F` (`A=10` to `F=15`).



---

### 2. Conversions Between Number Systems

#### A. Decimal to Binary Conversion

To convert a base-10 number to binary, perform **repeated division by 2** and record the remainders until the quotient becomes zero. Read the remainders from **bottom to top** (MSB to LSB).

##### Mathematical Formula Strategy (Used in Code):

When constructing the binary integer mathematically without strings:


$$\text{binary} = \sum (\text{remainder} \times 10^{\text{position}})$$

#### B. Binary to Decimal Conversion

To convert a binary number to decimal, multiply each binary digit by $2^{\text{position}}$ (starting at index 0 from right to left) and sum the products.

$$\text{decimal} = \sum (\text{bit} \times 2^{\text{position}})$$

---

### 3. Binary System Fundamentals & Quick Reference

#### A. Bit Position Power Table

| Position ($2^i$) | $2^7$ | $2^6$ | $2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **Decimal Weight** | **128** | **64** | **32** | **16** | **8** | **4** | **2** | **1** |

> **Key Observation (Odd/Even Check):** Any binary number with LSB ($2^0$) equal to `1` is an **odd number**. If LSB is `0`, it is an **even number**.

#### B. First 11 Decimal to Binary Values (0–10)

| Decimal | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **Binary** | `0` | `1` | `10` | `11` | `100` | `101` | `110` | `111` | `1000` | `1001` | `1010` |

---

### 4. Binary Addition Rules

Binary addition follows similar rules to decimal addition, carrying over when the sum exceeds base 2:

* $0 + 0 = 0$
* $0 + 1 = 1$
* $1 + 0 = 1$
* $1 + 1 = 10_2$ (Sum = $0$, Carry = $1$)
* $1 + 1 + 1 = 11_2$ (Sum = $1$, Carry = $1$)

---

### 5. Negative Number Representation (2's Complement)

Computers store negative integers in 32-bit RAM allocations using **2's Complement Form**.

#### Sign Bit / Most Significant Bit (MSB):

* **MSB = 0:** Represents a positive number.
* **MSB = 1:** Represents a negative number.

#### Steps to Find 2's Complement of a Negative Number (e.g., -10):

1. **Find Binary of Magnitude:** Find binary representation of $+10$ (e.g., `01010`).
2. **Find 1's Complement:** Invert all bits (`0` becomes `1`, `1` becomes `0`).
3. **Find 2's Complement:** Add `1` to the 1's complement result.

---

## 📊 Section 2: Markdown Visual Diagrams

### Visual 1: Decimal to Binary Conversion Steps (42 → Binary)

```text
    Division Process                  Remainder    Bit Weight (Read Upwards)
 
       2 | 42                              
         +----
       2 | 21  ------------------------>   0        ^  (LSB - 2^0)
         +----                             |        |
       2 | 10  ------------------------>   1        |
         +----                             |        |
       2 |  5  ------------------------>   0        |
         +----                             |        |
       2 |  2  ------------------------>   1        |
         +----                             |        |
       2 |  1  ------------------------>   0        |
         +----                             |        |
         |  0  ------------------------>   1        |  (MSB - 2^5)
                                                    |
 Result: (42)_10 = (101010)_2                       +--- Read Bottom to Top

```

---

### Visual 2: Binary to Decimal Conversion (101010 → 42)

```text
 Binary Bit:       1        0        1        0        1        0
                   |        |        |        |        |        |
 Positional        v        v        v        v        v        v
 Weight:         (2^5)    (2^4)    (2^3)    (2^2)    (2^1)    (2^0)
                   |        |        |        |        |        |
 Decimal           v        v        v        v        v        v
 Value:           32   +    0   +    8   +    0   +    2   +    0  = 42

```

---

### Visual 3: Two's Complement Workflow (-10 in 8-bit Representation)

```text
Step 1: Positive Binary (+10)    [ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 1 ][ 0 ]
                                                      |
                                        Invert Bits (1's Complement)
                                                      v
Step 2: 1's Complement           [ 1 ][ 1 ][ 1 ][ 1 ][ 0 ][ 1 ][ 0 ][ 1 ]
                                                      |
                                                  Add 1
                                                      v
Step 3: 2's Complement (-10)     [ 1 ][ 1 ][ 1 ][ 1 ][ 0 ][ 1 ][ 1 ][ 0 ]
                                   ^
                                   |--- MSB = 1 (Negative Sign Flag)

```

---


---

## 📝 Section 4: Homework Exercises & Solutions

### Homework Challenge 1: Convert -15 to Binary (2's Complement) using 8-bit Representation

#### Analytical Calculation:

1. **8-bit Representation of $+15$:** `0000 1111`
2. **1's Complement (Invert all bits):** `1111 0000`
3. **Add 1 to LSB:**

$$\begin{array}{rl}      11110000 \\    + 00000001 \\    \hline      11110001    \end{array}$$



**Result:** $-15$ in 8-bit 2's Complement is `11110001`.

---

### Homework Challenge 2: Convert Binary `11110001` back to Decimal

#### Analytical Calculation:

1. **Check MSB:** MSB is `1`, indicating a **negative number**.
2. **Apply 2's Complement to find magnitude:**
* **1's Complement:** Invert `11110001` $\rightarrow$ `00001110`
* **Add 1:** `00001110` $+ 1 =$ `00001111`


3. **Convert `00001111` to Decimal:**

$$0 \times 2^7 + \dots + 1 \times 2^3 + 1 \times 2^2 + 1 \times 2^1 + 1 \times 2^0 = 8 + 4 + 2 + 1 = 15$$


4. **Apply Sign Flag:** Since MSB was `1`, result is **$-15$**.

---

