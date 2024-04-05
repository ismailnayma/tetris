# Projet Tetris Console

## Description
Nous avons entièrement implémenté la version console du jeu Tetris. Il est normalement possible de jouer au jeu jusqu'au bout sans être bloqué par une fonctionnalité manquante ou un bug. Aucun bug connu ou avertissement n'est présent à la compilation.

## Fonctionnalités
Toutes les fonctionnalités ont été implémentées. Les pièces peuvent être déplacées dans n'importe quelle direction et tournées dans n'importe quel sens. Le calcul du score est correct, tout comme le tirage au sort des pièces. Les utilisateurs peuvent modifier la taille du plateau en début de jeu s'ils le souhaitent, et choisir de commencer avec un plateau partiellement rempli.

## Conditions de Victoire
Toutes les conditions de victoire sont implémentées. Le jeu se termine lorsque le joueur perd, atteint un certain score ou complète un certain nombre de lignes. Les joueurs peuvent modifier ces conditions dans la méthode `checkVictory` de la classe `Game`. Seule la condition basée sur le temps écoulé depuis le début du jeu n'est pas implémentée dans cette version console, mais elle le sera dans la version graphique.

## Piste d'amélioration
Mise en place d'une gestion d'erreur du modèle plus robuste. (Exemple: Lancer des exceptions pour des erreurs hors entrée utilisateur)

## Commandes de jeu
Après execution tout séra demandé à l'utilisateur. La touche 'H' affiches les commandes pour jouer.


Ce projet offre une expérience de jeu Tetris complète et sans erreur, avec toutes les fonctionnalités attendues et aucune limitation majeure.

Par Nayma Assam Ismail et Paraschiv Olivia
