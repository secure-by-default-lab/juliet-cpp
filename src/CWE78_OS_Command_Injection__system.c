/*
 * CWE-78: Improper Neutralization of Special Elements used in an OS Command
 *         (OS Command Injection)
 *
 * Source: pattern derived from NIST Juliet Test Suite for C/C++.
 *
 * Expected CodeQL findings:
 *   - cpp/command-line-injection
 *   - cpp/system-data-exposure (varies by query)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_BUFFER 256

void cwe78_command_injection_bad(const char *user_filename)
{
    char cmd[CMD_BUFFER];

    /* BAD: user_filename concatenated into a shell command. An attacker
     * supplying "foo; rm -rf /" gets arbitrary command execution. */
    snprintf(cmd, sizeof(cmd), "ls -l %s", user_filename);
    system(cmd);
}

void cwe78_command_injection_good(const char *user_filename)
{
    /* GOOD: validate input strictly, no shell involvement.
     * In real code we'd use execve with explicit argv, but the point here
     * is to show the pattern CodeQL flags vs the pattern it doesn't. */
    if (strpbrk(user_filename, ";&|`$<>\\\"'") != NULL) {
        fprintf(stderr, "rejected: shell metacharacters in filename\n");
        return;
    }

    char cmd[CMD_BUFFER];
    snprintf(cmd, sizeof(cmd), "ls -l %s", user_filename);
    system(cmd);
}

#ifdef INCLUDEMAIN
int main(int argc, char **argv)
{
    if (argc > 1) {
        cwe78_command_injection_bad(argv[1]);
        cwe78_command_injection_good(argv[1]);
    }
    return 0;
}
#endif
