#include <stdio.h>  
#include <stdlib.h>

// Definición de la estructura de un nodo de la lista enlazada
struct listNode {  
    int data;   // Campo de datos que almacena un valor entero
    struct listNode *nextPtr;   // Puntero que apunta al siguiente nodo de la lista
};

typedef struct listNode LISTNODE;   // Alias para la estructura 'listNode'
typedef LISTNODE *LISTNODEPTR;      // Alias para un puntero a 'LISTNODE'

// Declaración de las funciones que operan en la lista
void insert(LISTNODEPTR *, int);    // Función para insertar un elemento en la lista
int delete(LISTNODEPTR *, int);     // Función para eliminar un elemento de la lista
int isEmpty(LISTNODEPTR);           // Función que verifica si la lista está vacía
void printList(LISTNODEPTR);        // Función que imprime la lista
void instructions(void);            // Función que muestra las instrucciones al usuario

// Función principal
int main()
{
    LISTNODEPTR startPtr = NULL;    // Inicializa el puntero de inicio de la lista como vacío
    char choice;                    // Variable para almacenar la elección del usuario
    int item;                       // Variable para almacenar el valor a insertar/eliminar

    instructions();  // Llama a la función para mostrar el menú de instrucciones
    printf("? ");
    scanf("%c", &choice);   // Lee la elección del usuario

    // Ciclo mientras el usuario no elija la opción de terminar ('c')
    while (choice != 'c') {

        // Controla las acciones basadas en la opción seleccionada
        switch (choice) {
            case 'a':  // Caso para insertar un elemento en la lista
                printf("Enter a character: ");
                scanf("\n%d", &item);    // Lee el valor que el usuario desea insertar
                insert(&startPtr, item); // Llama a la función para insertar el valor en la lista
                printList(startPtr);     // Imprime la lista actualizada
                break;
            case 'b':  // Caso para eliminar un elemento de la lista
                if (!isEmpty(startPtr)) {    // Verifica si la lista no está vacía
                    printf("Enter character to be deleted: ");
                    scanf("\n%d", &item);    // Lee el valor que el usuario desea eliminar

                    if (delete(&startPtr, item)) {  // Intenta eliminar el valor de la lista
                        printf("%d deleted.\n", item);   // Informa si fue eliminado
                        printList(startPtr);             // Imprime la lista actualizada
                    }
                    else
                        printf("%d not found.\n\n", item);   // Informa si el valor no fue encontrado
                }
                else
                    printf("List is empty.\n\n");    // Mensaje si la lista está vacía

                break;
            default:   // Caso por defecto si el usuario ingresa una opción inválida
                printf("Invalid choice.\n\n");
                instructions();  // Muestra el menú de nuevo
                break;
        }

        printf("? ");   // Pide una nueva elección al usuario
        scanf(" %c", &choice);   // Lee la nueva elección
    }

    printf("End of run.\n");   // Mensaje de finalización del programa
    return 0;
}

// Función para mostrar las instrucciones del menú
void instructions(void)
{
    printf("Enter your choice:\n"
            "   a to insert an element into the list.\n"
            "   b to delete an element from the list.\n"
            "   c to end.\n");  // Instrucciones para el usuario sobre las opciones disponibles
}

// Función para insertar un nuevo valor en la lista en orden ascendente
void insert(LISTNODEPTR *sPtr, int value)
{
    LISTNODEPTR newPtr, previousPtr, currentPtr;

    newPtr = malloc(sizeof(LISTNODE));  // Asigna memoria para un nuevo nodo

    // Verifica si la asignación de memoria fue exitosa
    if (newPtr != NULL) {    
        newPtr->data = value;  // Almacena el valor en el nuevo nodo
        newPtr->nextPtr = NULL;  // Inicializa el puntero siguiente como NULL

        previousPtr = NULL;  // Inicializa el puntero anterior como NULL
        currentPtr = *sPtr;  // Apunta al inicio de la lista

        // Busca la posición correcta para insertar el nuevo valor
        while (currentPtr != NULL && value > currentPtr->data) {
            previousPtr = currentPtr;  // Avanza al siguiente nodo
            currentPtr = currentPtr->nextPtr;  // Actualiza el puntero al siguiente nodo
        }

        // Inserta el nodo al principio si no hay nodos anteriores
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;  // Conecta el nuevo nodo al inicio de la lista
            *sPtr = newPtr;  // Actualiza el puntero de inicio de la lista
        }
        else {
            previousPtr->nextPtr = newPtr;  // Conecta el nodo anterior al nuevo nodo
            newPtr->nextPtr = currentPtr;   // Conecta el nuevo nodo al nodo siguiente
        }
    }
    else
        printf("%d not inserted. No memory available.\n", value);  // Mensaje si no hay memoria disponible
}

// Función para eliminar un elemento de la lista
int delete(LISTNODEPTR *sPtr, int value)
{
    LISTNODEPTR previousPtr, currentPtr, tempPtr;

    // Verifica si el valor está en el primer nodo
    if (value == (*sPtr)->data) {
        tempPtr = *sPtr;   // Almacena temporalmente el nodo a eliminar
        *sPtr = (*sPtr)->nextPtr;  // Actualiza el puntero de inicio
        free(tempPtr);  // Libera la memoria del nodo eliminado
        return value;   // Retorna el valor eliminado
    }
    else {
        previousPtr = *sPtr;  // Apunta al primer nodo
        currentPtr = (*sPtr)->nextPtr;  // Apunta al siguiente nodo

        // Busca el nodo con el valor a eliminar
        while (currentPtr != NULL && currentPtr->data != value) {
            previousPtr = currentPtr;  // Avanza al siguiente nodo
            currentPtr = currentPtr->nextPtr;  // Actualiza el puntero al siguiente nodo
        }

        // Si encuentra el nodo, lo elimina
        if (currentPtr != NULL) {
            tempPtr = currentPtr;  // Almacena temporalmente el nodo a eliminar
            previousPtr->nextPtr = currentPtr->nextPtr;  // Conecta el nodo anterior con el siguiente
            free(tempPtr);  // Libera la memoria del nodo eliminado
            return value;   // Retorna el valor eliminado
        }
    }

    return '\0';  // Retorna NULL si el valor no fue encontrado
}

// Función que verifica si la lista está vacía
int isEmpty(LISTNODEPTR sPtr)
{
    return sPtr == NULL;  // Retorna 1 si la lista está vacía, 0 si no lo está
}

// Función para imprimir los elementos de la lista
void printList(LISTNODEPTR currentPtr)
{
    if (currentPtr == NULL)
        printf("List is empty.\n\n");  // Mensaje si la lista está vacía
    else {
        printf("The list is:\n");

        // Itera por la lista e imprime cada nodo
        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);  // Imprime el valor del nodo actual
            currentPtr = currentPtr->nextPtr;     // Avanza al siguiente nodo
        }

        printf("NULL\n\n");  // Indica el final de la lista
    }
}