/** @file utils.h
 *  @brief Useful utility functions.
 */ 

/** @brief \f$\epsilon\f$ used in comparisons.
 * 
 *  \f$\epsilon\f$ used in functions ::close_to and ::close_to_zero.
 */ 
#define EPSILON 1e-7;

/** @brief Returns whether two numbers can be considered equal.
 * 
 *  Numbers \f$a, b\f$ are considered equal if \f$|a - b| < \epsilon\f$.
 * 
 *  @param[in] a the first number.
 *  @param[in] b the second number.
 * 
 *  @return non-zero value if the numbers can be considered equal, otherwise 0
 */
int close_to(double a, double b);

/** @brief Returns whether given number can be considered equal to zero.
 *  
 *  Number \f$a\f$ is considered zero if \f$|a| < \epsilon\f$.
 * 
 *  @param[in] a the number to be compared.
 * 
 *  @return non-zero value if the number is close to zero, otherwise 0.
 */
int close_to_zero(double a);