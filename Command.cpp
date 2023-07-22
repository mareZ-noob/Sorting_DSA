#include "Command.h"

string displayName(char *sortName) {
    if (strcmp(sortName, "selection-sort") == 0)
        return "Selection Sort";
    else if (strcmp(sortName, "insertion-sort") == 0)
        return "Insertion Sort";
    else if (strcmp(sortName, "bubble-sort") == 0)
        return "Bubble Sort";
    else if (strcmp(sortName, "shaker-sort") == 0)
        return "Shaker Sort";
    else if (strcmp(sortName, "shell-sort") == 0)
        return "Shell Sort";
    else if (strcmp(sortName, "heap-sort") == 0)
        return "Heap Sort";
    else if (strcmp(sortName, "merge-sort") == 0)
        return "Merge Sort";
    else if (strcmp(sortName, "quick-sort") == 0)
        return "Quick Sort";
    else if (strcmp(sortName, "counting-sort") == 0)
        return "Counting Sort";
    else if (strcmp(sortName, "radix-sort") == 0)
        return "Radix Sort";
    else if (strcmp(sortName, "flash-sort") == 0)
        return "Flash Sort";
    return "Invalid Algorithm";
}

string displayOrder(char *inputOrder) {
    if (strcmp(inputOrder, "-rand") == 0)
        return "Randomized";
    else if (strcmp(inputOrder, "-nsorted") == 0)
        return "Nearly Sorted";
    else if (strcmp(inputOrder, "-sorted") == 0)
        return "Sorted";
    else if (strcmp(inputOrder, "-rev") == 0)
        return "Reversed";
    return "Invalid Input Order";
}

int sortIndex(char *sortName) {
    int index;
    if (strcmp(sortName, "selection-sort") == 0)
        index = 0;
    else if (strcmp(sortName, "insertion-sort") == 0)
        index = 1;
    else if (strcmp(sortName, "bubble-sort") == 0)
        index = 2;
    else if (strcmp(sortName, "shaker-sort") == 0)
        index = 3;
    else if (strcmp(sortName, "shell-sort") == 0)
        index = 4;
    else if (strcmp(sortName, "heap-sort") == 0)
        index = 5;
    else if (strcmp(sortName, "merge-sort") == 0)
        index = 6;
    else if (strcmp(sortName, "quick-sort") == 0)
        index = 7;
    else if (strcmp(sortName, "counting-sort") == 0)
        index = 8;
    else if (strcmp(sortName, "radix-sort") == 0)
        index = 9;
    else if (strcmp(sortName, "flash-sort") == 0)
        index = 10;
    return index;
}

int orderIndex(char *inputOrder) {
    int order;
    if (strcmp(inputOrder, "-rand") == 0)
        order = 0;
    else if (strcmp(inputOrder, "-nsorted") == 0)
        order = 1;
    else if (strcmp(inputOrder, "-sorted") == 0)
        order = 2;
    else if (strcmp(inputOrder, "-rev") == 0)
        order = 3;
    return order;
}

void Command1(char *sortName, char *inputFile, char *parameters) {
    ifstream ifs;
    ifs.open(inputFile);

    int n;
    ifs >> n;
    int a[n];
    for (int i = 0; i < n; i++) ifs >> a[i];

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << displayName(sortName) << "\n";
    std::cout << "Input file: " << inputFile << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "-------------------------"
              << "\n";

    int b[n];
    for (int i = 0; i < n; i++) b[i] = a[i];

    std::cout << "Running time (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-time") == 0)
        std::cout << allSortTime(a, n, sortIndex(sortName)) << " second(s)";
    std::cout << "\n";

    std::cout << "Comparisions (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-comp") == 0)
        std::cout << allSortCounting(b, n, sortIndex(sortName));
    std::cout << "\n\n\n";
    ifs.close();

    allSort(a, n, sortIndex(sortName));
    ofstream ofs;
    ofs.open("output.txt");
    ofs << n << "\n";
    for (int i = 0; i < n; i++) ofs << a[i] << " ";

    ofs.close();
}

void Command2(char *sortName, char *sizeInput, char *inputOrder,
              char *parameters) {
    int n = atoi(sizeInput);
    int a[n];

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << displayName(sortName) << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "Input order: " << displayOrder(inputOrder) << "\n";
    std::cout << "-------------------------"
              << "\n";

    GenerateData(a, n, orderIndex(inputOrder));

    ofstream ofs;
    ofs.open("input.txt");
    ofs << n << "\n";
    for (int i = 0; i < n; i++) ofs << a[i] << " ";
    ofs.close();

    int b[n];
    for (int i = 0; i < n; i++) b[i] = a[i];

    std::cout << "Running time (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-time") == 0)
        std::cout << allSortTime(a, n, sortIndex(sortName)) << " second(s)";
    std::cout << "\n";

    std::cout << "Comparisions (if required): ";
    if (strcmp(parameters, "-both") == 0 || strcmp(parameters, "-comp") == 0)
        std::cout << allSortCounting(b, n, sortIndex(sortName));
    std::cout << "\n\n\n";
}

