*This project has been created as part of the 42 curriculum by kmota.*

# ft_printf

![completed](https://img.shields.io/badge/completed-0a4518)

## Languages Used

- `C`
- `Makefile`

## Objective

Recode the libc `printf()` function, learning how variadic functions work in C, and produce a reusable static library (`libftprintf.a`).

## Description

**ft_printf** is a 42 curriculum project that consists of rewriting `printf()` from the C standard library.

The result is a static library, `libftprintf.a`, exposing a single function:

```c
int ft_printf(const char *fm, ...);
```

Like the original, it writes formatted output to standard output and returns the number of characters printed.

The implementation does not reproduce the buffer management of the original `printf()`. Characters are written directly using `write()`.

### Supported conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. If the pointer is NULL, prints `(null)`. |
| `%p` | Prints a pointer in hexadecimal format, prefixed with `0x`. A NULL pointer prints `(nil)`. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned hexadecimal number in lowercase. |
| `%X` | Prints an unsigned hexadecimal number in uppercase. |
| `%%` | Prints a percent sign. |

The implementation does not support flags, field width, precision, or length modifiers.

Unsupported conversion specifiers are consumed without producing output.

A `%` at the end of the format string is printed literally.

### External functions used

The implementation uses the following external functions:

- `write()` — writes characters to standard output.
- `va_start()` — initializes the variadic argument list.
- `va_arg()` — retrieves arguments from the variadic list.
- `va_end()` — closes the variadic argument list.

### Headers used

- `<unistd.h>`
- `<stdarg.h>`
- `<stdint.h>`
- `<stdlib.h>` (included in the header but not currently used).

This project reinforces concepts such as variadic functions (`stdarg.h`), recursion, number base conversion, pointer handling, return value handling, and building a static library with `ar`.

# Instructions

### Requirements

- `cc` compiler (GCC or Clang).
- `make`
- `ar`

### Compilation

From the project root:

```bash
make          # Compiles the sources and generates libftprintf.a
make clean    # Removes object files (.o)
make fclean   # Removes object files and libftprintf.a
make re       # Recompiles everything from scratch
```

The files are compiled using `cc` with the flags `-Wall -Wextra -Werror`.

The static library is created using `ar rcs`.

### Usage

1. Include `ft_printf.h` in your project:

```c
#include "ft_printf.h"
```

2. Compile your program by linking the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

### Quick Example

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello, %s! Number: %d, hex: %x, ptr: %p, %%\n",
            "42", 42, 255, "42");
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

### Testing

The function can be compared against the original `printf()` using the same format strings and arguments, comparing both the output and the returned value.

### Memory Testing with Valgrind

Memory leaks and memory-related errors can be checked using Valgrind.

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o a.out
```

Run Valgrind:

```bash
valgrind --leak-check=full ./a.out
```

For more detailed memory checking:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
```

Since the implementation does not allocate or free dynamic memory, its printing functions do not require heap memory management.

# Algorithm and Data Structure

### Overall approach

`ft_printf` receives a format string and a variable list of arguments (`va_list`).

The format string is read one character at a time, from left to right, in a single pass:

1. If the current character is not `%`, it is printed directly using `ft_putchar()`.
2. If the current character is `%` and another character follows, the next character is passed to the dispatcher function `ft_porcent()`.
3. The dispatcher identifies the conversion specifier and calls the corresponding function.
4. Each handler retrieves its argument using `va_arg()`, prints it, and returns the number of characters written.
5. The total number of printed characters is accumulated and returned by `ft_printf()`.
6. `va_start()` initializes the argument list at the beginning, and `va_end()` closes it at the end.

If `%` is the last character of the format string, it is printed literally.

### Why this design

- **Single pass:** The format string is processed from beginning to end without needing to scan it multiple times.
- **No intermediate buffer:** Characters are written directly using `write()`.
- **One handler per conversion:** Each function has a specific responsibility, making the implementation easier to understand and maintain.
- **Return value as a counter:** Each printing function returns the number of characters written, allowing the total to be accumulated.
- **Variadic arguments:** `va_list` is passed to the dispatcher and used to retrieve arguments in the correct order.

### Number conversion

The project uses different approaches to print numbers depending on their type.

**Signed integers (`%d` and `%i`)**

The `ft_putnbr()` function handles signed decimal integers.

- Converts the integer to a `long` to safely handle negative values, including `INT_MIN`.
- Prints the minus sign when the number is negative.
- Uses recursion to print digits from the most significant to the least significant.

**Unsigned integers (`%u`)**

The `ft_putintus()` function prints unsigned decimal integers.

- Finds the highest decimal divisor.
- Extracts and prints each digit iteratively.
- Reduces the number until all digits have been printed.

**Hexadecimal numbers (`%x` and `%X`)**

The `ft_puthex()` function converts numbers to hexadecimal.

- Uses recursion to divide the number by 16.
- Prints digits using a lookup string.
- Uses lowercase characters for `%x` and uppercase characters for `%X`.

**Pointers (`%p`)**

The `ft_putptr()` function handles pointer addresses.

- Prints `(nil)` when the pointer is NULL.
- Converts the pointer to `uintptr_t`.
- Prints the `0x` prefix followed by the hexadecimal address.

### Character and String Output

**ft_putchar()**

Uses `write()` to print a single character to standard output and returns `1`.

**ft_putstr()**

Prints a string character by character using `ft_putchar()`.

If the string pointer is NULL, it prints `(null)`.

### Data Structures

No complex data structures are needed.

The implementation uses:

- `va_list` to manage variadic arguments.
- Integer variables to count the number of printed characters.
- `uintptr_t` to handle pointer addresses.

No dynamic memory allocation is used in the printing functions.

# Project Structure

| File | Description |
|---|---|
| `ft_printf.c` | Main function and conversion dispatcher. |
| `ft_printf.h` | Function prototypes and header inclusions. |
| `ft_putchar.c` | Prints a single character. |
| `ft_putstr.c` | Prints a string. |
| `ft_putnbr.c` | Prints signed decimal integers. |
| `ft_putintus.c` | Prints unsigned decimal integers. |
| `ft_puthex.c` | Prints hexadecimal numbers. |
| `ft_putptr.c` | Prints pointer addresses. |
| `Makefile` | Compiles the project and creates the static library. |

# Resources

### Classic References

- [Linux Manual – printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) – documentation of the original function.
- [Linux Manual – stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html) – variadic functions.
- [Linux Manual – write(2)](https://man7.org/linux/man-pages/man2/write.2.html) – system call used for output.
- [Linux Manual – ar(1)](https://man7.org/linux/man-pages/man1/ar.1.html) – used to create the static library.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) – official Make documentation.
- [cppreference – C](https://en.cppreference.com/w/c) – reference for the C language and standard library.
- [Valgrind Documentation](https://valgrind.org/docs/manual/manual.html) – memory error and leak detection.
- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) – reference book for the C language.
- 42 Norm (Norminette) – coding style rules required by the curriculum.

### AI Usage

AI was used occasionally as a learning aid:

- **Understanding Concepts:** Explanations of how variadic functions work and of the expected behavior of `printf()` in edge cases.
- **Review:** Suggestions for code improvements and points of attention (memory leaks, NULL handling).
- **Testing:** Suggestions for test cases and memory leak checks.