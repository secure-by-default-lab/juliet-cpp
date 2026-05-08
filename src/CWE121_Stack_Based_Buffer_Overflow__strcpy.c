/*
 * CWE-121: Stack-based Buffer Overflow
 *
 * Source: pattern derived from NIST Juliet Test Suite for C/C++.
 * This file is a deliberately-vulnerable test case for static analysis tools.
 *
 * Expected CodeQL findings:
 *   - cpp/overflow-buffer  (or similar buffer-overflow query)
 *   - cpp/unsafe-strcat / cpp/unsafe-strcpy depending on query suite
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void cwe121_stack_overflow_strcpy_bad(const char *user_input)
{
    char buffer[BUFFER_SIZE];

    /* BAD: no length check before strcpy. If user_input is longer than
     * BUFFER_SIZE-1, this overflows the stack buffer. */
    strcpy(buffer, user_input);

    printf("Got: %s\n", buffer);
}

void cwe121_stack_overflow_strcpy_good(const char *user_input)
{
    char buffer[BUFFER_SIZE];

    /* GOOD: bounded copy with explicit null-termination. */
    strncpy(buffer, user_input, BUFFER_SIZE - 1);
    buffer[BUFFER_SIZE - 1] = '\0';

    printf("Got: %s\n", buffer);
}

#ifdef INCLUDEMAIN
int main(int argc, char **argv)
{
    if (argc > 1) {
        cwe121_stack_overflow_strcpy_bad(argv[1]);
        cwe121_stack_overflow_strcpy_good(argv[1]);
    }
    return 0;
}
#endif
