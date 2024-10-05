/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int [][13]);
void deal( int [][13], char *[], char *[]);

main()
{
   char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   char *face[13] = {"Ace", "Deuce", "Three", "Four",
                    "Five", "Six", "Seven", "Eight",
                    "Nine", "Ten", "Jack", "Queen", "King"};
int deck[4][13] = {0};

srand(time(NULL));

shuffle(deck);
deal(deck, face, suit);

return 0;
}

void shuffle(int wDeck[][13])
{
int card, row, column;

for(card = 1; card <= 52; card++) {
    row = rand() % 4;
    column = rand() % 13;

    while(wDeck[row][column] != 0) {
        row = rand() % 4;
        column = rand() % 13;
    }

    wDeck[row][column] = card;
}
}

void deal( int wDeck[][13], char *wFace[],
          char *wSuit[])
{
int card, row, column;

for (card = 1; card <= 52; card++)

    for (row = 0; row <= 3; row++)

        for (column = 0; column <= 12; column++)

            if (wDeck[row][column] == card)
            printf("%5s of %-8s%c",
                    wFace[column], wSuit[row],
                    card % 2 == 0 ? '\n' : '\t');
}