*This project has been created as part of the 42 curriculum by kmota.*
 
# ft_printf
 
![completed](https://img.shields.io/badge/completed-0a4518)
 
# <h3>Languages Used:</h3>
 
- `C`
- `Makefile`
# <h3>Objective:</h3>
 
<p>Recode the libc <code>printf()</code> function, learning how variadic functions work in C, and produce a reusable static library (<code>libftprintf.a</code>).</p>
# <h3>Description</h3>
 
**ft_printf** is a 42 curriculum project that consists of rewriting `printf()` from the C standard library. The result is a static library, `libftprintf.a`, exposing a single function:
 
```c
int	ft_printf(const char *format, ...);
```
 
Like the original, it writes the formatted output to the standard output and returns the number of characters printed. The buffer management of the original `printf()` is intentionally **not** implemented: characters are written directly with `write`.
 
### Supported conversions
 
| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | Prints a `void *` pointer in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16), lowercase. |
| `%X` | Prints a number in hexadecimal (base 16), uppercase. |
| `%%` | Prints a percent sign. |
 
### Allowed external functions
 
`malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
 
This project reinforces concepts such as variadic functions (`stdarg.h`), recursion, number base conversion, pointer handling, return value handling, and building a static library with `ar`.
 
# <h3>Instructions</h3>
 
### Requirements
 
- `cc` compiler (gcc or clang)
- `make`
- `ar`
### Compilation
 
From the repository root:
 
```bash
make          # compiles the sources and generates libftprintf.a
make clean    # removes object files (.o)
make fclean   # removes object files and libftprintf.a
make re       # recompiles everything from scratch
```
 
The files are compiled with `cc` using the flags `-Wall -Wextra -Werror`, and the library is created with `ar` (`libtool` is not used). `libftprintf.a` is generated at the root of the repository, and the Makefile does not relink unnecessarily.
 
### Usage
 
1. Copy `libftprintf.a` and `ft_printf.h` into your project (or reference them using their path).
2. Include the header in your code:
```c
#include "ft_printf.h"
```
 
3. Compile your program by linking the library:
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```
 
### Quick Example
 
```c
#include "ft_printf.h"
 
int	main(void)
{
	int	len;
 
	len = ft_printf("Hello, %s! Number: %d, hex: %x, ptr: %p, %%\n",
			"42", 42, 255, "42");
	ft_printf("Printed %d characters\n", len);
	return (0);
}
```
 
### Testing
 
The function was compared against the original `printf()` (same format and arguments, comparing both the output and the returned value).
 
Memory leaks were tested with Valgrind:
 
```bash
valgrind --leak-check=full ./a.out
```
 
# <h3>Algorithm and Data Structure</h3>
 
> Adjust this section so it matches exactly what your code does — you must be able to explain it during the evaluation.
 
### Overall approach
 
`ft_printf` receives the format string and a variable list of arguments (`va_list`). The format string is read **one character at a time, from left to right**, in a single pass:
 
1. If the current character is **not** `%`, it is written directly with `write` and the counter is incremented.
2. If it is `%`, the next character is the **conversion specifier**. A dispatcher function (a chain of comparisons on the specifier) calls the matching handler, passing the `va_list`.
3. Each handler fetches its argument with `va_arg`, prints it, and **returns the number of characters written**.
4. The total returned by `ft_printf` is the sum of all characters written (literal text + conversions).
5. `va_start` is called at the beginning and `va_end` at the end.
### Why this design
 
- **Single pass, no intermediate buffer:** the subject forbids reimplementing the buffer management of `printf()`. Writing directly keeps the code simple, uses no heap memory for the output, and makes memory leaks impossible by construction in the printing path.
- **One handler per conversion:** each function has one responsibility, which makes the code easy to read, test, and extend (adding a new conversion means adding one handler and one dispatcher case, which is also useful for the modification requested during the evaluation).
- **Return value as a counter:** every function returns how many bytes it wrote, so the total can be accumulated without a global variable and without computing lengths in advance.
- **`va_list` passed by the caller:** the same list is forwarded to the handlers, so the arguments are consumed in the right order.
### Number conversion
 
`%d`, `%i`, `%u`, `%x`, `%X` and `%p` share the same idea: a **recursive base conversion**. The number is divided by the base (10 or 16); the recursion prints the higher digits first, and each digit is then written using a lookup string (`"0123456789"`, `"0123456789abcdef"` or `"0123456789ABCDEF"`). This prints the digits in the correct order without needing an array or string allocation.
 
- Signed numbers (`%d`, `%i`) are handled by printing `-` first and working with a wider/unsigned value, so `INT_MIN` does not overflow.
- `%x`/`%X`/`%u` use `unsigned int`.
- `%p` uses `unsigned long` (the pointer address) and prefixes `0x`. A `NULL` pointer is handled as a special case, matching the behavior of the system `printf`.
- `%s` with a `NULL` string prints `(null)`, like the original.
### Data structures
 
No complex data structure is needed. The only structure used is the `va_list` that holds the variadic arguments, plus plain integers (counters) for the number of printed characters.
 
# <h4>🔗 ~ Resources</h4>
 
### Classic References
 
- [Linux Manual – printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) – documentation of the original function.
- [Linux Manual – stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html) – variadic functions (`va_start`, `va_arg`, `va_copy`, `va_end`).
- [Linux Manual – write(2)](https://man7.org/linux/man-pages/man2/write.2.html) – system call used for output.
- [Linux Manual – ar(1)](https://man7.org/linux/man-pages/man1/ar.1.html) – used to create the static library.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) – official Make documentation.
- [cppreference – C](https://en.cppreference.com/w/c) – reference for the C language and standard library.
- [Valgrind Documentation](https://valgrind.org/docs/manual/manual.html) – memory error and leak detection.
- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) – reference book for the C language.
- 42 Norm (Norminette) – coding style rules required by the curriculum.
### AI Usage
 
AI was used occasionally as a learning aid, **not** to generate the function code:

- **Understanding Concepts:** Explanations of how variadic functions work and of the expected behavior of `printf()` in edge cases.
- **Review:** Suggestions for test cases and points of attention (memory leaks, `NULL` handling).
- **Testing:** Creating different tests to make sure everything works alright.
