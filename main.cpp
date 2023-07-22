#include "main.h"

int main(int argc, char** argv) {
    if (argc == 5) {
        if (strcmp(argv[1], "-a") == 0) {
            if (isalpha(argv[3][0])) {
                Command1(argv[2], argv[3], argv[4]);
            } else {
                Command3(argv[2], argv[3], argv[4]);
            }
        } else if (strcmp(argv[1], "-c") == 0) {
            Command4(argv[2], argv[3], argv[4]);
        } else {
            std::cerr << "Invalid arguments !"
                      << "\n";
        }
    } else if (argc == 6) {
        if (strcmp(argv[1], "-a") == 0) {
            Command2(argv[2], argv[3], argv[4], argv[5]);
        } else if (strcmp(argv[1], "-c") == 0) {
            Command5(argv[2], argv[3], argv[4], argv[5]);
        } else {
            std::cerr << "Invalid arguments !"
                      << "\n";
        }
    } else {
        std::cerr << "Invalid arguments !"
                  << "\n";
    }

    return 0;
}
