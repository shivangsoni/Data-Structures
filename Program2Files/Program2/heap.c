/*
  heapSort example using priority queue from Sedgewick's Algorithms in C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numbers.h" // https://gist.github.com/911872

void insert(int);
int hremove(void);
void downheap(int);
void upheap(int);
void heapSort(struct numbers*); //heapsort conflicts with stdlib
int *heapArray;
int N=0;


int main()
{
    int i;
    struct numbers vals = generateRandoms(0, 300); // from https://gist.github.com/911872
    heapSort(&vals);
    // prove that it worked
    for (i=0; i<vals.size; i++)
        printf("%d ", vals.values[i]);
    printf("\n");
    return 0;
}

void insert(int item)
{
    heapArray[++N] = item;
    upheap(N);
}
// remove is in stdio.h
int hremove(void)
{
    int v = heapArray[1];
    heapArray[1] = heapArray[N--];
    downheap(1);
    return v;
}
void downheap(int k)
{
    int j, v;
    v = heapArray[k];
    while (k <= N/2)
    {
        j = k+k;
        if (j < N && heapArray[j] < heapArray[j+1]) j++;
        if (v >= heapArray[j]) break;
        heapArray[k] = heapArray[j]; k = j;
    }
    heapArray[k] = v;
}
void upheap(int k)
{
    int v;
    v = heapArray[k];
    while (heapArray[k/2] <= v)
    {
        heapArray[k] = heapArray[k/2];
        k = k/2;
    }
    heapArray[k] = v;
}

void heapSort(struct numbers *vals)
{
    // allocate a heapArray sufficient to hold all values plus sentinel
    heapArray = malloc(vals->size * sizeof(int) + 1);
    int max=0;
    int i=0;
    // find the largest value in vals->values and store it as a sentinel in heapArray[0]
    for (i = 0; i < vals->size; i++)
    {
        max = (vals->values[i] > max) ? vals->values[i] : max;
    }
    heapArray[0] = max+1;

    // this inserts the values, which places them into descending order in the heap
    for (i = 0; i < vals->size; i++)
    {
        insert(vals->values[i]);
    }
    // this removes the values from the heap from largest to smallest, they are stored
    // from the end of the array to the beginning to get the ascending array in order
    while (i--)
        vals->values[i] = hremove();

    free(heapArray);
}
