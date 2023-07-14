#include "Command.h"

int sortIndex(char *sortName) {
    if (strcmp(sortName, "selection-sort") == 0)
        return 0;
    else if (strcmp(sortName, "insertion-sort") == 0)
        return 1;
    else if (strcmp(sortName, "bubble-sort") == 0)
        return 2;
    else if (strcmp(sortName, "shaker-sort") == 0)
        return 3;
    else if (strcmp(sortName, "shell-sort") == 0)
        return 4;
    else if (strcmp(sortName, "heap-sort") == 0)
        return 5;
    else if (strcmp(sortName, "merge-sort") == 0)
        return 6;
    else if (strcmp(sortName, "quick-sort") == 0)
        return 7;
    else if (strcmp(sortName, "counting-sort") == 0)
        return 8;
    else if (strcmp(sortName, "radix-sort") == 0)
        return 9;
    else if (strcmp(sortName, "flash-sort") == 0)
        return 10;
    return 0;
}

int orderIndex(char *inputOrder) {
    if (strcmp(inputOrder, "-rand") == 0)
        return 0;
    else if (strcmp(inputOrder, "-nsorted") == 0)
        return 1;
    else if (strcmp(inputOrder, "sorted") == 0)
        return 2;
    else if (strcmp(inputOrder, "rev") == 0)
        return 3;
    return 0;
}

void Command1(char *sortName, char *inputFile, char *parameters) {
    ifstream ifs;
    ifs.open(inputFile);

    int n;
    ifs >> n;
    int a[n];
    for (int i = 0; i < n; i++) ifs >> a[i];

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << sortName << endl;
    cout << "Input file: " << inputFile << endl;
    cout << "Input size: " << n << endl;
    cout << "-------------------------" << endl;

    ifs.clear();
    ifs.seekg(0, ios::beg);

    cout << "Running time (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-time") == 0)
        cout << allSortTime(a, n, sortIndex(sortName));
    cout << endl;

    cout << "Comparisions (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-comp") == 0)
        cout << allSortCounting(a, n, sortIndex(sortName));
    cout << endl << endl;
    ifs.close();

    allSort(a, n, sortIndex(sortName));
    ofstream ofs;
    ofs.open("output.txt");
    ofs << n << endl;
    for (int i = 0; i < n; i++) ofs << a[i] << " ";

    ofs.close();
}

void Command2(char *sortName, char *sizeInput, char *inputOrder,
              char *parameters) {
    int n = atoi(sizeInput);
    int a[n];

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << sortName << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: " << inputOrder << endl;
    cout << "-------------------------" << endl;

    GenerateData(a, n, orderIndex(inputOrder));

    ofstream ofs;
    ofs.open("input.txt");
    ofs << n << endl;
    for (int i = 0; i < n; i++) ofs << a[i] << " ";
    ofs.close();

    ifstream ifs;
    ifs.open("input.txt");
    // for (int i = 0; i < n; i++) ifs >> a[i];

    cout << "Running time (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-time") == 0)
        cout << allSortTime(a, n, sortIndex(sortName));
    cout << endl;

    cout << "Comparisions (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-comp") == 0)
        cout << allSortCounting(a, n, sortIndex(sortName));
    cout << endl << endl;

    ifs.close();
}

void Command3(char *sortName, char *inputSize, char *parameters) {
    int n = atoi(inputSize);
    int a[n];

    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << sortName << endl;
    cout << "Input size: " << n << endl;
    cout << endl;

    ofstream ofs[4];

    char **file = new char *[5];
    for (int i = 0; i < 4; i++) {
        file[i] = new char[12];
        string fileName = "input_" + to_string(i + 1) + ".txt";
        strcpy(file[i], fileName.c_str());
    }

    for (int i = 0; i < 4; i++) {
        ofs[i].open(file[i]);
        cout << "Input order: ";

        if (i == 0)
            cout << "Randomize" << endl;
        else if (i == 1)
            cout << "Nearly Sorted" << endl;
        else if (i == 2)
            cout << "Sorted" << endl;
        else if (i == 3)
            cout << "Reversed" << endl;
        cout << "-------------------------" << endl;

        GenerateData(a, n, i);
        ofs[i] << n << endl;
        for (int j = 0; j < n; j++) ofs[i] << a[j] << " ";

        ifstream ifs(file[i]);
        int temp;
        ifs >> temp;
        int b[temp];
        for (int j = 0; j < n; j++) ifs >> b[j];

        cout << "Running time (if required): ";
        if (strcmp(parameters, "-both") == 0 ||
            strcmp(parameters, "-time") == 0)
            cout << allSortTime(b, temp, sortIndex(sortName));
        cout << endl;

        cout << "Comparisions (if required): ";
        if (strcmp(parameters, "-both") == 0 ||
            strcmp(parameters, "-comp") == 0)
            cout << allSortCounting(b, temp, sortIndex(sortName));
        cout << endl << endl;

        ifs.close();
        ofs[i].close();
    }
    cout << endl;
}

void Command4(char *sortName1, char *sortName2, char *inputFile) {
    cout << "COMPARISON MODE" << endl;
    cout << "Algorithm: " << sortName1 << " | " << sortName2 << endl;
    cout << "Input file: " << inputFile << endl;

    ifstream ifs;
    ifs.open(inputFile);
    int n;
    ifs >> n;
    int a[n];
    for (int i = 0; i < n; i++) ifs >> a[i];
    cout << "Running time: " << allSortTime(a, n, sortIndex(sortName1))
         << " seconds | ";
    cout << allSortTime(a, n, sortIndex(sortName2)) << " seconds" << endl;
    cout << endl;
    cout << "Comparisons: " << allSortCounting(a, n, sortIndex(sortName1))
         << " | ";
    cout << allSortCounting(a, n, sortIndex(sortName2)) << endl;

    allSort(a, n, sortIndex(sortName1));
    ofstream ofs;
    ofs.open("output.txt");
    ofs << n << endl;
    for (int i = 0; i < n; i++) ofs << a[i];

    ofs.close();
    ifs.close();
}

void Command5(char *sortName1, char *sortName2, char *inputSize,
              char *inputOrder) {
    int n = atoi(inputSize);
    int a[n];
    cout << "COMPARISON MODE\n";
    cout << "Algorithm: " << sortName1 << " | " << sortName2 << endl;
    cout << "Input size: " << inputSize << endl;
    cout << "Input order: " << inputOrder << endl;
    cout << "-------------------------" << endl;
    GenerateData(a, n, orderIndex(inputOrder));

    ofstream ofs;
    ofs.open("input.txt");
    ofs << n << endl;
    for (int i = 0; i < n; i++) ofs << a[i] << " ";
    ofs.close();

    ifstream ifs;
    ifs.open("input.txt");
    int temp;
    ifs >> temp;
    int b[temp];
    for (int i = 0; i < temp; i++) ifs >> b[i];

    cout << "Running time: " << allSortTime(b, temp, sortIndex(sortName1))
         << " seconds | ";
    cout << allSortTime(b, temp, sortIndex(sortName2)) << " seconds" << endl;
    cout << "Comparisons: " << allSortCounting(b, temp, sortIndex(sortName1))
         << " | ";
    cout << allSortCounting(b, temp, sortIndex(sortName2)) << endl;

    ifs.close();
}