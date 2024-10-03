/* Writing to a random access file */
#include <stdio.h>

struct clientData {
    int acctNum;
    char lastName[15];
    char firstName[10];
    float balance;
};

main()
{
   FILE *cfPtr;
    struct clientData client;

    if ((cfPtr = fopen("credit.dat", "r+")) == NULL)
        printf("File could not be opened.\n");
    else {
        printf("Enter account number"
                " (1 to 100, 0 to end input)\n? ");
        scanf("%d", &client.acctNum);

        while (client.acctNum != 0) {
            printf("Enter lastname, firstname, balance\n? ");
            scanf("%s%s%f", &client.lastName, 
                &client.firstName, &client.balance);
         fseek(cfPtr, (client.acctNum - 1) * 
                sizeof(struct clientData), SEEK_SET);
            fwrite(&client, sizeof(struct clientData), 1, cfPtr);
            printf("Enter account number\n? ");
            scanf("%d", &client.acctNum);
        }
    }

    fclose(cfPtr);

    return 0;
}