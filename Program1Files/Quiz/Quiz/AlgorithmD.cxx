// CycleSort implementation adapted from:
// https://www.geeksforgeeks.org/cycle-sorting/
// Note: This code is used to illustrate the utility of automated testing
// for verification purposes, so it may not function correctly. This is
// intentional.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"

#include <iostream>
using namespace std;
 
// Function sort the array using Cycle sort
void cycleSort (int arr[], int n)
{
    // count number of memory writes
    int writes = 0;
 
    // traverse array elements and put it to on
    // the right place
    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];
 
        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
            if (arr[i] < item)
                pos++;
 
        // If item is already in correct position
        if (pos == cycle_start)
            continue;
 
        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;
 
        // put the item to it's right position
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }
 
        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;
 
            // Find position where we put the element
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;
 
            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
 
            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
 
    // Number of memory writes or swaps
    // cout << writes << endl ;
}
 

// Driver program to test above function
int main(int argc, char** argv)
{
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
            std::copy(sample.begin(), sample.end(), sampleData);
            cycleSort(sampleData, n);
            for (int i = 0; i < n; i++) {
                result[itr.key()].push_back(sampleData[i]);
            }
        }
    }
    std::cout << result << '\n';
}