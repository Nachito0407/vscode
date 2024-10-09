/* dynamic stack program */
#include <stdio.h>
#include <stdlib.h>

struct stackNode {  /* self-referential structure */
    int data;
    struct stackNode *nextPtr;
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void push(STACKNODEPTR *, int);
int pop(STACKNODEPTR *);
int isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);
void instructions(void);

main()
{
   STACKNODEPTR stackPtr = NULL;  /* points to the stack top */
    int choice, value;

    instructions();
    printf("? ");
    scanf("%d", &choice);

    while (choice != 3) {

        switch (choice) {
         case 1:      /* push value onto stack */
            printf("Enter an integer: ");
            scanf("%d", &value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;
         case 2:      /* pop value off stack */
            if (!isEmpty(stackPtr))
                printf("The popped value is %d.\n", 
                        pop(&stackPtr));

            printStack(stackPtr);
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

/* Print the instructions */
void instructions(void)
{
    printf("Enter choice:\n"
            "1 to push a value on the stack\n"
            "2 to pop a value off the stack\n"
            "3 to end program\n");
}

/* Insert a node at the stack top */
void push(STACKNODEPTR *topPtr, int info)
{
    STACKNODEPTR newPtr;

    newPtr = malloc(sizeof(STACKNODE));
    if (newPtr != NULL) {
        newPtr->data = info;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
    }
    else
        printf("%d not inserted. No memory available.\n", info);
}

/* Remove a node from the stack top */
int pop(STACKNODEPTR *topPtr)
{
    STACKNODEPTR tempPtr;
    int popValue;

   tempPtr = *topPtr;
    popValue = (*topPtr)->data;
   *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

/* Print the stack */
void printStack(STACKNODEPTR currentPtr)
{
    if (currentPtr == NULL)
        printf("The stack is empty.\n\n");
    else {
        printf("The stack is:\n");

        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}

/* Is the stack empty? */
int isEmpty(STACKNODEPTR topPtr)
{
    return topPtr == NULL;
}
