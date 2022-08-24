#include <stdio.h>
#include "SquareSolver.h"

int main() {
    printf("Введите коэффициенты квадратного уравнения: ");
    double a = 0, b = 0, c = 0;

    while(scanf("%lg%lg%lg", &a, &b, &c) != 3) {
        while(getchar() != '\n') { }
        printf("Некорректный ввод, повторите: ");
    }

    struct SquareAnswer i;
    SolveSquare(a, b, c, &i);
    PrintAnswerSquare(&i);

    return 0;
}
