#include <cstdio>
#include <iostream>
#include <fstream>
#include <random>
#include <set>
#include <string>

#include "json.hpp"
#include "priorityqueue.h"
using namespace std;
int main(int argc, char** argv) {
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
