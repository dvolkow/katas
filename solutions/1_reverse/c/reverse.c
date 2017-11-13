#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inplace_reverse(char *line, size_t length)
{
    /* check if the line ends with newline character */
    int ends_with_newline = line[length - 1] == '\n';
    if (ends_with_newline)
        --length;

    /* in-place reverse */
    for (size_t i = 0; i < length / 2; ++i) {
        char temp = line[i];
        line[i] = line[length - i - 1];
        line[length - i - 1] = temp;
    }
}


int main()
{
    char *line = NULL;
    size_t block_length = 0;
    ssize_t n_read = 0;

    /* read the input strings */
    while ((n_read = getline(&line, &block_length, stdin)) != -1) {
        inplace_reverse(line, n_read);
        printf("%s", line);
    }
    /* cleanup */
    free(line);

    /* catch getline error */
    if (errno != 0) {
        perror("error in getline");
        return 1;
    }
    return 0;
}
