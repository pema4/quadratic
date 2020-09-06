#include "quadratic.h"
#include "utils.h"

#include "stdio.h"
#include "math.h"
#include "assert.h"

// a = 0
solutions_count_t solve_constant(double a, double *solutions)
{
	if (!close_to_zero(a))
		return NO_SOLUTIONS;

	solutions[0] = -a;
	return INF_SOLUTIONS;
}

// a * x + b = 0
solutions_count_t solve_linear(double a, double b, double *solutions)
{
	if (close_to_zero(a))
		return solve_constant(b, solutions);

	solutions[0] = -b / a;
	return ONE_SOLUTION;
}

// a * x^2 + b * x + c = 0
solutions_count_t solve_quadratic(double a, double b, double c, double *solutions)
{
	if (close_to_zero(a))
		return solve_linear(b, c, solutions);

	double d = b * b - 4 * a * c;
	if (d < 0)
		return NO_SOLUTIONS;
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
		return TWO_SOLUTION;
	}
}

solutions_count_t solve(double a, double b, double c, double *solutions)
{
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	assert(solutions != NULL);

	return solve_quadratic(a, b, c, solutions);
}