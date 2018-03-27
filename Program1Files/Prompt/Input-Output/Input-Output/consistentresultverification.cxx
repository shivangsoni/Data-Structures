#include<iostream>
#include<fstream>
#include <cstdio>
#include <random>
#include <string>
#include "json.hpp"
using namespace std;
int main(int argc, char* argv[]) {
  std::ifstream file;
  std::ifstream file2;
  file.open(argv[1]);
  file2.open(argv[2]);
  nlohmann::json jsonObject;
  nlohmann::json jsonObject2;
  
if(file.is_open()){
   file>>jsonObject;
  }

  if(file2.is_open()){
    file2>>jsonObject2;
  }

  //find the number of samples
  int samplesize = jsonObject["metadata"]["numSamples"];
  int arraySize = jsonObject["metadata"]["arraySize"];
    string str = "Sample";



//////////////////////////////////////////
int arraySampleSize[samplesize];
 //int arrayS[arraysize];
 for(int i=0;i<samplesize;i++)
 {
    arraySampleSize[i]=0;
 }
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
   int flag=0;
   for(int j=0;j<arraySize;j++)
   {
      int a = jsonObject[str][j]; 
      int b = jsonObject2[str][j];
      if(a != b)
       flag=1;
   }
   str="Sample";
   if(flag == 1)
   {
    arraySampleSize[i]++;
   } 
 }
/////////////////////////////////////////////////////////////////////
 int count=0;
  for(int i=0;i<samplesize;i++)
  {
   if(arraySampleSize[i]!=0)
    {
     //cout<<"Mismatch at index"<<i<<"\n";
     count++;
    }
  }
////////////////////////////////////////////////////////////////////




 str="Sample";

 cout<<"{";
 for(int i=0;i<samplesize;i++)
 { str="Sample";
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

    if(arraySampleSize[i]!=0)
    {
      cout<<'"'<<str<<'"'<<":{";
      cout<<"\"Mismatches\":{";
      int p=0;
      for(int j=0;j<arraySize;j++)
      {
           int a = jsonObject[str][j];
           int b = jsonObject2[str][j];
          
          if(a!=b)
           {
             if(p==0)
             {
               cout<<'"'<<j<<'"'<<":"<<"["<<a<<","<<b<<"]";
               p++;
             }
            else
             {
               cout<<",";
               cout<<'"'<<j<<'"'<<":"<<"["<<a<<","<<b<<"]";
             }
           }
      }
     cout<<"},";
     cout<<"\"sample1\":[";
     for(int j=0;j<arraySize;j++)
     {
       if(j==0)
       cout<<jsonObject[str][j];
       else
       cout<<","<<jsonObject[str][j];
     }
    cout<<"],";
     cout<<"\"sample2\":[";
     for(int j=0;j<arraySize;j++)
     {
       if(j==0)
       cout<<jsonObject2[str][j];
       else
       cout<<","<<jsonObject2[str][j];
     }    
    cout<<"]},";
    } 
 }
  cout<<"\"metadata\":{"<<"\"samplesWithConflictingResults\":"<<count<<"},";
  cout<<"\"sample1\":{"<<"\"metadata\":{";
  cout<<"\"arraySize\":"<<jsonObject["metadata"]["arraySize"]<<",";
  cout<<"\"file\":"<<'"'<<argv[1]<<'"'<<",";
  cout<<"\"numSamples\":"<<jsonObject["metadata"]["numSamples"]<<"}},";
  cout<<"\"sample2\":{"<<"\"metadata\":{";
  cout<<"\"arraySize\":"<<jsonObject2["metadata"]["arraySize"]<<",";
  cout<<"\"file\":"<<'"'<<argv[2]<<'"'<<",";
  cout<<"\"numSamples\":"<<jsonObject2["metadata"]["numSamples"]<<"}}}"<<endl;
  
////////////////////////////////////////////////////////////////////

}
