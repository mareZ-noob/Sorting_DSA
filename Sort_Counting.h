#ifndef _SORT_COUNTING_H_
#define _SORT_COUNTING_H_

#include "main.h"

// O(n^2)
unsigned long long int SelectionSortCounting(int a[], int n);
unsigned long long int InsertionSortCounting(int a[], int n);
unsigned long long int BubbleSortCounting(int a[], int n);
unsigned long long int ShakerSortCounting(int a[], int n);

// O(nlogn)
unsigned long long int ShellSortCounting(int a[], int n);
unsigned long long int HeapSortCounting(int a[], int n);
unsigned long long int MergeSortCounting(int a[], int first, int last);
unsigned long long int QuickSortCounting(int a[], int first, int last);

// O(n)
unsigned long long int CountingSortCounting(int a[], int n, int u);
unsigned long long int RadixSortCounting(int a[], int n);
unsigned long long int FlashSortCounting(int a[], int n);

// All
unsigned long long int allSortCounting(int a[], int n, int sortIndex);

// auxiliary functions
void mergeCounting(int arr[], int first, int mid, int last, unsigned long long int &cnt);
void heapRebuildCounting(int start, int arr[], int n, unsigned long long int &cnt);

#endif  // _SORT_COUNTING_H_