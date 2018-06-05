#include "file.h"

void startList(TList *l)
{
    l->first = l->last = NULL;
}

TList * startingList()
{
    TList *l = (TList*) malloc (sizeof (TList));
    l->first = l->last = NULL;
    return l;
}

int voidList (TList *l)
{
    if (l->first == NULL)
        return 1;
    else
        return 0;
}

/*
void insertOrdered(TContact *nContact, TList *l)
{
    TNO *novo = (TNO*) malloc (sizeof (TNO));
    int i = 0, j = 0;
    TNO *p = l->first, *aux = l->first;
    novo->contact = nContact;
    novo->prox = NULL;
    novo->previous = NULL;
    
    if (voidList(l))
        l->first = novo; // lista vazia
    else
    {
        while ((p != NULL)&& strcmp(p->contact->name, nContact->name) <= 0) // percorre lista
        {
            aux = p;
            p = p->prox;
        }
        
        if (p == aux) // Novo é menor
        {
            novo->previous = NULL;
            l->first->previous = novo;
            novo->prox = l->first;
            l->first = novo;
        }
        else if (p == NULL) // Novoé o maior
        {
            aux->prox = novo;
            novo->previous = aux;
            novo->prox = NULL;
        }
        else  //  O novo esta no meio
        {
            aux->prox->previous = novo;
            novo->prox = aux->prox;
            novo->previous = aux;
            aux->prox = novo;
        }
    }
}

*/

void insertEndList (TContact *nContact, TList *l)
{
    TNO *novo = (TNO*) malloc (sizeof (TNO));
    novo->contact = nContact;
    novo->next = NULL;

    if (voidList(l))
        l->first = novo;
    else
        l->last->next = novo;
    l->last = novo;
}


void listing(TList *l)
{
    int i = 1;
    TNO *atual = (TNO*)malloc(sizeof(TNO));
    atual = l->first;
    
    if (atual == NULL)
    {
        printf("Void!\n\n");
        return;
    }
    while(atual != NULL)
    {
        printf("\Item %d of list\n", i);
        printf("\nName: %s \nPhone: %s\n\n", atual->contact->name, atual->contact->phone);
        atual = atual->next;
        i++;
    }
    free(atual);
}

void listingOnFile(TList *l, int i, int level)
{
    FILE *arq;
    char urlSaidafechada[] = "saidaHashAVL.txt";
    arq = fopen(urlSaidafechada, "a");
    TNO *current = (TNO*)malloc(sizeof(TNO));
    current = l->first;

    if (current == NULL)
    {
        /*Empty list*/
        fprintf(arq, "%i;void!\n", i);
        return;
    }

    while(current != NULL)
    {
        /*Printing on file the index, level, name and phone*/
        fprintf(arq,"%d;%d;%s;%s\n", i, level, current->contact->name, current->contact->phone); // printa o indice e o elemento que está nelee
        current = current->next;
    }
    fclose(arq);
}

int AmountOnList(TList *l)
{
    TNO *current = (TNO*)malloc(sizeof(TNO));
    current = l->first;
    int amountList = 0;

    if (current == NULL)
    {
        return amountList;
    }

    while(current != NULL)
    {
        amountList++;
        current = current->next;
    }

    return amountList;
}

int removeList(TList *l, TContact *nContact)
{
    TNO *ante, *aux;    
    
    if (voidList(l))
    {
        return -1;
    }else
    {
        aux = l->first;
        ante=NULL;
        
        while ((aux != NULL) && (strcmp(aux->contact->name, nContact->name) < 0))
        {
            ante = aux;
            aux = aux->next;
        }
        if(aux==NULL || (strcmp(aux->contact->name, nContact->name) > 0))
            /*Non-existent element*/
            return 0;
        
        if (aux != l->first && aux != l->last)
            ante->next = aux->next;
        else
        {
            if (aux == l->first)
                l->first = l->first->next;
            
            if (aux == l->last)
            {
                l->last = ante;
                if (ante != NULL)
                    ante->next = NULL;
            }
        }
    }
    free(aux);
    return 1;
}

/*Checks if the string contains a \n that disturbs the comparison*/
int checkBarN(char string[])
{
    int i, lenght = strlen(string);
    for (i = 0; i <= lenght; i++)
    {
        if (string[i] == '\n')
            return 1;
    }
    return 0;
}
