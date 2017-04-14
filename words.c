#include "common.h"

int init() {
    FILE *fp;
    char *home;
    home = getenv("HOME");
    chdir(home);
    fp = fopen(".words", "w");
    if (fp == NULL) {
        fprintf(stderr, "error: couldn't create the file `~/.words`\n");
        return -1;
    }
}
