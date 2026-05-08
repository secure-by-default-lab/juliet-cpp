/*
 * CWE-122: Heap-based Buffer Overflow
 *
 * Source: pattern derived from NIST Juliet Test Suite for C/C++.
 *
 * Expected CodeQL findings:
 *   - cpp/overflow-buffer
 *   - cpp/unsafe-strcat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 32

void cwe122_heap_overflow_strcat_bad(const char *user_input)
{
    char *buffer = (char *)malloc(HEAP_SIZE);
    if (buffer == NULL) return;

    strcpy(buffer, "prefix-");

    /* BAD: strcat with no length check. If strlen("prefix-") + strlen(user_input)
     * >= HEAP_SIZE, this overflows the heap allocation. */
    strcat(buffer, user_input);

    printf("Result: %s\n", buffer);
    free(buffer);
}

void cwe122_heap_overflow_strcat_good(const char *user_input)
{
    char *buffer = (char *)malloc(HEAP_SIZE);
    if (buffer == NULL) return;

    strcpy(buffer, "prefix-");

    /* GOOD: bounded concatenation. */
    size_t remaining = HEAP_SIZE - strlen(buffer) - 1;
    strncat(buffer, user_input, remaining);

    printf("Result: %s\n", buffer);
    free(buffer);
}

#ifdef INCLUDEMAIN
int main(int argc, char **argv)
{
    if (argc > 1) {
        cwe122_heap_overflow_strcat_bad(argv[1]);
        cwe122_heap_overflow_strcat_good(argv[1]);
    }
    return 0;
}
#endif
