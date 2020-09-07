#include "quadratic.h"
#include "utils.h"
#include "testlib.h"

#include "stdio.h"

TEST(simple_equality)
    double sol[2] = {0};
    solutions_count_t count = NO_SOLUTIONS;

    count = solve(0, 0, 1, sol);
    ASSERT(NO_SOLUTIONS == count);

    count = solve(0, 0, 0, sol);
    ASSERT(INF_SOLUTIONS == count);
ENDTEST

TEST(linear)
    double sol[2] = {0};
    solutions_count_t count = NO_SOLUTIONS;

    count = solve(0, 1, 0, sol);
    ASSERT(ONE_SOLUTION == count);
    ASSERT(0 == sol[0]);

    count = solve(0, 1, 1, sol);
    ASSERT(ONE_SOLUTION == count);
    ASSERT(-1 == sol[0]);
ENDTEST

TEST(quadratic)
    double sol[2] = {0};
    solutions_count_t count = NO_SOLUTIONS;

    count = solve(1, -5, 6, sol);
    ASSERT(count == 2);
    int is2and3 = close_to(2, sol[0]) && close_to(3, sol[1]);
    int is3and2 = close_to(3, sol[0]) && close_to(2, sol[1]);
    ASSERT(is2and3 || is3and2);
ENDTEST

int main()
{
    simple_equality();
    linear();
    quadratic();
}