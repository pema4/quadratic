#include "utils.h"

#define FAIL(assert_name)                                               \
    do                                                                  \
    {                                                                   \
        fprintf(stderr, #assert_name " FAILED on line %d\n", __LINE__); \
        TEST_FAILED = 1;                                                \
        break;                                                          \
    }                                                                   \
    while (0)

#define ASSERT(condition)           \
    do                              \
    {                               \
        if (!(condition))           \
            FAIL(condition);        \
    } while (0)

#define TEST_NAME _test_name

#define TEST_FAILED _test_failed

#define TEST(name)                     \
    void name()                        \
    {                                  \
        const char *TEST_NAME = #name; \
        int TEST_FAILED = 0;           \
        do                             \
        {

#define ENDTEST                                         \
        }                                               \
        while (0);                                      \
        if (TEST_FAILED)                                \
            fprintf(stderr, "FAILED: %s\n", TEST_NAME); \
        else                                            \
            fprintf(stderr, "PASSED: %s\n", TEST_NAME); \
    }

// #undef FAIL
