/// @file
/// @brief Source file containing main function (for unit testing)

#include "UnitTesting.h"
#include <string.h>

int main(int argc, char* argv[]) {
    char testsFileName[256] = "tests.txt";
    if(argc > 1) {
        strcpy(testsFileName, argv[1]);
    }
    UnitTestingSquare(testsFileName);
    return 0;
}
