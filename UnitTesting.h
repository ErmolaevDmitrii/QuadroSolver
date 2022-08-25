/// @file
/// @brief Header file containing functions for SquareSolve() function unit testing

#include <stdio.h>
#include <assert.h>
#include "SquareSolver.h"

/// identify if 2 double numbers are equal with SS_ZERO accurancy
/// @param [in] a first number
/// @param [in] b second number
int isEqual(double a, double b);

/// read 3 coefficients of square equation from file
/// @param [in] file a pointer to a FILE struct
/// @param [out] a a pointer to a coefficient
/// @param [out] b a pointer to b coefficient
/// @param [out] c a pointer to c coefficient
void GetCoefficientsFromFile(FILE* file, double* a, double* b, double* c);

/// read an expected answer of square equation from file
/// @param [in] file a pointer to a FILE struct
/// @param [out] expectedAnswer a pointer to SquareAnswer struct
void GetExpectedAnswerFromFile(FILE* file, struct SquareAnswer* expectedAnswer);

/// identify if 2 answers of square equations are equal
/// @param [in] answer1 a pointer to first SquareAnswer struct
/// @param [in] answer2 a pointer to second SquareAnswer struct
int CompareAnswers(struct SquareAnswer* answer1, struct SquareAnswer* answer2);

/// testing SolveSquare() function
/// @param [in] fileName a string containing name of file with tests
void UnitTestingSquare(const char* fileName);
