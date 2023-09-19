# \_printf

A custom printf function

## Setup Instructions

   - Write your main function and use `_printf` instead of `printf`. Example:
    `_printf("String: %s\n", "I am a string !");`
   - To compile:

    `$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c`

## Execution

   - Run the executable:
    `$ ./printf`

## Modus Operandi

   - If `NULL` is passed to the function, returns **-1**
   - If string passed to the function is empty: (`_printf("");`) returns **0**
   - Else, returns the number of bytes printed

### Specifiers

#### Characters & Strings: %c and %s

   - If string passed to `%s` is null, prints **(null)**, returns length of **"(null)"**
   - If string only contains **"%"**, returns **-1**
   - If character passed to `%c` is null byte:
       - sends to write: `write(1, &c, 1)`
       - returns **1**

#### Decimal Integer & Other Base Integers: %d and %i

   - If octal or hex is passed, to `%d`, decimal base is assumed
   - If octal, binary or hex is passed to `%i` number is first converted to decimal then printed

#### Binary: %b

   - Takes an integer and converts to unsigned int before converting to binary:
       - Thus if number is negative, number becomes `UINT_MAX + (n)` where `n` is a negative number

#### Unsigned Integers, Octal, Hex(lowercase) & Hex(uppercase): %u, %o, %x and %X

   - Takes an integer and converts to unsigned int, then:
       - if `%u`, number is printed and if negative number becomes, `UINT_MAX + number`
       - if `%o`, unsigned int is converted to octal
       - if `%x`, unsigned int is converted to hexadecimal lowercase, i.e. **1023 becomes 3ff**
       - if `%X`, unsigned int is converted to hexadecimal uppercase, i.e. **1023 becomes 3FF**

#### Custom String: %S

   - Works like `%s` except:
       - non printable characters **(0 < ASCII value < 32 or >= 127)** are printed this way: `\x`
       - followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
   - Example: `_printf("%S\n", "Best\nSchool");` prints `Best\x0ASchool`

#### Address: %p


## More Information

   - Uses a local buffer of 1024 chars and calls write only when buffer is filled
