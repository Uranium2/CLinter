# CLinter
Linter in C
# To compile
```console
CLinter:~$ make
```
# To generate and view documentation
- Prerequisite: Install doxygen and graphviz 
```console
CLinter:~$ sudo apt-get insall doxygen
CLinter:~$ sudo apt-get insall graphviz
```
- Compile and View
```console
CLinter:~$ cd Doc/
CLinter/Doc:~$ doxygen Doxyfile
CLinter/Doc:~$ firefox html/index.html
```
# Before running program
- Get gcc and make
```console
CLinter:~$ sudo apt-get insall gcc
CLinter:~$ sudo apt-get insall make
```
# To run program
- Without arguments
```console
CLinter:~$ ./linter
```
- With configuration file in argument
```console
CLinter:~$ ./linter [path/to/config/file]
```

# TODO:
* Delimiter les tokens (Mot clés, délimiteurs, opérateurs, noms variables, espaces, reste?)	:+1: :-1:
* Partie 1:
	- [x] Récursif sur les dossiers
	- [x] Charger récursivement les fichiers de configuration
* Règles:
	- [x] array-bracket-eol
	- [x] operators-spacing 
	- [ ] indent
	- [x] comments-header
	- [x] max-line-numbers
	- [x] max-file-line-numbers
	- [x] no-trailing-spaces
	- [x] no-multi-declaration
	- [ ] unused-variable
	- [ ] undeclared-variable
	- [ ] no-prototype
	- [ ] unused-function
	- [ ] undeclared-function
	- [ ] variable-assignment-type
	- [ ] function-parameters-type
