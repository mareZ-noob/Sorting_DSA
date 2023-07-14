#include "Sort_Time.h"
#define MAX_SIZE 1000
int __L[300000];

double SelectionSortTime(int a[], int n){
    clock_t start = clock();
    for(int i = 0; i < n - 1; i++){
		int minId = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[minId])
				minId = j;
		}
		swap(a[i], a[minId]);
	}
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC; 
}

double InsertionSortTime(int a[], int n) {
    clock_t start = clock();
    for (int i = 1; i < n; ++i){
        int key = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC; 
}

double BubbleSortTime(int a[], int n) {
    clock_t start = clock();
    for (int pass = 1; pass < n; ++pass){
        for (int j = 0; j < n - pass; ++j){
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC; 
}

double ShakerSortTime(int a[], int n) {
    clock_t start = clock();
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
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC; 
}

// O(nlogn)
double ShellSortTime(int a[], int n) {
    clock_t start = clock();
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = a[i];
            int j;            
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
              
            a[j] = temp;
        }
    }
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC; 
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

double HeapSortTime(int a[], int n) {
    clock_t start = clock();
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuild(index, a, n);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1){
        heapRebuild(0, a, heapSize);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
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

double MergeSortTime(int a[], int first, int last) {
    clock_t start = clock();
    if (first < last) {
        int mid = (first + last) / 2;
        MergeSort(a, first, mid);
        MergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double QuickSortTime(int a[], int first, int last) {
    clock_t start = clock();
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
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

// O(n)
double CountingSortTime(int a[], int n, int u) { // u is the maximum value
    clock_t start = clock();
    int *f = new int[u+1] {0};
    for (int i = 0; i < n; i++)
        f[a[i]] ++;
    for (int i = 1; i <= u; i++)
        f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--) { 
        b[f[a[i]]-1] = a[i];
        f[a[i]]--; 
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete []b;
    delete []f;
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double RadixSortTime(int a[], int n) {
    clock_t start = clock();
    int max_val = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max_val) max_val = a[i];
    int digits = 0, div;
    do{
        digits++;
        div = max_val / pow(10, digits);
    } while (div > 0);
    int *tempArr[10];
    for (int i = 0; i < 10; ++i)
        tempArr[i] = new int[n];
    int tempCount[10];

    for (int i = 0; i < digits ; ++i) {
        int exp = pow(10, i);
        for (int j = 0; j < 10; ++j)
            tempCount[j] = 0;
        for (int j = 0; j < n; ++j) {
            int idx = (a[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = a[j];
        }
        int idx = 0;
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k)
                a[idx++] = tempArr[j][k];
    }
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}

double FlashSortTime(int a[], int n) { //https://github.com/leduythuccs
    clock_t start = clock();
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
    clock_t stop = clock();
    return double(stop - start) / CLOCKS_PER_SEC;
}