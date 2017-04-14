#include "common.h"

static void goto_home_dir() {
    char *home = getenv("HOME");
    chdir(home);
}

int init() {
    FILE *fp;
    goto_home_dir();
    fp = fopen(".words", "w");
    if (fp == NULL) {
        fprintf(stderr, "error: couldn't create the file `~/.words`\n");
        return -1;
    }
}

int add(const char *word) {
    FILE *fp;
    goto_home_dir();
    fp = fopen(".words", "a");
    if (fp == NULL) {
        fprintf(stderr, "error: couldn't append to the file `~/.words`\n"
                        "Maybe you need to first create it with "
                        "`learn-it init`");
        return -1;
    }
    if (fprintf(fp, "%s\n", word) < 0) {
        fprintf(stderr, "error: couldn't append to the file `~/.words`\n");
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}

int clear() {
    goto_home_dir();
    return unlink(".words");
}

static void print_words(std::vector<std::string> words) {
    for (int i = 0; i < words.size(); i++)
        std::cout << words[i] << std::endl;
}

static int read_words(std::vector<std::string> &words) {
    std::string word;
    goto_home_dir();
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

static int get_random_index(int max) {
    srand(time(NULL));
    return rand() % max;
}

int get() {
    std::vector<std::string> words;
    if (read_words(words))
        return -1;

    std::cout << words[get_random_index(words.size())] << std::endl;
}
