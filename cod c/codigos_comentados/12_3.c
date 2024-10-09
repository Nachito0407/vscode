/* Operating and maintaining a list */
#include <stdio.h>
#include <stdlib.h>

/*estructura autoreferenciada*/
struct listNode {  
   char data; // cada listNode contiene un caracter
   struct listNode *nextPtr; //apuntador al siguiente nodo
};

typedef struct listNode LISTNODE; //sinonimo para la estructura listNode
typedef LISTNODE *LISTNODEPTR; 

void insert(LISTNODEPTR *, char);
char delete (LISTNODEPTR *, char);
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
void instructions(void);

main()
{
   LISTNODEPTR startPtr = NULL; //inicialmente no existen nodos
   int choice; //eleccion de usuario
   char item; //caracter introducido por el usuario

   instructions();  // despliega el menu
    printf("? ");
    scanf("%d", &choice);

   //se repite mientras el usuario no elija 3
    while (choice != 3) { 

        switch (choice) {
            case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item); //inserta el elemento en la lista
            printList(startPtr);
            break;
            case 2: /*si la lista esta vacia*/
            if (!isEmpty(startPtr)) {
                printf("Enter character to be deleted: ");
                scanf("\n%c", &item);

                /*si encuentra el caracter, lo remueve*/
               if (delete(&startPtr, item)) { //elimina el elemento
                    printf("%c deleted.\n", item); 
                    printList(startPtr);
                }
                else
                    printf("%c not found.\n\n", item);
            }
            else
                printf("List is empty.\n\n");

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

/* despliega las intrucciones del programa para el usuario */
void instructions(void)
{
   printf("Enter your choice:\n" // introduzca su eleccion
          "   1 to insert an element into the list.\n" // insertar un elemento de la lista
          "   2 to delete an element from the list.\n" // eliminar un elemento de la lista
          "   3 to end.\n"); // terminar
}

/* Inserta un nuevo valor dentro de la lista en orden */
void insert(LISTNODEPTR *sPtr, char value)
{
   LISTNODEPTR newPtr, previousPtr, currentPtr; //apuntador a un nuevo nodo, a un nodo previo de la lista, al nodo actual de la lista

   newPtr = malloc(sizeof(LISTNODE)); //crea un nodo

   if (newPtr != NULL) {    // es espacio disponible
      newPtr->data = value; //coloca el valor en el nodo
      newPtr->nextPtr = NULL; //el nodo no se liga a otro nodo

        previousPtr = NULL;
      currentPtr = *sPtr;

        /*ciclo para localizar la unicacion correcta en la lista*/
        while (currentPtr != NULL && value > currentPtr->data) {
         previousPtr = currentPtr;          // entra al ...   
         currentPtr = currentPtr->nextPtr;  // ... siguiente nodo
        }

        /*Inserta un nuevo nodo al principio de la lista*/
        if (previousPtr == NULL) {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
        }
      else { //inserta un nuevo nodo entre ptrAnterior y ptrActual
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
      printf("%c not inserted. No memory available.\n", value); //imprime que no se inserto porque no hay memoria suficiente
}

/* Elimina un elemento de la lista */
char delete(LISTNODEPTR *sPtr, char value)
{
   LISTNODEPTR previousPtr, currentPtr, tempPtr; //apuntador a un nodo previo de la lista, al nodo actual de la lista, a un nodo temporal

    /* Elimina el primer nodo*/
    if (value == (*sPtr)->data) {
      tempPtr = *sPtr; //almacena el nodo a eliminar
      *sPtr = (*sPtr)->nextPtr;  // desata el nodo
      free(tempPtr); // libera el nodo desatado
        return value;
    }
    else {
      previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value) {
         previousPtr = currentPtr;          //entra al ...   
         currentPtr = currentPtr->nextPtr;  // ... siguiente nodo
        }

        /*Elimina el nodo de ptrActual*/
        if (currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }                                                        
    }

    return '\0';
}

/* Devuelve 1 si la lista esta vacia, de lo contrario, 0 */
int isEmpty(LISTNODEPTR sPtr)
{
    return sPtr == NULL;
}

/* Imprime la lista */
void printList(LISTNODEPTR currentPtr)
{
    /*si la lista esta vacia*/
    if (currentPtr == NULL) 
        printf("List is empty.\n\n"); 
    else {
        printf("The list is:\n");

        /*mientras no sea el final de la lista*/
        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}