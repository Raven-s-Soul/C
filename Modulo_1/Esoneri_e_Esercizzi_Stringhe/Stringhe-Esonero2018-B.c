#include <stdio.h>
#include <string.h>
/*
(6 pt) Una funzione sommaNumeri riceve come parametro una stringa e la modifica così che nella
stringa compaiano solo i numeri (ovvero le sequenze massimali di caratteri numerici) della stringa
parametro, dove ogni due numeri consecutivi sono separati da un ‘+’. Il primo e l’ultimo carattere
della stringa devono quindi essere numerici, ammesso che la stringa parametro contenga dei
caratteri numerici. Ad esempio, se la stringa parametro è "abc123d/ 45a!! 36 ", allora la stringa deve
essere modificata in "123+45+36".*/
void sommaNumeri(char *s)
{
    char s2[50];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            s2[j] = s[i];
            if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
            {
                s2[j + 1] = '+';
                j++;
            }
            j++;
        }
    }
    s2[j - 1] = '\0';
    s2[j] = '\0';
    strcpy(s, s2);
}

/*
(3 pt) Una funzione testSommaNumeri verifica la correttezza della funzione sommaNumeri. La funzione
di test deve realizzare un test a scatola nera. Ciascuno degli insiemi di dati di ingresso usato per il test
deve essere commentato nel codice con un’indicazione dell’insieme di equivalenza corrispondente.
Ad esempio:
// stringa vuota
char stringa1[] = “”;
sommaNumeri(stringa1);
printf(“Test sommaNumeri(\“\”): Atteso = \“ \”, Calcolato = \”%s\” \n”, stringa1);*/
void testSommaNumeri()
{
    char stringa1[] = "abc123d/ 45a!! 36 ";
    sommaNumeri(stringa1);
    printf("Test sommaNumeri(\"abc123d/ 45a!! 36 \"): Atteso = \"123+45+36\", Calcolato = \"%s\" \n", stringa1);
}
/*
(2 pt) Una funzione main chiede all'utente di inserire una stringa da tastiera ed utilizzando la funzione
fgets memorizza la stringa introdotta dall'utente all'interno di un array di 50 caratteri. Dopo aver
rimosso il carattere '\n' dalla stringa, la funzione main invoca la funzione sommaNumeri fornendole
come parametro la stringa letta; la funzione main stampa quindi la stringa modificata. La funzione
main termina invocando la funzione di test.
*/
int main()
{
    char s[50];
    printf("Damme na stringa: ");
    fgets(s, 50, stdin);
    s[strlen(s) - 1] = '\0';
    sommaNumeri(s);
    printf("Stringa modificata: %s\n", s);
    testSommaNumeri();
}