/// @file
/// @brief Header file containing functions for SquareSolve() function unit testing

#include <stdio.h>
#include <assert.h>
#include "SquareSolver.h"
#include "Colors.h"

/// identify if 2 double numbers are equal with SS_ZERO accurancy
/// @param [in] a first number
/// @param [in] b second number
/// @return SS_ERROR if input values aren't correct, 1 or 0 if numbers equal or not
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
/// @return SS_ERROR if input values aren't correct, 1 or 0 if answers equal or not
int CompareAnswers(const struct SquareAnswer* answer1,
                   const struct SquareAnswer* answer2);

/// take one SolveSquare() test
/// @param [in] file a pointer to a FILE struct
/// @param [out] answer a pointer to SquareAnswer struct
/// @param [out] expectedAnswer a pointer to SquareAnswer struct
/// @return SS_ERROR if something failed, 1 or 0 if test passed or not
int TakeOneTest(FILE*                           file,
                struct SquareAnswer*          answer,
                struct SquareAnswer* expectedAnswer);

/// testing SolveSquare() function
/// @param [in] fileName a string containing name of file with tests
void UnitTestingSquare(const char* fileName);
