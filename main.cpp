#include "main.h"

int main(int argc, char** argv) {
    if (argc == 5) {
        if (strcmp(argv[1], "-a") == 0)
            if (isalpha(argv[3][0]))
                cout << "command 3";
            else
                cout << "command 1";
        else if (strcmp(argv[1], "-c") == 0)
            cout << "command 4";
        else if (argc == 6)
            if (strcmp(argv[1], "-a") == 0)
                cout << "command 2";
            else if (strcmp(argv[1], "-c") == 0)
                cout << "command 5";

        return 0;
    }
