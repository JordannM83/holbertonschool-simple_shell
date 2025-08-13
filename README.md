# holbertonschool-simple_shell
1. main.c
Boucle principale du shell
Affichage du prompt
Lecture de la ligne utilisateur
Parsing de la ligne en arguments
Exécution de la commande (appel à execute)
Gestion de la sortie (EOF, exit, etc.)
Libération mémoire
2. prompt.c
Fonction pour afficher le prompt du shell
3. utils.c
Fonction pour lire une ligne depuis l’entrée standard
Fonctions utilitaires diverses (gestion de chaînes, etc.)
4. parse.c
Fonction pour découper la ligne utilisateur en tokens (arguments)
Gestion de la mémoire pour le tableau d’arguments
5. execute.c
Fonction pour exécuter une commande :
Gestion des commandes internes (built-ins)
Gestion des processus enfants (fork, execve, wait)
Recherche du chemin de la commande (PATH)
6. builtin.c
Fonctions pour les commandes internes (exit, env, cd, etc.)
7. env.c
Fonction pour afficher les variables d’environnement
8. error.c
Fonction pour afficher les messages d’erreur
9. shell.h
Prototypes de toutes les fonctions
Inclusions des bibliothèques nécessaires
Définition des macros utiles
10. README.md / man_1_simple_shell / AUTHORS
Documentation, manuel utilisateur, auteurs
Chaque fichier doit contenir uniquement la logique qui lui est propre, et les fonctions doivent être appelées depuis le main selon le flux : prompt → read_line → parse_line → execute → (built-in ou execve).
La gestion des erreurs et de la mémoire doit être présente à chaque étape.