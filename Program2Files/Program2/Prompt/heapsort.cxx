
#include <iostream>
#include <fstream>
#include <random>
#include <set>
#include <string>
#include "priorityqueue.h"
#include "json.hpp"
using namespace std;


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
    std::cout << result.dump(2) << '\n';
}
