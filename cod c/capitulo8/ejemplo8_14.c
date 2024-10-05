/* Using sprintf */
#include <stdio.h>

main()
{
    char s[80];
    int x;
    float y;

    printf("Enter an integer and a float:\n");
    scanf("%d%f", &x, &y);
    sprintf(s, "Integer:%6d\nFloat:%8.2f", x, y);
    printf("%s\n%s\n", 
            "The formatted output stored in array s is:", s);
    return 0;
}
