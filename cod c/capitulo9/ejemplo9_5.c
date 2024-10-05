/* Printing strings and characters */
#include <stdio.h>

main()
{
    
    char character = 'A';
    char string[] = "This is a string";
   char *stringPtr = "This is also a string";

    printf("%c\n", character);
    printf("%s\n", "This is a string");
    printf("%s\n", string);
    printf("%s\n", stringPtr);
    return 0;
}
