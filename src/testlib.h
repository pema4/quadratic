/** 
 * @file testlib.h
 * @brief Not so smart testing library powered by macros.
 */

#ifndef TESTLIB_H
#define TESTLIB_H

#include "utils.h"

/**
 * @brief A simple assertion to use within a test.
 *  
 * ASSERT macros must be placed within a test case.
 * 
 * If the condition evaluates to false, the test case is reported as failed
 * and corresponding message is printed to stderr.
 *
 * @param condition The condition that must be true.
 * 
 * @sa ::TEST
 */
#define ASSERT(condition)                                                 \
    do                                                                    \
        if (!(condition))                                                 \
        {                                                                 \
            fprintf(stderr, #condition " FAILED on line %d\n", __LINE__); \
            goto FAILED;                                                  \
        }                                                                 \
    while (0)

/** 
 * @brief Marks the beginning of a test case.
 * 
 * The TEST macro is used to define a test case. A test case 
 * starts with ::TEST(name) and ends with ::ENDTEST macros.
 * Test case is a regular C function with some conditions wrapped in ::ASSERT(condition) macros.
 * When tests are executed, the test case is marked as failed, if any of
 * these condition evaluate to false. Otherwise, the test case is marked as passed.
 * 
 * @param name Name of the test function. Also used in the output of tests.
 * 
 * @sa ::ENDTEST
 */
#define TEST(name) \
    void name()    \
    {              \
        const char *TEST_NAME = #name;

/** 
 * @brief Marks the end of a test case.
 * 
 * @sa ::TEST
 */ 
#define ENDTEST                                         \
        fprintf(stderr, "PASSED: %s\n", TEST_NAME);     \
        return;                                         \
        FAILED:                                         \
            fprintf(stderr, "FAILED: %s\n", TEST_NAME); \
            return;                                     \
    }

#endif // TESTLIB_H
