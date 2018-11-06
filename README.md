# CLinter
Linter in C
# To compile
make
# To run one file
./linter [path/to/c/file]

./linter [path/to/c/file] [path/to/config/file]

# To run tests
./test.sh

# TODO:
* Lire les options d'un fichier config
	- Faire extends + recursive
* Delimiter les tokens (Mot clés, délimiteurs, opérateurs, noms variables, espaces, reste?)	:+1: :-1:
* Stocker la string dans dans un token (struct Token)
* Règles:
	- [x] array-bracket-eol
	- [x] operators-spacing 
	- [ ] indent
	- [ ] comments-header
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
