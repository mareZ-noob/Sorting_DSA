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
long long MergeSortCounting(int a[], int n);
long long QuickSortCounting(int a[], int n);

// O(n)
long long CountingSortCounting(int a[], int n);
long long RadixSortCounting(int a[], int n);
long long FlashSortCounting(int a[], int n);

#endif  // _SORT_COUNTING_H_