#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <optional>
#include "../../model/Enums.h"
#include "../../model/Position.h"

class BoardWidget : public QWidget {
    Q_OBJECT

public:
    BoardWidget(QWidget *parent = nullptr);

    void updateCell(int row, int col, const QString& text);
    void updateBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea,
                     const std::vector<Position>& brickBoardPositions,
                     TypeShape currentBrickTypeShape);

private:
    QGridLayout *gridLayout; // Déclaration de la grille de mise en page
    QVector<QVector<QLabel*>> gridLabels; // Déclaration de la matrice de QLabel

    QColor getColorForShape(TypeShape shape) const;
};

#endif // BOARDWIDGET_H

