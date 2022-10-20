#include <stdio.h>

void swap_does_not_work(float z1, float z2)
{
    printf("z1=%f, z2=%f\n", z1,z2);
    float tmp = z2;
    z2 = z1;
    z1 = tmp;
    printf("z1=%f, z2=%f\n", z1,z2);
}

void swap_works(float* ptr_z1, float* ptr_z2)
{
    printf("z1=%f, z2=%f\n", *ptr_z1, *ptr_z2);
    float tmp = *ptr_z2;
    *ptr_z2 = *ptr_z1;
    *ptr_z1 = tmp;
    printf("z1=%f, z2=%f\n", *ptr_z1, *ptr_z2);
}


int main()
{
    float f1 = 10.0;
    float f2 = 20.0;

    printf("f1=%f, f2=%f\n", f1,f2);

    // Call-by-value
    swap_works(&f1,&f2);
    printf("f1=%f, f2=%f\n", f1,f2);


}