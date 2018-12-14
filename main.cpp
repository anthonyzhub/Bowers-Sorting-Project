//
//  main.cpp
//  Algorithm Project
//
//  Created by Anthony Zamora on 12/3/18.
//  Copyright © 2018 Anthony Zamora. All rights reserved.
//
// Sources: geekforgeek.org & stackoverflow.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#pragma mark Custom MergeSort Code
void insertionSort(int arr[], int size)
{
    int currentPos, elem, prevPos;
    
    for (currentPos = 1; currentPos < size; currentPos++)
    {
        // Get element
        elem = arr[currentPos];
        
        // Refer to previous position
        prevPos = currentPos - 1;
        
        // If previousPosition is within the array AND
        // Element at previous index is greater than element at current index
        while (prevPos >= 0 && arr[prevPos] > elem)
        {
            // Swap positions (pt. 1)
            arr[prevPos + 1] = arr[prevPos];
            
            // Increment counter
            prevPos = prevPos - 1;
        }
        
        // Swap positions (pt. 2)
        arr[prevPos + 1] = elem;
    }
}

// Send the array, first position, half-size, full-size
void merge(int arr[], int posBegin, int posMiddle, int posRear)
{
    // Size of temporary arrays
    int n1 = posMiddle - posBegin + 1;
    int n2 =  posRear - posMiddle;
    
    // create temp arrays
    int firstHalf[n1], secondHalf[n2];
    
    // index for arrays
    int i1, i2, curr;
    
    // Copy elements of array to temporary arrays
    for (i1 = 0; i1 < n1; i1++)
    {
        firstHalf[i1] = arr[posBegin + i1];
    }
    
    for (i2 = 0; i2 < n2; i2++)
    {
        secondHalf[i2] = arr[posMiddle + i2 + 1];
    }
    
    // Reset index, then merge both temporary arrays
    i1 = 0;
    i2 = 0;
    curr = posBegin;
    
    // while iterators doesn't reach the full length of both arrays
    while (i1 < n1 && i2 < n2)
    {
        // Check if element in firstHalf is less than secondHalf's
        if (firstHalf[i1] <= secondHalf[i2])
        {
            // Add firstHalf's element to original array
            arr[curr] = firstHalf[i1];
            
            // Incremement index
            i1++;
        }
        else
        {
            // Do the opposite, if element in secondHalf is less than firstHalf's
            arr[curr] = secondHalf[i2];
            
            // Increment index
            i2++;
        }
        
        // Incremement original array's index.
        curr++;
    }
    
    // Copy remaining elements
    // Only one "while" loop will be executed
    while (i1 < n1)
    {
        arr[curr] = firstHalf[i1];
        i1++;
        curr++;
    }
    
    while (i2 < n2)
    {
        arr[curr] = secondHalf[i2];
        i2++;
        curr++;
    }
}
/*
void jazzSort(int arr[], int posBegin, int posEnd)
{
    if (posBegin < posEnd)
    {
        // Find middle part of array
        int midPoint = (posBegin + posEnd)/2;
        
        // If size of array is less than 30.
        if (posEnd < 30)
        {
            insertionSort(arr, posEnd);
        }
        
        // Sort the first half of the array, then the other
        jazzSort(arr, posBegin, midPoint);
        jazzSort(arr, midPoint + 1, posEnd);
        
        // Merged the two sorted arrays
        merge(arr, posBegin, posMiddle, posEnd);
    }
}
*/

