# _Printf
The Printf Replica program is a simple C function that emulates the functionality of the `printf` function and provides similar format specifiers for formatted output. The program aims to provide a convenient way to generate formatted output in C, just like the popular `printf` function.
## Usage
The `Printf Replicator` program supports various format specifiers, allowing you to format and display different types of data. To use it, follow this syntax:
_printf("format specifier", parameter1, parameter2, ...);
Here, the "format specifier" represents a specific formatting pattern, and the parameters represent the data to be displayed.
Supported format specifiers include:
- `%d` - for displaying signed integers.
- `%u` - for displaying unsigned integers.
- `%f` - for displaying floating-point numbers.
- `%c` - for displaying characters.
- `%s` - for displaying strings.
You can also combine format specifiers with additional flags and width/precision modifiers. For example:
_printf("The value of x is %d and the value of pi is %.2f", x, pi);
In the example above, `%d` and `%.2f` are format specifiers, while `x` and `pi` are the corresponding parameters.
## Example
Here's a simple example that demonstrates the usage of the `Printf Replicator` program:
#include <stdio.h>
int main(void) 
{
    int age = 25;
    float height = 1.75;
    _printf("My age is %d and my height is %.2f meters.", age, height);
    return (0);
}
Output:
My age is 25 and my height is 1.75 meters.
## Authors
Sharon Seekoei: sharonlesegoseekoei@gmail.com
Ismael Mohammed: Ismael.mdev@gmail.com

