#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Game* game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(game),
    _scene(this)
{
    /*
    // Instanciez le contrôleur GUIController en passant une référence au jeu (game)
    controller = new GUIController(game);

    // Installez le filtre d'événements sur la vue principale (MainWindow)
    this->installEventFilter(controller);
*/
    // Initialisez le jeu
    game->start();

    // Configurez la scène et la vue graphique
    ui->setupUi(this);
    QRect viewContentsRect = ui->myGraphicsView->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->myGraphicsView->setScene(&_scene);

    // Installez le filtre d'événements sur la vue principale (MainWindow)
    this->installEventFilter(this);

    /*
    // Créer les raccourcis clavier
    QShortcut *leftShortcut = new QShortcut(Qt::Key_Left, this);
    QShortcut *rightShortcut = new QShortcut(Qt::Key_Right, this);
    QShortcut *downShortcut = new QShortcut(Qt::Key_Down, this);
    QShortcut *upShortcut = new QShortcut(Qt::Key_Up, this);
    QShortcut *zShortcut = new QShortcut(Qt::Key_Z, this);
    QShortcut *enterShortcut = new QShortcut(Qt::Key_Enter, this);

    // Connectez les raccourcis aux slots correspondants
    connect(leftShortcut, &QShortcut::activated, this, &MainWindow::onLeftKeyPressed);
    connect(rightShortcut, &QShortcut::activated, this, &MainWindow::onRightKeyPressed);
    connect(downShortcut, &QShortcut::activated, this, &MainWindow::onDownKeyPressed);
    connect(upShortcut, &QShortcut::activated, this, &MainWindow::onUpKeyPressed);
    connect(zShortcut, &QShortcut::activated, this, &MainWindow::onZKeyPressed);
    connect(enterShortcut, &QShortcut::activated, this, &MainWindow::onEnterKeyPressed);
*/
    // Initialisation supplémentaire si nécessaire
    initialize();


}

void MainWindow::initialize(){
    displayBoard();
    displayCurrentBrick();
    ui->lcdLevel->display(game->getGameLevel().getActualLevel());
    ui->lcdScore->display(game->getGameScore().getScore());
    ui->lcdLines->display(game->getGameLevel().getDeletedLines());

    displayBoard();
    displayCurrentBrick();
    ui->lcdLevel->display(game->getGameLevel().getActualLevel());
    ui->lcdScore->display(game->getGameScore().getScore());
    ui->lcdLines->display(game->getGameLevel().getDeletedLines());
}

QColor MainWindow::getColorForShape(std::optional<TypeShape> shapeOpt) const {
    static const std::unordered_map<TypeShape, QColor> colorMap = {
        {TypeShape::O_SHAPE, Qt::yellow},
        {TypeShape::I_SHAPE, Qt::cyan},
        {TypeShape::S_SHAPE, Qt::green},
        {TypeShape::Z_SHAPE, Qt::red},
        {TypeShape::L_SHAPE, Qt::blue},
        {TypeShape::J_SHAPE, Qt::magenta},
        {TypeShape::T_SHAPE, Qt::yellow} // Add color for T shape here
    };

    if (shapeOpt.has_value()) {
        auto it = colorMap.find(shapeOpt.value());
        if (it != colorMap.end()) {
            return it->second;
        }
    }

    return Qt::white; // Default color if optional parameter is empty or shape type is missing or invalid
}

void MainWindow::displayBoard(){
    const std::vector<std::vector<std::optional<TypeShape>>> boardArea = game->getGameBoard().getBoardArea();
    qDebug() << "je suis dans displayBoard debuut.";
    //_scene.clear();
    //int height =
     int height = boardArea.size();

    qDebug() << "je suis dans displayBoard apres height.";
     int width = boardArea.at(0).size();
       qDebug() << "je suis dans displayBoard apres width.";
    //const std::vector<std::vector<std::optional<TypeShape>>> boardArea = game.getGameBoard().getBoardArea();

  qDebug() << "je suis dans displayBoard milieu.";
    // Add rectangles to the scene based on the height and width of the board
    int rectSize = 20; // Size of each rectangle
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            QRectF rect(col * rectSize, row * rectSize, rectSize, rectSize); // Position and size of the rectangle
            std::optional<TypeShape> shape = boardArea[row][col];
            //std::optional<TypeShape> shape = TypeShape::L_SHAPE;
            QColor color = getColorForShape(shape); // Get color for the shape type
            _scene.addRect(rect, QPen(Qt::black), QBrush(color)); // Add the rectangle to the scene
        }
    }

    qDebug() << "je suis dans displayBoard fin.";
}

