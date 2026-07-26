*This project has been created as part of the 42 curriculum by jotto.*

# libft

## Description

libft is a custom C library that recreates a large set of standard library functions and adds a collection of utility functions.

Its goal is to give you a reliable personal toolkit made only from code you wrote yourself, so you can reuse it across future assignments without depending on the standard library implementation.

This library includes character checks, string and memory helpers, conversion utilities, file descriptor output functions, and a full set of linked list functions.

## Instructions

Build the library with `make`, which creates `libft.a` at the root of the project. Use `make clean`, `make fclean`, and `make re` to remove object files, remove the library, or rebuild everything from scratch. Include `libft.h` in your project and link against `libft.a` when compiling.

## Resources

- `man` pages for the C standard library functions
- google and & learn-C.org for research
- IBM C library documentation
- 42 subject and official project documentation

### Use of AI

AI was used to help draft and organize this README structure, rewrite function descriptions into short one-line summaries, and improve readability.

## Library contents

Below is a short explanation of name abbreviations and what each function name means and what it does.

### Character checks

| Function | Meaning | Description |
| --- | --- | --- |
| `ft_isalpha` | is alphabetic | Checks whether a character is a letter. |
| `ft_isdigit` | is digit | Checks whether a character is a number from 0 to 9. |
| `ft_isalnum` | is alphanumeric | Checks whether a character is a letter or a digit. |
| `ft_isascii` | is ASCII | Checks whether a character belongs to the ASCII table. |
| `ft_isprint` | is printable | Checks whether a character can be printed on screen. |

### String and memory functions

| Function | Meaning | Description |
| --- | --- | --- |
| `ft_strlen` | string length | Returns the length of a string. |
| `ft_memset` | memory set | Fills memory with a chosen byte value. |
| `ft_bzero` | byte zero | Sets memory bytes to zero. |
| `ft_memcpy` | memory copy | Copies bytes from one memory area to another. |
| `ft_memmove` | memory move | Copies bytes safely even when memory overlaps. |
| `ft_strlcpy` | string length copy | Copies a string with buffer size protection. |
| `ft_strlcat` | string length concatenate | Appends a string with buffer size protection. |
| `ft_toupper` | to uppercase | Converts a lowercase letter to uppercase. |
| `ft_tolower` | to lowercase | Converts an uppercase letter to lowercase. |
| `ft_strchr` | string character | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | string reverse character | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | string compare n | Compares two strings up to `n` characters. |
| `ft_memchr` | memory character | Finds a byte in memory. |
| `ft_memcmp` | memory compare | Compares two memory blocks. |
| `ft_strnstr` | string search in string | Finds a substring inside another string. |
| `ft_calloc` | contiguous allocation | Allocates memory and initializes it to zero. |
| `ft_strdup` | string duplicate | Creates a copy of a string. |

### String manipulation utilities

| Function | Meaning | Description |
| --- | --- | --- |
| `ft_substr` | substring | Extracts part of a string. |
| `ft_strjoin` | string join | Joins two strings into one new string. |
| `ft_strtrim` | string trim | Removes unwanted characters from the start and end of a string. |
| `ft_split` | split | Divides a string into an array of substrings. |
| `ft_itoa` | integer to ASCII | Converts an integer into a string. |
| `ft_strmapi` | string map with index | Creates a new string by applying a function to each character. |
| `ft_striteri` | string iterate with index | Applies a function to each character of a string in place. |

### File descriptor output

| Function | Meaning | Description |
| --- | --- | --- |
| `ft_putchar_fd` | put character to file descriptor | Writes one character to a file descriptor. |
| `ft_putstr_fd` | put string to file descriptor | Writes a string to a file descriptor. |
| `ft_putendl_fd` | put string end line to file descriptor | Writes a string followed by a newline. |
| `ft_putnbr_fd` | put number to file descriptor | Writes an integer to a file descriptor. |

### Linked list functions

| Function | Meaning | Description |
| --- | --- | --- |
| `ft_lstnew` | list new | Creates a new list node. |
| `ft_lstadd_front` | list add front | Adds a node to the beginning of the list. |
| `ft_lstsize` | list size | Returns the number of nodes in a list. |
| `ft_lstlast` | list last | Returns the last node in a list. |
| `ft_lstadd_back` | list add back | Adds a node to the end of the list. |
| `ft_lstdelone` | list delete one | Deletes a single node. |
| `ft_lstclear` | list clear | Deletes and frees all nodes in a list. |
| `ft_lstiter` | list iterate | Applies a function to each node in the list. |
| `ft_lstmap` | list map | Creates a new list by applying a function to each node. |