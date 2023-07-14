#include "Command.h"

void ifRequired() {}

void Command1(char *sortName, char *inputFile, char *parameters) {
    //
    //
}

void Command2(char *sortName, char *sizeInput, char *inputOrder,
              char *parameters) {
    //
    //
}

void Command3(char *sortName, char *inputSize, char *parameters) {
    int _size = atoi(inputSize);
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << sortName << endl;
    cout << "Input size: " << _size << endl;
    cout << endl;

    int *arr = new int[_size];
    ofstream *ofs = new ofstream[4];
    char **file = new char *[4];

    for (int i = 0; i < 4; i++) {
        file[i] = new char[11];
        string fileName = "input_" + to_string(i + 1) + ".txt";
        strcpy(file[i], fileName.c_str());
    }
    for (int i = 0; i < 4; i++) ofs[i].open(file[i]);

    for (int i = 0; i < 4; i++) {
        cout << "Input order: ";

        if (i == 0)
            cout << "Randomize" << endl;
        else if (i == 1)
            cout << " Nearly Sorted" << endl;
        else if (i == 2)
            cout << "Sorted" << endl;
        else if (i == 3)
            cout << "Reversed" << endl;

        cout << "-------------------------" << endl;
    }
}

void Command4(char *sortName1, char *sortName2, char *inputFile) {
    //
    //
}

void Command5(char *sortName1, char *sortName2, char *inputSize,
              char *inputOrder) {
    //
    //
}