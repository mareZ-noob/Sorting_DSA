#include "Sort_Couting.h"
#define MAX_SIZE 1000
int __L[300000];

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
    int left = 1, right = n-1, k = n-1;
    do {
        for (int j = right; j >= left; --j){
            if (a[j - 1] > a[j]){
                swap(a[j - 1], a[j]);
                k = j;
            }
        }
        left = k + 1;
        for (int j = left; j <= right; ++j){
            if (a[j - 1] > a[j]){
                swap(a[j - 1], a[j]); 
                k = j;
            }
        }
        right = k - 1;
    } while (left <= right);

    return cnt;
}

// O(n*logn)
long long ShellSortCounting(int a[], int n) {
    long long cnt = 0;
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = a[i];
            int j;            
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
              
            a[j] = temp;
        }
    }

    return cnt;
}

void heapRebuild(int start, int arr[], int n) {
    int leftChild = 2 * start + 1;
    if (leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n){
        if (arr[rightChild] > arr[largerChild])
            largerChild = rightChild; // Assumption was wrong
    }
    if (arr[start] < arr[largerChild]){
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n);
    }
}

long long HeapSortCounting(int a[], int n) {
    long long cnt = 0;
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuild(index, a, n);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1){
        heapRebuild(0, a, heapSize);
        heapSize--;
        swap(a[0], a[heapSize]);
    }

    return cnt;
}

void merge(int arr[], int first, int mid, int last) {
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int tempArr[MAX_SIZE];
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2)){
        if (arr[first1] <= arr[first2])
            tempArr[index++] = arr[first1++];
        else 
            tempArr[index++] = arr[first2++]; 
    }
    while (first1 <= last1)
        tempArr[index++] = arr[first1++]; 
    while (first2 <= last2)
        tempArr[index++] = arr[first2++]; 
    for (index = first; index <= last; ++index)
        arr[index] = tempArr[index];
}

long long MergeSortCounting(int a[], int first, int last) {
    long long cnt = 0;
    if (first < last) {
        int mid = (first + last) / 2;
        MergeSort(a, first, mid);
        MergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }

    return cnt;
}

long long QuickSortCounting(int a[], int first, int last) {
    long long cnt = 0;
    int pivot = a[(first + last) / 2];
    int i = first, j = last;
    do {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);
    if (first < j) QuickSort(a, first, j);
    if (i < last) QuickSort(a, i, last);

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

long long FlashSortCounting(int a[], int n) { //https://github.com/leduythuccs
    long long cnt = 0;
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) m = 2;
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < a[i]) Mx = a[i];
        if (Mn > a[i]) Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    //step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(a[i]);
        while (i >= __L[k]) 
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }   
    //step 3
    for (int k = 1; k < m; ++k) {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (t > a[j + 1]) {a[j] = a[j + 1]; ++j;}
                a[j] = t;
            }
    }

    return cnt;
}