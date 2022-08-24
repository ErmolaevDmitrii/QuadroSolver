/// @file
/// @brief Source file containing main function

#include <stdio.h>
#include "SquareSolver.h"

int main() {
    double a = 0, b = 0, c = 0;
    GetCoefficientsSquare(&a, &b, &c);

    struct SquareAnswer answer = {};
    SolveSquare(a, b, c, &answer);
    PrintAnswerSquare(&answer);

    return 0;
}
