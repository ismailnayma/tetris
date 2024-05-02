#include "GUIController.h"
#include <QKeyEvent>

GUIController::GUIController(QObject *parent)
    : QObject(parent), mainWindow(model)
{
    model.registerObserver(this);
    mainWindow.installEventFilter(this);

    connect(startWindow.getUi().playButton, SIGNAL(clicked(bool)), this, SLOT(playButtonHandler()));
    connect(restartWindow.getUi().replayPushButton, SIGNAL(clicked(bool)), this, SLOT(restartGame()));
    connect(restartWindow.getUi().quitPushButton, SIGNAL(clicked(bool)), this, SLOT(quitGame()));

    connect(&timer, &QTimer::timeout, this, &GUIController::intervalAction);

    startWindow.move(300, 200);
    mainWindow.move(200, 100);
    restartWindow.move(300,200);
    startWindow.show();
}

bool GUIController::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Q:
            model.moveCurrentBrick(Direction::LEFT);
            break;
        case Qt::Key_D:
            model.moveCurrentBrick(Direction::RIGHT);
            break;
        case Qt::Key_S:
            model.moveCurrentBrick(Direction::DOWN);
            break;
        case Qt::Key_Z:
            model.rotateCurrentBrick(Rotation::CLOCKWISE);
            break;
        case Qt::Key_A:
            model.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
            break;
        case Qt::Key_E:
            model.dropCurrentBrick();
            break;
        default:
            break;
        }
    }

    // Passez l'événement à l'objet parent (vue) pour qu'il le traite également
    return QObject::eventFilter(obj, event);
}

void GUIController::intervalAction()
{
    model.moveCurrentBrick(Direction::DOWN);
}

void GUIController::stopTimer()
{
    if(model.getGameState()== GameState::PLAYING){
        model.setState(GameState::TIMELOSS);
    }
    timer.stop();
}

void GUIController::playButtonHandler(){
    int width = startWindow.getWidthSpinBox();
    int height = startWindow.getHeightSpinBox();
    bool prefilled = startWindow.getPrefilledChoice();
    model.resetGame(width, height, !prefilled);
    startWindow.close();

    model.start();
    timer.setInterval((1000/60)* model.getGameLevel().getSpeed());
    timer.start();
    timer.singleShot(model.getDuration(), this, &GUIController::stopTimer);
    mainWindow.show();
}

void GUIController::restartGame(){
    startWindow.cleanRestart();
    restartWindow.close();
    startWindow.show();
}

void GUIController::quitGame(){
    restartWindow.close();
}

void GUIController::update() {
    mainWindow.initialize();

    if(model.getGameState() == GameState::LOSS){
        mainWindow.close();
        restartWindow.show();
        restartWindow.showMessage("You lost!");
        timer.stop();
    } else if(model.getGameState() == GameState::SCOREWIN){
        mainWindow.close();
        restartWindow.show();
        restartWindow.showMessage("You won! Max score reached!");
        timer.stop();
    } else if(model.getGameState() == GameState::LINESWIN){
        mainWindow.close();
        restartWindow.show();
        restartWindow.showMessage("You won! Max score reached!");
        timer.stop();
    } else if(model.getGameState() == GameState::TIMELOSS){
        mainWindow.close();
        restartWindow.show();
        restartWindow.showMessage("You lost! Time out!");
        timer.stop();
    }

}
