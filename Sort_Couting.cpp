#include "Sort_Couting.h"

// O(n*n)
long long SelectionSortCounting(int a[], int n) {
    long long cnt = 0;

    for(int i = 0 ; ++cnt &&   i < n - 1; i++){
        int min_idx = i;
        for(int j = i + 1 ; j < n ; j++)
            if(++cnt && a[j] < a[min_idx])
                min_idx = j;
        swap(a[min_idx], a[i]);
    }

    return cnt;
}

long long InsertionSortCounting(int a[], int n) {
    long long cnt = 0;

    for(int i = 1 ; ++cnt && i < n ; i++){
        int val = a[i], j = i - 1; 
        while(++cnt && j >= 0 && a[j] > val){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    }

    return cnt;
}

long long BubbleSortCounting(int a[], int n) {
    long long cnt = 0;

    for(int i = 1 ; ++cnt && i < n ; i++){
        for(int j = n - 1 ; ++cnt && j >= i ; j--)
            if(++cnt && a[j] < a[j-1])
                swap(a[j], a[j-1]);
    }

    return cnt;
}

long long ShakerSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}

// O(n*logn)
long long ShellSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}

long long HeapSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}

long long MergeSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}

long long QuickSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}

// O(n)
long long CountingSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}

long long RadixSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}

long long FlashSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}