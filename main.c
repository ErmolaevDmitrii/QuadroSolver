/// @file
/// @brief Source file containing main function

#include <stdio.h>
#include "Colors.h"
#include "SquareSolver.h"

int main() {
    double a = 0, b = 0, c = 0;
    int returned = GetCoefficientsSquare(&a, &b, &c);
    if(isError(returned)) {
        printf("\n%sEOF в вводе, выход\n%s", RED, RESET);
        return 0;
    }

    struct SquareAnswer answer = {};
    SolveSquare(a, b, c, &answer);
    PrintAnswerSquare(&answer);

    return 0;
}
