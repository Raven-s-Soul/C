#include <stdio.h>
#include <unistd.h>

void function()
{
    printf("Hello\n");
    sleep(1);
    function();
}

int main()
{
    function();
}