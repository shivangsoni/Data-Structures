// ShellSort implementation adapted from:
// https://www.geeksforgeeks.org/shellsort/
// Note: This code is used to illustrate the utility of automated testing
// for verification purposes, so it may not function correctly. This is
// intentional.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"
 
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n - 1; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
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
            shellSort(sampleData, n);
            for (int i = 0; i < n; i++) {
                result[itr.key()].push_back(sampleData[i]);
            }
        }
    }
    std::cout << result << '\n';
}
