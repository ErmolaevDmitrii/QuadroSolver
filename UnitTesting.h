#include <stdio.h>
#include <assert.h>
#include "SquareSolver.h"

int isEqual(double a, double b);
void GetCoefficientsFromFile(FILE* file, double* a, double* b, double* c);
void GetExpectedAnswerFromFile(FILE* file, struct SquareAnswer* expectedAnswer);
int CompareAnswers(struct SquareAnswer* answer1, struct SquareAnswer* answer2);
void UnitTestingSquare(const char* fileName);
