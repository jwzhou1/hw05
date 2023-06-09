#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    int minimumIndex = start;               // Initialize minimumIndex variable with start
    int minimumValue = array[start];        // Initialize minimumValue variable with value at start index of the array
    for (int i = start + 1; i <= stop; i++) // Loop from start + 1 to stop
    {
        if (array[i] < minimumValue) // Check if the value at index i is less than minimumValue
        {
            minimumValue = array[i]; // Update minimumValue to the new minimum value
            minimumIndex = i;        // Update minimumIndex to the index of the new minimum value
        }
    }
    return minimumIndex; // Return the index of the minimum value
}

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: Selection Sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    if (size == 0)
        return;                             // If the size is 0, there is nothing to sort, so return
    for (unsigned int i = 0; i < size; ++i) // Loop from 0 to size - 1
    {
        unsigned int minimumIndex = findMinimum(array, i, size - 1); // Find the index of the minimum value in the array from i to size - 1
        swap(&array[i], &array[minimumIndex]);                       // Swap the value at index i with the minimum value found
        if (print)                                                   // If print is true
        {
            for (unsigned int k = 0; k < size; ++k) // Loop through the array
            {
                printf("%d ", array[k]); // Print each element of the array
            }
            printf("\n"); // Print a newline character after printing the array
        }
    }
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: Insertion Sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    if (size == 0)
        return;                             // If the size is 0, there is nothing to sort, so return
    for (unsigned int i = 1; i < size; ++i) // Loop from 1 to size - 1
    {
        int key = array[i];              // Store the value at index i in the key variable
        int j = i - 1;                   // Set j to the index before i
        while (j >= 0 && array[j] > key) // While j is greater than or equal to 0 and the value at index j is greater than the key
        {
            array[j + 1] = array[j]; // Shift the value at index j to the right
            j--;                     // Decrement j
        }
        array[j + 1] = key; // Place the key at the correct position in the sorted portion of the array
        if (print)          // If print is true
        {
            for (unsigned int k = 0; k < size; ++k) // Loop through the array
            {
                printf("%d ", array[k]); // Print each element of the array
            }
            printf("\n"); // Print a newline character after printing the array
        }
    }
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    for (unsigned int i = 0; i < size - 1; i++) // Outer loop from 0 to size - 2
    {
        for (unsigned int j = 0; j < size - i - 1; j++) // Inner loop from 0 to size - i - 2
        {
            if (array[j] > array[j + 1]) // If the current element is greater than the next element
            {
                swap(&array[j], &array[j + 1]); // Swap the current element with the next element
            }
        }
        if (print) // If print is true
        {
            printf("Iteration %u: ", i + 1); // Print the iteration number
            printIntArray(array, size); // Print the array
        }
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL) // Check if either arr or temp is NULL
    {
        exit(1); // Exit the program with a non-zero status if either array is NULL
    }
    if (l > m || m + 1 > r) // Check if the left index is greater than the middle index or if the middle index + 1 is greater than the right index
        return; // If any of the conditions is true, return from the function
    int i = l; // Initialize i with the left index
    int j = m + 1; // Initialize j with the middle index + 1
    int start = l; // Initialize start with the left index
    while (i <= m && j <= r) // Loop while i is less than or equal to the middle index and j is less than or equal to the right index
    {
        if (arr[i] <= arr[j]) // If the element at index i in arr is less than or equal to the element at index j in arr
        {
            temp[start] = arr[i]; // Assign the element at index i in arr to the element at index start in temp
            i++; // Increment i
        }
        else // If the element at index i in arr is greater than the element at index j in arr
        {
            temp[start] = arr[j]; // Assign the element at index j in arr to the element at index start in temp
            j++; // Increment j
        }
        start++; // Increment start
    }
    while (i <= m) // Loop while i is less than or equal to the middle index
    {
        temp[start] = arr[i]; // Assign the element at index i in arr to the element at index start in temp
        i++; // Increment i
        start++; // Increment start
    }
    while (j <= r) // Loop while j is less than or equal to the right index
    {
        temp[start] = arr[j]; // Assign the element at index j in arr to the element at index start in temp
        j++; // Increment j
        start++; // Increment start
    }
    for (int k = l; k <= r; k++) // Loop from the left index to the right index
    {
        arr[k] = temp[k]; // Assign the element at index k in temp to the element at index k in arr
    }
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    if (l < r) // Check if the left index is less than the right index
    {
        int m = l + (r - l) / 2; // Calculate the middle index as the average of the left and right indices
        merge_sort(arr, temp, l, m); // Recursively call merge_sort on the left half of the array
        merge_sort(arr, temp, m + 1, r); // Recursively call merge_sort on the right half of the array
        merge(arr, temp, l, m, r); // Merge the two sorted halves of the array using the merge function
    }
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL) // Check if the array is NULL
    {
        exit(1); // Exit the program with a non-zero status if the array is NULL
    }
    if (size <= 1) // Check if the size of the array is less than or equal to 1
        return; // If true, the array is already sorted or empty, so there's nothing to sort, return.

    int *temp = (int *)malloc(sizeof(int) * size); // Allocate memory for a temporary array of the same size as the input array
    merge_sort(array, temp, 0, size - 1); // Call the merge_sort function to sort the array using the temporary array
    free(temp); // Free the memory allocated for the temporary array
}

// provided code

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif
