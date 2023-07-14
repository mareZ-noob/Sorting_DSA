#ifndef _SORT_COUNTING_H_
#define _SORT_COUNTING_H_

#include "main.h"

// O(n^2)
long long SelectionSortCounting(int a[], int n);
long long InsertionSortCounting(int a[], int n);
long long BubbleSortCounting(int a[], int n);
long long ShakerSortCounting(int a[], int n);

// O(nlogn)
long long ShellSortCounting(int a[], int n);
long long HeapSortCounting(int a[], int n);
long long MergeSortCounting(int a[], int first, int last);
long long QuickSortCounting(int a[], int first, int last);

// O(n)
long long CountingSortCounting(int a[], int n, int u);
long long RadixSortCounting(int a[], int n);
long long FlashSortCounting(int a[], int n);

// All
long long allSortCounting(int a[], int n, int sortIndex);

// auxiliary functions
void mergeCounting(int arr[], int first, int mid, int last, long long &cnt);
void heapRebuildCounting(int start, int arr[], int n, long long &cnt);

#endif  // _SORT_COUNTING_H_