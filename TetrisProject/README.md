# Projet Tetris

## Description
Nous avons entièrement implémenté la version demandée du jeu Tetris. Il est normalement possible de jouer au jeu jusqu'au bout sans être bloqué par une fonctionnalité manquante ou un bug. Aucun bug connu ou avertissement n'est présent à la compilation.

## Fonctionnalités
Toutes les fonctionnalités ont été implémentées. Les pièces peuvent être déplacées dans n'importe quelle direction et tournées dans n'importe quel sens. Le calcul du score est correct, tout comme le tirage au sort des pièces. Les utilisateurs peuvent modifier la taille du plateau en début de jeu s'ils le souhaitent, et choisir de commencer avec un plateau partiellement rempli. Les pièces sont déplacées vers le bas à chaque intervalle défini par le niveau.

## Conditions de fin
Toutes les conditions de fin de jeu sont implémentées. Le jeu se termine lorsque le joueur perd classiquement, atteint un certain score, complète un certain nombre de lignes ou lorsque le temps est écoulé. Les conditions peuvent être modifiées dans la méthode `checkVictory` de la classe `Game` et le temps de la durée de la partie peut être configuré en changeant la variable `duration` dans la classe `Game`.

## Pistes d'amélioration
Mise en place d'une gestion d'erreurs du modèle plus robuste. (Exemple : Lancer des exceptions pour des erreurs hors entrée utilisateur)
Mise en place d'une musique et d'un affichage de la prochaine pièce. 

## Commandes de jeu
Les commandes sont affichées dans la fenêtre de jeu.

### Crédits

Par Nayma Assam Ismail et Paraschiv Olivia
