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
* Stocker la string dans dans un token (struct Token)
	- Merge certain token ensemble. Si on a un token '>' et un autre '>'. On les merges pour avoir un '>>', puis on shift tout vers la droite? remplace par un espace? Remplace par un token 'NILL', qu'on pourrait skip si on passe dessus. (histoire de pas shift une enorme array)
* Grace a la grammaire, demander un token et dire si oui ou non il peut etre la.
	- => GRAMMAIRE (https://www.lysator.liu.se/c/ANSI-C-grammar-y.html) (oui on a envie de pleurer....)
	- Exemple de pseudo/c code dans le fichier parsing.txt
* Reset la ligne si on trouve pas le bon token? Ou alors on crash à la première erreur? Ou faire genre qu'on a trouvé le bon token et on continue? Risque d'avoir beaucoups d'erreurs... Il faut trouver un systeme de reprise sur erreur.
