/* Using gets and putchar */
#include <stdio.h>

main()
{
    char sentence[80];
   void reverse(char *);
    printf("Enter a line of text:\n");
    gets(sentence);

    printf("\nThe line printed backwards is:\n");
        reverse(sentence);

return 0;
}

void reverse(char *s)
{
        if (s[0] == '\0')
    return;
    else {
        reverse(&s[1]);
        putchar(s[0]);
    }
}
