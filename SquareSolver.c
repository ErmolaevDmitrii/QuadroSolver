#include "SquareSolver.h"

/// @file
/// @brief Source file containing definitions of functions from SquareSolver.h

int isError(int code) {
    return code < 0;
}

int CheckNumber(double a) {
    return !isinf(a) && !isnan(a);
}

int isZero(double a) {
    if(!CheckNumber(a)) {
        return SS_ERROR_BAD_VALUE;
    }
    return abs(a) < SS_ZERO;
}

int CleanTerminalBuffer() {
    int bufElement = 0;
    do {
        bufElement = getchar();
        if(bufElement == EOF) {
            return SS_ERROR_UNEXPECTED_EOF;
        }
    } while(bufElement != '\n');

    return SS_ERROR_OK;
}

int GetCoefficientsSquare(double* a, double* b, double* c) {
    if(a == NULL || b == NULL || c == NULL) {
        return SS_ERROR_NULL_PTR;
    }

    printf("%sВведите коэффициенты квадратного уравнения: %s", GREEN, RESET);

    while(true) {
        int scanned = scanf("%lg%lg%lg", a, b, c);
        if(scanned == EOF) {
            return SS_ERROR_UNEXPECTED_EOF;
        }
        if(scanned == 3) {
            break;
        }

        scanned = CleanTerminalBuffer();
        if(isError(scanned)) {
            return scanned;
        }
        printf("%sНекорректный ввод, повторите: %s", YELLOW, RESET);
    }
    return SS_ERROR_OK;
}

void PrintError(int code) {
    switch(code) {
        case SS_ERROR_FILE_NOT_OPENED:
            printf("File didn't open properly\n");
            break;
        case SS_ERROR_FILE_WRONG_INPUT:
            printf("File input failed\n");
            break;
        case SS_ERROR_UNEXPECTED_EOF:
            printf("Unexpected EOF\n");
            break;
        case SS_ERROR_BAD_VALUE:
            printf("Value is inf or nan\n");
            break;
        case SS_ERROR_NULL_PTR:
            printf("NULL was sent to function\n");
            break;
        case SS_ERROR_FILE_NOT_CLOSED:
            printf("File didn't closed properly\n");
            break;
        case SS_ERROR_OK:
            printf("OK\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
    return;
}

int PrintAnswerSquare(const struct SquareAnswer* answer) {
    if(answer == NULL) {
        return SS_ERROR_NULL_PTR;
    }

    switch(answer->rootsCount) {
        case 0:
            printf("%sНет корней\n%s", CYAN, RESET);
            break;
        case 1:
            printf("%s1 корень: %.2f\n%s", CYAN, answer->root1, RESET);
            break;
        case 2:
            printf("%s2 корня: %.2f, %.2f\n%s", CYAN, answer->root1, answer->root2, RESET);
            break;
        case SS_INF_NUMBER_OF_ROOTS:
            printf("%sБесконечное кол-во корней\n%s", CYAN, RESET);
            break;
        default:
            printf("%sОшибка\n%s", RED, RESET);
            PrintError(answer->rootsCount);
            break;
    }
    return 0;
}

void SolveLinear(double a, double b, struct SquareAnswer* answer) {
    if(answer == NULL) {
        *answer = {SS_ERROR_NULL_PTR, 0, 0};
        return;
    }
    if(!CheckNumber(a) || !CheckNumber(b)) {
        *answer = {SS_ERROR_BAD_VALUE, 0, 0};
        return;
    }

    if(isZero(a)) {
        if(isZero(b)) {
            *answer = {SS_INF_NUMBER_OF_ROOTS, 0, 0};
            return;
        }
        else {
            *answer = {0, 0, 0};
            return;
        }
    }
    *answer = {1, -b / a, 0};
    return;
}

void SolveSquare(double a, double b, double c, struct SquareAnswer* answer) {
    if(answer == NULL) {
        *answer = {SS_ERROR_NULL_PTR, 0, 0};
        return;
    }
    if(!CheckNumber(a) || !CheckNumber(b) || !CheckNumber(c)) {
        *answer = {SS_ERROR_BAD_VALUE, 0, 0};
        return;
    }

    if(isZero(a)) {
        SolveLinear(b, c, answer);
        return;
    }

    double D = b*b - 4*a*c;
    if(isZero(D)) {
        *answer = {1, -b / (2.0 * a), 0};
        return;
    }
    else if(D < 0) {
        *answer = {0, 0, 0};
        return;
    }
    double sqrtD = sqrt(D);
    *answer = {2,
               (-b + sqrtD) / (2.0 * a),
               (-b - sqrtD) / (2.0 * a)
              };
    return;
}
