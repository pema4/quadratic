#include "quadratic.h"

#include "stdio.h"

int main()
{
    double a, b, c;
    puts("Enter coefficients a, b, c in the equation ax^2 + bx + c = 0");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        puts("ERROR: wrong input");
        return -1;
    }

    double solution[2] = {0};
    solutions_count_t count = solve(a, b, c, solution);
    switch (count)
    {
        case NO_SOLUTION:
            puts("Equation has no solutions");
            break;
        case ONE_SOLUTION:
            printf("Equation has only one solution: %lf\n", solution[0]);
            break;
        case TWO_SOLUTIONS:
            printf("Equation has two solutions: %lf %lf\n", solution[0], solution[1]);
            break;
        case INF_SOLUTIONS:
            puts("Equation has infinite number of solutions");
    }

    return 0;
}
