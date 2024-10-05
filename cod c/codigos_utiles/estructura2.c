#include <stdio.h>
#include <stdlib.h>

struct listNode { /* self-referential structure */
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert (LISTNODEPTR *, char);
char delete (LISTNODEPTR *, char);
int isEmpty (LISTNODEPTR);
void printList (LISTNODEPTR);
void instructions (void);

int main(int argc, char const *argv[])
{
    LISTNODEPTR startptr = NULL;
    int choice;
    char item;

    instructions(); /* mostrar el menú */
    printf("?");
    scanf("%d", &choice);

    while (choice != 3)
    {
        switch (choice)
        {
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item); // Corregido: agregar & antes de 'item'
                insert(&startptr, item); // Llamada a insertar
                printList(startptr);
                break;
            case 2:
                if (!isEmpty(startptr)) {
                    printf("Enter character to be deleted: ");
                    scanf("\n%c", &item); // Corregido: agregar & antes de 'item'
                    if (delete(&startptr, item)) {
                        printf("%c deleted.\n", item);
                        printList(startptr);
                    } else {
                        printf("%c not found.\n\n", item);
                    }
                } else {
                    printf("List is empty.\n\n");
                }
                break;
            default:
                printf("Invalid choice.\n\n");
                instructions();
                break;
        }

        printf("?");
        scanf("%d", &choice);
    }
    printf("End of run.\n");
    return 0;
}

/* mostrar las instrucciones */
void instructions(void)
{
    printf("Enter your choice:\n"
        "   1 to insert an element into the list.\n"
        "   2 to delete an element from the list.\n"
        "   3 to end.\n");
}

/* ingresar un nuevo valor ordenado en la lista */
void insert(LISTNODEPTR *sPtr, char value)
{
    LISTNODEPTR newPtr, previousPtr, currentPtr;

    newPtr = malloc(sizeof(LISTNODE));
    if (newPtr != NULL) { /* espacio disponible */
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        /* encontrar la ubicación adecuada para el nuevo nodo */
        while (currentPtr != NULL && value > currentPtr->data) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        /* insertar al principio de la lista */
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        /* insertar en el medio o al final de la lista */
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf("%c not inserted. No memory available.\n", value);
    }
}

/* borrar un elemento de la lista */
char delete(LISTNODEPTR *sPtr, char value)
{
    LISTNODEPTR previousPtr, currentPtr, tempPtr;

    /* si el nodo a eliminar está al principio */
    if (value == (*sPtr)->data) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else {
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        /* encontrar el nodo a eliminar */
        while (currentPtr != NULL && currentPtr->data != value) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        /* eliminar el nodo */
        if (currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0'; /* valor no encontrado */
}

/* devuelve 1 si la lista está vacía, 0 en caso contrario */
int isEmpty(LISTNODEPTR sPtr)
{
    return sPtr == NULL;
}

/* imprime la lista */
void printList(LISTNODEPTR currentPtr)
{
    if (currentPtr == NULL) {
        printf("List is empty.\n\n");
    }
    else {
        printf("The list is:\n");

        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}
