module Main where

import System.Environment
import System.IO
import System.Directory
import System.Random
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

dictFile = ".words"

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
            "remove" -> removeFromDict $ head xs
            "get" -> getWord
            "help" -> putStrLn usageText
            "-h" -> putStrLn usageText
            "--help" -> putStrLn usageText
            _ -> putStrLn usageText

initDict :: IO ()
initDict = do
  handle <- openFile dictFile WriteMode
  hClose handle

clearDict :: IO ()
clearDict = removeIfExists dictFile

removeIfExists :: FilePath -> IO ()
removeIfExists fileName = do
  exists <- doesFileExist dictFile
  when exists $ removeFile dictFile

listDict :: IO ()
listDict = do
  contents <- readFile dictFile
  putStrLn contents

addToDict :: String -> IO ()
addToDict word = appendFile dictFile (word ++ "\n")

removeFromDict :: String -> IO ()
removeFromDict word = do
  contents <- readFile dictFile

  -- Ugly hack to avoid Lazy evaluation
  length contents `seq` writeFile dictFile $ unlines [x | x <- lines contents, x /= word]

getWord :: IO ()
getWord = do
  contents <- readFile dictFile
  gen <- getStdGen
  putStrLn $ getRandomWord gen $ lines contents

getRandomWord :: StdGen -> [String] -> String
getRandomWord gen  words =
  let num = length words
      (randNo, newGen) = randomR (0, num - 1) gen :: (Int, StdGen)
  in words !! randNo
