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
   - printf formatting is controlled by 'format identifiers' which have upto 6 parts as shown in the table below
   - They MUST be used in the order shown.

      |%|Flags|Width (minimum field width)|Period|Precision (maximum field width)|Specifier (argument type)|
      |:--:|:----:|:-------------:|:------:|:-----:|:-----------------:|:-----------:|
      |Required|Optional|Optional|Optional(required for precision)|Optional|Required|
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

   - Prints an address of a pointer:
       - casts pointer value to `uintptr_t`, then saves it in `unsigned long int`
       - then converts to hexadecimal and prints with prefix `0x`

#### Custom String: %r

   - Works like `%s` except:
       - string argument is printed in reverse  
   - Example: `_printf("%r\n", "Best School");` prints `loohcS tseB`

#### Custom String: %R

   - Works like `%s` except:
       - string argument is encrypted in ROT13  
   - Example: `_printf("%R\n", "Best");` prints `Orfg`

### Flags

#### Plus, Space and Hash(number sign): +, blank, '-', '0' and #

   - Plus sign, `+`:
       - prints a plus sign preceding positive values
       - example: `_printf("%+d", 1024)` prints `+1024`
       - prints a minus sign preceding negative values
       - example: `_printf("%+d", -1024)` prints `-1024`

   - Blank, `' '`:
       - prints a space before a positive value not printed with the `+` flag
       - example: `_printf("% d", 1024)` prints ` 1024`
       - if space is combined with '+' flag, then it just prints plus sign preceding positive values
       - example: `_printf("% +d", 1024)` prints `+1024`

   - Hash (number sign), `#`:
       - prints prefix `0` to the output value when used with the **octal** conversion character `o`
       - example: `_printf("%#o", 1024)` prints `02000`
       - prints prefix `0x` to the output value when used with the **hexadecimal** conversion character `x`
       - example: `_printf("%#x", 1024)` prints `0x400`

   - Zero, `0`:
       - for `d`, `i`, `o`, `u`, `x` and `X` conversions, leading `0`s (after indication of sign or base) are used to pad to the field width
       - no space padding is performed
       - if the `0` and `-` flags both appear, the 0 flag is ignored
       - if **precision** is specified, the `0` flag is ignored

   - Left justify, `-`:
       - the result of the conversion is left-justified within the field (width is padded with blanks on the right)
       - the conversion is right-justified if this flag is not specified

### Modifiers

#### Length modifiers: l & h

   - Handles length for `d`, `i`, `u`, `o`, `x` and `X`:
       - `ld`, `li`, `lu`, `lo`, `lx`, `lX`, `hd`, `hi`, `hu`, `ho`, `hx` & `hX`
   - Long uses `LONG_MIN` to `LONG_MAX` for `d` and `i` and `ULONG_MIN` to `ULONG_MAX` for `u`, `o`, `x` & `X`
   - Short uses `SHRT_MIN` to `SHRT_MAX` for `d` and `i` and `USHRT_MIN` to `USHRT_MAX` for `u`, `o`, `x` & `X`

#### Width modifier:
   -  minimum field width can be specified as a decimal digit string following any flag specifier:
       -  in which case the field width is set to the specified number of columns
   -  the field width can also be specified as asterisk (*):
       -  in which case an additional argument of type int is accessed to determine the field width.
   -  example: to print an integer x, in a field width 6, you would write the statement `_printf("%*d", 6, x);`

#### Precision modifier:
   -  if you wish to specify the precision of an argument, it MUST be prefixed with the period 
   -  precision for the conversion can be specified as a decimal digit string or by an asterisk (*)
   -  once again, they must follow or come after a period
   -  if an asterisk is used to specify the precision:
       -  an additional argument of type int prior to the conversion/specifier argument is accessed to determine the precision
   -  if both width and precision are specified as asterisks:
       -  the order of arguments to printf() for the conversion should appear in the following order: *width*, *precision*, *value*

## More Information

   - Uses a local buffer of 1024 chars and calls write only when buffer is filled
