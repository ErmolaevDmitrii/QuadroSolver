/// @file
/// @brief Source file containing definitions of functions from UnitTesting.h

#include "UnitTesting.h"

int isEqual(double a, double b) {
    if(!CheckNumber(a) || !CheckNumber(b)) {
        assert(false);
        return SS_ERROR_BAD_VALUE;
    }

    return abs(a - b) < SS_ZERO;
}

int GetExpectedAnswerFromFile(FILE* file, struct SquareAnswer* expectedAnswer) {
    if(file == NULL || expectedAnswer == NULL) {
        assert(false);
        return SS_ERROR_NULL_PTR;
    }

    int rootsCount = 0;
    int scanned = fscanf(file, "%d", &rootsCount);
    if(scanned == EOF) {
        return SS_ERROR_UNEXPECTED_EOF;
    }
    if(scanned != 1) {
        return SS_ERROR_FILE_WRONG_INPUT;
    }

    double root1 = 0, root2 = 0;
    switch(rootsCount) {
        case 2:
            scanned = fscanf(file, "%lg%lg", &root1, &root2);
            if(scanned == EOF) {
                return SS_ERROR_UNEXPECTED_EOF;
            }
            if(scanned != 2) {
                return SS_ERROR_FILE_WRONG_INPUT;
            }
            break;
        case 1:
            scanned = fscanf(file, "%lg", &root1);
            if(scanned == EOF) {
                return SS_ERROR_UNEXPECTED_EOF;
            }
            if(scanned != 1) {
                return SS_ERROR_FILE_WRONG_INPUT;
            }
            break;
        default:
            break;
    }

    *expectedAnswer = {rootsCount, root1, root2};
    return SS_ERROR_OK;
}

int GetCoefficientsFromFile(FILE* file, double* a, double* b, double* c) {
    if(a == NULL || b == NULL || c == NULL || file == NULL) {
        assert(false);
        return SS_ERROR_NULL_PTR;
    }

    int scanned = fscanf(file, "%lg%lg%lg", a, b, c);
    if(scanned == EOF) {
        assert(false);
        return SS_ERROR_UNEXPECTED_EOF;
    }
    if(scanned != 3) {
        assert(false);
        return SS_ERROR_FILE_WRONG_INPUT;
    }
    return SS_ERROR_OK;
}

int CompareAnswers(const struct SquareAnswer* answer1,
                   const struct SquareAnswer* answer2) {
    if(answer1 == NULL || answer2 == NULL) {
        assert(false);
        return SS_ERROR_NULL_PTR;
    }

    int returned1 = isEqual(answer1->root1, answer2->root1),
        returned2 = isEqual(answer1->root2, answer2->root2);
    if(isError(returned1)) {
        return returned1;
    }
    if(isError(returned2)) {
        return returned2;
    }

    return answer1->rootsCount == answer2->rootsCount && returned1 && returned2;
}

int TakeOneTest(FILE*                          file,
                struct SquareAnswer*         answer,
                struct SquareAnswer* expectedAnswer) {
    if(file == NULL || answer == NULL || expectedAnswer == NULL) {
        assert(false);
        return SS_ERROR_NULL_PTR;
    }

    double a = 0, b = 0, c = 0;
    int returned = GetCoefficientsFromFile(file, &a, &b, &c);
    if(isError(returned)) {
        assert(false);
        return returned;
    }

    SolveSquare(a, b, c, answer);

    returned = GetExpectedAnswerFromFile(file, expectedAnswer);
    if(isError(returned)) {
        assert(false);
        return returned;
    }

    return CompareAnswers(answer, expectedAnswer);
}

int UnitTestingSquare(const char* fileName) {
    if(fileName == NULL) {
        return SS_ERROR_NULL_PTR;
    }

    FILE* file = fopen(fileName, "r");
    if(file == NULL) {
        return SS_ERROR_FILE_NOT_OPENED;
    }

    int N = 0, passedTests = 0, ErrorWhileTesting = 0;
    int scanned = fscanf(file, "%d", &N);
    if(scanned == EOF) {
        return SS_ERROR_UNEXPECTED_EOF;
    }
    if(scanned != 1) {
        return SS_ERROR_FILE_WRONG_INPUT;
    }

    for(int i = 1; i <= N; ++i) {
        SquareAnswer answer = { }, expectedAnswer = { };
        int testResult = TakeOneTest(file, &answer, &expectedAnswer);

        if(isError(testResult)) {
            printf("%sError occused while testing. Exiting...\n%s", RED, RESET);
            ErrorWhileTesting = testResult;
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
    if(scanned == EOF) {
        return SS_ERROR_FILE_NOT_CLOSED;
    }
    if(isError(ErrorWhileTesting)) {
        return ErrorWhileTesting;
    }
    return SS_ERROR_OK;
}
