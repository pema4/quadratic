/** 
 * @file quadratic.h
 * @brief The library for solving quadratic equations.
 */

#ifndef QUADRATIC_H
#define QUADRATIC_H

/** 
 * @brief Return type of the ::solve_quadratic.
 * @sa ::solve_quadratic
 */
typedef enum solutions_count_t
{
    NO_SOLUTION   = 0,
    ONE_SOLUTION  = 1,
    TWO_SOLUTIONS = 2,
    INF_SOLUTIONS = -1
} solutions_count_t;

/** 
 * @brief Solves a quadratic equation with given coefficients.
 *  
 * This fuctnions solves given quadratic equation \f$ax^2 + bx + c = 0\f$
 * 
 * @param [in] a The coefficient of x^2 in the equation.
 *               Must not be infinite or nan.
 * @param [in] b The coefficient of x in the equation.
 *               Must not be infinite or nan.
 * @param [in] c The constant in the equation.
 *               Must not be infinite or nan. 
 * @param [out] solutions The array to store solutions in.
 *                        Size must be at least 2.
 * 
 * @return A count of solutions (none, one, two or infinity)
 */
solutions_count_t solve_quadratic(double a, double b, double c, double *solutions);

#endif // QUADRATIC_H
