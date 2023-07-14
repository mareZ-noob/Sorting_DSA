#ifndef _SORT_TIME_H_
#define _SORT_TIME_H_

#include "main.h"

// O(n^2)
double SelectionSortTime(int a[], int n);
double InsertionSortTime(int a[], int n);
double BubbleSortTime(int a[], int n);
double ShakerSortTime(int a[], int n);

// O(nlogn)
double ShellSortTime(int a[], int n);
double HeapSortTime(int a[], int n);
double MergeSortTime(int a[], int first, int last);
double QuickSortTime(int a[], int first, int last);

// O(n)
double CountingSortTime(int a[], int n, int u);
double RadixSortTime(int a[], int n);
double FlashSortTime(int a[], int n);

// All
double allSortTime(int a[], int n, int sortIndex);

#endif  // _SORT_TIME_H_