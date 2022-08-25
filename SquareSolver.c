#include "SquareSolver.h"

/// @file
/// @brief Source file containing definitions of functions from SquareSolver.h

int CheckNumber(double a) {
    return !isinf(a) && !isnan(a);
}

int isZero(double a) {
    if(!CheckNumber(a)) {
        return SS_ERROR;
    }
    return abs(a) < SS_ZERO;
}

void CleanTerminalBuffer() {
    while(getchar() != '\n') { }
    return;
}

int GetCoefficientsSquare(double* a, double* b, double* c) {
    if(a == NULL || b == NULL || c == NULL) {
        return SS_ERROR;
    }

    printf("Введите коэффициенты квадратного уравнения: ");

    while(scanf("%lg%lg%lg", a, b, c) != 3) {
        CleanTerminalBuffer();
        printf("Некорректный ввод, повторите: ");
    }
    return 0;
}

int PrintAnswerSquare(const struct SquareAnswer* answer) {
    if(answer == NULL) {
        return SS_ERROR;
    }

    switch(answer->rootsCount) {
        case 0:
            printf("Нет корней\n");
            break;
        case 1:
            printf("1 корень: %.2f\n", answer->root1);
            break;
        case 2:
            printf("2 корня: %.2f, %.2f\n", answer->root1, answer->root2);
            break;
        case SS_INF_NUMBER_OF_ROOTS:
            printf("Бесконечное кол-во корней\n");
            break;
        default:
            printf("Ошибка\n");
            break;
    }
    return 0;
}

void SolveLinear(double a, double b, struct SquareAnswer* answer) {
    if(!CheckNumber(a) || !CheckNumber(b) || answer == NULL) {
        *answer = {SS_ERROR, 0, 0};
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
    if(!CheckNumber(a) || !CheckNumber(b) || !CheckNumber(c) || answer == NULL) {
        *answer = {SS_ERROR, 0, 0};
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
