#include <stdio.h>
#include "SquareSolver.h"

int main() {
    printf("Введите коэффициенты квадратного уравнения: ");
    double a = 0, b = 0, c = 0;

    while(scanf("%lg%lg%lg", &a, &b, &c) != 3) {
        char temp = 0;
        do {
            temp = getchar();
        } while(temp != '\n');
        printf("Неправильный ввод, повторите: ");
    }
    SquareAnswer i;
    SolveSquare(a, b, c, &i);

    switch(i.rootsCount) {
        case 0:
            printf("Нет корней\n");
            break;
        case 1:
            printf("1 корень: %.2f\n", i.root1);
            break;
        case 2:
            printf("2 корня: %.2f, %.2f\n", i.root1, i.root2);
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
