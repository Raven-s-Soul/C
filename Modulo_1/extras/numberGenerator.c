// per laura
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <string.h>

int main(void)
{
    int times, x, y, mod;
    srand(time(0));

    printf("How many ripetitions? ");
    scanf("%d", &times);
    printf("Generate numbers from 0 to ? ");
    scanf("%d", &mod);
    mod++;

    for (int i = 1; i < times + 1; i++)
    {

        x = rand() % mod;
        y = rand() % mod;

        printf("%d) %d + %d = %d\n", i, x, y, x + y);
    }
}