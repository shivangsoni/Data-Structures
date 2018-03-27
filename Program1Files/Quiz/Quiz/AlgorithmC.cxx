// PancakeSort implementation adapted from:
// https://www.geeksforgeeks.org/pancake-sorting/
// Note: This code is used to illustrate the utility of automated testing
// for verification purposes, so it may not function correctly. This is
// intentional.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"
 
/* Reverses arr[0..i] */
void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}
 
// Returns index of the 
// maximum element in 
// arr[0..n-1] 
int findMax(int arr[], int n)
{
int mi, i;
for (mi = 0, i = 0; i < n; ++i)
    if (arr[i] > arr[mi])
            mi = i;
return mi;
}
 
// The main function that 
// sorts given array using 
// flip operations
void pancakeSort(int *arr, int n)
{
    // Start from the complete
    // array and one by one 
    // reduce current size 
    // by one
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        // Find index of the 
        // maximum element in 
        // arr[0..curr_size-1]
        int mi = findMax(arr, curr_size);
 
        // Move the maximum
        // element to end of 
        // current array if
        // it's not already
        // at the end
        if (mi != curr_size-1)
        {
            // To move at the end,
            // first move maximum 
            // number to beginning 
            flip(arr, mi);
 
            // Now move the maximum 
            // number to end by 
            // reversing current array
            flip(arr, curr_size-1);
        }
    }
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
            pancakeSort(sampleData, n);
            for (int i = 0; i < n; i++) {
                result[itr.key()].push_back(sampleData[i]);
            }
        }
    }
    std::cout << result << '\n';
}