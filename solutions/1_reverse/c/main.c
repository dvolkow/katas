#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *line = NULL;
    size_t block_length = 0;

    /* read the input string */
    ssize_t n_read = getline(&line, &block_length, stdin);
    if (n_read == -1) {
        if (errno != 0) {
            /* error in getline */
            perror("error in getline");
            free(line);
            return 1;
        }
        /* empty string */
        return 0;
    }
    size_t length = strlen(line);

    /* check if the line ends with newline character */
    int ends_with_newline = line[length - 1] == '\n';
    if (ends_with_newline)
        --length;

    /* single newline symbol check */
    if (length == 0)
        return 0;

    /* in-place reverse */
    for (size_t i = 0; i < length / 2; ++i) {
        char temp = line[i];
        line[i] = line[length - i - 1];
        line[length - i - 1] = temp;
    }

    /* output with correct newline symbol */
    printf("%s", line);
    if (!ends_with_newline)
        printf("\n");

    free(line);
    return 0;
}
