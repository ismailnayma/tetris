#include "GUIController.h"
#include <QKeyEvent>

GUIController::GUIController(Game &model, QObject *parent)
    : QObject(parent), model(model)
{
    // Ne connectez pas directement les signaux et les slots ici
    // Installez plutôt un filtre d'événements sur la vue principale
}

bool GUIController::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Left:
            model.moveCurrentBrick(Direction::LEFT);
            break;
        case Qt::Key_Right:
            model.moveCurrentBrick(Direction::RIGHT);
            break;
        case Qt::Key_Down:
            model.moveCurrentBrick(Direction::DOWN);
            break;
        case Qt::Key_Up:
            model.rotateCurrentBrick(Rotation::CLOCKWISE);
        case Qt::Key_Z:
            model.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
            break;
        case Qt::Key_Enter:
            model.dropCurrentBrick();
            break;

        default:
            break;
        }
    }

    // Passez l'événement à l'objet parent (vue) pour qu'il le traite également
    return QObject::eventFilter(obj, event);
}
