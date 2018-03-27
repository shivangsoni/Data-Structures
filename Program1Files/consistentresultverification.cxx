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
  /* cout<<"Print File1 in JSON"<<endl;
   for(auto itr=jsonObject.begin();itr != jsonObject.end();++itr)
   {
    cout<<"key: "<<itr.key()<<" value: "<<itr.value()<<'\n';
   }*/
  }

  if(file2.is_open()){
    file2>>jsonObject2;
 /*  cout<<"Print File2 in JSON"<<endl;
   for(auto itr=jsonObject2.begin();itr != jsonObject2.end();++itr)
   {
    cout<<"key: "<<itr.key()<<" value: "<<itr.value()<<'\n';
   }*/
  }
////////////////////////////////////////////////////////////// 
/*SampleExample sample1count*/
int sample1count=0;
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
  }
///////////////////////////////////////////////////////////
/*SampleExample sample1count*/
int sample2count=0;
  for (auto arrayItr = jsonObject["Sample2"].begin();
   arrayItr != jsonObject["Sample2"].end();
   ++arrayItr) {
      sample2count++;
  }
  int sample2[sample2count];
  int h=0; 
  for (auto arrayItr = jsonObject["Sample2"].begin();
   arrayItr != jsonObject["Sample2"].end();
   ++arrayItr) {
      sample2[h++]=*arrayItr;
  }
////////////////////////////////////////////////////////////
/*AlmostSampleExample sample1count*/
int sample1countalmost=0;
  for (auto arrayItr = jsonObject2["Sample1"].begin();
   arrayItr != jsonObject2["Sample1"].end();
   ++arrayItr) {
      sample1countalmost++;
  }
  int sample1almost[sample1countalmost];
  int k=0; 
  for (auto arrayItr = jsonObject2["Sample1"].begin();
   arrayItr != jsonObject2["Sample1"].end();
   ++arrayItr) {
      sample1almost[k++]=*arrayItr;
  }
/////////////////////////////////////////////////////////////
/*AlmostSampleExample sample2count*/
int sample2countalmost=0;
  for (auto arrayItr = jsonObject2["Sample2"].begin();
   arrayItr != jsonObject2["Sample2"].end();
   ++arrayItr) {
      sample2countalmost++;
  }
  int sample2almost[sample2countalmost];
  int k1=0; 
  for (auto arrayItr = jsonObject2["Sample2"].begin();
   arrayItr != jsonObject2["Sample2"].end();
   ++arrayItr) {
      sample2almost[k1++]=*arrayItr;
  }
//////////////////////////////////////////////////////////////
/*Check if mismatch is found in sample 1*/
int mismatch1=0;
  for(int i=0;i<k;i++)
  {
      if(sample1[i]!=sample1almost[i])
      { mismatch1++;}
  }
int mismatch2=0;
  for(int i=0;i<k1;i++)
  {
      if(sample2[i]!=sample2almost[i])
      { mismatch2++;}
  }
 
cout<<"{";
 if(mismatch1!=0)
 {
   cout<<"\"Sample1\":{\"Mismatches\":{";
 int j=0;   
for(int i=0;i<k;i++)
   {    
     if(sample1[i]!=sample1almost[i])
     {
       if(j!=0)
       {
         cout<<",";
       }
       j++;
       cout<<'"'<<i<<'"'<<":["<<sample1[i]<<","<<sample1almost[i]<<"]";
     }
   }
 cout<<"},";
 cout<<"\"sample1\":"<<"[";
 cout<<sample1[0];
 for(int i=1;i<k;i++)
 {
  cout<<","<<sample1[i];
 }
 cout<<"],";
 cout<<"\"sample2\":"<<"[";
 cout<<sample1almost[0];
 for(int i=1;i<k;i++)
 {
  cout<<","<<sample1almost[i];
 }
 cout<<"]},"; 
 }
////////////////////////////////////////////////////////////////////// 
 if(mismatch2!=0)
 {
   cout<<"\"Sample2\":{\"Mismatches\":{";
 int j=0;   
for(int i=0;i<k1;i++)
   {
    
     if(sample2[i]!=sample2almost[i])
     {
       if(j!=0)
       {
         cout<<",";
       }
       j++;
       cout<<'"'<<i<<'"'<<":["<<sample2[i]<<","<<sample2almost[i]<<"]";
     }
   }
 cout<<"},";
 cout<<"\"sample1\":"<<"[";
 cout<<sample2[0];
 for(int i=1;i<k1;i++)
 {
  cout<<","<<sample2[i];
 }
 cout<<"],";
 cout<<"\"sample2\":"<<"[";
 cout<<sample2almost[0];
 for(int i=1;i<k1;i++)
 {
  cout<<","<<sample2almost[i];
 }
 cout<<"]},"; 
 }
/////////////////////////////////////////////////////////////////////////
/*Missmatch*/

cout<<"\"metadata\":{"<<"\"sampleWithConflictingResults\":";
 if(mismatch1>0 && mismatch2>0)
 {
  cout<<2;
 }  
  else if((mismatch1>0 && mismatch2==0)||(mismatch1==0 && mismatch2>0))
 {
  cout<<1;
 }
 else
 {
  cout<<0;
 }
cout<<"},";
////////////////////////////////////////////////////////////////////////
 cout<<"\"sample1\":{"<<"\"metadata\":{"<<"\"arraySize\":"<<jsonObject["metadata"]["arraySize"]<<","<<"\"file\":"<<'"'<<argv[1]<<'"'<<",";
 cout<<"\"numSamples\":"<<jsonObject["metadata"]["numSamples"]<<"}},";
////////////////////////////////////////////////////////////////////////
 cout<<"\"sample2\":{"<<"\"metadata\":{"<<"\"arraySize\":"<<jsonObject2["metadata"]["arraySize"]<<","<<"\"file\":"<<'"'<<argv[2]<<'"'<<",";
 cout<<"\"numSamples\":"<<jsonObject2["metadata"]["numSamples"]<<"}}}";
}
