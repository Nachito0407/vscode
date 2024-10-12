/* Operar y mantener una lista */
#include <stdio.h>  
#include <stdlib.h>  

/* Estructura autorreferenciada para un nodo de la lista */
struct listNode {  
    char data; // Cada listNode contiene un carácter
    struct listNode *nextPtr; // Apuntador al siguiente nodo
};

typedef struct listNode LISTNODE; // Crea un sinónimo para la estructura listNode
typedef LISTNODE *LISTNODEPTR;    // Crea un sinónimo para un puntero a LISTNODE

// Prototipos de funciones
void insert(LISTNODEPTR *, char);       // Inserta un carácter en la lista
char delete (LISTNODEPTR *, char);      // Elimina un carácter de la lista
int isEmpty(LISTNODEPTR);               // Verifica si la lista está vacía
void printList(LISTNODEPTR);            // Imprime los elementos de la lista
void instructions(void);                // Muestra las instrucciones al usuario

int main() // Función principal
{
    LISTNODEPTR startPtr = NULL; // Inicialmente, la lista está vacía (no existen nodos)
    int choice; // Variable para almacenar la elección del usuario
    char item; // Variable para almacenar el carácter ingresado por el usuario

    instructions();  // Despliega el menú de opciones al usuario
    printf("? "); // Muestra un prompt para la entrada del usuario
    scanf("%d", &choice); // Lee la elección del usuario

    // Repite mientras el usuario no elija 3 (terminar)
    while (choice != 3) { 

        switch (choice) { // Evalúa la elección del usuario
            case 1:
                printf("Enter a character: "); // Solicita al usuario que ingrese un carácter
                scanf("\n%c", &item); // Lee el carácter ingresado
                insert(&startPtr, item); // Inserta el carácter en la lista
                printList(startPtr); // Imprime la lista actualizada
                break;
            case 2: // Opción para eliminar un elemento de la lista
                if (!isEmpty(startPtr)) { // Verifica si la lista no está vacía
                    printf("Enter character to be deleted: "); // Solicita el carácter a eliminar
                    scanf("\n%c", &item); // Lee el carácter ingresado

                   // Intenta eliminar el carácter de la lista
                    if (delete(&startPtr, item)) { // Si la eliminación fue exitosa
                        printf("%c deleted.\n", item); // Informa al usuario que se eliminó el carácter
                        printList(startPtr); // Imprime la lista actualizada
                    }
                    else
                        printf("%c not found.\n\n", item); // Informa que el carácter no se encontró
                }
                else
                   printf("List is empty.\n\n"); // Informa que la lista está vacía
                break;
            default:
               printf("Invalid choice.\n\n"); // Informa que la elección es inválida
               instructions(); // Muestra nuevamente las instrucciones
                break;
        } 

       printf("? "); // Muestra el prompt nuevamente
       scanf("%d", &choice); // Lee la siguiente elección del usuario
    }

    printf("End of run.\n"); // Informa al usuario que el programa ha finalizado
    return 0; // Finaliza la función principal
}

/* Despliega las instrucciones del programa para el usuario */
void instructions(void)
{
    printf("Enter your choice:\n" // Muestra las opciones disponibles
            "   1 to insert an element into the list.\n" // Opción 1: Insertar un elemento
            "   2 to delete an element from the list.\n" // Opción 2: Eliminar un elemento
            "   3 to end.\n"); // Opción 3: Terminar el programa
}

