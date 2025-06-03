# libftprintf

> **TL;DR:**  
> This is my implementation of `ft_printf` from the 42 School Common Core (without bonus exercises).  
> - Contains basic formatting functions for characters, strings, numbers (decimal, unsigned, hex), and pointers.  
> - Build with `make` to produce `libftprintf.a`.  
> - Include `ft_printf.h` in your own project to use `ft_printf`.

---

## Table of Contents

1. [Project Overview](#project-overview)  
2. [Features](#features)  
3. [Getting Started](#getting-started)  
   - [Prerequisites](#prerequisites)  
   - [Installation & Compilation](#installation--compilation)  
4. [Usage](#usage)  
   - [Include & Link](#include--link)  
   - [Function Prototype](#function-prototype)  
   - [Supported Format Specifiers](#supported-format-specifiers)  
5. [File Structure](#file-structure)  
6. [Function Descriptions](#function-descriptions)  
7. [Makefile Details](#makefile-details)  
8. [Cleaning & Rebuilding](#cleaning--rebuilding)  
9. [Author](#author)  

---

## Project Overview

`libftprintf` is a student‐built static library that replicates a subset of the standard C `printf` function. It is designed to satisfy the 42 School’s coding standards (no warnings, proper memory management, Norminette‐compliant style) and to serve as a lightweight replacement for `printf` when forbidden by project rules.  

This project implements:

- `ft_printf` for formatted output to `stdout`.  
- Utility functions to print characters, strings, decimal and unsigned integers, hexadecimal numbers (lowercase & uppercase), and pointers.  

---

## Features

- **Basic Format Specifiers:**  
  - `%c` → print single character  
  - `%s` → print null‐terminated string  
  - `%d` / `%i` → print signed decimal integer  
  - `%u` → print unsigned decimal integer  
  - `%x` / `%X` → print unsigned hexadecimal integer (lowercase/uppercase)  
  - `%p` → print pointer address in hexadecimal with `0x` prefix  
  - `%%` → print literal percent sign  

- **Error Handling & Return Value:**  
  - Returns the total number of characters printed (mimicking standard `printf`).  
  - Handles `NULL` string pointers by printing `(null)`.  

- **No External Dependencies:**  
  - Only uses standard C library headers (`<unistd.h>`, `<stdlib.h>`, etc.).  

- **Norminette & Compiler Flags:**  
  - Compiles without warnings under `-Wall -Wextra -Werror`.  
  - Header file guarded to prevent double inclusion.  

---

## Getting Started

### Prerequisites

- A Unix‐like environment (Linux or macOS).  
- A C compiler (`cc` / `gcc`).  
- GNU Make (to use the provided `Makefile`).  
- 42 School coding‐style familiarity (Norminette requirements).  

### Installation & Compilation

1. **Clone the Repository** 
   ```bash
   git clone https://github.com/yourusername/libftprintf.git
   cd libftprintf
   ```
2. **Compile with Make**  
   Run:
   ```bash
   make
   ```
   This will:
   - Create an `objects/` directory.
   - Compile each `.c` file into a corresponding `.o` file.
   - Archive all `.o` files into `libftprintf.a`.
3. **Verify output**
   After the build is successful, you should see the following structure:
   ```bash
   ls
   ft_printf.c   ft_printf.h   Makefile   objects/   libftprinf.a   utils/
   ```
   - `libftprintf.a` is the static library you will link against.

## Usage
### Include & Link
1. **Include the Header**  
In any C file where you want to use `ft_printf`, add:
```c
#include "ft_printf.c"
```
2. **Link the library**
When compiling your own program, link against `libftprintf.a`. For example:
```bash
cc -I. main.c libftprintf.a -o my_program
```
- `-I.` ensures the compiler finds `ft_printf.h` in the current directory.
- Replace `main.c` with your source file(s).

### Function Prototype  
```c
int   ft_printf(const char *format, ...);
```
- **Return Value:** The return value of `ft_printf`, similar to `printf`, is the number of characters printed (excluding the null terminator).
- **Behavior:** Parses the `format` string, formats each argument, and writes to `stdout`.

## Supported Format Specifiers
| Specifier  | Output Example       | Notes                                                               |
|------------|----------------------|---------------------------------------------------------------------|
| `%c`       | `A`                  | Single character.                                                   |
| `%s`       | `Hello, 42!`         | Null-terminated string. Prints `(null)` if argument is `NULL`.      |
| `%d`, `%i` | `-123`               | Signed decimal integer.                                             |
| `%u`       | `4294967295`         | Unsigned decimal integer.                                           |
| `%x`       | `ffee`               | Unsigned hexadecimal (lowercase).                                   |
| `%X`       | `FFEE`               | Unsigned hexadecimal (uppercase).                                   |
| `%p`       | `0x7ffc12345678`     | Pointer address (lowercase hex with `0x` prefix). Prints `(nil)` if `NULL`. |
| `%%`       | `%`                  | Prints a literal percent sign.                                      |

---

## File Structure
```
.
├── ft_printf.c
├── ft_printf.h
├── Makefile
├── libftprintf.a      ← (generated after running `make`)
├── objects/           ← (generated after running `make`)
│   ├── ft_printf.o
│   ├── ft_putchar.o
│   ├── ft_puthex.o
│   ├── ft_putnbr.o
│   ├── ft_putptr.o
│   ├── ft_putstr.o
│   └── ft_putunsigned.o
└── utils/
    ├── ft_putchar.c
    ├── ft_puthex.c
    ├── ft_putnbr.c
    ├── ft_putptr.c
    ├── ft_putstr.c
    └── ft_putunsigned.c
```
- `ft_printf.c`
   - Implements the main `ft_printf` function: parses the format string and delegates the utility functions in the `utils/` directory.
- `ft_printf.h`
  - Header file that declares `ft_printf` and all necessary functions and libraries.
- `utils/`
  - Contains helper functions to print individual data types:
    - `ft_putchar.c` -> write a sungle character to `stdout`.
    - `ft_putstr.c` -> write a null-terminated string to `stdout`.
    - `ft_putnbr` -> print a signed decimal int.
    - `ft_putunsigned` -> print an unsigned decimal integer.
    - `ft_puthex` -> print a hexadecimal number (lowercase or uppercase).
    - `ft_putptr` -> print a pointer address (basically the same as hex, but only lowercase with `0x` prefix).
- `objects/` (created by `make`)
  - Stores created `.o` files.
  - Cleaned by `make clean` or `make fclean`.

---

## Function Descriptions
1. `ft_printf(const char *format, ...)`
   - Parses the `format` string character by character.
   - When it encounters `%` and theres a character after it, it inspects the format specifier and calls the matching utility function.
   - Returns the total number of characters printed.
2. `ft_putchar(char c)`
   - Writes the character `c` to `stdout` using `write(1, &c, 1)`
   - Returns `1` (one character printed).
3. `ft_putstr(char *s)`
   - If `s` is `NULL`, outputs `(null)`, mimicking `printf`'s behavior.
   - Otherwise, writes each character in the string with `ft_putchar`, and the terminating `\0`.
   - Returns the number of characters printed.
4. `ft_putnbr(int n)`
   - Handles negative numbers and recursively prints them to `stdout`.
   - Returns the number of characters printed.
5. `ft_putunsigned(unsigned int n)`
   - Basically the same as `ft_putnbr()`.
   - Recursively breaks `n` down to print it's decimal digits.
   - Returns the number of characters printed.
6. `ft_puthex(unsigned int n, const char format)`
   - Converts `n` to hexadecimal.
   - If `format == 'x'`, prints lowercase digits (`a-f` & `0-9`)
   - If `else`, prints uppercase digits (`A-F` & `0-9`)
   - Returns the number of characters printed.
7. `ft_putptr(unsigned long long ptr)`
   - If `ptr == 0`, prints `(nil)`.
   - Otherwise, prints the prefix `0x` followed by hexadecimal representation of `ptr` in lowercase.
   - Returns the number of characters printed (`0x` included).

---

## Makefile details
- **Variables**
   - `NAME` -> `libftprintf.a` (the name of the static library).
   - `CC` -> what compiler to use (`cc` in this case).
   - `CFLAGS` -> what flags will be used when compiling (`-Wall -Wextra -Werror -I.`)
     - `-Wall` and `-Wextra` enable all warnings, and `-Werror` treats warnings as errors. (These are all mandatory in 42)
     - `-I.` adds the project root to the compiler's include path, so that `#include "ft_printf.h"` in `utils/` files can find the `.h` file.
   - `AR` -> creates and updates the static library or archive (`ar rcs`).
- **Source & Object Lists**
  - `SRCS` list each `.c` file, include paths for `utils/`.
  - `OBJSDIR = objects` defines where to place `.o` files.
  - `SRCS = ...` defines existing `.c` files.
  - `SRC_NAMES = $(notdir $(SRCS))` strips directory prefixes from `SRCS`, leaving just the filenames.
  - `OBJS = $(addprefix $(OBJSDIR)/, $(SRC_NAMES:.c=.o))` constructs all `.c` files into `.o` files and puts them inside the `OBJSDIR` directory.
- **Targets**
  - `all: $(NAME)` -> default rule; builds the library.
  - `$(NAME): $(OBJS)` -> archives all object files into `libftprintf.a`.
  - `$(OBJSDIR)/%.o: %.c ft_printf.h | $(OBJSDIR)` -> compiles root-level resources.
  - `$(OBJSDIR)/%.o: %.c utils/%.c ft_printf.h | $(OBJSDIR)` -> compiles utility resources.
  - `$(OBJSDIR):` -> creates the `objects/` directory, if it doesn't exist.
  - `clean:` -> deletes `objects/` and everything inside it.
  - `fclean: clean` -> runs `clean` and also deletes `libftprintf.a`.
  - `re: fclean all` -> runs `fclean` and then `all`, forcing a full rebuild from scratch.
  - `.PHONY: all clean fclean re` -> declares these targets as "phony" so Make always executes them.

---
## Cleaning & Rebuilding
- **Delete only object files**
  ```bash
  make clean
  ```
  - removes `objects/` directory and all compiled `.o` files.
- **Delete everything (objects + library)**
  ```bash
  make fclean
  ```
  - runs `make clean` and then deletes `libftprintf.a`.
- **Rebuild from scratch**
  ```bash
  make re
  ```
  - equivalent to `make fclean && make all`.

---

## Author
- **Tomás Andrade (@toandrad)**
- 42 School Project: Implementation of a mini-`printf` function complying with 42 standards.
- Grade: **100%**
