# Documentation visuelle - Simple Shell

Ce dossier contient la documentation visuelle du projet Simple Shell.

## Images disponibles

### 📊 Flowchart.png
- **Description** : Diagramme de flux complet du Simple Shell
- **Contenu** : 
  - Architecture modulaire du projet
  - Flux d'exécution principal (prompt → lecture → parsing → exécution)
  - Gestion des erreurs et codes de retour
  - Processus fork/exec/wait
  - Gestion de la mémoire (allocation/libération)
- **Utilisation** : Intégré dans le README.md principal et section Architecture

### 📖 Man_page_part1.png
- **Description** : Première partie du manuel d'utilisation
- **Contenu** :
  - NAME : Nom et description courte
  - SYNOPSIS : Syntaxe d'utilisation
  - DESCRIPTION : Fonctionnalités détaillées
  - USAGE : Instructions de compilation
  - FEATURES : Liste des fonctionnalités
- **Utilisation** : Section Man Page du README.md

### 📖 Man_page_part2.png
- **Description** : Deuxième partie du manuel d'utilisation
- **Contenu** :
  - BUILT-IN COMMANDS : Commandes intégrées
  - EXAMPLES : Exemples d'utilisation
  - RETURN VALUE : Codes de retour
  - ENVIRONMENT : Variables d'environnement
  - LIMITATIONS : Fonctionnalités non supportées
  - AUTHORS : Informations développeurs
- **Utilisation** : Section Man Page du README.md

## Intégration dans le README

Ces images sont automatiquement intégrées dans le README.md principal :

```markdown
![Simple Shell Architecture](./IMG/Flowchart.png)
![Man Page - Partie 1](./IMG/Man_page_part1.png)
![Man Page - Partie 2](./IMG/Man_page_part2.png)
```

## Formats supportés

- **Format** : PNG
- **Résolution** : Optimisée pour la lecture
- **Taille** : Équilibrée entre qualité et taille de fichier
- **Compatibilité** : GitHub, GitLab, VS Code, navigateurs web

## Maintenance

Pour mettre à jour ces images :
1. Modifier le diagramme source
2. Exporter en PNG avec la même résolution
3. Remplacer le fichier dans ce dossier
4. Les liens dans le README.md se mettront à jour automatiquement
