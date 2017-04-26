## Introduction

This software helps you to keep the track of words you have read which
you want to digest better. Whenever we read a book, there might be a few
words whose meaning we aren't sure of but we can make a quick guess
about their meaning from the sentence itself. In this process, we forget
the word afterwards and thus it doesn't lead to increase in our
vocabulary. This software is intended to keep track of all those words
and then when you are free it can randomly show you some word just to make
sure you know its meaning.

## Installation

We would prefer to use `cabal new-build` but one can also use `cabal build`.

**Note:** `cabal new-build` is only available for cabal >= 1.24

To get the latest version of cabal:

```
cabal update
cabal install cabal-install
```

To build using `cabal new-build` just type:

```
$ cabal new-build
```

You will get the binaries for testing in your `dist-newstyle/` folder.

To build using `cabal build` just type:

```
$ cabal build
```

You will get the binaries for testing in your `dist/` folder.
