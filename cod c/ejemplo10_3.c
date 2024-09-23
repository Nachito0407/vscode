/* The card shuffling and dealing program using structures */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
   char *face;
   char *suit;
};

typedef struct card Card;

void fillDeck(Card *, char *[], char *[]);
void shuffle(Card *);
void deal(Card *);

main()
{
    Card deck[52];
   char *face[] = {"Ace", "Deuce", "Three", "Four", "Five",
                    "Six", "Seven", "Eight", "Nine", "Ten",
                    "Jack", "Queen", "King"};
   char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    srand(time(NULL));

    fillDeck(deck, face, suit);
    shuffle(deck);
    deal(deck);
    return 0;
}

void fillDeck(Card *wDeck, char *wFace[], char *wSuit[])
{
    int i;

    for (i = 0; i <= 51; i++) {
        wDeck[i].face = wFace[i % 13];
        wDeck[i].suit = wSuit[i / 13];
    }
}

void shuffle(Card *wDeck)
{
    int i, j;
    Card temp;

    for (i = 0; i <= 51; i++) {
        j = rand() % 52;
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

void deal(Card *wdeck)
{
    int i;

    for (i = 0; i <= 51; i++)
        printf("%5s of %-8s%c", wdeck[i].face, wdeck[i].suit,
                (i + 1) % 2 ? '\t' : '\n');
}
