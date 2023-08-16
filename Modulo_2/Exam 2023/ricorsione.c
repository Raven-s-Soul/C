#include <stdio.h>
#include <stdlib.h>

#define fname "interi.dat"

/* funzione ricorsiva che verifica ... Qui devi scrivere
   anche l'intestazione */

int tripleGrandiOConPiccolo(int *array, int len)
{
    int res = 0;
    if (len < 3)
    {
        // fine ricorsione
        res = 2;
    }
    else
    {
        if ((((array[0] + array[1] + array[2]) > 20) || array[0] < -20 || array[1] < -20 || array[2] < -20) && tripleGrandiOConPiccolo(array + 1, len - 1))
            res = 1;
    }
    return res;
}

/* funzione che conta ... */
int quantiNumeri()
{
    FILE *fp = fopen(fname, "rb");
    int counter = 0;
    if (!fp)
    {
        printf("\nImpossibile leggere nel file\n");
    }
    else
    {
        int aux;
        while (fread(&aux, sizeof(int), 1, fp) > 0)
        {
            counter++;
        }
    }
    fclose(fp);
    return counter;
}

/* funzione che legge ... */
void leggiNumeri(int *sequenza, int lunghezza)
{
    FILE *fp = fopen(fname, "rb");
    if (!fp)
    {
        printf("\nImpossibile leggere il file\n");
    }
    else
    {
        for (int i = 0; i < lunghezza; i++)
        {
            fread(&sequenza[i], sizeof(int), 1, fp);
        }
    }
    fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int *sequenza, int lunghezza)
{
    FILE *fp = fopen(fname, "wb");
    if (!fp)
    {
        printf("\nImpossibile scrivere nel file\n");
    }
    else
    {
        for (int i = 0; i < lunghezza; i++)
        {
            fwrite(&sequenza[i], sizeof(int), 1, fp);
        }
    }
    fclose(fp);
}

/* funzione principale */
int main()
{
    int lunghezza; //	lunghezza dell'array
    int scelta;    //	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d", &scelta);

    /* introduzione sequenza da input */
    if (scelta == 1)
    {
        /* determina la lunghezza della sequenza */
        printf("Introduci la lunghezza della sequenza: ");
        scanf("%d", &lunghezza);

        /* crea l'array e leggine i valori degli elementi */
        int array[lunghezza];
        printf("Scrivi %d elementi \n", lunghezza);
        for (int i = 0; i < lunghezza; i++)
            scanf("%d", &array[i]);

        // ricorsione
        int res = tripleGrandiOConPiccolo(array, lunghezza);
        if (res == 1)
        {
            printf("\nOgni tripla e' maggiore di 20 o e' presente un valore minore di -20 in ciascuna.\n");
        }
        else if (res == 2)
        {
            printf("\nNon sono stati introdotti abbastanza numeri.\n");
        }
        else
        {
            printf("\nNon ogni tripla e' maggiore di 20, e non e' presente un valore minore di -20.\n");
        }

        /* salva la sequenza su file */
        scriviNumeri(array, lunghezza);
    }
    /* recupero sequenza da file */
    else
    {
        /* determina la lunghezza della sequenza */
        lunghezza = quantiNumeri();
        // printf("\n%d\n",lunghezza); //!Dubug use-only
        /* prosegui se array non vuoto */
        if (lunghezza > 0)
        {
            /* crea l'array e leggine i valori degli elementi da file */
            int array[lunghezza];
            leggiNumeri(array, lunghezza);
            printf("Ecco la sequenza recuperata\n");
            for (int i = 0; i < lunghezza; i++)
                printf("%d ", array[i]);
            printf("\n");

            // ricorsione
            int res = tripleGrandiOConPiccolo(array, lunghezza);
            if (res == 1)
            {
                printf("\nOgni tripla e' maggiore di 20 o e' presente un valore minore di -20 in ciascuna.\n");
            }
            else if (res == 2)
            {
                printf("\nNon sono stati introdotti abbastanza numeri.\n");
            }
            else
            {
                printf("\nNon ogni tripla e' maggiore di 20, e non e' presente un valore minore di -20.\n");
            }
        }
    }
}