#include <cstdio>
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
 int priority[1000];
 int count;
 MaxPriorityQueue(){
  n=1;
  count=1;
 }
 MaxPriorityQueue(int a){
  priority[0]=1000000;
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
       count=count-1;
       priority[1]=priority[count];
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
 
void change(int k,int newk){
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

void heapifyup(int k){
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
void heapifydown(int k){
    int j, v;
    v = priority[k];
    //cout<<"Value to be replaced"<<v<<"index"<<k<<"with count"<<count<<"\n";
    while (k <= (count-1)/2)
    {
        j = k+k;
        if (j < (count-1) && priority[j] < priority[j+1]) j++;
        if (v >= priority[j]) break;
        int temp =priority[k]; 
        priority[k] = priority[j];
        priority[j] = temp;
        //priority[k] = priority[j]; 
        k = j;
    }
    //priority[k] = v;
 }
/*
void heapifydown(int in)
{
 
    int child = 2*in;
    int child1 = 2*in+1;
    if (child >= 0 && child1 >= 0 && priority[child] > priority[child1])
    {
       child = child1;
    }
    if (child > 0 && priority[in] > priority[child])
    {
        int temp = priority[in];
        priority[in] = priority[child];
        priority[child] = temp;
        heapifydown(child);
    }
}
*/
};
int main(int argc, char** argv) {
 /* MaxPriorityQueue a(4);
  //cout<<"Call Insert\n";
  a.insert(4065);
  a.insert(3047);
  a.change(4065,4358);
  a.change(4358,3562);
  a.change(3562,4654);
  a.change(4654,2955);
  a.change(3047,1123);
  a.insert(95);
  int h=a.removeMax();
  a.change(1123,4791);
  a.change(4791,2971);
  a.change(2971,4847);
  a.change(4847,869);
  a.change(869,3551);
  a.change(3551,1018);
  a.insert(1317);
  a.insert(2188);
  a.change(1018,1142);
  a.removeMax();
  a.change(1142,4824);
  for(int i=1;i<a.count;i++){
    cout<<a.priority[i]<<"\t";
  }
  cout<<"\n";*/
  //a.removeKey(2);
  //a.change(9,1);
  //a.removeMax();
  /*for(int i=1;i<a.count;i++){
    cout<<a.priority[i];
  }*/


  
    if (argc != 2) {
        printf("Usage: %s inputFile\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get samples
    string inputFilename(argv[1]);
    ifstream inputFile;
    inputFile.open(inputFilename.c_str());
    nlohmann::json samples;
    if (inputFile.is_open()) {
        inputFile >> samples;
    } else {
        printf("Unable to open file %s\n", inputFilename.c_str());
        return EXIT_FAILURE;
    }

    int n = samples["metadata"]["maxHeapSize"];
    MaxPriorityQueue a(n);
    //cout<<"The capacity of priority Queue\t"<<a.n<<"\n";
    nlohmann::json result;
    result["metadata"]["maxHeapSize"] = samples["metadata"]["maxHeapSize"];
    result["metadata"]["max_size"] = samples["metadata"]["maxHeapSize"];
    result["metadata"]["numOperations"] = samples["metadata"]["numOperations"];
    int countt=0;
    for (auto itr = samples.begin(); itr != samples.end(); ++itr) {
        if (itr.key() != "metadata") {
            auto sample = itr.value();
            string str = sample["operation"];
            //cout<<str<<"\n";
            if(str.compare("insert") == 0)
            {
               int t = sample["key"];
               //cout<< "The value to be inserting is"<<t<<"\n";
               a.insert(t);
               //continue;
            }
            else if(str.compare("removeMax") == 0)
            {
              int k = a.removeMax();
              //cout<< "The value deleted is"<<k<<"Count Value is"<<a.count<<"\n";
              //continue;
            }
            else if(str.compare("change") == 0)
            {
              int key = sample["key"];
              int newkey = sample["newKey"];
            //  cout<< "The value to be changed is"<<key<<"Updated Value"<<newkey<<"\n";
              a.change(key,newkey);
              //continue;              
            }
            else if(str.compare("removeKey") == 0){
              int key =sample["key"]; 
              //cout<<"The key to be removed is"<<key<<"\n";
              a.removeKey(key);
              //continue;     
            }
           /*for(int i=1;i<a.count;i++){
             cout<<a.priority[i]<<" ";
           }*/
           //cout<<"\n";
          //countt++;
         // cout<<" This is C "<<countt<<"\n";
        }
    }
   result["metadata"]["size"]=a.count-1;
   for(int i=1;i<a.count;i++){
     //cout<<a.priority[i]<<"\t";
     string s = to_string(i);
     result[s]["key"]=a.priority[i];
     if((2*i)<a.count){
      result[s]["leftChild"]= to_string(2*i);
     }
     if((i/2) >= 1){
      result[s]["parent"]= to_string(i/2);
     }
     if((2*i+1)<a.count){
      result[s]["rightChild"]= to_string(2*i+1);
    }
  }
  cout<<result.dump(2);
}
