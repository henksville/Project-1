//
//  Sort.cpp
//  Final Project
//
//  Created by Ore Runsewe on 5/6/18.
//  Copyright © 2018 Ore Runsewe. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "Sort.h"

//template <typename T>
void Sort::SelectionSort(int elements[], int numbersSize) {
    int i = 0;
    int j = 0;
    int indexSmallest = 0;
    int temp;  // Temporary variable for swap
    
    // cout << "SELECTION SORT" << endl << endl;
    
    for (i = 0; i < numbersSize - 1; ++i) {
        
        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; ++j) {
            if ( elements[j] < elements[indexSmallest] ) {
                indexSmallest = j;
            }
        }
        
        // Swap numbers[i] and numbers[indexSmallest]
        temp = elements[i];
        elements[i] = elements[indexSmallest];
        elements[indexSmallest] = temp;
        
    }
}

//template <typename  T>
void Sort::InsertionSort(int elements[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp;  // Temporary variable for swap
    
    //    cout << "INSERTION SORT" << endl << endl;
    
    for (i = 1; i < numbersSize; ++i) {
        j = i;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && elements[j] < elements[j - 1]) {
            // cout << "numbers[j]: " << numbers[j] << endl;
            // Swap numbers[j] and numbers[j - 1]
            temp = elements[j];
            
            elements[j] = elements[j - 1];
            elements[j - 1] = temp;
            --j;
        }
    }
}

//template <typename  T>
void Sort::Merge(int elements[], int i, int j, int k) {
    int mergedSize = k - i + 1;                // Size of merged partition
    int mergePos = 0;                          // Position to insert merged number
    int leftPos = 0;                           // Position of elements in left partition
    int rightPos = 0;                          // Position of elements in right partition
    int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
    // for merged numbers
    
    leftPos = i;                               // Initialize left partition position
    rightPos = j + 1;                          // Initialize right partition position
    
    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (elements[leftPos] < elements[rightPos]) {
            mergedNumbers[mergePos] = elements[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = elements[rightPos];
            ++rightPos;
            
        }
        ++mergePos;
    }
    
    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = elements[leftPos];
        ++leftPos;
        ++mergePos;
    }
    
    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = elements[rightPos];
        ++rightPos;
        ++mergePos;
    }
    
    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        elements[i + mergePos] = mergedNumbers[mergePos];
    }
}


//template <typename  T>
void Sort::MergeSort(int *elements, int i, int k) {
    int j = 0;
    
    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition
        
        // Recursively sort left and right partitions
        MergeSort(elements, i, j);
        MergeSort(elements, j + 1, k);
        
        // Merge left and right partition in sorted order
        Merge(elements, i, j, k);
    }
}
    


/*NODE *merge(NODE *first, NODE *second)
{
    // If first linked list is empty
    if (!first)
        return second;
    
    // If second linked list is empty
    if (!second)
        return first;
    
    // Pick the smaller value
    if (first->song < second->song) {
        first->next = merge(first->next, second);
        first->next->previous = first;
        first->previous = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->previous = second;
        second->previous = NULL;
        return second;
    }
}

// Function to do merge sort
NODE *mergeSort(NODE *head)
{
    if (!head || !head->next)
        return head;
    NODE *second = split(head);
    
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
    
    // Merge the two sorted halves
    return merge(head, second);
} */


