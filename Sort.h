//
//  Sort.h
//  Final Project
//
//  Created by Ore Runsewe on 5/6/18.
//  Copyright © 2018 Ore Runsewe. All rights reserved.
//

#ifndef Sort_h
#define Sort_h

#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

//template <typename T>
class Sort {
public:
    static void SelectionSort(int elements[], int numbersSize);
    static void InsertionSort(int elements[], int numbersSize);
    static void Merge(int elements[], int i, int j, int k);
    static void MergeSort(int *elements, int i, int k);
   // NODE *merge(NODE *first, NODE *second);
// NODE *mergeSort(NODE *head);
};


#endif /* Sort_h */
