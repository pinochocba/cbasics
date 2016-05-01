/*
 * Display length of longest line
 *
 * NOTE: Pointeer version
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10000 /* Note: MAXLINE includes terminating newline and null characters */

/* getbigline: read an aribitrarily long line placing as much as
 * possible into 's' and returning the full length
 */

static size_t getbigline(char *s, size_t lim) {

    char c;
    char *start = s;

    while (--lim > 0 && (c = (char)getchar()) != (char)EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return (size_t)(s - start);
}

/* copy: copy 'from' into 'to'; assume to is big enough */

static void copy(char *to, char *from) {
    while ((*to++ = *from++) != '\0')
        ; // Empty
}

/* Main */

int main(void) {

    char   line[MAXLINE]   = "";
    char   longest[MAXLINE] = "";
    int    nl     = 0;
    size_t len    = 0;
    size_t maxlen = 0;

    while ((len = getbigline(line, MAXLINE)) > 0) {
        if (len > maxlen) {
            maxlen = len;
            copy(longest, line);
        }
        ++nl;
    }

    printf("%d line%s read.\n", nl, (nl == 1)?"":"s");
    if (nl > 0) {
        printf("The longest line is %u character%s long.\n", (unsigned)maxlen, (maxlen == 1) ? "" : "s");
        printf("The %slongest line is: %s\n", (maxlen > MAXLINE) ? "first part of the " : "", longest);
    }

    exit(EXIT_SUCCESS);
}