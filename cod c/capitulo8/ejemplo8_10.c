/* Using strtol */
#include <stdio.h>
#include <stdlib.h>

main()
{
long x;
   char *string = "-1234567abc", *remainderPtr;

x = strtol(string, &remainderPtr, 0);
printf("%s\"%s\"\n%s%ld\n%s\"%s\"\n%s%ld\n",
    "The original string is ", string,
    "The converted value is ", x,
    "The remainder of the original string is ", 
    remainderPtr,
    "The converted value plus 567 is ", x + 567);
return 0;
}
