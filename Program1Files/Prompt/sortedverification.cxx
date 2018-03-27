#include<iostream>
#include<fstream>
#include <cstdio>
#include <random>
#include <string>
#include <stdlib.h>
#include "json.hpp"
using namespace std;
int main(int argc, char** argv) {
  ifstream file;
  file.open(argv[1]);
  nlohmann::json jsonObject;
  if(file.is_open()){
   file>>jsonObject;
  }
  /* int sample1count=0;
  for (auto arrayItr = jsonObject["Sample1"].begin();
   arrayItr != jsonObject["Sample1"].end();
   ++arrayItr) {
      sample1count++;
  }
  int sample1[sample1count];
  int g=0; 
  for (auto arrayItr = jsonObject["Sample1"].begin();
   arrayItr != jsonObject["Sample1"].end();
   ++arrayItr) {
      sample1[g++]=*arrayItr;
  }*/
  int samplesize = jsonObject["metadata"]["numSamples"];
  int arraysize = jsonObject["metadata"]["arraySize"];
  string str = "Sample";
  
 // array which are not sorted 
 
 /*str = "Sample01";
 for (auto arrayItr = jsonObject[str].begin();
   arrayItr != jsonObject[str].end();
   ++arrayItr) {
      cout<<*arrayItr<<"\t";
  }*/


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
   for(int j=1;j<arraysize;j++)
   {
      int a = jsonObject[str][j-1]; 
      int b = jsonObject[str][j];
      if(a > b)
       flag=1;
   }
   str="Sample";
   if(flag == 1)
   {
    arraySampleSize[i]++;
   } 
 }
  int count=0;
  for(int i=0;i<samplesize;i++)
  {
   if(arraySampleSize[i]==1)
    count++;
  }

 //The arrays not sorted has to be in the list.
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
      cout<<"\"ConsecutiveInversions\":{";
      int p=0;
      for(int j=0;j<arraysize-1;j++)
      {
           int a = jsonObject[str][j];
           int b = jsonObject[str][j+1];
          
          if(a>b)
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
     cout<<"\"sample\":[";
     for(int j=0;j<arraysize;j++)
     {
       if(j==0)
       cout<<jsonObject[str][j];
       else
       cout<<","<<jsonObject[str][j];
     }
    cout<<"]},";
    } 
 }
  cout<<"\"metadata\":{";
  cout<<"\"arraySize\":"<<jsonObject["metadata"]["arraySize"]<<",";
  cout<<"\"file\":"<<'"'<<argv[1]<<'"'<<",";
  cout<<"\"numSamples\":"<<jsonObject["metadata"]["numSamples"]<<",";
  cout<<"\"samplesWithInversions\":"<<count<<"}}"<<endl;
}
