#include "file.h"

TNodo* createAvlTree()
{
    TNodo* root = (TNodo*) malloc(sizeof(TNodo));
    if(root != NULL)
        root = NULL;
    return root;
}

TNodo* startAvlTree(TNodo* root)
{
    if(root != NULL)
        root = NULL;
    return root;
}

int treeHeight(TNodo *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int greaterHeight(int a, int b)
{
    if(a>b){
        return a;
    }else{
        return b;
    }
}

TNodo *turnRight(TNodo *y)
{
    TNodo *x = y->left;
    TNodo *z = x->right;

    // Turning
    x->right = y;
    y->left = z;

    //  Update the height
    y->height = greaterHeight(treeHeight(y->left), treeHeight(y->right))+1;
    x->height = greaterHeight(treeHeight(x->left), treeHeight(x->right))+1;


    // Return the root
    return x;
}

TNodo *turnLeft(TNodo *x)
{
    TNodo *y = x->right;
    TNodo *z = y->left;

    // Turning
    y->left = x;
    x->right = z;

    //  Update the height
    x->height = greaterHeight(treeHeight(x->left), treeHeight(x->right))+1;
    y->height = greaterHeight(treeHeight(y->left), treeHeight(y->right))+1;

    // Return the root
    return y;
}

int getBalancingFactor(TNodo *N)
{
    if (N == NULL)
        return 0;
    return treeHeight(N->left) - treeHeight(N->right);
}

TNodo* newNodo(TContact *contact)
{
    TNodo* nodo = (TNodo*) malloc(sizeof(TNodo));
    nodo->table = startingList();
    insertEndList(contact, nodo->table) ;
    nodo->left = NULL;
    nodo->right = NULL;
    nodo->height = 1;
    return(nodo);
}

TNodo* insertNodo(TNodo* nodo, TContact *contact)
{
    if (nodo == NULL)
        return(newNodo(contact));

    if(strcmp(contact->name, nodo->table->first->contact->name) == 0)
        insertEndList(contact, nodo->table);

    if (strcmp(contact->name, nodo->table->first->contact->name) < 0)
        nodo->left  = insertNodo(nodo->left, contact);

    if (strcmp(contact->name, nodo->table->first->contact->name) > 0)
        nodo->right = insertNodo(nodo->right, contact);

    nodo->height = greaterHeight(treeHeight(nodo->left), treeHeight(nodo->right)) + 1;

    int fator_balanc = getBalancingFactor(nodo);

    // Unbalanced

    if (fator_balanc > 1 && strcmp(contact->name,nodo->left->table->first->contact->name)<0)
        return turnRight(nodo);

    if (fator_balanc < -1 && strcmp(contact->name,nodo->right->table->first->contact->name)>0)
        return turnLeft(nodo);

    if (fator_balanc > 1 && strcmp(contact->name,nodo->left->table->first->contact->name)>0)
    {
        nodo->left =  turnLeft(nodo->left);
        return turnRight(nodo);
    }

    if (fator_balanc < -1 && strcmp(contact->name,nodo->right->table->first->contact->name)<0)
    {
        nodo->right = turnRight(nodo->right);
        return turnLeft(nodo);
    }
    return nodo;
}

TNodo* removeNodo (TContact *contact,  TNodo *nodo)
{
    int auxRemove;

    if (nodo == NULL || nodo->table == NULL)
        return nodo;

    // Looking for the left
    if (strcmp(contact->name, nodo->table->first->contact->name) < 0)
        nodo->left = removeNodo(contact, nodo->left);

    // Looking for the right
    else if (strcmp(contact->name, nodo->table->first->contact->name) > 0)
        nodo->right = removeNodo(contact, nodo->right);

    // Found
    else
    {
        if((nodo->left == NULL) && (nodo->right == NULL))
        {
            // Removing from list
            auxRemove = removeList(nodo->table, contact);
            free(nodo);
            nodo = NULL;
        }
        else if(nodo->left == NULL)
        {
            TNodo *aux = nodo;
            nodo = nodo->right;
            auxRemove = removeList(nodo->table, aux->table->first->contact);
            free(aux);
        }
        else if(nodo->right == NULL)
        {
            TNodo *aux = nodo;
            nodo = nodo->left;
            auxRemove = removeList(nodo->table, aux->table->first->contact);
            free(aux);
        }
        else
        {
            TNodo *aux = nodo;
            nodo = nodo->right;
            if(nodo->left == NULL)
            {
                nodo->left = aux->left;
                auxRemove = removeList(nodo->table, aux->table->first->contact);
                free(aux);
            }
            else
            {
                TNodo *son = nodo->left;

                while (son->left != NULL)
                    son = son->left;

                son->left = aux->left;
                auxRemove = removeList(nodo->table, aux->table->first->contact);
                free(aux);
            }
        }
    }

    return nodo;
}

TReturn *searchNodo (TContact *contact, TNodo *nodo, TReturn *ret)
{
    if (nodo == NULL)
    {
        ret->flag = 0;
        return ret;
    }
    // Looking for the left
    else if (strcmp(contact->name, nodo->table->first->contact->name) < 0)
    {
        ret->flag = 0;
        ret->amount =  ret->amount + 1;
        ret = searchNodo(contact, nodo->left, ret);
    }
    // Looking for the right
    else if (strcmp(contact->name, nodo->table->first->contact->name) > 0)
    {
        ret->flag = 0;
        ret->amount =  ret->amount + 1;
        ret = searchNodo(contact, nodo->right, ret);
    }
    //Found
    else
    {
        ret->contact = nodo->table->first->contact;
        ret->flag = 1;
    }

    return ret;
}

void hikingPerOrder(TNodo *R)
{
    if (R != NULL)
    {
        hikingPerOrder(R->left);
        listing(R->table);
        //        printf("\t\t%s\n",R->table->first->contact->name);
        hikingPerOrder(R->right);
    }
}

void hikingAfterOrder(TNodo *R)
{
    if (R != NULL)
    {
        hikingAfterOrder(R->left);
        hikingAfterOrder(R->right);
        printf("\t\t%s\n",R->table->first->contact->name);
    }
}

void hikingBeforeOrder(TNodo *R)
{
    if (R != NULL)
    {
        if(R->table!= NULL)
        {
            printf("\t\t%s\n",R->table->first->contact->name);
            hikingAfterOrder(R->left);
            hikingAfterOrder(R->right);
        }
    }
}

void startRow(TRow *f)
{
    f->first = f->last = NULL;
}

int voidRow(TRow * f)
{
    return (f->first == NULL);
}

void insertRow (TRow *f, TNodo *v)
{
    TRowElement * n = (TRowElement *)malloc(sizeof(TRowElement));
    n->info = v;
    n->next = NULL;
    if (!voidRow(f))
        f->last->next = n;
    else
        f->first = n;
    f->last = n;
}

TNodo* removeRow(TRow * f)
{
    TRowElement * t;
    TNodo *v;
    if (voidRow(f))
    {
        printf("Void Row.\n");
        return NULL;
    }
    t = f->first;
    v = t->info;
    f->first = t->next;
    if (f->first == NULL)
        f->last = NULL;
    free(t);
    return v;
}

void hikingLevel(TNodo *R)
{
    TNodo *nodo;
    TRow *row = (TRow *) malloc(sizeof(TRow));

    if (R != NULL)
    {
        startRow(row);
        insertRow(row, R);

        while(voidRow(row) != 1)
        {
            nodo= removeRow (row);

            if (nodo->left !=NULL)
                insertRow(row,nodo->left);

            if (nodo->right !=NULL)
                insertRow(row,nodo->right);

            listing(nodo->table);
        }
    }
}

void hikingLevelFile(TNodo *R, int j)
{
    FILE *arq;
    char urlSaidafechada[] = "saidaHashAVL.txt";
    arq = fopen(urlSaidafechada, "a");
    TNodo *nodo;
    TRow *row = (TRow *) malloc(sizeof(TRow));
    int i = 0;
    int level = 0;

    if (R != NULL)
    {
        startRow(row);
        insertRow(row, R);

        while(voidRow(row) != 1)
        {
            nodo= removeRow (row);

            if (nodo->left !=NULL)
                insertRow(row,nodo->left);

            if (nodo->right !=NULL)
                insertRow(row,nodo->right);

//            nodo = setLevel(nodo, i);
            level = R->height - nodo->height +1;

            listingOnFile(nodo->table, j, level);
            //            printf("%d;%d;%s;%s\n", j, nodo->level, nodo->table->first->contact->name, nodo->table->first->contact->phone);
            //            fprintf(arq,"%d;%d;%s;%s\n", j, nodo->level, nodo->table->first->contact->name, nodo->table->first->contact->phone);
            //            i++;
            //            listing(nodo->table);

        }
    }
    fclose(arq);
}

void hikingLevelFileAmount(TNodo *R, int j)
{
    FILE *arq;
    char urlSaidafechada[] = "saidaHashAVL.txt";
    arq = fopen(urlSaidafechada, "a");
    TNodo *nodo;
    TRow *row = (TRow *) malloc(sizeof(TRow));
    int i = 0;

    if (R != NULL)
    {
        startRow(row);
        insertRow(row, R);

        while(voidRow(row) != 1)
        {
            nodo= removeRow (row);

            if (nodo->left !=NULL)
                insertRow(row,nodo->left);

            if (nodo->right !=NULL)
                insertRow(row,nodo->right);

            i = i + AmountOnList(nodo->table);

            //            listing(nodo->table);

        }
        fprintf(arq,"%d;%d;%d;", j, i, R->height);
        //        printf("%d;%d;%d;", j, i, nodo->height);
    }
    fclose(arq);
}

TNodo *setLevel(TNodo *R, int i)
{
    R->level = i;
    //        printf("nivel: %d\n", R->level);

    if (R->left != NULL)
        R = setLevel(R->left, i+1);

    if (R->right != NULL)
        R = setLevel(R->right, i+1);
    return (R);
}
