#include "SquareSolver.h"

bool isZero(double a) {
    return abs(a) < SS_ZERO;
}

void PrintAnswerSquare(struct SquareAnswer* answer) {
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
}

void SolveSquare(double a, double b, double c, struct SquareAnswer* answer) {
    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));

    if(isZero(a)) {
        if(isZero(b)) {
            if(isZero(c)) {
                *answer = {SS_INF_NUMBER_OF_ROOTS, 0, 0};
                return;
            }
            else {
                *answer = {0, 0, 0};
                return;
            }
        }
        else {
            *answer = {1, -c / b, 0};
            return;
        }
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
    else {
        *answer = {2, (-b + sqrt(D)) / (2.0 * a), (-b - sqrt(D)) / (2.0 * a)};
        return;
    }
}
