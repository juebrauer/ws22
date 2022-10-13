#include <stdio.h>

int main()
{ 
    int z;
    for (z=1; z<=10; z=z+1)
    {
        printf("Zahl %d quadriert = %d\n", z, z*z);
    }
    printf("z nach Schleifenabbruch: %d\n", z);

    int y;
    y=1;
    while (y<=10)
    {
        printf("Zahl %d quadriert = %d\n", y, y*y);
        y=y+1;
    }

    int x;
    x=1;
    do
    {
         printf("Zahl %d quadriert = %d\n", x, x*x);
         x=x+1;
    } while (x<=10);
    


}