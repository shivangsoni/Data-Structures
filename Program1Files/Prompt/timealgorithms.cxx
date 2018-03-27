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
  ofstream file2;
  file2.open("Example.csv");
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

/*int start_s=clock();
 int f=0;
 Quicksort(a,0,4,f,f);
int stop_s=clock();
cout << "time: " << (float)((stop_s-start_s)/CLOCKS_PER_SEC)<< endl;//Execution time in milliseconds. time=0.003
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
/*for(int i=0;i<samplesize;i++)
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
cout<<"\n";*/
/////////////////////////////////////////////////////////
///////////////////Quick Sort////////////////////////////
/////////////////////////////////////////////////////////
cout<<"Sample"<<","<<"InsertionSortTime,"<<"InsertionSortCompares,"<<"InsertionSortMemaccess,"<<"MergeSortTime,"<<"MergeSortCompares,"<<"MergeSortMemaccess,";
cout<<"QuickSortTime,"<<"QuickSortCompares,"<<"QuickSortMemaccess"<<endl;

file2<<"Sample"<<","<<"InsertionSortTime,"<<"InsertionSortCompares,"<<"InsertionSortMemaccess,"<<"MergeSortTime,"<<"MergeSortCompares,"<<"MergeSortMemaccess,";
file2<<"QuickSortTime,"<<"QuickSortCompares,"<<"QuickSortMemaccess"<<endl;

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
    cout<<str<<",";
    file2<<str<<",";
    for(int j=0;j<arraysize;j++)
    {
       arrayS[j] =jsonObject[str][j];
    }
    int keeptrack[arraysize];
    for(int j=0;j<arraysize;j++)
    {
       keeptrack[j]= arrayS[j];
    }
    int counttt=0;
    int co=0;
    clock_t start_s=clock();
     InsertionSort(arrayS,arraysize,counttt,co);
    clock_t stop_s=clock();
    double cpuduration =((stop_s-start_s)/(double)CLOCKS_PER_SEC);
    cout <<cpuduration<<",";
    file2<<cpuduration<<",";
    //InsertionSort(arrayS,arraysize,counttt,co);
    cout<<counttt<<","<<co<<",";
    file2<<counttt<<","<<co<<",";
    for(int j=0;j<arraysize;j++)
    {
       arrayS[j]=keeptrack[j];
    }
    counttt=0;
    co=0;
     start_s=clock();
     //Quicksort(arrayS,0,arraysize-1,counttt,co);
     MergeSort(arrayS,0,arraysize-1,counttt,co);
     stop_s=clock();
    cpuduration =((stop_s-start_s)/(double)CLOCKS_PER_SEC);
    cout <<cpuduration<<",";
    file2 <<cpuduration<<",";
    cout<<counttt<<","<<co<<",";
    file2<<counttt<<","<<co<<",";
    counttt=0;
    co=0;
    for(int j=0;j<arraysize;j++)
    {
       arrayS[j]=keeptrack[j];
    }
     start_s=clock();
     Quicksort(arrayS,0,arraysize-1,counttt,co);
     stop_s=clock();
    cpuduration =((stop_s-start_s)/(double)CLOCKS_PER_SEC);
    cout <<cpuduration<<",";
     file2<<cpuduration<<",";
     cout<<counttt<<","<<co<<"\n";
     file2<<counttt<<","<<co; 
     file2<<endl;
    str="Sample";
 }
}
