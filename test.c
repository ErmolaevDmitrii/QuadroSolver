/// @file
/// @brief Source file containing main function (for unit testing)

#include "UnitTesting.h"
#include <string.h>

int main(int argc, char* argv[]) {
    char testsFileName[256] = "tests.txt";
    if(argc > 1) {
        strncpy(testsFileName, argv[1], 256);
    }
    int returned = UnitTestingSquare(testsFileName);
    if(returned == SS_ERROR) {
        printf("%sTesting ended with errors\n%s", RED, RESET);
    }
    return 0;
}
