#include "SquareSolver.h"

/// @file
/// @brief Source file containing definitions of functions from SquareSolver.h

int isZero(double a) {
    if(isinf(a)) {
        return SS_ERROR;
    }
    return abs(a) < SS_ZERO;
}

void CleanTerminalBuffer() {
    while(getchar() != '\n') { }
    return;
}

int GetCoefficientsSquare(double* a, double* b, double* c) {
    if(!a || !b || !c) {
        return SS_ERROR;
    }
    /*assert(a);
    assert(b);
    assert(c);*/

    printf("Введите коэффициенты квадратного уравнения: ");

    while(scanf("%lg%lg%lg", a, b, c) != 3) {
        CleanTerminalBuffer();
        printf("Некорректный ввод, повторите: ");
    }
    return 0;
}

int PrintAnswerSquare(struct SquareAnswer* answer) {
    if(!answer) {
        return SS_ERROR;
    }
    //assert(answer);

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
    if(isinf(a) || isinf(b) || !answer) {
        *answer = {SS_ERROR, 0, 0};
        return;
    }
    /*assert(!isinf(a));
    assert(!isinf(b));
    assert(answer);*/

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
    if(isinf(a) || isinf(b) || isinf(c) || !answer) {
        *answer = {SS_ERROR, 0, 0};
        return;
    }
    /*assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));
    assert(answer);*/

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
