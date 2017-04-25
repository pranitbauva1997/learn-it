module Main where

usageText =
  "Usage: learn-it <command> [word]\n\
  \ learn-it is a simple command to store the words which you want\n\
  \ to learn so that you can make use of them in your daily life.\n\n\
  \ Commands:\n\
  \     init        - Initialize a new library of words\n\
  \     help        - Print help text\n\
  \     add <word>  - Add new word to your library\n\
  \     list        - List all words from the library\n\
  \     get         - Get a random word from the library\n\
  \     remove      - Remove a word from the library\n\
  \     clear       - Clear the whole library\n\n\
  \ Options:\n\
  \     -h|--help     This is help text\n"

main :: IO ()
main = putStrLn usage_text
