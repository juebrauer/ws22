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
    printf("2) Subtrahieren\n");
    printf("3) Multiplizieren\n");
    printf("4) Dividieren\n");

    int op;
    scanf("%d", &op);

    float res;
    /*
    if (op==1)
        res = z1+z2;
    else if (op==2)
        res = z1-z2;
    else if (op==3)
        res = z1*z2;
    else if (op==4)
        res = z1/z2;
    */
    switch (op)
    {
        case 1: res=z1+z2;
                printf("Ich addiere\n");
        case 2: res=z1-z2;
                printf("Ich subtrahiere\n");
        case 3: res=z1*z2;
                printf("Ich multipliziere\n");
        case 4: res=z1/z2;
                printf("Ich dividiere\n");
    }

    printf("Das Ergebnis ist: %f\n", res);

}