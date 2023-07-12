#ifndef _SORT_COUNTING_H_
#define _SORT_COUNTING_H_

#include "main.h"

// O(n^2)
int SelectionSortCounting(int a[], int n);
int InsertionSortCounting(int a[], int n);
int BubbleSortCounting(int a[], int n);
int ShakerSortCounting(int a[], int n);

// O(nlogn)
int ShellSortCounting(int a[], int n);
int HeapSortCounting(int a[], int n);
int MergeSortCounting(int a[], int n);
int QuickSortCounting(int a[], int n);

// O(n)
int CountingSortCounting(int a[], int n);
int RadixSortCounting(int a[], int n);
int FlashSortCounting(int a[], int n);

#endif  // _SORT_COUNTING_H_