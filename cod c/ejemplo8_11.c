/* Using strtoul */
#include <stdio.h>
#include <stdlib.h>

main()
{
unsigned long x;
   char *string = "1234567abc", *remainderPtr;

x = strtoul(string, &remainderPtr, 0);
printf("%s\"%s\"\n%s%lu\n%s\"%s\"\n%s%lu\n",
        "The original string is ", string,
        "The converted value is ", x,
        "The remainder of the original string is ", 
        remainderPtr, 
        "The converted value minus 567 is ", x - 567);
return 0;
}
