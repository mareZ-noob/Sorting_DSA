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
void MergeSort(int a[], int n);
void QuickSort(int a[], int n);

// O(n)
void CountingSort(int a[], int n);
void RadixSort(int a[], int n);
void FlashSort(int a[], int n);

#endif  // _SORT_H_