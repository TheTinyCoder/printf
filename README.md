# \_printf

A custom printf function

## Setup Instructions

- Write your main function and use `_printf` instead of `printf`. Example:
    `_printf("String: %s\n", "I am a string !");`
- Run:

    `$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c`

## Execution

- Run the executable:
    `$ ./printf`

## Modus Operandi

- If `NULL` is passed to the function, returns **-1**

### Specifiers

#### Characters & Strings: %c and %s

    - If string passed to `%s` is null, prints **(null)**, returns length of **"(null)"**
    - If string only contains **"%"**, returns **-1**
    - If character passed to `%c` is null byte:
        - sends to write: `write(1, &c, 1)`
        - returns **1**

#### Decimal Integer & Other Base Integers: %d and %i


