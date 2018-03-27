// Merge Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "mergesort.h"
void Merge(int numbers[], int i, int j, int k, int& count, int& memaccess) {
   int mergedSize = k - i + 1;                // Size of merged partition
   int mergePos = 0;                          // Position to insert merged number
   int leftPos = 0;                           // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
                                                    // for merged numbers
   
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
       count++;
       memaccess +=2;
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
         memaccess=memaccess+2;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         memaccess=memaccess+2;
      }
      ++mergePos;
     
   }
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      
      mergedNumbers[mergePos] = numbers[leftPos];
      memaccess=memaccess+2;
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      
      memaccess=memaccess+2;
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
      memaccess+=2;
   }
}

void MergeSort(int numbers[], int i, int k, int& count, int& memaccess) {
   int j = 0;  
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j, count,memaccess);
      MergeSort(numbers, j + 1, k, count, memaccess);
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k,count,memaccess);
   }
}
