// Insertion Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"
/*
void InsertionSort(std::vector<int>* numbers) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < numbers->size(); ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp = (*numbers)[j];
         (*numbers)[j] = (*numbers)[j - 1];
         (*numbers)[j - 1] = temp;
         --j;
      }
   }
   
   return;
}*/
void InsertionSort(int numbers[], int numbersSize, int &count , int &memoryaccess) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   for (i = 1; i < numbersSize; ++i) {
      j = i;
      count++;
       memoryaccess +=2; 
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         count = count + 1;
         memoryaccess = memoryaccess +2;
         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
        memoryaccess = memoryaccess +4;
         --j;
      }
   }   
   return;
}
