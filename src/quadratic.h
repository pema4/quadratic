typedef enum solutions_count_t
{
    NO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTION,
    INF_SOLUTIONS
} solutions_count_t;

solutions_count_t solve(double a, double b, double c, double *solutions);