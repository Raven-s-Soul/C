/*
!Scrivi un programma che chiede all'utente di inserire quattro numeri interi, li legge e stampa uno dei seguenti messaggi:
!- "Ci sono esattamente 4 numeri fra loro uguali" (se i numeri sono ad esempio 1,1,1,1)
!- "Ci sono esattamente 3 numeri fra loro uguali" (se i numeri sono ad esempio 1,1,1,2)
!- "Ci sono esattamente 2 numeri fra loro uguali" (se i numeri sono ad esempio 1,1,2,3)
//!- "Ci sono due coppie di numeri fra loro uguali" (se i numeri sono ad esempio 1,1,2,2)
!- "Ci sono esattamente 0 numeri fra loro uguali" (se i numeri sono ad esempio 1,2,3,4)
? Parte NON ESSENZIALE, ma riservata solo agli studenti più curiosi. Come si risolve l'esercizio potendo utilizzare solamente
? istruzioni di stampa e lettura, l'operatore di assegnamento, operatori matematici (+, -, *, /), operatori di confronto (==, >, ...),
?ed UNA SOLA ISTRUZIONE IF-ELSE? Sono quindi vietate istruzioni ripetitive, istruzioni condizionali diverse da if-else, array, stringhe, operatori logici (||, &&, !) ...
//Se riesci a risolvere la parte non essenziale, invia la tua soluzione a @ Una soluzione verrà pubblicata online quando almeno uno studente avrà inviato una soluzione corretta.
*/
#include <stdio.h>
// #include <time.h>

int main()
{
    // clock_t lastTime, currentTime;

    float a, b, c, d;
    int var1, var2, var3, sum;

    printf("Dammi 4 numeri, capiro' se ci sono dei uguali ");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    // lastTime = clock();
    var1 = (a == b && c == d) || (a == c && b == d) || (a == d && c == b);
    var2 = (a == b && a == c && a == d);

    if (var1 == 1 && var2 == 0)
        printf("Sono presenti 2 coppie di numeri\n");
    else
    {
        sum = (a == b) + (a == c) + (a == d) + (b == c) + (b == d) + (c == d);
        var1 = a == b && a == c && a == d;
        var2 = (a == b) && (a != c && a != d) || (a == c) && (a != b && a != d) || (a == d) && (a != b && a != c) || (b == c) && (b != a && b != d) || (b == d) && (b != a && b != d) || (c == d) && (c != a && c != b);
        sum = (sum - (var1 * 2)) + var2;
        printf("%d uguali \n", sum);
    }
    /*
    currentTime = clock();
    double deltaTime = currentTime - lastTime;
    printf("%f time \n", deltaTime);
    */
}
