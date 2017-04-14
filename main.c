#include "common.h"

int main(int argc, const char **argv) {
    int i;

    if (argc < 2)
        return print_help();

    for (i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "help") || !strcmp(argv[i], "-h") ||
            !strcmp(argv[i], "--help")) {
            return print_help();
        } else {
            fprintf(stderr, "error: sorry couldn't identify what you are\n"
                            "       saying. Please try `learn-it help`\n");
            return -1;
        }
    }
}
