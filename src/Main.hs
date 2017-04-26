module Main where

import System.Environment
import System.IO
import System.Directory
import Control.Monad

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
main = do
  args <- getArgs
  handleArgs args

handleArgs :: [String] -> IO ()
handleArgs [] = putStrLn usageText
handleArgs (x:xs) =
  case x of "init" -> initDict
            "clear" -> clearDict
            "list" -> listDict
            "add" -> addToDict $ head xs
            "help" -> putStrLn usageText
            "-h" -> putStrLn usageText
            "--help" -> putStrLn usageText
            _ -> putStrLn usageText

initDict :: IO ()
initDict = do
  handle <- openFile ".words" WriteMode
  hClose handle

clearDict :: IO ()
clearDict = removeIfExists ".words"

removeIfExists :: FilePath -> IO ()
removeIfExists fileName = do
  exists <- doesFileExist ".words"
  when exists $ removeFile ".words"

listDict :: IO ()
listDict = do
  contents <- readFile ".words"
  putStrLn contents

addToDict :: String -> IO ()
addToDict word = appendFile ".words" (word ++ "\n")
