#include<iostream>
#include<fstream>
#include <cstdio>
#include <random>
#include <string>
#include "json.hpp"
#include <ctime>
#include "mergesort.h"
#include "quicksort.h"
#include "insertionsort.h"
using namespace std;
int main(int argc, char** argv) {
 int a[5]={1,3,2,5,4};
    ifstream file;
  file.open(argv[1]);
  nlohmann::json jsonObject;
  if(file.is_open()){
   file>>jsonObject;
  }

 // Quicksort(a,0,4);
 // InsertionSort(a,5);
 // MergeSort(a,0,4);e
 
/* cout<<"This is the wall clock time for merge sort\n";
int start_s=clock();
 MergeSort(a,0,4);
int stop_s=clock();
cout << "time: " << (stop_s-start_s) << endl; //Execution time in milliseconds. time=0.008
*/
/* QuickSort
int start_s=clock();
 Quicksort(a,0,4);
int stop_s=clock();
cout << "time: " << (stop_s-start_s) << endl;//Execution time in milliseconds. time=0.003
*/
//double time = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  int samplesize = jsonObject["metadata"]["numSamples"];
  int arraysize = jsonObject["metadata"]["arraySize"];
  string str = "Sample";

 int arraySampleSize[samplesize];
 int arrayS[arraysize];
 for(int i=0;i<samplesize;i++)
 {
    arraySampleSize[i]=0;
 }

////////////////////////////////////////////////////////////
////////////////////Insertion Sort//////////////////////////
////////////////////////////////////////////////////////////
for(int i=0;i<samplesize;i++)
 {
    if(samplesize >=10 && samplesize <100)
     {
       if((i+1)<10)
       {   string str3 = "0";  
           string str2 = to_string(i+1);
           str3.append(str2);
           str.append(str3);
       }
       else
       {
        string str2 = to_string(i+1);
        str.append(str2);
       }
     }
     else
     {
      string str2 = to_string(i+1);
      str.append(str2);
     }
    for(int j=0;j<arraysize;j++)
    {
       arrayS[j] =jsonObject[str][j];
    }
    
    int counttt=0;
    int co=0;
    InsertionSort(arrayS,arraysize,counttt,co);
    cout<<counttt<<"\t"<<co<<"\n";
    str="Sample";
 }
cout<<"\n";
/////////////////////////////////////////////////////////
///////////////////Quick Sort////////////////////////////
/////////////////////////////////////////////////////////
for(int i=0;i<samplesize;i++)
 {
    if(samplesize >=10 && samplesize <100)
     {
       if((i+1)<10)
       {   string str3 = "0";  
           string str2 = to_string(i+1);
           str3.append(str2);
           str.append(str3);
       }
       else
       {
        string str2 = to_string(i+1);
        str.append(str2);
       }
     }
     else
     {
      string str2 = to_string(i+1);
      str.append(str2);
     }
    for(int j=0;j<arraysize;j++)
    {
       arrayS[j] =jsonObject[str][j];
    }
    
    int counttt=0;
    int co=0;
    Quicksort(arrayS,0,arraysize-1,counttt,co);
    cout<<counttt<<"\t"<<co<<"\n";
    str="Sample";
 }
cout<<"\n";

/////////////////////////////////////////////////////////
////////////////////Merge Sort///////////////////////////
/////////////////////////////////////////////////////////
for(int i=0;i<samplesize;i++)
 {
    if(samplesize >=10 && samplesize <100)
     {
       if((i+1)<10)
       {   string str3 = "0";  
           string str2 = to_string(i+1);
           str3.append(str2);
           str.append(str3);
       }
       else
       {
        string str2 = to_string(i+1);
        str.append(str2);
       }
     }
     else
     {
      string str2 = to_string(i+1);
      str.append(str2);
     }
    for(int j=0;j<arraysize;j++)
    {
       arrayS[j] =jsonObject[str][j];
    }
    
    int counttt=0;
    int co=0;
    MergeSort(arrayS,0,arraysize-1,counttt,co);
    cout<<counttt<<"\t"<<co<<"\n";
    str="Sample";
 }
 cout<<"\n";
}
