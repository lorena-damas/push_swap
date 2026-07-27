*This project has been created as part of the 42 curriculum by lordamas.*

# ft_printf

## Description

`ft_printf` is a 42 School project whose goal is to recreate a simplified version of the standard C `printf` function.

The project focuses on understanding variadic functions in C, parsing format strings, handling different data types, printing formatted output, and returning the number of characters printed.

The final result is a static library named:

```bash
libftprintf.a
```

This library contains the function:

```c
int ft_printf(const char *format, ...);
```

The mandatory implementation supports the following conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will generate:

```bash
libftprintf.a
```

### Cleaning object files

```bash
make clean
```

### Removing object files and the library

```bash
make fclean
```

### Recompiling from scratch

```bash
make re
```

### Example usage

Create a test file:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s!\n", "42");
	ft_printf("Number: %d\n", -42);
	ft_printf("Hex: %x\n", 255);
	return (0);
}
```

Compile it with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Run:

```bash
./test
```

## Algorithm and Data Structure Explanation

The main idea of `ft_printf` is to read the format string character by character.

If the current character is not `%`, it is printed directly using `write`.

If the current character is `%`, the next character is checked to identify the conversion type. Depending on the conversion, the correct argument is retrieved using variadic argument macros from `<stdarg.h>`.

The project uses:

```c
va_list
va_start
va_arg
va_end
```

These macros allow the function to access an unknown number of arguments passed after the format string.

The parsing logic follows this general structure:

```text
Read format string
        |
        |-- normal character
        |       |-- print character
        |
        |-- '%' found
                |-- check next character
                |-- get the correct argument type
                |-- print using the matching helper function
```

The implementation uses helper functions to keep the code organized:

- `ft_putchar_count` prints one character and returns `1`.
- `ft_putstr_count` prints a string and returns the number of characters printed.
- `ft_putnbr_count` prints signed integers recursively.
- `ft_putunsigned_count` prints unsigned integers recursively.
- `ft_puthex_count` prints hexadecimal numbers using a base string.
- `ft_putptr_count` prints pointer addresses in hexadecimal format.

Recursion is used for number printing because the last digit is obtained first with the modulo operator.

For example, with the number `123`, the expression `123 % 10` gives `3`, but the function must print `1` first. Recursion allows the function to print the left part of the number before printing the last digit.

For decimal numbers, the function uses base 10:

```c
n / 10
n % 10
```

For hexadecimal numbers, the same idea is used with base 16:

```c
n / 16
n % 16
```

A base string is used to choose the correct hexadecimal character:

```c
"0123456789abcdef"
"0123456789ABCDEF"
```

For pointers, the function prints the `0x` prefix before printing the address in lowercase hexadecimal. If the pointer is `NULL`, the implementation prints `(nil)` to match the behavior of the system `printf`.

The project does not implement the original `printf` buffer management, because this is not required by the subject.

## Resources

The following resources were useful for understanding the concepts used in this project:

- 42 project subject: `ft_printf`
- C documentation for `write`
- C documentation for variadic functions:
  - `va_list`
  - `va_start`
  - `va_arg`
  - `va_end`
- Manual page for `printf`
- Manual page for `ar`
- Peer discussions and testing with comparison against the original `printf`

## AI Usage

AI was used as a tutoring and learning support tool during this project.

It helped with:

- Understanding the goal of the project.
- Explaining variadic functions step by step.
- Reviewing small pieces of code.
- Finding bugs through guided questions.
- Creating test cases to compare `printf` and `ft_printf`.
- Structuring this README file.

The implementation was tested, reviewed, and adapted manually. The goal of using AI was not to skip the learning process, but to support understanding and debugging while building the project step by step.

## Status

Mandatory part completed.

Implemented conversions:

```text
%c %s %p %d %i %u %x %X %%
```
