#include "Sort_Time.h"

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
