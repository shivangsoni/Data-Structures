#include "priorityqueue.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
MaxPriorityQueue::MaxPriorityQueue(){
  n=1;
  count=1;
 }

MaxPriorityQueue::MaxPriorityQueue(int a){
  priority[0]=1000000;
  n=a;
  count=1;
 }

void MaxPriorityQueue::insert(int k){
    if(count == n+1){
     cout<<"Priority Queue is full cannot insert\n";
     exit(0);
    }
    else{
      //cout<<"Inside insert";
      priority[count] = k;
      heapifyup(count);
      count++;
    }
 }

int MaxPriorityQueue::removeMax(){
    if(count == 1){
     cout<<"Priority Queue is empty cannot delete\n";
     exit(0);     
    }
   else{
       int v = priority[1];
       count=count-1;
       priority[1]=priority[count];
       heapifydown(1);
       return v;
    }
}

int MaxPriorityQueue::removeKey(int k){
  int index = 0;
  for(int i=1;i<count;i++){
    if(k == priority[i]){
     index = i;
    }
  }
  if(index == 0)
  {
     cout<<"Key to be deleted does not exist in Priority Queue"<<k<<"\n";
     exit(0); 
  }
  int v = priority[index];
  priority[index] = priority[--count];
  if(priority[index] < v)
    heapifydown(index);
  else
    heapifyup(index);
  return v;
 }
 
 void MaxPriorityQueue::change(int k,int newk){
   int index=0;
   for(int i=1;i<count;i++){
    if(priority[i] == k){
       index = i;
    }
   }
  if(index == 0){
    cout<<"Key to be changed"<<k<<" does not exist in Priority Queue\n";
     /*for(int i=0;i<count;i++){
         cout<<priority[i]<<"\t";
     }*/
     exit(0);    
  }
  priority[index] = newk;
  //cout<<"This is the new key"<<newk<<"Key to replace is"<<k<<"The key found at index"<<index<<"\n";
   if(newk < k){
      heapifydown(index);
    }
  else{
      heapifyup(index);
     }
 }

void MaxPriorityQueue::heapifyup(int k){
    int v;
    v = priority[k];
    //if(k>=2){  
    while (priority[k/2] < v)
    {   int temp; 
        temp =priority[k];
        priority[k] = priority[k/2];
        priority[k/2] = temp;
        //cout<<"Priority of k "<<priority[k]<<"\t V value"<<v<<"\n";
        k = k/2;
      //if(k<2){break;}
    }
   //}
    //priority[k] = v;
 }
void MaxPriorityQueue::heapifydown(int k){
    int j, v;
    v = priority[k];
    //cout<<"Value to be replaced"<<v<<"index"<<k<<"with count"<<count<<"\n";
    while (k <= (count-1)/2)
    {
        j = k+k;
        if (j < (count-1) && priority[j] < priority[j+1]) j++;
        if (v >= priority[j]) break;
        int temp = priority[k]; 
        priority[k] = priority[j];
        priority[j] = temp;
        //priority[k] = priority[j]; 
        k = j;
    }
    //priority[k] = v;
 }


void MaxPriorityQueue::heapifydown1(int* p,int n,int k){
    int j, v;
    v = *(p+k);
    while (k <= n/2)
    {
        j = k+k;
        if (j < n && *(p+j) < *(p+(j+1))) j++;
        if (v >= *(p+j)) break;
        *(p+k) = *(p+j); k = j;
    }
    *(p+k) = v;
}
void MaxPriorityQueue::heapsort(int priorityArray[],int n){
   int sortedArray[n+1];
   int k=1;
   for(int i=1;i<=n;i++){
     sortedArray[k++]=priorityArray[1];
     priorityArray[1]=priorityArray[n];
     heapifydown1(priorityArray,n,1);
     i=1;
     n--;
   }
 //cout<<"The sorted array is\n";
 for(int i=1;i<k;i++){
   //cout<<sortedArray[k-i]<<"\t";
   p[i]=sortedArray[k-i];
 }
}
