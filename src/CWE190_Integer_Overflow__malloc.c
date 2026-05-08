/*
 * CWE-190: Integer Overflow or Wraparound
 *
 * Source: pattern derived from NIST Juliet Test Suite for C/C++.
 *
 * Expected CodeQL findings:
 *   - cpp/integer-overflow
 *   - cpp/uncontrolled-arithmetic (varies)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void cwe190_integer_overflow_bad(int user_count)
{
    /* BAD: user_count multiplied without overflow check. A large value
     * wraps to a small or negative number, producing a tiny allocation
     * that subsequent code overflows. */
    int total = user_count * 100;
    char *buffer = (char *)malloc(total);
    if (buffer == NULL) return;

    /* Write assuming we got 'total' bytes - if total wrapped negative,
     * malloc returns NULL or a tiny buffer and this corrupts memory. */
    memset(buffer, 'A', total);
    free(buffer);
}

void cwe190_integer_overflow_good(int user_count)
{
    /* GOOD: bound check before multiplication. */
    if (user_count <= 0 || user_count > INT_MAX / 100) {
        fprintf(stderr, "rejected: count out of range\n");
        return;
    }

    int total = user_count * 100;
    char *buffer = (char *)malloc(total);
    if (buffer == NULL) return;

    memset(buffer, 'A', total);
    free(buffer);
}

#ifdef INCLUDEMAIN
int main(int argc, char **argv)
{
    if (argc > 1) {
        int n = atoi(argv[1]);
        cwe190_integer_overflow_bad(n);
        cwe190_integer_overflow_good(n);
    }
    return 0;
}
#endif
