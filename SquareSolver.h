/// @file
/// @brief Header file with structs and functions for solving square equations#include <math.h>

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

/// identify if value is small enough to being zero
/// @param [in] a value to identify if it's zero
bool isZero(double a);

/// clean terminal buffer
void CleanTerminalBuffer();

/// get coefficients of square equation from terminal
/// @param [out] a an a coefficient
/// @param [out] b a b coefficient
/// @param [out] c a c coefficient
void GetCoefficientsSquare(double* a, double* b, double* c);

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
void PrintAnswerSquare(struct SquareAnswer* answer);
