#ifndef _SORT_COUNTING_H_
#define _SORT_COUNTING_H_

#include "main.h"

// O(n^2)
unsigned long long SelectionSortCounting(int a[], int n);
unsigned long long InsertionSortCounting(int a[], int n);
unsigned long long BubbleSortCounting(int a[], int n);
unsigned long long ShakerSortCounting(int a[], int n);

// O(nlogn)
unsigned long long ShellSortCounting(int a[], int n);
unsigned long long HeapSortCounting(int a[], int n);
unsigned long long MergeSortCounting(int a[], int first, int last,
                                         unsigned long long &cnt);
unsigned long long QuickSortCounting(int a[], int first, int last,
                                         unsigned long long &cnt);

// O(n)
unsigned long long CountingSortCounting(int a[], int n, int u);
unsigned long long RadixSortCounting(int a[], int n);
unsigned long long FlashSortCounting(int a[], int n);

// All
unsigned long long allSortCounting(int a[], int n, int sortIndex);

// auxiliary functions
void mergeCounting(int arr[], int first, int mid, int last,
                   unsigned long long &cnt);
void heapRebuildCounting(int start, int arr[], int n,
                         unsigned long long &cnt);

#endif  // _SORT_COUNTING_H_