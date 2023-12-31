#ifndef _DATAGENERATOR_H_
#define _DATAGENERATOR_H_

#include "main.h"

template <class T>
void HoanVi(T &a, T &b) {
    T x = a;
    a = b;
    b = x;
}
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif  // _DATAGENERATOR_H_