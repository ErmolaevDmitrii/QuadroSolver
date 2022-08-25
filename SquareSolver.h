/// @file
/// @brief Header file with structs and functions for solving square equations

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// threshold value for isZero function
const double SS_ZERO = 10e-9;
/// index for infinite count of roots
const int SS_INF_NUMBER_OF_ROOTS = -1;
/// index for error occused while calculating square equation
const int SS_ERROR = -2;

/// struct containing answer of some square equation
struct SquareAnswer {
    /// count of roots
    int rootsCount;
    /// variable for first root
    double root1;
    /// variable for second root
    double root2;
};

/// check if number is correct or NaN/inf
/// @param [in] a value to check
/// @return 1 or 0 if it's correct or not
int CheckNumber(double a);

/// identify if value is small enough to being zero
/// @param [in] a value to identify if it's zero
/// @return SS_ERROR if input value isn't correct, 1 or 0 if value is 0 or not
int isZero(double a);

/// clean terminal buffer
void CleanTerminalBuffer();

/// get coefficients of square equation from terminal
/// @param [out] a a pointer to a coefficient
/// @param [out] b a pointer to b coefficient
/// @param [out] c a pointer to c coefficient
/// @return SS_ERROR if input values aren't correct, 0 if there are no problems
int GetCoefficientsSquare(double* a, double* b, double* c);

/// Solve linear equations of form "kx + b = 0"
/// @param [in] a a k coefficient
/// @param [in] b a b coefficient
/// @param [out] answer a pointer to SquareAnswer struct
void SolveLinear(double a, double b, struct SquareAnswer* answer);

/// Solve square equations of form "a*x^2 + bx + c = 0"
/// @param [in] a an a coefficient
/// @param [in] b a b coefficient
/// @param [in] c a c coefficient
/// @param [out] answer a pointer to SquareAnswer struct
void SolveSquare(double a, double b, double c, struct SquareAnswer* answer);

/// Print answer for square equation in terminal
/// @param [in] answer a pointer to SquareAnswer struct
/// @return SS_ERROR if input value isn't correct, 0 if there are no problems
int PrintAnswerSquare(const struct SquareAnswer* answer);
