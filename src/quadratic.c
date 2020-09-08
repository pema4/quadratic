#include "quadratic.h"
#include "utils.h"

#include "stdio.h"
#include "math.h"
#include "assert.h"

/** @brief Simple equation solver.
 * 
 * 	Used to solve \f$a = 0\f$ equation.
 * 
 * 	@param [in] a The constant in the equation.
 * 	@param [out] solutions The array to store solutions in.
 *                         Size must be at least 1.
 * 
 * 	@return A count of solutions (none, one or infinity)
 */ 
solutions_count_t solve_constant(double a, double *solutions)
{
    if (!close_to_zero(a))
        return NO_SOLUTION;

    solutions[0] = -a;
    return INF_SOLUTIONS;
}

/** @brief Linear equation solver.
 * 
 * 	Used to solve \f$ax + b = 0\f$ equation.
 * 
 *  @param [in] a The coefficient of x in the equation.
 * 	@param [in] b The constant in the equation.
 * 	@param [out] solutions The array to store solutions in.
 *                         Size must be at least 1.
 * 
 * 	@return A count of solutions (none, one or infinity)
 */ 
solutions_count_t solve_linear(double a, double b, double *solutions)
{
    // Check if this equation is 'simple' (without any variables).
    if (close_to_zero(a))
        return solve_constant(b, solutions);

    solutions[0] = -b / a;
    return ONE_SOLUTION;
}

/** @brief Solves a quadratic equation with given coefficients.
 *  
 *  This fuctnions solves given quadratic equation \f$ax^2 + bx + c = 0\f$
 *  It is just like ::solve, but without any assertions.
 * 
 *  @param [in] a The coefficient of x^2 in the equation.
 *  @param [in] b The coefficient of x in the equation.
 *  @param [in] c The constant in the equation.
 *  @param [out] solutions The array to store solutions in.
 *                         Size must be at least 2.
 * 
 *  @return A count of solutions (none, one, two or infinity)
 */ 
solutions_count_t solve_quadratic(double a, double b, double c, double *solutions)
{
    // Check if this equation is linear.
    if (close_to_zero(a))
        return solve_linear(b, c, solutions);

    // Discriminant calculation.
    double d = b * b - 4 * a * c;
    if (d < 0)
        return NO_SOLUTION;
    else if (close_to_zero(d))
    {
        solutions[0] = -b / (2 * a);
        return ONE_SOLUTION;
    }
    else
    {
        double root_of_d = sqrt(d);
        solutions[0] = (-b + root_of_d) / (2 * a);
        solutions[1] = (-b - root_of_d) / (2 * a);
        return TWO_SOLUTIONS;
    }
}

solutions_count_t solve(double a, double b, double c, double *solutions)
{
    // Sanity checks
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(solutions != NULL);

    return solve_quadratic(a, b, c, solutions);
}
