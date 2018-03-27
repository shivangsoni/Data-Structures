// Quicksort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks
#include "quicksort.h"
int Partition(int numbers[], int i, int k, int& count,int &memaccess) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint]; memaccess++;
   
   l = i;
   h = k;
   while (!done) {
      /* Increment l while numbers[l] < pivot */
      memaccess=memaccess+1;
      count++;
      while (numbers[l] < pivot) {
         ++l; count++;
         memaccess=memaccess+1;
      }
      
      /* Decrement h while pivot < numbers[h]*/
      count++;
      memaccess=memaccess+1;
      while (pivot < numbers[h]) {
         --h; count++;
           memaccess=memaccess+1;
      }
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */ 
        //count++;
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         memaccess=memaccess+4;
         ++l;
         --h;
      }
   }
   
   return h;
}

void Quicksort(int numbers[], int i, int k, int& count,int &memaccess) {
 int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(numbers, i, k, count, memaccess);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   Quicksort(numbers, i, j, count, memaccess);
   Quicksort(numbers, j + 1, k, count, memaccess);
   
   return;
}

