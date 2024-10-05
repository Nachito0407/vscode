/* Operating and maintaining a list */
#include <stdio.h>
#include <stdlib.h>

struct listNode {  /* self-referential structure */
    int data;
   struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *, int);
int delete(LISTNODEPTR *, int);
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
void instructions(void);

main()
{
    LISTNODEPTR startPtr = NULL;
    char choice;
    int item;

   instructions();  /* display the menu */
    printf("? ");
    scanf("%c", &choice);

    while (choice != 'c') {

        switch (choice) {
            case 'a':
            printf("Enter a character: ");
            scanf("\n%d", &item);
            insert(&startPtr, item);
            printList(startPtr);
            break;
            case 'b':
            if (!isEmpty(startPtr)) {
                printf("Enter character to be deleted: ");
                scanf("\n%d", &item);

                if (delete(&startPtr, item)) {
                    printf("%d deleted.\n", item);
                    printList(startPtr);
                }
                else
                    printf("%d not found.\n\n", item);
            }
            else
                printf("List is empty.\n\n");

            break;
            default:
            printf("Invalid choice.\n\n");
            instructions();
            break;
        }

        printf("? ");
        scanf("%c", &choice);
    }

    printf("End of run.\n");
    return 0;
}

/* Print the instructions */
void instructions(void)
{
    printf("Enter your choice:\n"
            "   a to insert an element into the list.\n"
            "   b to delete an element from the list.\n"
            "   c to end.\n");
}

/* Insert a new value into the list in sorted order */
void insert(LISTNODEPTR *sPtr, int value)
{
    LISTNODEPTR newPtr, previousPtr, currentPtr;

    newPtr = malloc(sizeof(LISTNODE));

   if (newPtr != NULL) {    /* is space available */
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
      currentPtr = *sPtr;

        while (currentPtr != NULL && value > currentPtr->data) {
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
        }

        if (previousPtr == NULL) {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
        printf("%d not inserted. No memory available.\n", value);
}

/* Delete a list element */
int delete(LISTNODEPTR *sPtr, int value)
{
    LISTNODEPTR previousPtr, currentPtr, tempPtr;

    if (value == (*sPtr)->data) {
      tempPtr = *sPtr;
      *sPtr = (*sPtr)->nextPtr;  /* de-thread the node */
      free(tempPtr);             /* free the de-threaded node */
        return value;
    }
    else {
      previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value) {
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
        }

        if (currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty(LISTNODEPTR sPtr)
{
    return sPtr == NULL;
}

/* Print the list */
void printList(LISTNODEPTR currentPtr)
{
    if (currentPtr == NULL)
        printf("List is empty.\n\n");
    else {
        printf("The list is:\n");

        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        } 

        printf("NULL\n\n");
    }
}