# Divide and Conquer, Sorting and Searching, and Randomized Algorithms

There are 4 modules in this course
The primary topics in this part of the specialization are:

- asymptotic ("Big-oh") notation,
- sorting and searching,
- divide and conquer (master method, integer and matrix multiplication, closest pair), and
- randomized algorithms (QuickSort, contraction algorithm for min cuts).

## Karatsuba Multplicaton

This is a multiplication system of two numbers that uses divide and conquer to generate the product in a faster way. For example `x = 5678` and `y = 1234`.

```
x * y = (ac * 10^n) + (a*d + c*d)(10^(n/2)) + (b * d)
```

### Karatsuba Multiplication Algorithm

- If `x` or `y` is less than 10, return `x * y`
- Divide `x` into two parts: `a = 56` and `b = 78`
- Divide `y` into two parts: `c = 12` and `d = 34`
- `a` and `c` are considered as high while `b` and `d` are low
- `n` is the maximum length of `x` and `y`. The biggest length of either is stored in `n`
- z0 - recursively compute `a*c`
- z1 - recursively compute `b*d`
- z2 - recursively compute `(a+b)*(c+d)` (Gauss’ Trick: (3) - (1) - (2) = ad + bc)
- return `z2 * 10^n + (z2 - z1 - z0) * 10^(n/2) + z0`

See implementation at [karatsuba.c](karatsuba.c)

**How to run the program**
- Make sure your current directory is where [karatsuba.c](karatsuba.c) is located
- Identify the path of `main.h`
- Compile with `gcc -Wall -pedantic -Werror -Wextra -std=gnu99 -g karatsuba.c -o compiled/karatsuba -lm`
- Test the program by running `./compiled/karatsuba 5678 1234`
- I assume that you have already created compilled folder to organize your files