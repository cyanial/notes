Pointers On C by Kenneth Reek 
=============================

- [Pointers On C by Kenneth Reek](#pointers-on-c-by-kenneth-reek)
- [1.1 Tip: Comments code bocks with `#if 0 #endif`](#11-tip-comments-code-bocks-with-if-0-endif)
- [1.1 `getchar()` return a int type](#11-getchar-return-a-int-type)
- [3.2 When & Why check an array subscript](#32-when--why-check-an-array-subscript)
- [5.1 Bit Manipulation](#51-bit-manipulation)
- [7.6 Variable Argument Lists](#76-variable-argument-lists)

# 1.1 Tip: Comments code bocks with `#if 0 #endif`

Supposed that we have blocks of codes with traditional c-comments(`/* */`).

```c
/* This is a multi-line comments.
 * line 
 * line
 */
#include <stdio.h>
...
```

If we comments the code in traditional way, then - 

```c
/*
/* This is a multi-line comments.
 * line 
 * line
 */
*/
#include <stdio.h>
...
```
It may cause a compiler-time error. Cause that `/* */` are not paired like brickets.

# 1.1 `getchar()` return a int type

When there's nothing to read in the input buffer, the function will return `EOF`. A `char` is too small to hold that value. Also, use `int` to represent `char` is always feasible when we are not care about the memory.

# 3.2 When & Why check an array subscript

> If a subscript was computed from values that are already known to be correct, then there is no need to check its value. Any value this is derived in any way from data trhat the user has entered must be checked before being used as a subscript to ensure that it is in the proper range.

# 5.1 Bit Manipulation

Set specified bit to one:

```c
value = value | 1 << bit_number;
value |= 1 << bit_number;
```

Clear specified bit to zero:

```c
value = value & ~ (1 << bit_number);
value &= ~(1 << bit_number);
```

Test specified bit and is nonzero if the bit is set:

```c
vale & 1 << bit_number
```

# 7.6 Variable Argument Lists

The standard C library `stdarg.h` provides a way to access varied function parameters. And, we can access these paremeters with the specified macros defined in the head file. Example Codes:

```c
#include <stdarg.h>

float average(int n_values, ...)
{
    va_list var_arg;
    float sum = 0.0f;

    va_start(var_arg, n_values);

    for (int i = 0; i < n_values; i++) {
        sum += va_arg(var_arg, int);
    }

    va_end(var_arg);

    return sum / n_values;
}
```
