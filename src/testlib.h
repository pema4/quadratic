#include "utils.h"

#define FAIL(assert_name)                                               \
    do                                                                  \
    {                                                                   \
        fprintf(stderr, #assert_name " FAILED on line %d\n", __LINE__); \
        goto FAILED;                                                    \
    } while (0)

#define ASSERT(condition)    \
    do                       \
    {                        \
        if (!(condition))    \
            FAIL(condition); \
    } while (0)

#define TEST_NAME _test_name

#define TEST_FAILED _test_failed

#define TEST(name) \
    void name()    \
    {              \
        const char *TEST_NAME = #name;

#define ENDTEST                                         \
        fprintf(stderr, "PASSED: %s\n", TEST_NAME);     \
        return;                                         \
        FAILED:                                         \
            fprintf(stderr, "FAILED: %s\n", TEST_NAME); \
            return;                                     \
    }

