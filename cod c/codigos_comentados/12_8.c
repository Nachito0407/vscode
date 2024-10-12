#include <stdio.h>  
#include <stdlib.h> 

/* Estructura autoreferenciada para los nodos de la pila */
struct stackNode {  
    int data; // Dato almacenado en el nodo (un entero)
    struct stackNode *nextPtr; // Puntero al siguiente nodo de la pila
};

typedef struct stackNode STACKNODE; // Crea un alias para la estructura stackNode
typedef STACKNODE *STACKNODEPTR; // Crea un alias para un puntero a un stackNode

/* Prototipos de funciones */
void push(STACKNODEPTR *, int); // Función para insertar un valor en la pila
int pop(STACKNODEPTR *);        // Función para eliminar un valor de la pila
int isEmpty(STACKNODEPTR);      // Función para verificar si la pila está vacía
void printStack(STACKNODEPTR);  // Función para imprimir la pila
void instructions(void);        // Función para mostrar las instrucciones

int main() // Empieza la ejecución del programa
{
    STACKNODEPTR stackPtr = NULL;  // Inicializa el puntero de la pila como NULL (pila vacía)
    int choice, value; // Variables para la elección del usuario y el valor a insertar en la pila

    instructions(); // Despliega el menú de opciones
    printf("? ");
    scanf("%d", &choice); // Lee la opción elegida por el usuario

    /* Mientras el usuario no elija 3 (finalizar programa) */
    while (choice != 3) {
        switch (choice) {
            case 1: // Caso para insertar un valor en la pila
            printf("Enter an integer: ");
            scanf("%d", &value); // Lee el valor a insertar
            push(&stackPtr, value); // Inserta el valor en la pila
            printStack(stackPtr);    // Imprime el contenido de la pila
            break;

            case 2: // Caso para eliminar un valor de la pila
            if (!isEmpty(stackPtr)) // Verifica si la pila no está vacía
               printf("The popped value is %d.\n", pop(&stackPtr)); // Elimina y muestra el valor de la cima
            printStack(stackPtr); // Imprime el contenido de la pila
            break;

            default: // Si elige una opción no válida
            printf("Invalid choice.\n\n"); // Mensaje de opción inválida
            instructions(); // Muestra nuevamente el menú de opciones
            break;
        }

        printf("? ");
        scanf("%d", &choice); // Lee la siguiente elección del usuario
    }

    printf("End of run.\n"); // Mensaje de finalización del programa
    return 0; // Termina el programa correctamente
}

/* Muestra el menú de opciones para el usuario */
void instructions(void)
{
    printf("Enter choice:\n" // Muestra las opciones del menú
            "1 to push a value on the stack\n" // Opción para insertar un valor en la pila
            "2 to pop a value off the stack\n" // Opción para eliminar un valor de la pila
            "3 to end program\n"); // Opción para finalizar el programa
}

/* Inserta un nodo en la cima de la pila */
void push(STACKNODEPTR *topPtr, int info)
{
    STACKNODEPTR newPtr; // Crea un puntero para el nuevo nodo

    newPtr = malloc(sizeof(STACKNODE)); // Asigna memoria para el nuevo nodo
    if (newPtr != NULL) { // Verifica si se pudo asignar memoria
        newPtr->data = info;        // Asigna el valor al nuevo nodo
        newPtr->nextPtr = *topPtr;  // El nuevo nodo apunta al nodo actual de la cima de la pila
        *topPtr = newPtr;           // Actualiza la cima de la pila con el nuevo nodo
    } else { // Si no hay memoria suficiente
        printf("%d not inserted. No memory available.\n", info); // Muestra un mensaje de error
    }
}

/* Elimina un nodo de la cima de la pila */
int pop(STACKNODEPTR *topPtr)
{
   STACKNODEPTR tempPtr; // Crea un puntero temporal para almacenar el nodo a eliminar
   int popValue;         // Variable para almacenar el valor del nodo eliminado

   tempPtr = *topPtr;            // Apunta al nodo de la cima
   popValue = (*topPtr)->data;   // Obtiene el valor del nodo de la cima
   *topPtr = (*topPtr)->nextPtr; // Actualiza la cima de la pila al siguiente nodo
   free(tempPtr);                // Libera la memoria del nodo eliminado
   return popValue;              // Devuelve el valor del nodo eliminado
}

/* Imprime el contenido de la pila */
void printStack(STACKNODEPTR currentPtr)
{
   if (currentPtr == NULL) { // Si la pila está vacía
        printf("The stack is empty.\n\n"); // Muestra un mensaje de pila vacía
   } else { // Si la pila contiene nodos
        printf("The stack is:\n"); // Muestra los valores de la pila

        while (currentPtr != NULL) { // Recorre la pila hasta el final
            printf("%d --> ", currentPtr->data); // Imprime el valor del nodo actual
            currentPtr = currentPtr->nextPtr;    // Avanza al siguiente nodo
        }

      printf("NULL\n\n"); // Indica el final de la pila
    }
}

/* Verifica si la pila está vacía, devuelve 1 si es vacía, 0 si no */
int isEmpty(STACKNODEPTR topPtr)
{
    return topPtr == NULL; // Retorna 1 si la cima de la pila es NULL (vacía), 0 si no
}
