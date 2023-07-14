#include "Sort_Counting.h"

// O(n*n)
long long SelectionSortCounting(int a[], int n) {
    long long cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        int minId = i;
        for (int j = i + 1; j < n; j++) {
            if (++cnt && a[j] < a[minId]) minId = j;
        }
        swap(a[i], a[minId]);
    }

    return cnt;
}

long long InsertionSortCounting(int a[], int n) {
    long long cnt = 0;

    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (++cnt && j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    return cnt;
}

long long BubbleSortCounting(int a[], int n) {
    long long cnt = 0;

    for (int pass = 1; pass < n; ++pass) {
        for (int j = 0; j < n - pass; ++j) {
            if (++cnt && a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }

    return cnt;
}

long long ShakerSortCounting(int a[], int n) {
    long long cnt = 0;
    int left = 1, right = n - 1, k = n - 1;
    do {
        for (int j = right; j >= left; --j) {
            if (++cnt && a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                k = j;
            }
        }
        left = k + 1;
        for (int j = left; j <= right; ++j) {
            if (++cnt && a[j - 1] > a[j]) {
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
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = a[i];
            int j;
            for (j = i; ++cnt && j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }

    return cnt;
}

void heapRebuildCounting(int start, int arr[], int n, long long &cnt) {
    int leftChild = 2 * start + 1;
    if (leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n) {
        if (++cnt && arr[rightChild] > arr[largerChild])
            largerChild = rightChild;  // Assumption was wrong
    }
    if (++cnt && arr[start] < arr[largerChild]) {
        swap(arr[largerChild], arr[start]);
        heapRebuildCounting(largerChild, arr, n, cnt);
    }
}

long long HeapSortCounting(int a[], int n) {
    long long cnt = 0;
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuildCounting(index, a, n, cnt);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1) {
        heapRebuildCounting(0, a, heapSize, cnt);
        heapSize--;
        swap(a[0], a[heapSize]);
    }

    return cnt;
}

void mergeCounting(int arr[], int first, int mid, int last, long long &cnt) {
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int tempArr[INT_MAX];
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2)) {
        if (++cnt && arr[first1] <= arr[first2])
            tempArr[index++] = arr[first1++];
        else
            tempArr[index++] = arr[first2++];
    }
    while (first1 <= last1) tempArr[index++] = arr[first1++];
    while (first2 <= last2) tempArr[index++] = arr[first2++];
    for (index = first; index <= last; ++index) arr[index] = tempArr[index];
}

long long MergeSortCounting(int a[], int first, int last) {
    long long cnt = 0;

    if (first < last) {
        int mid = (first + last) / 2;
        MergeSortCounting(a, first, mid);
        MergeSortCounting(a, mid + 1, last);
        mergeCounting(a, first, mid, last, cnt);
    }

    return cnt;
}

long long QuickSortCounting(int a[], int first, int last) {
    long long cnt = 0;
    int pivot = a[(first + last) / 2];
    int i = first, j = last;
    do {
        while (++cnt && a[i] < pivot) i++;
        while (++cnt && a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (first < j) QuickSortCounting(a, first, j);
    if (i < last) QuickSortCounting(a, i, last);

    return cnt;
}

// O(n)
long long CountingSortCounting(int a[], int n, int u) {
    long long cnt = 0;

    int *f = new int[u + 1]{0};
    for (int i = 0; i < n; i++) f[a[i]]++;
    for (int i = 1; i <= u; i++) f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }
    for (int i = 0; i < n; i++) a[i] = b[i];

    delete[] b;
    delete[] f;
    return cnt;
}

long long RadixSortCounting(int a[], int n) {
    long long cnt = 0;

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

    return cnt;
}

long long FlashSortCounting(int a[], int n) {
    long long cnt = 0;

    int minVal = a[0];
    int maxIdx = 0;
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; ++cnt && i < m; i++) {
        l[i] = 0;
    }

    for (int i = 1; ++cnt && i < n; i++) {
        if (++cnt && a[i] < minVal) {
            minVal = a[i];
        }
        if (++cnt && a[i] > a[maxIdx]) {
            maxIdx = i;
        }
    }

    if (++cnt && a[maxIdx] == minVal) {
        return cnt;
    }

    double c1 = 1.00 * (m - 1) / (a[maxIdx] - minVal);

    for (int i = 0; ++cnt && i < n; i++) {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }

    for (int i = 1; ++cnt && i < m; i++) {
        l[i] += l[i - 1];
    }

    swap(a[maxIdx], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (++cnt && nmove < n - 1) {
        while (++cnt && j > l[k] - 1) {
            j++;
            k = int(c1 * (a[j] - minVal));
        }

        flash = a[j];

        if (++cnt && k < 0) {
            break;
        }

        while (++cnt && j != l[k]) {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];

            a[t] = flash;
            flash = hold;

            ++nmove;
        }
    }
    delete[] l;
    cnt += InsertionSortCounting(a, n);

    return cnt;
}

long long allSortCounting(int a[], int n, int sortIndex) {
    if (sortIndex == 0)
        return SelectionSortCounting(a, n);
    else if (sortIndex == 1)
        return InsertionSortCounting(a, n);
    else if (sortIndex == 2)
        return BubbleSortCounting(a, n);
    else if (sortIndex == 3)
        return ShakerSortCounting(a, n);
    else if (sortIndex == 4)
        return ShellSortCounting(a, n);
    else if (sortIndex == 5)
        return HeapSortCounting(a, n);
    else if (sortIndex == 6)
        return MergeSortCounting(a, 0, n - 1);
    else if (sortIndex == 7)
        return QuickSortCounting(a, 0, n - 1);
    else if (sortIndex == 8)
        return CountingSortCounting(a, n, INT_MAX);
    else if (sortIndex == 9)
        return RadixSortCounting(a, n);
    else if (sortIndex == 10)
        return FlashSortCounting(a, n);
    return 0;
}