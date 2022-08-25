/// @file
/// @brief Source file containing definitions of functions from UnitTesting.h

#include "UnitTesting.h"

int isEqual(double a, double b) {
    assert(!isinf(a));
    assert(!isinf(b));

    return abs(a - b) < SS_ZERO;
}

void GetExpectedAnswerFromFile(FILE* file, struct SquareAnswer* expectedAnswer) {
    assert(file);
    assert(expectedAnswer);

    int rootsCount = 0;
    fscanf(file, "%d", &rootsCount);

    double root1 = 0, root2 = 0;
    switch(rootsCount) {
        case 2:
            fscanf(file, "%lg%lg", &root1, &root2);
            break;
        case 1:
            fscanf(file, "%lg", &root1);
            break;
        default:
            break;
    }

    *expectedAnswer = {rootsCount, root1, root2};
    return;
}

void GetCoefficientsFromFile(FILE* file, double* a, double* b, double* c) {
    assert(a);
    assert(b);
    assert(c);

    fscanf(file, "%lg%lg%lg", a, b, c);
    return;
}

int CompareAnswers(struct SquareAnswer* answer1, struct SquareAnswer* answer2) {
    assert(answer1);
    assert(answer2);

    return answer1->rootsCount == answer2->rootsCount &&
           isEqual(answer1->root1, answer2->root1)    &&
           isEqual(answer1->root2, answer2->root2);
}

void UnitTestingSquare(const char* fileName) {
    assert(fileName);

    FILE* file = fopen(fileName, "r");
    assert(file);

    int N = 0;
    fscanf(file, "%d", &N);

    for(int i = 1; i <= N; ++i) {
        double a = 0, b = 0, c = 0;
        GetCoefficientsFromFile(file, &a, &b, &c);

        SquareAnswer answer = { };
        SolveSquare(a, b, c, &answer);

        SquareAnswer expectedAnswer = { };
        GetExpectedAnswerFromFile(file, &expectedAnswer);

        if(!CompareAnswers(&answer, &expectedAnswer)) {
            printf("[%d] Error\n", i);
            continue;
        }
        printf("[%d] OK\n", i);
    }
    fclose(file);
    return;
}
