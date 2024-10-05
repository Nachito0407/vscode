/* Printing an unsigned integer in bits */
#include <stdio.h>

main()
{
    unsigned x;
    void displayBits(unsigned);

    printf("Enter an unsigned integer: ");
    scanf("%u", &x);
    displayBits(x);
    return 0;
}

void displayBits(unsigned value)
{
    unsigned c, displayMask = 1 << 15;

    printf("%7u = ", value);

    for (c = 1; c <= 16; c++) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1;

        if (c % 8 == 0)
            putchar(' ');
    }

    putchar('\n');
}
