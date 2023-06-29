#include <stdio.h>
#include <stdlib.h>

#define fname "interi.dat"

/* funzione ricorsiva che verifica ... */
int tuttiAlternati(int *seq, int lunghezza)
{
    int res = 1;
    if (lunghezza < 2)
    {
        res = 1;
    }
    else
    {
        if (!(((seq[0] * seq[1]) < 0) && tuttiAlternati(seq + 1, lunghezza - 1)))
            res = 0;
    }
    return res;
}

/* funzione che conta ... */
int quantiNumeri()
{
    FILE *fp = fopen(fname, "rb");
    int count = 0;
    if (!fp)
    {
        printf("\nErrore apertura file\n");
    }
    else
    {
        int buffer;
        while (fread(&buffer, sizeof(int), 1, fp) > 0)
        {
            count++;
        }
    }
    fclose(fp);
    // printf("count : %d\n", count);
    return count;
}

/* funzione che legge ... */
void leggiNumeri(int *sequenza, int lunghezza)
{
    FILE *fp = fopen(fname, "rb");
    if (fp == NULL)
    {
        printf("\nErrore scrittura file\n");
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
    if (fp == NULL)
    {
        printf("\nErrore scrittura file\n");
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

        /* invoca la funzione ricorsiva e stampa il risultato */
        if (tuttiAlternati(array, lunghezza))
            printf(" Positivo \n");
        else
            printf(" Negativo \n");

        /* salva la sequenza su file */
        scriviNumeri(array, lunghezza);
    }
    /* recupero sequenza da file */
    else
    {
        /* determina la lunghezza della sequenza */
        lunghezza = quantiNumeri();

        /* crea l'array e leggine i valori degli elementi da file */
        int array[lunghezza];
        leggiNumeri(array, lunghezza);
        printf("Ecco la sequenza recuperata\n");
        for (int i = 0; i < lunghezza; i++)
            printf("%d ", array[i]);
        printf("\n");

        /* invoca la funzione ricorsiva e stampa il risultato */
        if (tuttiAlternati(array, lunghezza))
            printf(" Positivo \n");
        else
            printf(" Negativo \n");

        /* salva la sequenza su file */
        scriviNumeri(array, lunghezza);
    }
}
