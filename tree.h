#ifndef TREE_H
#define TREE_H

#include "file.h"

/*------------------ DECLARATION OF STRUCTURES ------------------*/

typedef struct strReturn
{
    int flag;
    int amount;
    TContact *contact;
}TReturn;

typedef struct Nodo
{
    TList *table;
    struct Nodo *left;
    struct Nodo *right;
    int height;
    int level;
}TNodo;

typedef struct rowElement
{
    TNodo *info;
    struct rowElement * next;
}TRowElement;

typedef struct row
{
    TRowElement * first;
    TRowElement * last;
}TRow;

/*------------------ CALL FUNCTIONS ------------------*/

TNodo *createAvlTree();

TNodo *startAvlTree(TNodo* root);

int treeHeight(TNodo *N);

int greaterHeight(int a, int b);

TNodo *turnRight(TNodo *y);

TNodo *turnLeft(TNodo *x);

int getBalancingFactor(TNodo *N);

TNodo *newNodo(TContact *contact);

TNodo *insertNodo(TNodo* nodo, TContact *contact);

TNodo *removeNodo (TContact *contact,  TNodo *nodo);

TReturn *searchNodo (TContact *contact, TNodo *nodo, TReturn *ret);

void hikingPerOrder(TNodo *R);

void hikingAfterOrder(TNodo *R);

void hikingBeforeOrder(TNodo *R);

void startRow(TRow *f);

int voidRow(TRow * f);

void insertRow (TRow *f, TNodo *v);

TNodo *removeRow(TRow * f);

void hikingLevel(TNodo *R);

void hikingLevelFile(TNodo *R, int i);

void hikingLevelFileAmount(TNodo *R, int j);

TNodo *setLevel(TNodo *R, int i);

#endif // TREE_H
