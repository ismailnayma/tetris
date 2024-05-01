#include "GUIController.h"
#include <QKeyEvent>

GUIController::GUIController(QObject *parent)
    : QObject(parent), mainWindow(model)
{

    model.registerObserver(this);
    mainWindow.installEventFilter(this);

    connect(startWindow.getUi().playButton, SIGNAL(clicked(bool)), this, SLOT(playButtonHandler()));
    startWindow.show();
}

bool GUIController::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Q:
            qDebug() << "Une touche a été gauche.";
            model.moveCurrentBrick(Direction::LEFT);
            break;
        case Qt::Key_D:
            qDebug() << "Une touche a été droite.";
            model.moveCurrentBrick(Direction::RIGHT);
            break;
        case Qt::Key_S:
            qDebug() << "Une touche a été bas.";
            model.moveCurrentBrick(Direction::DOWN);
            break;
        case Qt::Key_Z:
            qDebug() << "Une touche a été haut.";
            model.rotateCurrentBrick(Rotation::CLOCKWISE);
            break;
        case Qt::Key_A:
            qDebug() << "Une touche Z a été haut.";
            model.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
            break;
        case Qt::Key_E:
            qDebug() << "Une touche enter été haut.";
            model.dropCurrentBrick();
            break;
        default:
            qDebug() << "je suis dans default.";
            break;
        }
    }


    // Passez l'événement à l'objet parent (vue) pour qu'il le traite également
    return QObject::eventFilter(obj, event);
}


void GUIController::playButtonHandler(){
    int width = startWindow.getWidthSpinBox();
    int height = startWindow.getHeightSpinBox();
    bool prefilled = startWindow.getPrefilledChoice();

    startWindow.close();

    model.resetGame(width, height, !prefilled);
    model.start();

    mainWindow.show();
}


void GUIController::update() {
    mainWindow.initialize();

    if(model.getGameState() == GameState::LOSS){
        CustomMessageBox *customMsgBox = new CustomMessageBox(this);
        customMsgBox->showMessage("You lost :(");

        //pop out: std::cout<<"You lost :("<<std::endl;
    } else if(model.getGameState() == GameState::SCOREWIN){
        //pop out: std::cout<<"You reached the maximum score!, Congragulations, you won ! :)"<<std::endl;
    } else if(model.getGameState() == GameState::LINESWIN){
        //pop out: std::cout<<"You reached the maximum number of deleted lines!,Congragulations, you won ! :)"<<std::endl;
    } else if(model.getGameState() == GameState::TIMELOSS){
        //pop out:std::cin.clear();
        //pop out:std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //pop out:std::cout << "Game Over: Time expired!" << std::endl;
    }

}

