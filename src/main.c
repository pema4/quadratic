#include "quadratic.h"
#include "utils.h"
#include "tests.h"

#include "stdio.h"

TEST(petukh)
    int x = 0;
    x += 1;
    ASSERT(1 == x);
    ASSERT(0 == 1);
ENDTEST

void test_one()
{
    double sol[2] = {0};
    solutions_count_t count = solve(1, -5, 6, sol);
    if (close_to(2, sol[0]) && close_to(3, sol[1]) ||
        close_to(3, sol[0]) && close_to(2, sol[1]))
        puts("PASSED");
    else
        puts("FAILED");
    printf("%lf %lf\n", sol[0], sol[1]);
}

int main()
{
    petukh();
    return 0;
}
