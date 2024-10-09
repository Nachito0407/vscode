/* Operating and maintaining a queue */

#include <stdio.h>
#include <stdlib.h>

struct queueNode {  /* self-referential structure */
    char data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QUEUENODE;
typedef QUEUENODE *QUEUENODEPTR;

/* function prototypes */
void printQueue(QUEUENODEPTR);
int isEmpty(QUEUENODEPTR);
char dequeue(QUEUENODEPTR *, QUEUENODEPTR *);
void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, char);
void instructions(void);

main()
{
    QUEUENODEPTR headPtr = NULL, tailPtr = NULL;
    int choice;
    char item;

    instructions();
    printf("? ");
    scanf("%d", &choice);

    while (choice != 3) {

        switch(choice) {

            case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;
            case 2:
            if (!isEmpty(headPtr)) {
                item = dequeue(&headPtr, &tailPtr);
                printf("%c has been dequeued.\n", item);
            }

            printQueue(headPtr);
            break;

            default:
            printf("Invalid choice.\n\n");
            instructions();
            break;
        }

        printf("? ");
        scanf("%d", &choice);
    }

    printf("End of run.\n");
    return 0;
}

void instructions(void)
{
    printf ("Enter your choice:"
            "   1 to add an item to the queue"
            "   2 to remove an item from the queue"
            "   3 to end");
}

void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, 
                char value)
{
    QUEUENODEPTR newPtr;

    newPtr = malloc(sizeof(QUEUENODE));

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if (isEmpty(*headPtr))
         *headPtr = newPtr;
        else
            (*tailPtr)->nextPtr = newPtr;

      *tailPtr = newPtr;
    }
    else
        printf("%c not inserted. No memory available.\n", value);
}

char dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr)
{
    char value;
    QUEUENODEPTR tempPtr;

    value = (*headPtr)->data;
   tempPtr = *headPtr;
   *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL)
        *tailPtr = NULL;

    free(tempPtr);
    return value;
}

int isEmpty(QUEUENODEPTR headPtr)
{
    return headPtr == NULL;
}

void printQueue(QUEUENODEPTR currentPtr)
{
    if (currentPtr == NULL)
        printf("Queue is empty.\n\n");
    else {
        printf("The queue is:\n");

        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}