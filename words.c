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

int add(const char *word) {
    FILE *fp;
    char *home;
    home = getenv("HOME");
    chdir(home);
    fp = fopen(".words", "a");
    if (fp == NULL) {
        fprintf(stderr, "error: couldn't append to the file `~/.words`\n"
                        "Maybe you need to first create it with "
                        "`learn-it init`");
        return -1;
    }
    if (fprintf(fp, "%s\n", word) < 0) {
        fprintf(stderr, "error: couldn't append to the file `~/.words`\n");
        return -1;
    }
    return 0;
}
