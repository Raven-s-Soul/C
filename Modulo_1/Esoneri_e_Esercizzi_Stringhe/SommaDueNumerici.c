#include <stdio.h>
#include <string.h>

/*
Una funzione sommaDueNumerici riceve come parametro una stringa e la modifica
rimpiazzando ogni sequenza (massimale) di esattamente due caratteri numerici adiacenti nella stringa
con la somma dei numeri corrispondenti ai caratteri. Ad esempio, se la stringa ricevuta come
parametro è "xx13xxx74xx784xx00xx6xx", la stringa deve essere modificata in
"xx4xxx11xx784xx0xx6xx", in quanto 1+3=4, 7+4=11 e 0+0=0.
*/
void sommaDueNumerici(char *s)
{
    //! Debug purpuse
    // char s2[50] = "xx13xxx74xx784xx00xx6xx";
    //  strcpy(s, s2);
    //   end Debug
    int buffer;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (((s[i] >= '0' && s[i] <= '9') && (s[i + 1] >= '0' && s[i + 1] <= '9')) && !(s[i + 2] >= '0' && s[i + 2] <= '9') && !(s[i - 1] >= '0' && s[i - 1] <= '9'))
        {
            // printf("To Edit %c -\n", s[i]);
            buffer = s[i] - '0' + s[i + 1] - '0';
            if (buffer >= 10)
            {

                s[i] = '1';
                s[i + 1] = buffer + '0' - 10;
            }

            else
            {
                s[i] = buffer + '0';
                for (int j = i + 1; s[j] != '\0'; j++)
                {
                    s[j] = s[j + 1];
                }
            }
        }
    }
}

/*
Una funzione testSommaDueNumerici verifica la correttezza della funzione sommaDueNumerici.
La funzione di test deve realizzare un test a scatola nera. Ciascuno degli insiemi di dati di ingresso
usato per il test deve essere commentato nel codice con un’indicazione dell’insieme di equivalenza
corrispondente. Ad esempio:
// stringa vuota
char stringa1[] = “”;
sommaDueNumerici(stringa1);
printf(“Test sommaDueNumerici (\“\”): Atteso = \“\”, Calcolato = \”%s\” \n”, stringa1
*/
void testSommaDueNumerici()
{
    char stringa1[] = "xx13xxx74xx784xx00xx6xx";
    sommaDueNumerici(stringa1);
    printf("Test sommaDueNumerici(\"xx13xxx74xx784xx00xx6xx\"): Atteso = \"xx4xxx11xx784xx0xx6xx\", Calcolato = \"%s\" \n", stringa1);
}

/*
Una funzione main chiede all'utente di inserire una stringa da tastiera ed utilizzando la funzione
fgets memorizza la stringa introdotta dall'utente all'interno di un array di 50 caratteri. Dopo aver
rimosso il carattere '\n' dalla stringa, la funzione main invoca la funzione sommaDueNumerici
fornendole come parametro la stringa letta; la funzione main stampa quindi la stringa modificata. La
funzione main termina invocando la funzione di test.
*/
int main()
{
    char s[50];
    printf("Damme na stringa: ");
    fgets(s, 50, stdin);
    s[strlen(s) - 1] = '\0';
    sommaDueNumerici(s);
    printf("Stringa modificata: %s\n", s);
    testSommaDueNumerici();
}