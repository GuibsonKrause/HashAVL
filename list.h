#ifndef LIST_H
#define LIST_H

#include "file.h"

/*------------------ DECLARATION OF STRUCTURES ------------------*/

typedef struct contact
{
    char name[50];
    char phone[50];
}TContact;

typedef struct NO
{
    TContact *contact;
    struct NO *previous, *next;
}TNO;

typedef struct list
{
    struct NO *first, *last;
}TList;

/*------------------ CALL FUNCTIONS ------------------*/

void startList(TList *l);

TList * startingList();

int voidList (TList *nList);

//void insertOrdered(TContact *nContact, TList *l);

void insertEndList (TContact *nContact, TList *l);

void listing(TList *l);

void listingOnFile(TList *l, int i, int level);

int AmountOnList(TList *l);

int removeList(TList *l, TContact *nContact);

int checkBarN(char string[]);

#endif // LIST_H
