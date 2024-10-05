/* Create a sequential file */
#include <stdio.h>

main()
{
    int account;
    char name[30];
    float balance;
    FILE *cfPtr;   /* cfPtr = clients.dat file pointer */

    if ((cfPtr = fopen("clients.dat", "w")) == NULL)
        printf("File could not be opened\n");
    else {
        printf("Enter the account, name, and balance.\n");
        printf("Enter EOF to end input.\n");
        printf("? ");
        scanf("%d%s%f", &account, name, &balance);

        while (!feof(stdin)) {
            fprintf(cfPtr, "%d %s %.2f\n", 
                    account, name, balance);
            printf("? ");
            scanf("%d%s%f", &account, name, &balance);
        }

        fclose(cfPtr);
    }

    return 0;
}
