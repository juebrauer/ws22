#include <stdio.h>

int main()
{
    float f = 123.456;


    for (int i=1; i<=3; i++)
    {
        float* ptr_f = &f;
        printf("f=%f\n", f);
        printf("size of a float=%ld\n", sizeof(float) );
        printf("size of a float*=%ld\n", sizeof(float*) );
        printf("ptr_f = %p\n", ptr_f);
    }
}