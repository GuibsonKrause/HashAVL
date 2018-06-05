#ifndef CLOSEDHASH_H
#define CLOSEDHASH_H

#include "file.h"
#include "tree.h"

/*------------------ DECLARATION OF STRUCTURES ------------------*/

typedef struct element
{
    TContact *contact;
    struct element *next;

}TElement;

typedef struct closedHash
{
    TNodo **table;
    int amount;
}TClosedHash;

/*------------------ CALL FUNCTIONS ------------------*/

TClosedHash *createClosedHash(int t);

unsigned long int hashCode(TContact *c, TClosedHash *h);

void insertClosedHash(TClosedHash *hash, TContact *nContact);

TReturn *removeClosedHash(TClosedHash *hash, TContact *nContact, TReturn *ret);

void listClosedHash(TClosedHash *hash);

void listingClosedHashFile(TClosedHash *hash);

TReturn *searchClosedHash(TClosedHash *hash, TContact *nContact, TReturn *ret);

#endif // CLOSEDHASH_H
