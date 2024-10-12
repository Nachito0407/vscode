/* operacion y mantenimiento de una cola */

#include <stdio.h>
#include <stdlib.h>

/*Estrucutura autoreferenciada*/
struct queueNode {  
   char data; //defide data como char
   struct queueNode *nextPtr; //puntero queueNode
};

typedef struct queueNode QUEUENODE;
typedef QUEUENODE *QUEUENODEPTR;

/* prototipo de las funciones */
void printQueue(QUEUENODEPTR);
int isEmpty(QUEUENODEPTR);
char dequeue(QUEUENODEPTR *, QUEUENODEPTR *);
void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, char);
void instructions(void);

/*la funcion main comienza la ejecucion del programa*/
main()
{
   QUEUENODEPTR headPtr = NULL, tailPtr = NULL; //inicializa headPtr y tailPtr
   int choice; //eleccion del menu del usuario
   char item; //entrada char del usuario

   instructions(); //despliega el menu
    printf("? ");
    scanf("%d", &choice);

    /*mientras el usuario no introduzca 3*/
    while (choice != 3) {

        switch(choice) {

            /*agrega el valor*/
            case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;

            /*retira el valor*/
            case 2:
            if (!isEmpty(headPtr)) { //si la cola no esta vacia
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

/*despliega las instrucciones del programa para el usuario*/
void instructions(void)
{
   printf ("Enter your choice:" //introduzca su opcion
           "   1 to add an item to the queue" //para retirar un elemento a la cola
           "   2 to remove an item from the queue" //para eliminar un elemento de la cola
            "   3 to end");
}

/*insertar un nodo al final de la cola*/
void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, 
                char value)
{
   QUEUENODEPTR newPtr; //puntero a un nuevo nodo

    newPtr = malloc(sizeof(QUEUENODE));

   if (newPtr != NULL) { //es espacio disponible
        newPtr->data = value;
        newPtr->nextPtr = NULL;

      if (isEmpty(*headPtr)) //si esta vacia agrega un nodo a la cabeza
         *headPtr = newPtr;
        else
            (*tailPtr)->nextPtr = newPtr;

      *tailPtr = newPtr;
    }
    else
        printf("%c not inserted. No memory available.\n", value);
}

/*elimina el nodo de la cabeza de la cola*/
char dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr)
{
   char value; //valor del nodo
   QUEUENODEPTR tempPtr; //puntero a un nodo temporal

    value = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

   if (*headPtr == NULL) //si la cola esta vacia
      *tailPtr = NULL;

    free(tempPtr);
    return value;
}

/*devuelve 1 si la cola esta vacia, de lo contrario 0*/
int isEmpty(QUEUENODEPTR headPtr)
{
    return headPtr == NULL;
}

void printQueue(QUEUENODEPTR currentPtr) //imprime la cola
{
   if (currentPtr == NULL) //si la cola esta vacia
        printf("Queue is empty.\n\n");
    else {
        printf("The queue is:\n");

      while (currentPtr != NULL) { //mientras no sea el final de la cola
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}

