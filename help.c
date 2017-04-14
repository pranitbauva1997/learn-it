#include "common.h"

void help() {
    const char *help_str =
        "Usage: learn-it <command> [word]\n"
        "\nlearn-it is a simple command to store the words which you want\n"
        "to learn so that you can make use of them in your daily life.\n"
        "\nCommands: \n"
        "    init          - Initialize a new library of words\n"
        "    help          - Print help ie. this screen\n"
        "    add <word>    - Add new word to your library\n"
        "    list          - List all words from the library\n"
        "    get           - Get a random word from the library\n"
        "    remove <word> - Remove a word from the library\n"
        "\nOptions:\n"
        "    -h|--help       This is help text\n";
    printf("%s", help_str);
}
