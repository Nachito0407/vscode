/* Operando y manteniendo una lista */
#include <stdio.h>
#include <stdlib.h>

struct listNode {  /* estructura auto-referencial */
   int data;
   struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *, int);
int delete(LISTNODEPTR *, int);
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
void instructions(void);

main()
{
   LISTNODEPTR startPtr = NULL;
   char choice;
   int item;

   instructions();  /* mostrar el menú */
   printf("? ");
   scanf("%c", &choice);

   while (choice != 'c') {

      switch (choice) {
         case 'a':
            printf("Enter a character: ");
            scanf("\n%d", &item);
            insert(&startPtr, item);
            printList(startPtr);
            break;
         case 'b':
            if (!isEmpty(startPtr)) {
               printf("Enter character to be deleted: ");
               scanf("\n%d", &item);

               if (delete(&startPtr, item)) {
                  printf("%d deleted.\n", item);
                  printList(startPtr);
               }
               else
                  printf("%d not found.\n\n", item);
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
      scanf(" %c", &choice);
   }

   printf("End of run.\n");
   return 0;
}

/* Mostrar las instrucciones */
void instructions(void)
{
   printf("Enter your choice:\n"
          "   a to insert an element into the list.\n"
          "   b to delete an element from the list.\n"
          "   c to end.\n");
}

/* Insertar un nuevo valor en la lista en orden ascendente */
void insert(LISTNODEPTR *sPtr, int value)
{
   LISTNODEPTR newPtr, previousPtr, currentPtr;

   newPtr = malloc(sizeof(LISTNODE));

   if (newPtr != NULL) {    /* ¿hay espacio disponible? */
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while (currentPtr != NULL && value > currentPtr->data) {
         previousPtr = currentPtr;          /* avanzar a ...   */
         currentPtr = currentPtr->nextPtr;  /* ... el siguiente nodo */
      }

      if (previousPtr == NULL) {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      }
      else {
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      }
   }
   else
      printf("%d not inserted. No memory available.\n", value);
}

/* Eliminar un elemento de la lista */
int delete(LISTNODEPTR *sPtr, int value)
{
   LISTNODEPTR previousPtr, currentPtr, tempPtr;

   if (value == (*sPtr)->data) {
      tempPtr = *sPtr;
      *sPtr = (*sPtr)->nextPtr;  /* desenlazar el nodo */
      free(tempPtr);             /* liberar el nodo desenlazado */
      return value;
   }
   else {
      previousPtr = *sPtr;
      currentPtr = (*sPtr)->nextPtr;

      while (currentPtr != NULL && currentPtr->data != value) {
         previousPtr = currentPtr;          /* avanzar a ...   */
         currentPtr = currentPtr->nextPtr;  /* ... el siguiente nodo */
      }

      if (currentPtr != NULL) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      }
   }

   return '\0';
}

/* Devuelve 1 si la lista está vacía, 0 en caso contrario */
int isEmpty(LISTNODEPTR sPtr)
{
   return sPtr == NULL;
}

/* Mostrar la lista */
void printList(LISTNODEPTR currentPtr)
{
   if (currentPtr == NULL)
      printf("List is empty.\n\n");
   else {
      printf("The list is:\n");

      while (currentPtr != NULL) {
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      printf("NULL\n\n");
   }
}
