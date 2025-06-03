# libftprintf

> **TL;DR:**  
> A minimal `printf`‐style library for 42 School projects.  
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
10. [License](#license)  

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
