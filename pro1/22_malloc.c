#include <stdio.h>
#include <stdlib.h> // malloc & friends
#include <string.h>

#define N 100*1024*1024

int main() {

   char c;
   printf("Step 1: press a key to allocate %d chars\n", N);
   scanf("%c", &c);
       
   char* A = malloc(N * sizeof(char));
   memset(A, 0, N);   

   printf("Step 2: press a key to resize to %d chars\n", N/2);
   scanf("%c", &c);
 
   A = realloc(A, N/2 * sizeof(char));

   printf("Step 3: press a key to free the memory\n");
   scanf("%c", &c);
 
   free (A);
   
   printf("Finished!\n");

}