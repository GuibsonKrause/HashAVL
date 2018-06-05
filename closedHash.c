#include "file.h"

TClosedHash *createClosedHash(int t)
{
    int i;
    TClosedHash *hash = (TClosedHash *) malloc (sizeof (TClosedHash));
    hash->amount = t;
    hash->table = (TNodo**) malloc(t * sizeof (TNodo));

    for (i = 0; i < t; i++)
        hash->table[i] = startAvlTree(hash->table[i]);
    return hash;
}

unsigned long int hashCode(TContact *c, TClosedHash *h)
{
    unsigned long int amount = 1, code;
    int lenght = strlen(c->name);
    int i = 0;
    while (i < 3 && i <= lenght)
    {
        amount *= c->name[i];
        i++;
    }
    code = amount % h->amount;
    return code;
}

void insertClosedHash(TClosedHash *hash, TContact *nContact)
{

    unsigned long int code = hashCode(nContact, hash);
    hash->table[code]= insertNodo( (hash->table[code]), nContact);
}

TReturn *removeClosedHash(TClosedHash *hash, TContact *nContact, TReturn *ret)
{
    unsigned long int code = hashCode(nContact, hash);

    hash->table[code]= removeNodo( nContact, hash->table[code]);
    return searchNodo(nContact, hash->table[code], ret);
}

void listClosedHash(TClosedHash *hash)
{
    int i = 0;
    for(i = 0; i< hash->amount; i++)
    {
        printf("\nIndex: %i \n",i );
        hikingLevel(hash->table[i]);
    }
}

void listingClosedHashFile(TClosedHash *hash)
{
    int i = 0;
    for(i = 0; i< hash->amount; i++)
    {
        hikingLevelFile(hash->table[i], i);
    }

    for(i = 0; i< hash->amount; i++)
    {
        hikingLevelFileAmount(hash->table[i], i);
    }
}

TReturn *searchClosedHash(TClosedHash *hash, TContact *nContact, TReturn *ret)
{
    unsigned long int code = hashCode(nContact, hash);
    return searchNodo( nContact, hash->table[code], ret);
}
