#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent) {
    // Crée un layout de grille pour organiser les cellules du plateau
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0); // Pas d'espacement entre les cellules

    // Initialise la matrice de QLabel pour représenter les cellules du plateau
    for (int row = 0; row < 20; ++row) {
        QVector<QLabel*> rowLabels;
        for (int col = 0; col < 10; ++col) {
            QLabel *label = new QLabel(this); // Utilise "." pour représenter une cellule vide par défaut
            label->setStyleSheet("background-color: white; border: 1px solid black;");
            label->setFixedSize(20, 20); // Taille de chaque cellule
            label->setAlignment(Qt::AlignCenter); // Centre le texte dans la cellule
            //label->setStyleSheet("QLabel { border: 1px solid black; }"); // Bordure pour chaque cellule
            gridLayout->addWidget(label, row, col); // Ajoute le QLabel au layout de grille
            rowLabels.append(label);
        }
        gridLabels.append(rowLabels);
    }
}

void BoardWidget::updateCell(int row, int col, const QString& text) {
    QLabel *label = gridLabels[row][col];
    label->setText(text); // Met à jour le texte de la cellule
}

// Méthode pour obtenir la couleur correspondante à une forme
QColor BoardWidget::getColorForShape(TypeShape shape) const {
    switch (shape) {
    case TypeShape::O_SHAPE: return Qt::yellow;
    case TypeShape::I_SHAPE: return Qt::cyan;
    case TypeShape::S_SHAPE: return Qt::green;
    case TypeShape::Z_SHAPE: return Qt::red;
    case TypeShape::L_SHAPE: return Qt::blue;
    case TypeShape::J_SHAPE: return Qt::magenta;
    case TypeShape::T_SHAPE: return Qt::yellow; // Choisissez une autre couleur pour la forme T
    default: return Qt::white; // Couleur par défaut
    }
}

// Méthode pour mettre à jour l'affichage du boardArea avec la brique courante
void BoardWidget::updateBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea,
                              const std::vector<Position>& brickBoardPositions,
                              TypeShape currentBrickTypeShape) {

    // Parcourir toutes les cases de la grille
    for (int row = 0; row < boardArea.size(); ++row) {
        for (int col = 0; col < boardArea[row].size(); ++col) {
            QLabel *label = gridLabels[row][col];

            // Mise à jour de l'affichage pour le plateau de jeu
            if (!boardArea[row][col].has_value()) {
                label->setText("");
                label->setStyleSheet("background-color: white; border: 1px solid black;"); // Fond blanc pour les cases vides
            } else {
                label->setText("");
                label->setStyleSheet("background-color: " + getColorForShape(boardArea[row][col].value()).name() +";border: 1px solid black;" );
            }
        }
    }

    // Mettre à jour les positions de la brique courante
    for (const auto& pos : brickBoardPositions) {
        // Vérifier si la position de la brique est dans les limites de la grille
        if (pos.getPosY() >= 0 && pos.getPosY() < gridLabels.size() &&
            pos.getPosX() >= 0 && pos.getPosX() < gridLabels[pos.getPosY()].size()) {
            QLabel *label = gridLabels[pos.getPosY()][pos.getPosX()];
            label->setText("");
            label->setStyleSheet("background-color: " + getColorForShape(currentBrickTypeShape).name()+";border: 1px solid black;");
        }
    }


    /*
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {

             gridLabels[row][col] ->setStyleSheet("background-color: " + getColorForShape(currentBrickTypeShape).name()+";border: 1px solid black;");
        }
    }
*/

    /*
            if (!boardArea[1][1].has_value()) {
            gridLabels[0][0] -> setStyleSheet("background-color: yellow; border: 1px solid black;");

            } else {
                 gridLabels[0][0] -> setStyleSheet("background-color: green; border: 1px solid black;");
            }
            */

/*
            for (const Position& pos : brickBoardPositions) {
                // Vérifier si la position de la brique est dans les limites de la grille
                if (pos.getPosY() >= 0 && pos.getPosY() < gridLabels.size() &&
                    pos.getPosX() >= 0 && pos.getPosX() < gridLabels[pos.getPosY()].size()) {
                    QLabel *label = gridLabels[pos.getPosY()][pos.getPosX()];
                    label->setStyleSheet("background-color: " + getColorForShape(currentBrickTypeShape).name());
                    label->setText("");
                    label->setStyleSheet("background-color: " + getColorForShape(currentBrickTypeShape).name());
                } else {
                    gridLabels[pos.getPosY()][pos.getPosX()] -> setStyleSheet("background-color: green" );
                }
            }
            */



}
