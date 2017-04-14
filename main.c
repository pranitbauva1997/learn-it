#include "common.h"

int main(int argc, const char **argv) {
    int i;

    if (argc < 2)
        return print_help();

    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "help") || !strcmp(argv[i], "-h") ||
            !strcmp(argv[i], "--help")) {
            return print_help();
        } else if (!strcmp(argv[i], "init")) {
            return init();
        } else if (!strcmp(argv[i], "add") && i + 1 < argc) {
            return add(argv[++i]);
        } else if (!strcmp(argv[i], "clear")) {
            return clear();
        } else if (!strcmp(argv[i], "list")) {
            return list();
        } else if (!strcmp(argv[i], "get")) {
            return get();
        } else {
            fprintf(stderr, "error: sorry couldn't identify what you are\n"
                            "       saying. Please try `learn-it help`\n");
            return -1;
        }
    }
}
