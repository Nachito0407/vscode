/* Addition program */
#include <stdio.h>
#include <stdlib.h>
main()
{
   int integer1, integer2, sum;      /* declaration */

   printf("Enter first integer\n");  /* prompt */
   scanf("%d", &integer1);           /* read an integer */
   printf("Enter second integer\n"); /* prompt */
   scanf("%d", &integer2);           /* read an integer */
   sum = integer1 + integer2;        /* assignment of sum */
   printf("Sum is %d\n", sum);       /* print sum */

   return 0;  /* indicate that program ended successfully */
}

