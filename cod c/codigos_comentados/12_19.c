/* crea un arbol binario y lo recorre en preorden,
inorden, y en postorden */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*estructura autoreferenciada*/
struct treeNode {
   struct treeNode *leftPtr; //puntero al subarbol izquierdo
   int data; //valor del nodo
   struct treeNode *rightPtr; //puntero al subarbol derecho
};

typedef struct treeNode TREENODE; //sinonimo de la estructura treeNode
typedef TREENODE *TREENODEPTR; //sinonimo de TREENODE

/*prototipos*/
void insertNode(TREENODEPTR *, int);
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);

/*la funcion main comineza con la ejecucion del programa*/
main()
{
   int i, item; //contador para el ciclo del 1 a 10 y variable para almacenar valores al azar
   TREENODEPTR rootPtr = NULL; //arbol inicialmente vacio

    srand(time(NULL));

   /* inserta valores al azar entre 1 y 15 en el arbol */
    printf("The numbers being placed in the tree are:\n");

    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

   /* recorre el arbol en preorden */
    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);

   /* recorre el arbol en inorden */
    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);

   /* recorre el arbol en postorden */
    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);

    return 0;
}

/*inserta un nodo dentro del arbol*/
void insertNode(TREENODEPTR *treePtr, int value)
{
   if (*treePtr == NULL) {   // si el arbol esta vacio 
      *treePtr = malloc (sizeof(TREENODE));

      if (*treePtr != NULL) { //si la memoria esta asignada entonces el dato
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else 
            printf("%d not inserted. No memory available.\n", 
                value);

    }
   else //el arbol no esta vacio
      if (value < (*treePtr)->data) //el dato a insertar es menor que el dato en el nodo actual
            insertNode(&((*treePtr)->leftPtr), value);
        else
         if (value > (*treePtr)->data) //el dato a insertar es mayor que el dato en el nodo actual
            insertNode(&((*treePtr)->rightPtr), value);
         else //ignora el valor duplicado del dato
            printf("dup");
}

/*comienza el recorrido inorden del arbol*/
void inOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) { //si el arbol no esta vacio, entonces recorrelo
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

/*comienza el reocorrido preorden del arbol*/
void preOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) { //si el arbol no esta vacio, entonces recorrelo
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

/*comienza el recorrido postorden del arbol*/
void postOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) { //si el arbol no esta vacio, entonces recorrelo
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}

