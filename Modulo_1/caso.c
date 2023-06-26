#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string()
{
    char *buffer = (char *)malloc(100 * sizeof(char)); // allocazione dinamica del buffer di 100 caratteri
    if (buffer == NULL)
    {
        fprintf(stderr, "Errore: Impossibile allocare il buffer di memoria.\n");
        exit(1);
    }

    printf("Inserisci una stringa: ");
    // legge una stringa di massimo 99 caratteri dall'input utente
    scanf("%99s", buffer);

    // calcola la lunghezza della stringa letta
    int len = strlen(buffer);
    // allocazione dinamica dell'array di caratteri
    char *str_array = (char *)malloc((len + 1) * sizeof(char));

    // Copia i caratteri dal buffer alla memoria allocata per l'array di caratteri
    strncpy(str_array, buffer, len);

    // libera il buffer di memoria allocato con malloc
    free(buffer);
    // aggiunge il carattere di terminazione della stringa
    str_array[len] = '\0';
    // restituisce l'array di caratteri
    return str_array;
}

int main()
{
    char *str = read_string(); // richiama la funzione per leggere una stringa
    printf("La stringa letta e': %s\n", str);

    free(str); // libera la memoria allocata per l'array di caratteri

    return 0;
}
