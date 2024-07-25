#include <stdio.h>
#include <string.h>

int hash(char *str, int length) {
    int hash = 5381;
    printf("nick: %s",str);
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % length;
}
