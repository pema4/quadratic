#include "quadratic.h"
#include "utils.h"

#include "stdio.h"

int main()
{
    double a = 0, b = 0, c = 0;
    puts("Enter coefficients a, b, c in the equation ax^2 + bx + c = 0");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        puts("ERROR: wrong input");
        return -1;
    }

    double solution[2] = {0};
    solutions_count_t count = solve_quadratic(a, b, c, solution);

    // if solution is close to zero, then it is zero.
    for (int i = 0; i < count; ++i)
        if (close_to_zero(solution[i]))
            solution[i] = 0;

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
        break;
    default:
        printf("Unexpected number of solutions: %d", count);
        return -1;
    }

    return 0;
}
