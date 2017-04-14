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

int clear() {
    char *home;
    home = getenv("HOME");
    chdir(home);
    return unlink(".words");
}

int list() {
    char *home;
    std::string line;
    home = getenv("HOME");
    chdir(home);
    std::fstream fp (".words");
    if (fp.is_open()) {
        while (getline(fp, line))
            std::cout << line << std::endl;
        fp.close();
    }
    else {
        fprintf(stderr, "error: couldn't open the file ~/.words for reading\n"
                        "Maybe, you need to do a `learn-it init` first\n");
        return -1;
    }

    return 0;
}
