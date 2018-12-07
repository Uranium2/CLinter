# CLinter

This project has objective to warn the developper of a potential compilation error or a coding style error before compiling. It is a Linter written in C for C code.

You will need to compile the project to have the binaries. Before executing the binary you will need to create a configuration file named ***\<name\>**.lconf*. This configuration file must follow some rules. Here is an example.

    =extends
    myConfig.lconf
    
    =rules
    - array-bracket-eol = on
    - no-trailing-spaces = on
    - operators-spacing = on
    - max-line-numbers = 80
    - max-file-line-numbers = 80
    - no-multi-declaration = on
    - comments-header = on
    - unused-variable = on
    - unused-function = on
    - undeclared-function = on
    - undeclared-variable = on
    
    =excludedFiles
    - main.c
    - hello2.c
    - hello3.c
    - hello4.c
    
    =recursive
    false
    
**extends** is the rule to fetch and load the configuration from the file given below.

**rules** are the rules the Linter will follow.

**excludedFiles** are the files to not analyze.

**recursive** is the option to find c files in folders.

You will find at the end of this page, the rules implemented that you can use in the configuration file.

## Before running program

- Get gcc, make and doxygen

```console
CLinter:~$ sudo apt-get install gcc
CLinter:~$ sudo apt-get install make
CLinter:~$ sudo apt-get install doxygen
```

## To compile

```console
CLinter:~$ make all
```

The '**make all**' command will generate a binary, named **linter**, in the **test/** folder. You can drop your **c** files in the **test/** folder.

## To generate and view documentation

- Prerequisite: Install doxygen and graphviz 

```console
CLinter:~$ sudo apt-get install doxygen
CLinter:~$ sudo apt-get install graphviz
```

- Compile and View

```console
CLinter:~$ cd Doc/
CLinter/Doc:~$ doxygen Doxyfile
CLinter/Doc:~$ firefox html/index.html
```

## To run program

- Without arguments: Make sure you have at least *default.lconf* file in the folder you are running *linter*

```console
CLinter:~$ ./linter
```

- With configuration file in argument

```console
CLinter:~$ ./linter [path/to/config/file]
```

## TODO

- Partie 1:
  - [x] Récursif sur les dossiers
  - [x] Charger récursivement les fichiers de configuration
  - [x] Ouvrir les fichiers non exclus.
  - [x] Delimiter les mots par des tokens.
- Règles:
  - [x] array-bracket-eol
  - [x] operators-spacing
  - [ ] indent
  - [x] comments-header
  - [x] max-line-numbers
  - [x] max-file-line-numbers
  - [x] no-trailing-spaces
  - [x] no-multi-declaration
  - [x] unused-variable         :+1: :-1: Ne marche pas dans les blocks IF ELSE WHILE DO SWITCH. Mais marche dans les blocks Fonctions
  - [x] undeclared-variable     :+1: :-1: Ne marche pas dans les blocks IF ELSE WHILE DO SWITCH. Mais marche dans les blocks Fonctions
  - [ ] no-prototype
  - [x] unused-function         :+1: :-1:
  - [x] undeclared-function     :+1: :-1:
  - [ ] variable-assignment-type
  - [ ] function-parameters-type
- Mémoire:
  - [x] Free all.
