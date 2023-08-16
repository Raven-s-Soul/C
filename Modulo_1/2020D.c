/*
 * SPECIFICA
 * Input: sequenza di numeri interi
 * Pre-condizione: almeno 3 numeri in input
 * Output: 1 vero 0 falso
 * Post-condizione: e'vero se la somma fra il primo e il secondo elemento è equivalente al terzo elemento meno il secondo,altrimenti falso.
 * TIPO DI PROBLEMA:  verifica universale
 */

#include <stdio.h>

int verificaSuccessione(int *a, int l);

int main()
{
    int l;
    printf("Quanti numeri prendere in input? ");
    scanf("%d", &l);
    int a[l];
    for (int i = 0; i < l; i++)
    {
        printf("Numero %d :", i + 1);
        scanf("%d", &a[i]);
    }
    int risultato = verificaSuccessione(a, l);
    printf("%d", risultato);
}

int verificaSuccessione(int *a, int l)
{
    int risultato = 1;
    for (int i = 0; i < l - 2; i++)
    {
        if (!((a[i] + a[i + 1]) == (a[i + 2] - a[i + 1])))
            risultato = 0;
    }
    return risultato;
}