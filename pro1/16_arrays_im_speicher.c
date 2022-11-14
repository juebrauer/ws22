#include <stdio.h>

int main()
{
    char A[5];
    A[0] = 0;
    A[1] = 111;
    A[2] = 2;
    A[3] = 3;
    A[4] = 4;

    for (int i=0; i<5; i++)
        printf("A[%d]=%03d - address: %p\n", i, A[i], &(A[i]));

}