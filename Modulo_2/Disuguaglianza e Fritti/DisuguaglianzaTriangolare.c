#include <stdio.h>
#include <stdlib.h>

/*
?   L’applicazione contiene una funzione ricorsiva disuguaglianzaTriangolare che verifica, all’interno di un array di interi ricevuto come parametro,
?   se esiste una terna di interi consecutivi nella sequenza che soddisfa la disuguaglianza triangolare (ovvero ciascuno dei tre interi è strettamente
?   minore della somma degli altri due). Ad esempio, se l’array è [2, 4, 10, 7, 1], la funzione deve restituire 1, in quanto la tripla [4, 10, 7] è tale
?   che 4<10+7, 10<4+7 e 7<4+10. Se l’array è [1, 3, 1], la funzione deve restituire 0, poiché nell’unica tripla [1, 3, 1] non è vero che 3<1+1. Notare
?   che non si richiede che i tre interi della tripla cercata siano positivi.
*/
/*
?   La funzione disuguaglianzaTriangolare ha due parametri: l’array e la sua lunghezza. Nel caso in cui si desideri utilizzare un terzo parametro per realizzare
?   la ricorsione, deve essere definita un’ulteriore funzione disuguaglianzaTriangolareRic che ha tre parametri e che realizza la ricorsione. In tal caso la funzione
?   disuguaglianzaTriangolare invoca la funzione disuguaglianzaTriangolareRic (fornendole opportuni parametri) per calcolare il risultato.
*/

int disuguaglianzaTriangolare(int array[], int len)
{
    // debug-Only
    // for (int i = 0; i < len; i++)
    // {
    //     printf("\n%d", array[i]);
    // }

    int value = 0;
    if (len < 3)
    {
        // printf("\nExit ricorsione\n");
        value = 0;
    }
    else
    {
        if ((array[0] < (array[1] + array[2])) && (array[1] < (array[0] + array[2])) && (array[2] < (array[0] + array[1])))
        {
            // printf("\nfound");
            return 1;
        }
        else
        {
            // printf("iterazione\n");
            value = disuguaglianzaTriangolare(array + 1, len - 1);
        }
    }
    return value;
}

/*
?   L’applicazione contiene una funzione scriviNumeri che scrive i valori di un array di interi su di un file. La funzione riceve come parametro l’array, la sua lunghezza
?   ed un ulteriore intero di controllo. Il file si deve chiamare interi.dat (nel caso sia binario) oppure interi.txt (nel caso in cui sia testuale). La scelta se utilizzare
?   un file binario oppure un file di testo è lasciata allo studente.

?   L’applicazione contiene una funzione quantiNumeri che determina quanti numeri interi sono memorizzati su un file dal nome interi.dat (nel caso in cui si utilizzi un file binario)
?   oppure interi.txt (nel caso in cui si utilizzi un file testuale).

?   L’applicazione contiene una funzione leggiNumeri che legge una sequenza di interi da un file dal nome interi.dat (nel caso in cui si utilizzi un file binario) oppure interi.txt
?   (nel caso in cui si utilizzi un file testuale) e li memorizza su un array che è ricevuto come parametro

?   Una funzione main che è già stata implementata in un file ricorsione.c (ad eccezione dei messaggi finali per l’utente) il cui codice può essere scaricato e copiato da moodle
?   (il file contiene anche le intestazioni delle altre funzioni). La funzione chiede all’utente se vuole inserire una sequenza di interi, oppure leggere la sequenza e l’intero
?   di controllo che sono memorizzati sul file. Dopo aver memorizzato tale sequenza in un array, viene stampato un messaggio che indica se esiste una terna di interi consecutivi
?   nella sequenza che soddisfa la disuguaglianza triangolare. La funzione termina salvando il contenuto dell’array su di un file.
*/

int quantiNumeri()
{
    char *filename = "interi.dat";
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        printf("Recupero sequenza non riuscito!");
    }
    int len = 0;
    int buffer;
    while (fread(&buffer, sizeof(int), 1, fp) > 0)
    {
        len++;
    }
    fclose(fp);
    return len;
}

void scriviNumeri(int *array, int len)
{
    char *filename = "interi.dat";
    // remember to swap for binary or not
    FILE *fp = fopen(filename, "wb+");

    if (fp == NULL)
    {
        printf("\nFile opening failed");
    }
    else
    {
        //! txt
        // for (int i = 0; i < len; i++)
        // {
        //     fprintf(fp, "%d ", array[i]);
        //     printf("%d ", array[i]);
        // }
        //! binary
        size_t status = fwrite(array, sizeof(array[0]), len, fp);
        if (status)
        {
            printf("\nScrittura Riuscita");
        }
    }
    fclose(fp);
    // remove(filename);
}

void leggiNumeri(int *array)
{
    char *filename = "interi.dat";
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        printf("Recupero sequenza non riuscito!");
    }
    else
    {
        int len = quantiNumeri();
        fread(array, sizeof(int), len, fp);
        printf("Lettura Effettuata\n");
    }

    fclose(fp);
}

int main()
{
    int len = quantiNumeri();
    int *array = malloc(sizeof(int) * len);
    leggiNumeri(array);

    for (int i = 0; i < len; i++)
    {
        printf("\nl'elemento %d: %d ", i + 1, array[i]);
    }

    int scelta = -1;
    printf("\nReset array? 1-Yes 0-No ");
    scanf("%d", &scelta);
    if (scelta == 1)
    {
        printf("Nuova lunghezza Array: ");
        scanf("%d", &len);
        if (!realloc(array, len))
        {
            printf("Errore realloc");
        }

        for (int i = 0; i < len; i++)
        {
            printf("\nInserisci l'elemento %d: ", i + 1);
            scanf("%d", &array[i]);
        }
    }

    int res = disuguaglianzaTriangolare(array, len);
    printf("\nIstanza = %d\n", res);

    scriviNumeri(array, len);
}