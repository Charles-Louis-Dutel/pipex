# Pipex — École 42

Projet développé en **C** dans le cadre du cursus de l'école 42.

L'objectif est de reproduire le fonctionnement des pipes et des redirections d'un shell Unix, en permettant l'exécution de commandes reliées entre elles.

Ce projet permet d'approfondir la programmation système, la gestion des processus et la communication entre processus sous Unix.

## Fonctionnalités

- Exécution de commandes externes.
- Création de processus avec `fork()`.
- Communication entre processus à l'aide de `pipe()`.
- Redirection des entrées et sorties avec `dup2()`.
- Exécution de programmes avec `execve()`.
- Recherche des exécutables à partir de la variable d'environnement `PATH`.
- Gestion des descripteurs de fichiers et des erreurs système.

## Compétences mises en œuvre

- Programmation en C
- Programmation système Unix
- Gestion des processus
- Communication interprocessus (IPC)
- Descripteurs de fichiers et redirections
- Gestion des erreurs et des ressources

## Auteur

Charles-Louis Dutel — [GitHub](https://github.com/Charles-Louis-Dutel)
