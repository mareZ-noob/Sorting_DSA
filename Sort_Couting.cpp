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
    
    int max_val = a[0];
    for(int i = 1 ; ++cnt && i < n ; i++)
        if(++cnt && max_val < a[i])
            max_val = a[i];

    int *count = new int [max_val + 1];
    for(int i = 0 ; ++cnt && i < n ; i++)
        count[a[i]]++;

    for(int i = 1 ; ++cnt && i <= max_val ; i++)
        count[i] = count[i] + count[i-1];

    int* b = new int [n];
    for(int i = n - 1 ; ++cnt && i >= 0 ; i--){
        b[count[a[i]] - 1]  = a[i];
        count[a[i]] --;
    }

    for(int i = 0 ; ++cnt && i < n ; i++)
        a[i] = b[i];

    return cnt;
}

long long RadixSortCounting(int a[], int n) {
    long long cnt = 0;
    
    int max_val = a[0];
    for(int i = 1 ; ++cnt && i < n ; i++)
        if(++cnt && a[i] > max_val)
            max_val = a[i];
    
    int digits = 0, div;
    do{
        digits++;
        div = max_val/pow(10,digits);
    }while(div);

    int* tmp_arr[10];
    for(int i = 0 ; ++cnt && i < 10 ; i++)
        tmp_arr[i] = new int [n];

    int tmp_count[10];

    for(int i = 1 ; ++cnt && i < max_val ; i*= 10){
        for(int j = 0 ; ++cnt && j < 10 ; j++)  
            tmp_count[j] = 0;
        for(int j = 0 ; ++cnt && j < n ; j++){
            int idx = a[j]/i%10;
            tmp_arr[idx][tmp_count[idx]++] = a[j];
        }

        int idx = 0;
        for(int j = 0 ; ++cnt && j < 10 ; j++)
            for(int k = 0 ; ++cnt && k < tmp_count[j] ; k++)
                a[idx++] = tmp_arr[j][k];
    }

    return cnt;
}

long long FlashSortCounting(int a[], int n) {
    long long cnt = 0;

    /*
        TODO
    */

    return cnt;
}