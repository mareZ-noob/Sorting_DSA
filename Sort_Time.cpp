#include "Sort_Time.h"

double SelectionSortTime(int a[], int n) {
    clock_t start = clock();
    SelectionSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double InsertionSortTime(int a[], int n) {
    clock_t start = clock();
    InsertionSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double BubbleSortTime(int a[], int n) {
    clock_t start = clock();
    BubbleSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double ShakerSortTime(int a[], int n) {
    clock_t start = clock();
    ShakerSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

// O(nlogn)
double ShellSortTime(int a[], int n) {
    clock_t start = clock();
    ShellSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double HeapSortTime(int a[], int n) {
    clock_t start = clock();
    HeapSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double MergeSortTime(int a[], int first, int last) {
    clock_t start = clock();
    MergeSort(a, first, last);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double QuickSortTime(int a[], int first, int last) {
    clock_t start = clock();
    QuickSort(a, first, last);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

// O(n)
double CountingSortTime(int a[], int n, int u) {  // u is the maximum value
    clock_t start = clock();
    CountingSort(a, n, 1000001);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double RadixSortTime(int a[], int n) {
    clock_t start = clock();
    RadixSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double FlashSortTime(int a[], int n) {
    clock_t start = clock();
    FlashSort(a, n);
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double allSortTime(int a[], int n, int sortIndex) {
    if (sortIndex == 0)
        return SelectionSortTime(a, n);
    else if (sortIndex == 1)
        return InsertionSortTime(a, n);
    else if (sortIndex == 2)
        return BubbleSortTime(a, n);
    else if (sortIndex == 3)
        return ShakerSortTime(a, n);
    else if (sortIndex == 4)
        return ShellSortTime(a, n);
    else if (sortIndex == 5)
        return HeapSortTime(a, n);
    else if (sortIndex == 6)
        return MergeSortTime(a, 0, n - 1);
    else if (sortIndex == 7)
        return QuickSortTime(a, 0, n - 1);
    else if (sortIndex == 8)
        return CountingSortTime(a, n, 1000001);
    else if (sortIndex == 9)
        return RadixSortTime(a, n);
    else if (sortIndex == 10)
        return FlashSortTime(a, n);
    return 0;
}