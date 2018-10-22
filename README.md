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
* Stocker les options dans une structure
* Ouvrir un fichier code (\*.c). Le charger dans un char**	:+1:
* Lire ligne par ligne	:+1:
* Delimiter les tokens (Mot clés, délimiteurs, opérateurs, noms variables, espaces, reste?)	:+1: :-1:
	* Dans parser.c, un momement on s'arrête sur un char. Il faudrait arriver à lire une string pour les opérateurs à 2 charactères
* Stocker la string dans dans un token (struct Token)
* Charger les tokens dans un AST (https://en.wikipedia.org/wiki/Abstract_syntax_tree)
* Faire une "grammaire". Apres tel type de neuds de l'AST on doit trouver tel type de noeuds:
	- exemple: Après un token mot clé "int". On doit avoir un nom de variable + (espace?) + un égal + (espace?) + Entier.
	- Un Entier c'est soit un function qui retourne un int, soit un int, soit un calcul.
	- Un calcul c'est une fonction qui retourne un int + un operateur + un Entier (donc ca peut retomber sur un Calcul ou une fonction)
	- => GRAMMAIRE (https://www.lysator.liu.se/c/ANSI-C-grammar-y.html) (oui on a envie de pleurer....)

Le but c'est d'arriver a parcourir notre AST ou autre structure et de faire des checks sur la grammaire.


Note 1, type de noeuds dans un AST possible:

	Operator node (+=-*/^<> '!=' %)
	Demimitor node (,;:.(){}[] espace tab + tous les node Operateurs)
	Numerical node (int double float -2.23e-10)
	Variable node ([alpha][alphaNum]*)
	Type node (int, char, unsigned, char*, char**, char********** (nouveau Type?))
	Argument node (Type node + Variable node)
	ListArgument node (Argument node + ',' + ListArgument node )
	Function node (Type node + Variable node + Operator node '(' + ListArgument node + ')')
	Return node ()
	Statement node (Le coeur d'une fonction)

Il "faudrait" suivre la grammaire du C pour créer un noeuds par situation: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html

Note 2: Comment on charge proprement les tokens dans l'AST?