void MainWindow::displayCurrentBrick(){
    const auto currentBrickBoardPositions = game->getGameBoard().getBrickBoardPositions(game->getGameBoard().getBrick());
    const auto currentBrickTypeShape = game->getGameBoard().getBrick().getTypeShape();
    int rectSize = 20;

       // Iterate over the positions of the current brick
       for (const auto& position : currentBrickBoardPositions) {
           int x = position.getPosX() * rectSize; // X coordinate of the rectangle
           int y = position.getPosY() * rectSize; // Y coordinate of the rectangle

           // Update the color of the rectangle at position (x, y) in the scene
           QColor color = getColorForShape(currentBrickTypeShape);
           _scene.addRect(x, y, rectSize, rectSize, QPen(Qt::black), QBrush(color));
       }
}



void MainWindow::update() {


    if(game->getGameState() == GameState::LOSS){
        //pop out: std::cout<<"You lost :("<<std::endl;
    } else if(game->getGameState() == GameState::SCOREWIN){
        //pop out: std::cout<<"You reached the maximum score!, Congragulations, you won ! :)"<<std::endl;
    } else if(game->getGameState() == GameState::LINESWIN){
        //pop out: std::cout<<"You reached the maximum number of deleted lines!,Congragulations, you won ! :)"<<std::endl;
    } else if(game->getGameState() == GameState::TIMELOSS){
        //pop out:std::cin.clear();
        //pop out:std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //pop out:std::cout << "Game Over: Time expired!" << std::endl;
    } else{
        displayBoard();
        displayCurrentBrick();
        ui->lcdLevel->display(game->getGameLevel().getActualLevel());
        ui->lcdScore->display(game->getGameScore().getScore());
        ui->lcdLines->display(game->getGameLevel().getDeletedLines());
    }

}

/*
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Left:
            qDebug() << "Une touche a été gauche.";
            game->moveCurrentBrick(Direction::LEFT);
            break;
        case Qt::Key_Right:
            qDebug() << "Une touche a été droite.";
            game->moveCurrentBrick(Direction::RIGHT);
            break;
        case Qt::Key_Down:
            qDebug() << "Une touche a été bas.";
            game->moveCurrentBrick(Direction::DOWN);
            break;
        case Qt::Key_Up:
            qDebug() << "Une touche a été haut.";
            game->rotateCurrentBrick(Rotation::CLOCKWISE);
            break;
        case Qt::Key_Z:
            qDebug() << "Une touche Z a été haut.";
            game->rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
            break;
        case Qt::Key_Enter:
            qDebug() << "Une touche enter été haut.";
            game->dropCurrentBrick();
            break;
        default:
              qDebug() << "je suis dans default.";
            break;
        }
    }

    // Laissez l'événement être traité par la classe de base
    return QMainWindow::eventFilter(obj, event);
}
*/
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Q:
            qDebug() << "Une touche a été gauche.";
            game->moveCurrentBrick(Direction::LEFT);
            break;
        case Qt::Key_D:
            qDebug() << "Une touche a été droite.";
            game->moveCurrentBrick(Direction::RIGHT);
            break;
        case Qt::Key_S:
            qDebug() << "Une touche a été bas.";
            game->moveCurrentBrick(Direction::DOWN);
            break;
        case Qt::Key_Z:
            qDebug() << "Une touche a été haut.";
            game->rotateCurrentBrick(Rotation::CLOCKWISE);
            break;
        case Qt::Key_A:
            qDebug() << "Une touche Z a été haut.";
            game->rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
            break;
        case Qt::Key_E:
            qDebug() << "Une touche enter été haut.";
            game->dropCurrentBrick();
            break;
        default:
            qDebug() << "je suis dans default.";
            break;
        }
    }

    // Laissez l'événement être traité par la classe de base
    return QMainWindow::eventFilter(obj, event);
}


/*
void MainWindow::onLeftKeyPressed() {
    game->moveCurrentBrick(Direction::LEFT);
}

void MainWindow::onRightKeyPressed() {
    game->moveCurrentBrick(Direction::RIGHT);
}

void MainWindow::onDownKeyPressed() {
    game->moveCurrentBrick(Direction::DOWN);
}

void MainWindow::onUpKeyPressed() {
    game->rotateCurrentBrick(Rotation::CLOCKWISE);
}

void MainWindow::onZKeyPressed() {
     qDebug() << "Z été pressée.";
    game->rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
}

void MainWindow::onEnterKeyPressed() {
    game->dropCurrentBrick();
}
*/


MainWindow::~MainWindow()
{
    delete ui;
}


