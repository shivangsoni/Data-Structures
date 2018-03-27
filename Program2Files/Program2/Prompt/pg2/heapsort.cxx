
#include <iostream>
#include <fstream>
#include <random>
#include <set>
#include <string>

#include "json.hpp"
using namespace std;
class MaxPriorityQueue
{
 public:
 int n;
 int priority[10000];
 int count;
 int p[1000000];
 MaxPriorityQueue(){
  n=1;
  count=1;
 }
 MaxPriorityQueue(int a){
  priority[0]=-1000000;
  n=a;
  count=1;
 }
 void insert(int k){
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
 int removeMax(){
    if(count == 1){
     cout<<"Priority Queue is empty cannot delete\n";
     exit(0);     
    }
   else{
       int v = priority[1];
       priority[1]=priority[--count];
       heapifydown(1);
       return v;
    }
 }
 int removeKey(int k){
  int index = 0;
  for(int i=1;i<count;i++){
    if(k == priority[i]){
     index = i;
    }
  }
  if(index == 0)
  {
     cout<<"Key to be deleted does not exist in Priority Queue\n";
     exit(0); 
  }
  int v = priority[index];
  priority[index] = priority[--count];
  heapifydown(index);
  return v;
 }
 
void change(int k,int newk){
   int index=0;
   for(int i=1;i<count;i++){
    if(priority[i] == k){
       index = i;
    }
   }
  if(index == 0){
     cout<<"Key to be changed does not exist in Priority Queue\n";
     exit(0);    
  }
  priority[index] = newk;
  if(newk <= k){
   heapifydown(index);
  }
  else{
   heapifyup(index);
  }
 }

void heapifyup(int k){
    int v;
    v = priority[k];
    if(k>=2){  
    while (priority[k/2] < v)
    {   int temp; 
        temp =priority[k];
        priority[k] = priority[k/2];
        priority[k/2] = temp;
        //cout<<"Priority of k "<<priority[k]<<"\t V value"<<v<<"\n";
        k = k/2;
      if(k<2){break;}
    }
   }
    priority[k] = v;
 }
void heapifydown(int k){
    int j, v;
    v = priority[k];
    while (k <= count/2)
    {
        j = k+k;
        if (j < count && priority[j] < priority[j+1]) j++;
        if (v >= priority[j]) break;
        priority[k] = priority[j]; k = j;
    }
    priority[k] = v;
 }
void heapifydown1(int* p,int n,int k){
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
void heapsort(int priorityArray[],int n){
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

};

int main(int argc, char** argv) {
 /* MaxPriorityQueue a(5);
  //cout<<"Call Insert\n";
  a.insert(4);
  a.insert(2);
  a.insert(9);
  a.insert(5);
  a.insert(7);
  for(int i=1;i<a.count;i++){
    cout<<a.priority[i];
  }
  cout<<"\n";
  //a.removeKey(2);
  //a.change(9,1);
  //a.removeMax();
  for(int i=1;i<a.count;i++){
    cout<<a.priority[i];
  }
  a.heapsort(a.priority,a.count);*/

    if (argc != 2) {
        printf("Usage: %s inputFile\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get samples
    std::string inputFilename(argv[1]);
    std::ifstream inputFile;
    inputFile.open(inputFilename.c_str());
    nlohmann::json samples;
    if (inputFile.is_open()) {
        inputFile >> samples;
    } else {
        printf("Unable to open file %s\n", inputFilename.c_str());
        return EXIT_FAILURE;
    }

    int n = samples["metadata"]["arraySize"];
    int* sampleData = (int*) malloc(sizeof(int) * n);
    nlohmann::json result;
    result["metadata"] = samples["metadata"];

    for (auto itr = samples.begin(); itr != samples.end(); ++itr) {
        if (itr.key() != "metadata") {
            auto sample = itr.value();
            // InsertionSort
           // cout<<sample<<"\n";
            std::copy(sample.begin(), sample.end(), sampleData);
            //shellSort(sampleData, n);
            int A[n];
            int i=0;
            for(auto itr1 = sample.begin();itr1!= sample.end();++itr1){
                A[i++]=itr1.value();
                //cout<<A[i-1];
            }
            MaxPriorityQueue B(n);
            for(int j=0;j<i;j++){
             B.insert(A[j]);
            }
            int q=1;
            B.heapsort(B.priority,B.count);
            for(auto itr1 = sample.begin();itr1!= sample.end();++itr1){
             itr1.value()=B.p[q++];
             //cout<<itr1.value()<<"\t";
             result[itr.key()].push_back(itr1.value());
            }
            //cout<<"\n";
            /*for (int i = 0; i < n; i++) {
                result[itr.key()].push_back(sampleData[i]);
            }*/
        }
    }
    std::cout << result << '\n';
}
