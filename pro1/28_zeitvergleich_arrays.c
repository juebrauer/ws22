#include <stdio.h>
#include <stdlib.h> // malloc & friends

typedef unsigned int uint;

#define NR_ACCESSES 100000
#define dimX 100
#define dimY 100

#include <time.h>


void exp_arrays_von_pointern()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int** myArray2D = malloc(dimY * sizeof(int*));
    for (uint y = 0; y < dimY; y++)
        myArray2D[y] = malloc(dimX * sizeof(int));

    for (int accnr=0; accnr<NR_ACCESSES; accnr++)
    {
        int counter = 0;
        for (uint y = 0; y < dimY; y++)
            for (uint x = 0; x < dimX; x++)
                myArray2D[y][x] = counter++;
    }

    for (uint y = 0; y < dimY; y++)
        free (myArray2D[y]);
    free(myArray2D);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu_time_used (Array von Pointern)=%f\n", cpu_time_used);

}



void exp_ein_grosser_speicherblock()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int* myArray2D = malloc(dimX*dimY*sizeof(int));

    for (int accnr=0; accnr<NR_ACCESSES; accnr++)
    {
        int counter = 0;
        for (uint y = 0; y < dimY; y++)
            for (uint x = 0; x < dimX; x++)
                myArray2D[ y*dimX+x ] = counter++;
    }

    free(myArray2D);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu_time_used (ein Speicherblock)=%f\n", cpu_time_used);

}

int main() {

    exp_arrays_von_pointern();

    exp_ein_grosser_speicherblock();

   

}