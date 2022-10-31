#include <stdio.h>

int main()
{
    float f=1.0;
    for (int i=1; i<=50; i++)
    {
        f = f/10.0;
        printf("i=%02d --> f=%.70f\n", i, f);
    }

}