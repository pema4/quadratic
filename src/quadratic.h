/** @file quadratic.h
 *  @brief The library for solving quadratic equations.
 */ 

/** @brief Return type of the ::solve.
 *  @sa ::solve
 */ 
typedef enum solutions_count_t
{
    NO_SOLUTION,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INF_SOLUTIONS
} solutions_count_t;

/** @brief Solves a quadratic equation with given coefficients.
 *  
 *  This fuctnions solves given quadratic equation \f$ax^2 + bx + c = 0\f$
 * 
 *  @param[in] a the coefficient of x^2 in the equation.
 *  @param[in] b the coefficient of x in the equation.
 *  @param[in] c the constant coefficient in the equation.
 *  @param[out] solutions the array to store solutions in.
 *              Must be at least size of 2.
 * 
 *  @return a count of solutions (none, one, two or infinity)
 */ 
solutions_count_t solve(double a, double b, double c, double *solutions);