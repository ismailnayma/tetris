#include "GUIController.h"

GUIController::GUIController(QObject *parent)
    : QObject(parent), mainWindow(model)
{
    startWindow.move(300, 200);
    mainWindow.move(200, 100);
    restartWindow.move(300,200);

    model.registerObserver(this);

    mainWindow.installEventFilter(this);

    connect(startWindow.getUi().playButton, SIGNAL(clicked(bool)), this, SLOT(playButtonHandler()));
    connect(restartWindow.getUi().replayPushButton, SIGNAL(clicked(bool)), this, SLOT(restartGame()));
    connect(restartWindow.getUi().quitPushButton, SIGNAL(clicked(bool)), this, SLOT(quitGame()));
    connect(&timer, &QTimer::timeout, this, &GUIController::intervalAction);
    connect(&timerDuration, &QTimer::timeout, this, &GUIController::stopTimerDuration);

    startWindow.show();
}

bool GUIController::eventFilter(QObject *obj, QEvent *event){

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
        case Qt::Key_L:
            askIfReplayGame();
        default:
            break;
        }
    }

    // Pass the event to the parent object (view) for it to handle as well
    return QObject::eventFilter(obj, event);
}

void GUIController::update() {
    mainWindow.initialize();
    timer.setInterval((1000/60) * model.getGameLevel().getSpeed());

    QString message;
    switch(model.getGameState()) {
    case GameState::LOSS:
        message = "You lost!";
        break;
    case GameState::SCOREWIN:
        message = "You won! Max score reached!";
        break;
    case GameState::LINESWIN:
        message = "You won! Max lines reached!";
        break;
    case GameState::TIMELOSS:
        message = "You lost! Time out!";
        break;
    default:
        return; // Do nothing for other states and continue playing
    }

    askIfReplayGame(message);
}

void GUIController::stopTimerDuration(){
    if(model.getGameState()== GameState::PLAYING){
            model.setState(GameState::TIMELOSS);
    }

    timer.stop();
    timerDuration.stop();
}

void GUIController::playButtonHandler(){
    int width = startWindow.getWidthSpinBox();
    int height = startWindow.getHeightSpinBox();
    bool prefilled = startWindow.getPrefilledChoice();
    model.resetGame(width, height, !prefilled);
    model.start();

    timer.setInterval((1000/60) * model.getGameLevel().getSpeed());
    timerDuration.start(model.getDuration());
    timer.start();

    startWindow.close();
    mainWindow.show();
}

void GUIController::intervalAction() {
    model.moveCurrentBrick(Direction::DOWN);
}

void GUIController::askIfReplayGame(QString message){
    timer.stop();
    timerDuration.stop();
    mainWindow.close();
    restartWindow.show();
    restartWindow.showMessage(message);
}

void GUIController::restartGame(){
    startWindow.cleanRestart();
    restartWindow.close();
    startWindow.show();
}

void GUIController::quitGame(){
    restartWindow.close();
}
