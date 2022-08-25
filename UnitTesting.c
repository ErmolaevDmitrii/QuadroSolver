/// @file
/// @brief Source file containing definitions of functions from UnitTesting.h

#include "UnitTesting.h"

int isEqual(double a, double b) {
    if(!CheckNumber(a) || !CheckNumber(b)) {
        assert(false);
        return SS_ERROR;
    }

    return abs(a - b) < SS_ZERO;
}

int GetExpectedAnswerFromFile(FILE* file, struct SquareAnswer* expectedAnswer) {
    if(file == NULL || expectedAnswer == NULL) {
        assert(false);
        return SS_ERROR;
    }

    int rootsCount = 0;
    int scanned = fscanf(file, "%d", &rootsCount);
    if(scanned == EOF || scanned != 1) {
        assert(false);
        return SS_ERROR;
    }

    double root1 = 0, root2 = 0;
    switch(rootsCount) {
        case 2:
            scanned = fscanf(file, "%lg%lg", &root1, &root2);
            if(scanned == EOF || scanned != 2) {
                assert(false);
                return SS_ERROR;
            }
            break;
        case 1:
            scanned = fscanf(file, "%lg", &root1);
            if(scanned == EOF || scanned != 1) {
                assert(false);
                return SS_ERROR;
            }
            break;
        default:
            break;
    }

    *expectedAnswer = {rootsCount, root1, root2};
    return 0;
}

int GetCoefficientsFromFile(FILE* file, double* a, double* b, double* c) {
    if(a == NULL || b == NULL || c == NULL) {
        assert(false);
        return SS_ERROR;
    }

    int scanned = fscanf(file, "%lg%lg%lg", a, b, c);
    if(scanned == EOF || scanned != 3) {
        assert(false);
        return SS_ERROR;
    }
    return 0;
}

int CompareAnswers(const struct SquareAnswer* answer1,
                   const struct SquareAnswer* answer2) {
    if(answer1 == NULL || answer2 == NULL) {
        assert(false);
        return SS_ERROR;
    }

    if(isEqual(answer1->root1, answer2->root1) == SS_ERROR ||
       isEqual(answer2->root2, answer2->root1) == SS_ERROR) {
        assert(false);
        return SS_ERROR;
    }

    return answer1->rootsCount == answer2->rootsCount &&
           isEqual(answer1->root1, answer2->root1)    &&
           isEqual(answer1->root2, answer2->root2);
}

int TakeOneTest(FILE*                          file,
                struct SquareAnswer*         answer,
                struct SquareAnswer* expectedAnswer) {
    if(file == NULL || answer == NULL || expectedAnswer == NULL) {
        assert(false);
        return SS_ERROR;
    }

    double a = 0, b = 0, c = 0;
    if(GetCoefficientsFromFile(file, &a, &b, &c) == SS_ERROR) {
        assert(false);
        return SS_ERROR;
    }

    SolveSquare(a, b, c, answer);

    if(GetExpectedAnswerFromFile(file, expectedAnswer) == SS_ERROR) {
        assert(false);
        return SS_ERROR;
    }

    return CompareAnswers(answer, expectedAnswer);
}

int UnitTestingSquare(const char* fileName) {
    if(fileName == NULL) {
        return SS_ERROR;
    }

    FILE* file = fopen(fileName, "r");
    if(file == NULL) {
        return SS_ERROR;
    }

    int N = 0, passedTests = 0, isErrorWhileTesting = 0;
    int scanned = fscanf(file, "%d", &N);
    if(scanned == EOF || scanned != 1) {
        return SS_ERROR;
    }

    for(int i = 1; i <= N; ++i) {
        SquareAnswer answer = { }, expectedAnswer = { };
        int testResult = TakeOneTest(file, &answer, &expectedAnswer);

        if(testResult == SS_ERROR) {
            printf("%sError occused while testing. Exiting...\n%s", RED, RESET);
            isErrorWhileTesting = 1;
            break;
        }

        if(!testResult) {
            printf("%s[%d] FAILED\n%s", RED, i, RESET);
            printf("Got: %d %lg %lg\n",               answer.rootsCount,
                                                           answer.root1,
                                                           answer.root2);
            printf("Expected: %d %lg %lg \n", expectedAnswer.rootsCount,
                                                   expectedAnswer.root1,
                                                   expectedAnswer.root2);
            continue;
        }
        printf("%s[%d] OK\n%s", GREEN, i, RESET);
        ++passedTests;
    }

    printf("%s %d/%d passed\n%s", GREEN, passedTests, N, RESET);
    scanned = fclose(file);
    if(scanned == EOF || isErrorWhileTesting) {
        return SS_ERROR;
    }
    return 0;
}
