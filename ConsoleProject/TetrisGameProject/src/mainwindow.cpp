#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(Game& game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(this),
    game(game),
    board(new BoardWidget)
{

    ui->setupUi(this);

    //Associer la scène à la vue
    ui->myGraphicsView->setScene(&_scene);


    // Instancier le contrôleur et le connecter à la vue MainWindow
    controller = new GUIController(game, this); // Assurez-vous de passer une référence à Game
    this->installEventFilter(controller); // Installer le filtre d'événements sur MainWindow

    // Nous définissons la taille de la scène sur la taille de QGraphicsView pour simplifier le système de coordonnées
    QRect viewContentsRect = ui->myGraphicsView->contentsRect();
    _scene.setSceneRect(viewContentsRect);


    // Dessine un rectangle à la position (20, 20) avec une largeur de 100 et une hauteur de 100 (coordonnées en haut à gauche)
    //_scene.addRect(20, 20, 100, 100);

    // Créer une instance du contrôleur GUIController et le connecter à la vue BoardWidget
   // GUIController *controller = new GUIController(board, this);
    // board->installEventFilter(controller); // Installer le filtre d'événements sur BoardWidget


    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

/*
    connect(startButton, &QPushButton::clicked, board, &BoardWidget::start);
    connect(quitButton , &QPushButton::clicked, qApp, &QCoreApplication::quit);
    connect(pauseButton, &QPushButton::clicked, board, &BoardWidget::pause);

    connect(board, &BoardWidget::scoreChanged,
            scoreLcd, qOverload<int>(&QLCDNumber::display));
    connect(board, &BoardWidget::levelChanged,
            levelLcd, qOverload<int>(&QLCDNumber::display));
    connect(board, &BoardWidget::linesRemovedChanged,
            linesLcd, qOverload<int>(&QLCDNumber::display));
*/


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    //layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("SCORE")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);

}

QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}

void MainWindow::update() {

    if(game.getGameState() == GameState::LOSS){
        //pop out: std::cout<<"You lost :("<<std::endl;
    } else if(game.getGameState() == GameState::SCOREWIN){
        //pop out: std::cout<<"You reached the maximum score!, Congragulations, you won ! :)"<<std::endl;
    } else if(game.getGameState() == GameState::LINESWIN){
        //pop out: std::cout<<"You reached the maximum number of deleted lines!,Congragulations, you won ! :)"<<std::endl;
    } else if(game.getGameState() == GameState::TIMELOSS){
        //pop out:std::cin.clear();
        //pop out:std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //pop out:std::cout << "Game Over: Time expired!" << std::endl;
    } else{
       // ConsoleView::displayLevelAndScore();
        //ConsoleView::showBoardAndBrick(game.getGameBoard().getBoardArea(),
        //                               game.getGameBoard().getBrickBoardPositions(game.getGameBoard().getBrick()),
      //                                 game.getGameBoard().getBrick().getTypeShape());

        // Récupérer les informations du modèle
        const auto& boardArea = game.getGameBoard().getBoardArea();
        const auto& currentBrickBoardPositions = game.getGameBoard().getBrickBoardPositions(game.getGameBoard().getBrick());

        const auto& currentBrickTypeShape = game.getGameBoard().getBrick().getTypeShape();

        // Mettre à jour l'affichage dans le widget BoardWidget
        //board->updateBoard(boardArea, currentBrickBoardPositions, currentBrickTypeShape);


    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


