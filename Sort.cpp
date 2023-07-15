#include "Sort.h"

// O(n^2)
void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        swap(a[minIdx], a[i]);
    }
}

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void BubbleSort(int a[], int n) {
    for (int pass = 1; pass < n; ++pass) {
        for (int j = 0; j < n - pass; ++j) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void ShakerSort(int a[], int n) {
    int left = 1, right = n - 1, k = n - 1;
    do {
        for (int j = right; j >= left; --j) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                k = j;
            }
        }
        left = k + 1;
        for (int j = left; j <= right; ++j) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                k = j;
            }
        }
        right = k - 1;
    } while (left <= right);
}

// O(nlogn)
void ShellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

void heapRebuild(int start, int arr[], int n) {
    int leftChild = 2 * start + 1;
    if (leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n) {
        if (arr[rightChild] > arr[largerChild])
            largerChild = rightChild;  // Assumption was wrong
    }
    if (arr[start] < arr[largerChild]) {
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n);
    }
}

void HeapSort(int a[], int n) {
    for (int index = (n - 1) / 2; index >= 0; index--) heapRebuild(index, a, n);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1) {
        heapRebuild(0, a, heapSize);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
}

void merge(int arr[], int first, int mid, int last) {
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int tempArr[500001];
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2)) {
        if (arr[first1] <= arr[first2])
            tempArr[index++] = arr[first1++];
        else
            tempArr[index++] = arr[first2++];
    }
    while (first1 <= last1) tempArr[index++] = arr[first1++];
    while (first2 <= last2) tempArr[index++] = arr[first2++];
    for (index = first; index <= last; ++index) arr[index] = tempArr[index];
}

void MergeSort(int a[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        MergeSort(a, first, mid);
        MergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

void QuickSort(int a[], int first, int last) {
    int pivot = a[(first + last) / 2];
    int i = first, j = last;
    do {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (first < j) QuickSort(a, first, j);
    if (i < last) QuickSort(a, i, last);
}

// O(n)
void CountingSort(int a[], int n, int u) {  // u is the maximum value
    int *f = new int[u + 1]{0};
    for (int i = 0; i < n; i++) f[a[i]]++;
    for (int i = 1; i <= u; i++) f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }
    for (int i = 0; i < n; i++) a[i] = b[i];
}

void RadixSort(int a[], int n) {
    int max_val = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max_val) max_val = a[i];
    int digits = 0, div;
    do {
        digits++;
        div = max_val / pow(10, digits);
    } while (div > 0);
    int *tempArr[10];
    for (int i = 0; i < 10; ++i) tempArr[i] = new int[n];
    int tempCount[10];

    for (int i = 0; i < digits; ++i) {
        int exp = pow(10, i);
        for (int j = 0; j < 10; ++j) tempCount[j] = 0;
        for (int j = 0; j < n; ++j) {
            int idx = (a[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = a[j];
        }
        int idx = 0;
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k) a[idx++] = tempArr[j][k];
    }
}

void FlashSort(int a[], int n) {
    int minVal = a[0];
    int maxIdx = 0;
    int m = int(0.43 * n);
    int *l = new int[m];
    for (int i = 0; i < m; i++) {
        l[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i];
        }
        if (a[i] > a[maxIdx]) {
            maxIdx = i;
        }
    }

    if (a[maxIdx] == minVal) {
        return;
    }

    double c1 = 1.00 * (m - 1) / (a[maxIdx] - minVal);

    for (int i = 0; i < n; i++) {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }

    for (int i = 1; i < m; i++) {
        l[i] += l[i - 1];
    }

    swap(a[maxIdx], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (nmove < n - 1) {
        while (j > l[k] - 1) {
            j++;
            k = int(c1 * (a[j] - minVal));
        }

        flash = a[j];

        if (k < 0) {
            break;
        }

        while (j != l[k]) {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];

            a[t] = flash;
            flash = hold;

            ++nmove;
        }
    }
    delete[] l;
    InsertionSort(a, n);
}

void allSort(int a[], int n, int sortIndex) {
    if (sortIndex == 0)
        SelectionSort(a, n);
    else if (sortIndex == 1)
        InsertionSort(a, n);
    else if (sortIndex == 2)
        BubbleSort(a, n);
    else if (sortIndex == 3)
        ShakerSort(a, n);
    else if (sortIndex == 4)
        ShellSort(a, n);
    else if (sortIndex == 5)
        HeapSort(a, n);
    else if (sortIndex == 6)
        MergeSort(a, 0, n - 1);
    else if (sortIndex == 7)
        QuickSort(a, 0, n - 1);
    else if (sortIndex == 8)
        CountingSort(a, n, 1000001);
    else if (sortIndex == 9)
        RadixSort(a, n);
    else if (sortIndex == 10)
        FlashSort(a, n);
}