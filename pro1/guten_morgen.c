#include <stdio.h>

int main()
{
    int a = 42;    
    
    // True = 1
    // False = 0
    switch (a % 42 == 0)
    {
        case 0 : printf("A"); break;
        case 1 : switch (a == 2*22)
                 {
                    case 1: printf("B"); break;
                    case 0: printf("C"); break;                    
                 }
                 break;
    }


}