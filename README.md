# CLinter
Linter in C
# To compile
make
# To run one file
./linter 
	or
./linter [path/to/config/file]

# To run tests
./test.sh

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
