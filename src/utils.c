#include "utils.h"

#include "math.h"

int close_to(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

int close_to_zero(double a)
{
    return close_to(a, 0);
}
