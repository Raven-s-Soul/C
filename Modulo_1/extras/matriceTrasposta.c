/*Realizzare un programma che legge una matrice M di interi introdotta dall'utente
(prima di leggere gli elementi di tale matrice chiede all'utente il numero di righe ed il numero di colonne della matrice).
Il programma crea quindi larghezza matrice trasposta M^T della matrice M, ovvero larghezza matrice ottenuta da M scambiando le righe con le colonne.
Il programma stampa quindi larghezza matrice M^T e stampa inoltre un messaggio che indica se larghezza matrice M è simmetrica (ovvero se è uguale alla sua matrice trasposta).

Oltre alla funzione main, si possono definire a piacimento funzioni, ad esempio per il calcolo della matrice trasposta,
per larghezza stampa di una matrice, per larghezza verifica se due matrici sono uguali...*/

#include <stdio.h>

void printMatrix(int *matrix, int lunghezza, int larghezza);
void traspostaMatrix(int *matrix, int *trasposta, int lunghezza, int larghezza);
void makeBuffer(int *buffer, int *matrix, int lunghezza, int larghezza);

int main()
{
    int lunghezza, larghezza;
    // pre-input
    printf("Dimmi larghezza lunghezza e larghezza larghezza (3 3) ");
    scanf("%d %d", &lunghezza, &larghezza);
    int array[lunghezza][larghezza];
    int trasposta[larghezza][lunghezza];

    // input
    for (int i = 0; i < lunghezza; i++)
    {
        for (int j = 0; j < larghezza; j++)
        {
            printf("%d riga e %d colonna: ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
    // Main Funcitions
    printMatrix(array, lunghezza, larghezza);
    traspostaMatrix(array, trasposta, lunghezza, larghezza);
}

void printMatrix(int *matrix, int lunghezza, int larghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        for (int j = 0; j < larghezza; j++)
        {
            printf("%d ", matrix[i * larghezza + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void traspostaMatrix(int *matrix, int *trasposta, int lunghezza, int larghezza)
{
    int bufferSize = lunghezza * larghezza;
    int buffer[bufferSize];
    makeBuffer(buffer, matrix, lunghezza, larghezza);

    // drift from buffer to trasposta
    int k = 0;
    for (int i = 0; i < larghezza; i++)
    {
        for (int j = 0; j < lunghezza; j++)
        {
            trasposta[i * lunghezza + j] = buffer[k];
            k++;
        }
    }
    printMatrix(trasposta, larghezza, lunghezza);

    // Contollo
    if (larghezza == lunghezza)
    {
        int bufferT[bufferSize];
        int simmetrica = 1;
        makeBuffer(bufferT, trasposta, larghezza, lunghezza);
        int max = lunghezza * larghezza;

        for (int i = 0; i < max; i++)
        {
            // printf("%d ", buffer[i]);
            // printf("%d ", bufferT[i]);
            if (!(buffer[i] == bufferT[i]))
                simmetrica = 0;
        }
        if (simmetrica)
            printf("Simmetrica");
    }
}

void makeBuffer(int *customBuffer, int *matrix, int lunghezza, int larghezza)
{
    int bufferSize = lunghezza * larghezza;
    customBuffer[bufferSize];
    int k = 0;
    for (int j = 0; j < larghezza; j++)
    {
        for (int i = 0; i < lunghezza; i++)
        {
            customBuffer[k] = matrix[i * larghezza + j];
            // !Debug use
            // printf("%d - %d\n", customBuffer[k], k);
            k++;
        }
    }
}