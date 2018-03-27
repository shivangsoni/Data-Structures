#include <cstdio>
#include <iostream>
#include <fstream>
#include <random>
#include <set>
#include <string>
#include "json.hpp"
//#include "priorityqueue.h"
#include "AVL.h"
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

    int n = samples["metadata"]["numOps"];
    BST a;
    //cout<<"The capacity of priority Queue\t"<<a.n<<"\n";
    nlohmann::json result;
    /*
    result["metadata"]["maxHeapSize"] = samples["metadata"]["maxHeapSize"];
    result["metadata"]["max_size"] = samples["metadata"]["maxHeapSize"];
    result[""]["numOperations"] = samples["metadata"]["numOperations"];*/
    result["height"] = a.hsearch(a.array[i]);
    result["size"]= a.ssize();
    result["root"]=a.(root->data);
    int countt=0;
    for (auto itr = samples.begin(); itr != samples.end(); ++itr) {
        if (itr.key() != "metadata") {
            auto sample = itr.value();
            string str = sample["operation"];
            //cout<<str<<"\n";
            if(str.compare("Insert") == 0)
            {
               int t = sample["key"];
               //cout<< "The value to be inserting is"<<t<<"\n";
               a.insert(t);
               //continue;
            }
            else if(str.compare("Delete") == 0)
            {
              int k = sample["key"];
              a.remove(k);
              //cout<< "The value deleted is"<<k<<"Count Value is"<<a.count<<"\n";
              //continue;
            }
            else if(str.compare("DeleteMin") == 0)
            {
              a.DeleteMin();
              //continue;              
            }
        }
    }
   //result["metadata"]["size"]=a.count-1;        Calculate size of AVL Tree.

/*   for(int i=1;i<a.count;i++){
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
  }*/
 for(int i=0;i<a.index;i++){
  string s = to_string(a.array[i]);
  //result[s]["balance factor"]
  //result[s]["height"]
  //result[s]["parent"]
  //result[s]["right"]
  //result[s]["left"]
  result[s]["balance factor"] = a.Balancefactor(a.array[i]);
  result[s]["height"] = a.hsearch(a.array[i]);
   if(a.array[i] == a.(root->data)){
    result[s]["root"] = true;   
   }
  node* t = a.search(a.array[i]);
  if(t->left!= NULL){
   result[s]["left"] = (t->left)->data;
  }
  if(t->right != NULL){
    result[s]["right"] = (t->right)->data;
  }
  if(a.array[i]!=a.(root->data)){
    result[s]["parent"] = a.getP(a.array[i]);
  }
 } 
 cout<<result.dump(2);
}    
