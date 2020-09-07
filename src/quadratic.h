typedef enum solutions_count_t
{
    NO_SOLUTION,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INF_SOLUTIONS
} solutions_count_t;

solutions_count_t solve(double a, double b, double c, double *solutions);