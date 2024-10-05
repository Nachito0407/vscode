/* Creating a randomly accessed file sequentially */
#include <stdio.h>

struct clientData {
    int acctNum;
    char lastName[15];
    char firstName[10];
    float balance;
};

main()
{
    int i;
    struct clientData blankClient = {0, "", "", 0.0};
   FILE *cfPtr;

    if ((cfPtr = fopen("credit.dat", "w")) == NULL)
        printf("File could not be opened.\n");
    else {

        for (i = 1; i <= 100; i++)
            fwrite(&blankClient, 
                sizeof(struct clientData), 1, cfPtr);

        fclose (cfPtr);
    }

    return 0;
}
