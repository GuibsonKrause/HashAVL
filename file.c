#include "file.h"

void run()
{
    TContact *nContact;
    TReturn *ret = (TReturn*) malloc(sizeof (TReturn));
    ret->amount = 0;
    ret->flag = 0;

    TClosedHash *hash = createClosedHash(1000);

    char urlEntrada[] = "entrada_10mil.txt", urlOperation[] = "operacoes.txt", info[100],
            *psReturn, urlBusca[] = "buscas.txt";
    FILE *file, *arqBusca;

    file = fopen(urlEntrada, "r");

    if(file == NULL)
        printf("Error, could not open input file\n");
    else
    {
        while( (fgets(info, sizeof(info), file))!=NULL )
        {
            nContact = (TContact*) malloc (sizeof (TContact));
            psReturn = strtok(info, ";");
            strcpy(nContact->name, psReturn);
            /*In the next calls, you must pass a null pointer.
             *  This indicates for the function that the search
             *  should continue on the previous pointer.*/
            psReturn = strtok('\0', "");

            /*A null value is always considered false in Boolean comparisons.*/
            if(psReturn)
            {
                if (checkBarN(psReturn) == 1)
                {
                    /*Used to remove \n from the end of the string.*/
                    psReturn = strtok(psReturn, "\n");
                }
                strcpy(nContact->phone, psReturn);
            }
            insertClosedHash(hash, nContact);
        }
    }
    fclose(file);
//    listClosedHash(hash);

    file = fopen(urlOperation, "r");
    if (file == NULL)
        printf("Error, could not open the file of operations\n");
    else
    {
        while( (fgets(info, sizeof(info), file))!=NULL )
        {
            nContact = (TContact*) malloc (sizeof (TContact));
            psReturn = strtok(info, ";");

            if (strcmp(psReturn, "E") == 0)
            {
                nContact = (TContact*) malloc (sizeof (TContact));

                psReturn = strtok('\0', "\n");
                strcpy(nContact->name, psReturn);

                ret = removeClosedHash(hash, nContact, ret);
                free(nContact);

            }
            else if (strcmp(psReturn, "I") == 0)
            {
                nContact = (TContact*) malloc (sizeof (TContact));
                psReturn = strtok('\0', ";");
                strcpy(nContact->name, psReturn);
                /*In the next calls, you must pass a null pointer.
                 *  This indicates for the function that the search
                 *  should continue on the previous pointer.*/
                psReturn = strtok('\0', "");

                /*A null value is always considered false in Boolean comparisons.*/
                if(psReturn)
                {
                    if (checkBarN(psReturn) == 1)
                    {
                        /*Used to remove \n from the end of the string.*/
                        psReturn = strtok(psReturn, "\n");
                    }
                    strcpy(nContact->phone, psReturn);
                }
                insertClosedHash(hash, nContact);
            }
            else if (strcmp(psReturn, "B") == 0)
            {
                arqBusca = fopen(urlBusca, "a");

                psReturn = strtok('\0', ";");
                strcpy(nContact->name, psReturn);
                /*In the next calls, you must pass a null pointer.
                 *  This indicates for the function that the search
                 *  should continue on the previous pointer.*/
                psReturn = strtok('\0', "");

                /*A null value is always considered false in Boolean comparisons.*/
                if(psReturn)
                {
                    if (checkBarN(psReturn) == 1)
                    {
                        /*Used to remove \n from the end of the string.*/
                        psReturn = strtok(psReturn, "\n");
                    }
                    strcpy(nContact->phone, psReturn);
                }
                ret = searchClosedHash(hash, nContact, ret);

                /*Search output file*/
                if(arqBusca == NULL)
                    printf("Erro, nao foi possivel abrir o arquivo de busca\n");
                else
                {
                    fprintf(arqBusca, "%s;%s;%d;%d\n", nContact->name,
                            nContact->phone, ret->flag, ret->amount);
                }
                fclose(arqBusca);
            }
        }
    }
    fclose(file);
    listingClosedHashFile(hash);
}