void jazzSort(int arr[], int posBegin, int posMiddle, int posRear = NULL)
{
    int midPoint;
    
    if (posBegin < posMiddle)
    {
        // Find middle part of array
        midPoint = (posBegin + posMiddle)/2;
        
        // If size of array is less than 30.
        if (posMiddle < 30)
            insertionSort(arr, posMiddle);
        
        // Sort the first half of the array, then the other
        jazzSort(arr, posBegin, midPoint);
        jazzSort(arr, midPoint + 1, posMiddle);
        
        // Merged the two sorted arrays
        merge(arr, posBegin, midPoint, posMiddle);
    } else if (posMiddle < posRear) {
        
        // Midpoint between posMiddle and posRear
        midPoint = (posMiddle + posRear)/2;
        
        // If size is less than 30
        if (posRear < 30)
            insertionSort(arr, posRear);
        
        // Sort the arrays
        jazzSort(arr, posMiddle, midPoint);
        jazzSort(arr, midPoint + 1, posRear);
        
        merge(arr, posMiddle, midPoint, posRear);
    }
}

# pragma mark QuickSort Code
void swap(int* a, int* b)
{
    // Simple function to swap elements
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int posBegin, int posRear)
{
    int pivot = arr[posRear];
    int index = (posBegin - 1);
    
    // Get size of array
    float size = sizeof(*arr)/sizeof(arr[0]);
    float pivotRange = size * .05;
    static int counter;
    
    // Check if pivot is %5 in range from either end of the array
    if (float(pivot) == pivotRange || float(pivot) == size - pivotRange)
    {
        counter++;
        
        // If this happens 4x, switch to JazzSort
        if (counter == 4)
        {
            jazzSort(arr, posBegin, posRear);
        }
    }
    
    for (int i = posBegin; i <= posRear- 1; i++)
    {
        // Organize array in ascending order
        if (arr[i] <= pivot)
        {
            index++;
            swap(&arr[index], &arr[i]);
        }
    }
    
    // Swap remaining element
    swap(&arr[index + 1], &arr[posRear]);
    
    return index + 1;
}

void quickSort(int arr[], int posBegin, int posRear)
{
    if (posBegin < posRear)
    {
        // Partition array
        int index = partition(arr, posBegin, posRear);
        
        // Sort array before and after partitioning
        quickSort(arr, posBegin, index - 1);
        quickSort(arr, index + 1, posRear);
    }
}

#pragma mark Universal Print function
void printArray(vector <int> arr[], int size)
{
    // Print out the sorted arrays
    for (int i = 0; i < 7; i++)
    {
        cout<<"\nLine "<<i<<" has: "<<endl;
        for (int x = 0; x < arr[i].size(); x++)
        {
            cout<<arr[i].data()[x]<<" ";
        }
    }
    cout<<endl;
}

void textReader(vector<int> allNumArray[])
{
    // Get file
    ifstream inputFile("/Users/anthonyzamora/Documents/C++/Algorithm Project/Algorithm Project/unsorted7.txt");
    string line;
    
    // Check if file can be opened
    if (inputFile.is_open())
    {
        int index = 0;
        
        // Go through each line
        while (getline(inputFile, line))
        {
            // Get each number separately
            stringstream iss(line);
            string num;
            
            // Get every number and put it into num
            while (iss >> num)
            {
                // 1. Access array of vectors at index position
                // 2. Add number from line to the array
                // 3. Print number that was added.
                allNumArray[index].push_back(stoi(num));
            }
            
            // Move to next vector in array
            index++;
        }
            // Close file
            inputFile.close();
    } else {
        cout<<"File cannot be opened."<<endl;
    }
}

#pragma mark MAIN
int main(int argc, const char * argv[])
{
    // Create an array that holds 7 vectors
    vector<int> arr[7]; // Will be used for jazzSort
    vector<int> arr1[7]; // Will be used for quickSort
    
    // Send the array to textReader.
    // Get the numbers from the text file and put it into array
    textReader(arr);
    textReader(arr1);
    
    // For every vector of array, call jazzSort
    for (int i = 0; i < 7; i++)
    {
        jazzSort(arr[i].data(), 0, arr[i].size() - 1);
        quickSort(arr1[i].data(), 0, arr[i].size() - 1);
    }
    
    // Print sorted arrays
    cout<<"Jazz Sort:"<<endl;
    printArray(arr, 7);
    
    cout<<"Quick Sort:"<<endl;
    printArray(arr1, 7);
    
    return 0;
}
