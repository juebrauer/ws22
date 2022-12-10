#include <stdio.h>

int main()
{
   int a,b;
   a = 2;
   b = 3;
   a = b = 5; // a=3   or   a=5 ?
   printf("a=%d\n", a);
   printf("b=%d\n", b);
}