/* Inserta un nuevo valor dentro de la lista en orden */
void insert(LISTNODEPTR *sPtr, char value)
{
    LISTNODEPTR newPtr, previousPtr, currentPtr; // Declaración de punteros para el nuevo nodo, nodo previo y nodo actual

    newPtr = malloc(sizeof(LISTNODE)); // Reserva memoria para un nuevo nodo

    if (newPtr != NULL) {    // Verifica si se asignó memoria correctamente
        newPtr->data = value; // Asigna el valor al campo data del nuevo nodo
        newPtr->nextPtr = NULL; // Inicializa el puntero nextPtr del nuevo nodo como NULL

        previousPtr = NULL; // Inicializa el puntero previo como NULL
        currentPtr = *sPtr; // Asigna el inicio de la lista al puntero actual

        /* Ciclo para localizar la ubicación correcta en la lista */
        while (currentPtr != NULL && value > currentPtr->data) { // Recorre la lista mientras no se llegue al final y el valor sea mayor que el actual
            previousPtr = currentPtr;          // Actualiza el puntero previo al nodo actual
            currentPtr = currentPtr->nextPtr;  // Avanza al siguiente nodo
        }

        /* Inserta un nuevo nodo al principio de la lista */
        if (previousPtr == NULL) { // Si el nodo se inserta al inicio
            newPtr->nextPtr = *sPtr; // El nuevo nodo apunta al antiguo primer nodo
            *sPtr = newPtr; // Actualiza el inicio de la lista al nuevo nodo
        }
        else { // Inserta un nuevo nodo entre previousPtr y currentPtr
            previousPtr->nextPtr = newPtr; // El nodo previo apunta al nuevo nodo
            newPtr->nextPtr = currentPtr; // El nuevo nodo apunta al nodo actual
        }
    }
    else
        printf("%c not inserted. No memory available.\n", value); // Informa que no se pudo insertar el carácter por falta de memoria
}

/* Elimina un elemento de la lista */
char delete(LISTNODEPTR *sPtr, char value)
{
    LISTNODEPTR previousPtr, currentPtr, tempPtr; // Declaración de punteros para el nodo previo, nodo actual y nodo temporal

    /* Elimina el primer nodo si coincide con el valor */
    if (value == (*sPtr)->data) { // Verifica si el primer nodo contiene el valor a eliminar
        tempPtr = *sPtr; // Almacena el nodo a eliminar
        *sPtr = (*sPtr)->nextPtr;  // Actualiza el inicio de la lista al siguiente nodo
        free(tempPtr); // Libera la memoria del nodo eliminado
        return value; // Retorna el valor eliminado
    }
    else {
        previousPtr = *sPtr; // Inicializa el puntero previo al primer nodo
        currentPtr = (*sPtr)->nextPtr; // Inicializa el puntero actual al segundo nodo

        // Recorre la lista buscando el nodo que contiene el valor
        while (currentPtr != NULL && currentPtr->data != value) {
         previousPtr = currentPtr;          // Actualiza el puntero previo al nodo actual
         currentPtr = currentPtr->nextPtr;  // Avanza al siguiente nodo
        }

        /* Elimina el nodo si se encontró */
        if (currentPtr != NULL) { // Si se encontró el nodo con el valor
            tempPtr = currentPtr; // Almacena el nodo a eliminar
            previousPtr->nextPtr = currentPtr->nextPtr; // El nodo previo apunta al siguiente nodo, saltando el nodo eliminado
            free(tempPtr); // Libera la memoria del nodo eliminado
            return value; // Retorna el valor eliminado
        }                                                        
    }

    return '\0'; // Retorna carácter nulo si no se encontró el valor
}

/* Devuelve 1 si la lista está vacía, de lo contrario, 0 */
int isEmpty(LISTNODEPTR sPtr)
{
    return sPtr == NULL; // Retorna 1 si sPtr es NULL (lista vacía), de lo contrario 0
}

/* Imprime la lista */
void printList(LISTNODEPTR currentPtr)
{
    /* Verifica si la lista está vacía */
    if (currentPtr == NULL) 
        printf("List is empty.\n\n"); // Informa que la lista está vacía
    else {
        printf("The list is:\n"); // Indica que a continuación se mostrará la lista

        /* Recorre la lista hasta el final */
        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data); // Imprime el carácter del nodo actual seguido de una flecha
            currentPtr = currentPtr->nextPtr; // Avanza al siguiente nodo
        }

        printf("NULL\n\n"); // Indica el final de la lista
    }
}