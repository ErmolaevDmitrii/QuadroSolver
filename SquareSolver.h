#include <math.h>
#include <cassert>

#define SS_ZERO 10e-9
#define SS_INF_NUMBER_OF_ROOTS -1

struct SquareAnswer {
    int rootsCount;
    double root1, root2;
};

bool isZero(double);

void SolveSquare(double a, double b, double c, SquareAnswer* answer);
