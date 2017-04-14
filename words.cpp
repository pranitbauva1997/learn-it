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

static void print_words(std::vector<std::string> words) {
    for (int i = 0; i < words.size(); i++)
        std::cout << words[i] << std::endl;
}

static int read_words(std::vector<std::string> &words) {
    std::string word;
    char *home = getenv("HOME");
    chdir(home);
    std::fstream fp(".words");
    if (fp.is_open()) {
        while (getline(fp, word))
            words.push_back(word);
        fp.close();
    } else {
        fprintf(stderr, "error: couldn't open the file ~/.words for reading\n"
                        "Maybe you need to first create it with"
                        "`learn-it init`\n");
        return -1;
    }

    return 0;
}

int list() {
    std::vector<std::string> words;
    if (read_words(words))
        return -1;

    print_words(words);

    return 0;
}
