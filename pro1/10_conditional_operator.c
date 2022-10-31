#include <stdio.h>

int main()
{

    float z1, z2;
    
    printf("Zahl 1: ");
    scanf("%f", &z1);

    printf("Zahl 2: ");
    scanf("%f", &z2);

    printf("Was willst du mit den Zahlen machen?\n");
    printf("1) Addieren\n");
    printf("sonst) Subtrahieren\n");

    int op;
    scanf("%d", &op);

    float res;

    // conditional operator
    res = (op==1) ? z1+z2 : z1-z2;
    //(op==1) && (res=z1+z2);
    //(op!=1) && (res=z1-z2);
    /* 
    if (op==1)
        res = z1+z2;
    else
        res = z1-z2;
    */    
    printf("Das Ergebnis ist: %f\n", res);

}
