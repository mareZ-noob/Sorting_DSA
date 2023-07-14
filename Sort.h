#ifndef _SORT_H_
#define _SORT_H_

#include "main.h"

// O(n^2)
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void BubbleSort(int a[], int n);
void ShakerSort(int a[], int n);

// O(nlogn)
void ShellSort(int a[], int n);
void HeapSort(int a[], int n);
void MergeSort(int a[], int first, int last);
void QuickSort(int a[], int first, int last);

// O(n)
void CountingSort(int a[], int n, int u);
void RadixSort(int a[], int n);
void FlashSort(int a[], int n);

// All
void allSort(int a[], int n, int sortIndex);

// Auxiliary functions
void heapRebuild(int start, int arr[], int n);
void merge(int arr[], int first, int mid, int last);

#endif  // _SORT_H_