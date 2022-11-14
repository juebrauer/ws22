#include <stdio.h>

//void foo(int arr[])
void foo(int* arr)
{
    arr[0] = 42;

    // arr[1] = 43;
    *(arr+1) = 43; // Pointer Arithmetik
}


int main()
{
    int A[5];
    A[0] = 0;
    A[1] = 1;
    A[2] = 2;
    A[3] = 3;
    A[4] = 4;

    foo(A); // call by value oder call by reference?

    for (int i=0; i<5; i++)
        printf("A[%d]=%d\n", i, A[i]);

}