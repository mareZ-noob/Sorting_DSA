#include <time.h>

#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "DataGenerator.h"
#include "Sort.h"
#include "Command.h"
#include "Sort_Couting.h"
#include "Sort_Time.h"

using namespace std;

template <class T>
void HoanVi(T &a, T &b) {
    T x = a;
    a = b;
    b = x;
}