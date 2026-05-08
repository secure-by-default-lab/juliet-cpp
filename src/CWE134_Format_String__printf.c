/*
 * CWE-134: Use of Externally-Controlled Format String
 *
 * Source: pattern derived from NIST Juliet Test Suite for C/C++.
 *
 * Expected CodeQL findings:
 *   - cpp/tainted-format-string
 *   - cpp/non-constant-format
 */

#include <stdio.h>
#include <string.h>

void cwe134_format_string_bad(const char *user_input)
{
    /* BAD: user_input passed directly as the format string. An attacker
     * supplying "%s%s%s%s" can read stack memory; "%n" can write. */
    printf(user_input);
}

void cwe134_format_string_good(const char *user_input)
{
    /* GOOD: user_input is an argument to a constant format string. */
    printf("%s", user_input);
}

#ifdef INCLUDEMAIN
int main(int argc, char **argv)
{
    if (argc > 1) {
        cwe134_format_string_bad(argv[1]);
        cwe134_format_string_good(argv[1]);
    }
    return 0;
}
#endif
