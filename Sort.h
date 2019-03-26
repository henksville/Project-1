// Created by Henry Odunze
//  main.cpp
//  Final Project
//  Copyright © 2018 Odunze Henry. All rights reserved.


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
