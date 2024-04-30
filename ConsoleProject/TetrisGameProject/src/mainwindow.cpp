#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(Game& game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(game),
    _scene(this)
{
    game.start();

    ui->setupUi(this);

    QRect viewContentsRect = ui->myGraphicsView->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->myGraphicsView->setScene(&_scene);
    ui->myGraphicsView->setAlignment(Qt::AlignCenter);
    QString styleSheet = "QGraphicsView { border: none; }";
    ui->myGraphicsView->setStyleSheet(styleSheet);

    int columns = 10;
    int rows = 20;
    int startX = 20; // Position de départ en X
        int startY = 20; // Position de départ en Y
        int size = 20; // Taille des rectangles
        int spacingX = 0; // Espacement horizontal entre les colonnes
        int spacingY = 0; // Espacement vertical entre les lignes

        for (int i = 0; i < columns; ++i) {
            for (int j = 0; j < rows; ++j) {
                _scene.addRect(startX + (size + spacingX) * i, startY + (size + spacingY) * j, size, size);
            }
        }
    /*
    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

    QGridLayout *layout = new QGridLayout();

    // Première colonne
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    // Ajoutez ici le widget pour afficher la prochaine pièce (nextPieceLabel)

    layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
    // Ajoutez ici le widget pour afficher le niveau (levelLcd)

    layout->addWidget(startButton, 4, 0);

    // Deuxième colonne
    layout->addWidget(board, 0, 1, 6, 1);

    // Troisième colonne
    layout->addWidget(createLabel(tr("SCORE")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);

    layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    // Ajoutez ici le widget pour afficher les lignes supprimées (linesLcd)

    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);

    update();
    */
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
        const auto boardArea = game.getGameBoard().getBoardArea();
        const auto currentBrickBoardPositions = game.getGameBoard().getBrickBoardPositions(game.getGameBoard().getBrick());

        const auto currentBrickTypeShape = game.getGameBoard().getBrick().getTypeShape();

        // Mettre à jour l'affichage dans le widget BoardWidget



    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


