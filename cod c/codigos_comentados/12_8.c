/* programa de pila dianmica*/
#include <stdio.h>
#include <stdlib.h>

/*estructura autoreferenciada*/
struct stackNode {  
   int data; //define un dato como int
   struct stackNode *nextPtr; //puntero a stackNode
};

typedef struct stackNode STACKNODE; //sinonimo de la estrucutra stackNode
typedef STACKNODE *STACKNODEPTR; //sinonimo para STACKNODE

/*prototipos*/
void push(STACKNODEPTR *, int);
int pop(STACKNODEPTR *);
int isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);
void instructions(void);

main() //empieza la ejecucion del programa
{
   STACKNODEPTR stackPtr = NULL;  // apunta al tope de la pila
   int choice, value; //eleccion del menu del usuario, entrada int del usuario

   instructions(); //despliega el menu
    printf("? ");
    scanf("%d", &choice);

/*mientras el usuario no introduzca 3*/
    while (choice != 3) {

        switch (choice) {
            /*empuja el valor dentro de la pila*/
            case 1:      
            printf("Enter an integer: ");
            scanf("%d", &value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;

            /*saca el valor de la pila*/
            case 2:
            if (!isEmpty(stackPtr)) //si la pila no esta vacia
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

/* despliega instrucciones del programa para el usuario */
void instructions(void)
{
   printf("Enter choice:\n" //elija una opcion
          "1 to push a value on the stack\n" //empujar un valor dentro de la pila
          "2 to pop a value off the stack\n" //sacar un valor de la pila
          "3 to end program\n"); //terminar el programa
}

/* inserta un nodo en la cima de la pila */
void push(STACKNODEPTR *topPtr, int info)
{
   STACKNODEPTR newPtr; //puntero al nuevo nodo

    newPtr = malloc(sizeof(STACKNODE)); 
   if (newPtr != NULL) { //inserta el nodo en la cima de la pila
        newPtr->data = info;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
    }
   else //no queda espacio disponible
        printf("%d not inserted. No memory available.\n", info);
}

/* elimina un nodo de la cima de la pila */
int pop(STACKNODEPTR *topPtr)
{
   STACKNODEPTR tempPtr; //puntero a un nodo temporal
   int popValue; // valor del nodo

   tempPtr = *topPtr;
    popValue = (*topPtr)->data;
   *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

/* imprime la pila */
void printStack(STACKNODEPTR currentPtr)
{
   if (currentPtr == NULL) //si la pila esta vacia
        printf("The stack is empty.\n\n");
    else {
        printf("The stack is:\n");

      while (currentPtr != NULL) { //mientras no sea el final de la pila
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}

/* devuelve 1 si la pila esta vacia, de lo contrario 0 */
int isEmpty(STACKNODEPTR topPtr)
{
    return topPtr == NULL;
}

