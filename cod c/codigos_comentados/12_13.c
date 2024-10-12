#include <stdio.h>
#include <stdlib.h>

/* Estructura autoreferenciada */
struct queueNode {  
    char data; // Almacena un dato de tipo char
    struct queueNode *nextPtr; // Puntero al siguiente nodo en la cola
};

typedef struct queueNode QUEUENODE; // Define el tipo QUEUENODE como alias de struct queueNode
typedef QUEUENODE *QUEUENODEPTR; // Define un puntero a QUEUENODE como QUEUENODEPTR

/* Prototipo de las funciones */
void printQueue(QUEUENODEPTR); // Prototipo para imprimir la cola
int isEmpty(QUEUENODEPTR); // Prototipo para verificar si la cola está vacía
char dequeue(QUEUENODEPTR *, QUEUENODEPTR *); // Prototipo para eliminar un elemento de la cola
void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, char); // Prototipo para agregar un elemento a la cola
void instructions(void); // Prototipo para mostrar las instrucciones del programa

/* La función main comienza la ejecución del programa */
main()
{
    QUEUENODEPTR headPtr = NULL, tailPtr = NULL; // Inicializa headPtr y tailPtr como NULL (cola vacía)
    int choice; // Opción del menú seleccionada por el usuario
    char item; // Caracter introducido por el usuario

    instructions(); // Muestra el menú de instrucciones
    printf("? ");
    scanf("%d", &choice); // Lee la opción del usuario

    /* Mientras el usuario no seleccione 3 */
    while (choice != 3) {

        switch(choice) {

            /* Opción para agregar un valor a la cola */
            case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item); // Lee un carácter del usuario
            enqueue(&headPtr, &tailPtr, item); // Agrega el carácter a la cola
            printQueue(headPtr); // Imprime el estado actual de la cola
            break;

            /* Opción para eliminar un valor de la cola */
            case 2:
            if (!isEmpty(headPtr)) { // Si la cola no está vacía
                item = dequeue(&headPtr, &tailPtr); // Elimina el elemento de la cabeza de la cola
                printf("%c has been dequeued.\n", item); // Muestra el valor eliminado
            }

            printQueue(headPtr); // Imprime el estado actual de la cola
            break;

            /* Opción inválida */
            default:
            printf("Invalid choice.\n\n"); // Informa al usuario que ha introducido una opción no válida
            instructions(); // Vuelve a mostrar las instrucciones
            break;
        }

        printf("? ");
        scanf("%d", &choice); // Lee la siguiente opción del usuario
    }

    printf("End of run.\n"); // Finaliza el programa
    return 0; // Retorna 0 indicando que el programa ha terminado correctamente
}

/* Muestra las instrucciones del programa al usuario */
void instructions(void)
{
   printf ("Enter your choice:" // Introduce tu opción
            "   1 to add an item to the queue" // Opción para agregar un elemento a la cola
            "   2 to remove an item from the queue" // Opción para eliminar un elemento de la cola
            "   3 to end"); // Opción para terminar el programa
}

/* Inserta un nodo al final de la cola */
void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, 
                char value)
{
   QUEUENODEPTR newPtr; // Crea un puntero a un nuevo nodo

    newPtr = malloc(sizeof(QUEUENODE)); // Reserva memoria para un nuevo nodo

   if (newPtr != NULL) { // Si hay espacio disponible
        newPtr->data = value; // Asigna el valor introducido al nuevo nodo
        newPtr->nextPtr = NULL; // El nuevo nodo no apunta a ningún otro nodo (final de la cola)

        if (isEmpty(*headPtr)) // Si la cola está vacía, el nuevo nodo será la cabeza
         *headPtr = newPtr;
        else
            (*tailPtr)->nextPtr = newPtr; // Si la cola no está vacía, enlaza el nuevo nodo al final

        *tailPtr = newPtr; // El nuevo nodo se convierte en el final de la cola
    }
    else
        printf("%c not inserted. No memory available.\n", value); // Si no hay memoria, muestra un mensaje de error
}

/* Elimina el nodo de la cabeza de la cola */
char dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr)
{
    char value; // Almacena el valor del nodo que se va a eliminar
    QUEUENODEPTR tempPtr; // Puntero a un nodo temporal para eliminar

    value = (*headPtr)->data; // Obtiene el valor del nodo en la cabeza
    tempPtr = *headPtr; // Apunta temporalmente al nodo de la cabeza
    *headPtr = (*headPtr)->nextPtr; // Mueve la cabeza al siguiente nodo

    if (*headPtr == NULL) // Si la cola queda vacía, también reinicia el puntero al final
        *tailPtr = NULL;

    free(tempPtr); // Libera la memoria del nodo eliminado
    return value; // Retorna el valor eliminado
}

/* Devuelve 1 si la cola está vacía, de lo contrario 0 */
int isEmpty(QUEUENODEPTR headPtr)
{
    return headPtr == NULL; // Si el puntero a la cabeza es NULL, la cola está vacía
}

/* Imprime el contenido de la cola */
void printQueue(QUEUENODEPTR currentPtr) 
{
    if (currentPtr == NULL) // Si la cola está vacía
        printf("Queue is empty.\n\n"); // Muestra que la cola está vacía
    else {
        printf("The queue is:\n");

        while (currentPtr != NULL) { // Mientras no sea el final de la cola
            printf("%c --> ", currentPtr->data); // Imprime el dato actual
            currentPtr = currentPtr->nextPtr; // Avanza al siguiente nodo
        }

        printf("NULL\n\n"); // Indica el final de la cola
    }
}
