#include <stdio.h>

class A
{
    public:
    A() {
        printf("Constructor A() called.\n");
    }
    ~A() {
        printf("Destructor ~A() called.\n");
    }
    void foo() {
        printf("foo()\n");
    }
private:
    char daten[100 * 1024 * 1024];
};

int main()
{
    // 1. Generate dynamically an array of N=5 instances of class A
    const int N = 5;
    A* myArray = new A[N];
    printf("I have generated %d instances of class A.\n", N);

    // 2. Do something with the instances
    for (int i = 0; i < N; i++)
    {
        myArray[i].foo();
    }
  
    delete[] myArray;
    //delete myArray;
    
}

