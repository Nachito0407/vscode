#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*estructura autoreferenciada*/
struct treeNode {
   struct treeNode *leftPtr; // Puntero al subárbol izquierdo
   int data; // Valor del nodo
   struct treeNode *rightPtr; // Puntero al subárbol derecho
};

typedef struct treeNode TREENODE; // Sinónimo para la estructura treeNode
typedef TREENODE *TREENODEPTR; // Sinónimo para un puntero a TREENODE

/*prototipos*/
void insertNode(TREENODEPTR *, int); // Función para insertar un nodo en el árbol
void inOrder(TREENODEPTR);           // Función para recorrer el árbol en inorden
void preOrder(TREENODEPTR);          // Función para recorrer el árbol en preorden
void postOrder(TREENODEPTR);         // Función para recorrer el árbol en postorden

/*la función main comienza con la ejecución del programa*/
main()
{
   int i, item; // Contador para el ciclo y variable para almacenar valores aleatorios
   TREENODEPTR rootPtr = NULL; // Inicializa el puntero de la raíz del árbol como NULL (árbol vacío)

    srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios

   /* inserta valores al azar entre 1 y 15 en el árbol */
    printf("The numbers being placed in the tree are:\n");

    for (i = 1; i <= 10; i++) {  // Repite 10 veces para insertar 10 valores aleatorios
        item = rand() % 15;      // Genera un número aleatorio entre 0 y 14
        printf("%3d", item);     // Imprime el valor generado
        insertNode(&rootPtr, item); // Inserta el valor en el árbol
    }

   /* recorre el árbol en preorden */
    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr); // Llama a la función para recorrer en preorden

   /* recorre el árbol en inorden */
    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr); // Llama a la función para recorrer en inorden

   /* recorre el árbol en postorden */
    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr); // Llama a la función para recorrer en postorden

    return 0; // Finaliza el programa con éxito
}

/*inserta un nodo dentro del árbol*/
void insertNode(TREENODEPTR *treePtr, int value)
{
   if (*treePtr == NULL) {   // Si el árbol está vacío
      *treePtr = malloc (sizeof(TREENODE)); // Reserva memoria para un nuevo nodo

      if (*treePtr != NULL) { // Si la memoria fue asignada correctamente
            (*treePtr)->data = value;      // Asigna el valor al nodo
            (*treePtr)->leftPtr = NULL;    // Inicializa el puntero izquierdo como NULL
            (*treePtr)->rightPtr = NULL;   // Inicializa el puntero derecho como NULL
        }
        else 
            printf("%d not inserted. No memory available.\n", 
                value); // Si no hay suficiente memoria, imprime un mensaje de error

    }
   else // Si el árbol no está vacío
      if (value < (*treePtr)->data) // Si el valor a insertar es menor que el nodo actual
            insertNode(&((*treePtr)->leftPtr), value); // Inserta en el subárbol izquierdo
        else
         if (value > (*treePtr)->data) // Si el valor a insertar es mayor que el nodo actual
            insertNode(&((*treePtr)->rightPtr), value); // Inserta en el subárbol derecho
         else // Si el valor es igual al del nodo actual (evita duplicados)
            printf("dup"); // Muestra "dup" (duplicado)
}

/*comienza el recorrido inorden del árbol*/
void inOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) { // Si el árbol no está vacío
        inOrder(treePtr->leftPtr);  // Recorre primero el subárbol izquierdo
        printf("%3d", treePtr->data); // Imprime el valor del nodo
        inOrder(treePtr->rightPtr); // Recorre luego el subárbol derecho
    }
}

/*comienza el recorrido preorden del árbol*/
void preOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) { // Si el árbol no está vacío
        printf("%3d", treePtr->data); // Imprime el valor del nodo
        preOrder(treePtr->leftPtr);   // Recorre el subárbol izquierdo
        preOrder(treePtr->rightPtr);  // Recorre el subárbol derecho
    }
}

/*comienza el recorrido postorden del árbol*/
void postOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) { // Si el árbol no está vacío
        postOrder(treePtr->leftPtr);  // Recorre primero el subárbol izquierdo
        postOrder(treePtr->rightPtr); // Recorre luego el subárbol derecho
        printf("%3d", treePtr->data); // Imprime el valor del nodo
    }
}