void Command3(char *sortName, char *inputSize, char *parameters) {
    int n = atoi(inputSize);

    std::cout << "ALGORITHM MODE"
              << "\n";
    std::cout << "Algorithm: " << displayName(sortName) << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "\n";

    ofstream ofs[4];

    char **file = new char *[5];
    for (int i = 0; i < 4; i++) {
        file[i] = new char[12];
        string fileName = "input_" + to_string(i + 1) + ".txt";
        strcpy(file[i], fileName.c_str());
    }

    for (int i = 0; i < 4; i++) {
        ofs[i].open(file[i]);
        std::cout << "Input order: ";

        if (i == 0)
            std::cout << "Randomized"
                      << "\n";
        else if (i == 1)
            std::cout << "Nearly Sorted"
                      << "\n";
        else if (i == 2)
            std::cout << "Sorted"
                      << "\n";
        else if (i == 3)
            std::cout << "Reversed"
                      << "\n";
        std::cout << "-------------------------"
                  << "\n";

        int a[n];
        GenerateData(a, n, i);
        ofs[i] << n << "\n";
        for (int j = 0; j < n; j++) ofs[i] << a[j] << " ";

        int b[n];
        for (int j = 0; j < n; j++) b[j] = a[j];

        std::cout << "Running time (if required): ";
        if (strcmp(parameters, "-both") == 0 ||
            strcmp(parameters, "-time") == 0)
            std::cout << allSortTime(a, n, sortIndex(sortName)) << " second(s)";
        std::cout << "\n";

        std::cout << "Comparisions (if required): ";
        if (strcmp(parameters, "-both") == 0 ||
            strcmp(parameters, "-comp") == 0)
            std::cout << allSortCounting(b, n, sortIndex(sortName));
        std::cout << "\n\n";

        ofs[i].close();
    }
    for (int i = 0; i < 4; i++) delete[] file[i];
    delete[] file;

    std::cout << "\n";
}

void Command4(char *sortName1, char *sortName2, char *inputFile) {
    ifstream ifs;
    ifs.open(inputFile);
    int n;
    ifs >> n;
    std::cout << "COMPARE MODE"
              << "\n";
    std::cout << "Algorithm: " << displayName(sortName1) << " | "
              << displayName(sortName2) << "\n";
    std::cout << "Input file: " << inputFile << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "-------------------------"
              << "\n";

    int a[n];
    for (int i = 0; i < n; i++) ifs >> a[i];

    int b[n], c[n], d[n];
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    std::cout << "Running time: " << allSortTime(a, n, sortIndex(sortName1))
              << " second(s) | ";
    std::cout << allSortTime(b, n, sortIndex(sortName2)) << " second(s)"
              << "\n";
    std::cout << "Comparisions: " << allSortCounting(c, n, sortIndex(sortName1))
              << " | ";
    std::cout << allSortCounting(d, n, sortIndex(sortName2)) << "\n"
              << "\n";
    ifs.close();

    allSort(a, n, sortIndex(sortName1));
    ofstream ofs;
    ofs.open("output.txt");
    ofs << n << "\n";
    for (int i = 0; i < n; i++) ofs << a[i] << " ";

    ofs.close();
}

void Command5(char *sortName1, char *sortName2, char *inputSize,
              char *inputOrder) {
    int n = atoi(inputSize);
    int a[n];
    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << displayName(sortName1) << " | "
              << displayName(sortName2) << "\n";
    std::cout << "Input size: " << inputSize << "\n";
    std::cout << "Input order: " << displayOrder(inputOrder) << "\n";
    std::cout << "-------------------------"
              << "\n";
    GenerateData(a, n, orderIndex(inputOrder));

    ofstream ofs;
    ofs.open("input.txt");
    ofs << n << "\n";
    for (int i = 0; i < n; i++) ofs << a[i] << " ";
    ofs.close();

    int b[n], c[n], d[n];
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    std::cout << "Running time: " << allSortTime(a, n, sortIndex(sortName1))
              << " second(s) | ";
    std::cout << allSortTime(b, n, sortIndex(sortName2)) << " second(s)"
              << "\n";
    std::cout << "Comparisions: " << allSortCounting(c, n, sortIndex(sortName1))
              << " | ";
    std::cout << allSortCounting(d, n, sortIndex(sortName2)) << "\n\n";
}