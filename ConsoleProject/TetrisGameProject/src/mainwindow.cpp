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

    displayBoard();


}

QColor MainWindow::getColorForShape(std::optional<TypeShape> shapeOpt) const {
    static const std::unordered_map<TypeShape, QColor> colorMap = {
        {TypeShape::O_SHAPE, Qt::yellow},
        {TypeShape::I_SHAPE, Qt::cyan},
        {TypeShape::S_SHAPE, Qt::green},
        {TypeShape::Z_SHAPE, Qt::red},
        {TypeShape::L_SHAPE, Qt::blue},
        {TypeShape::J_SHAPE, Qt::magenta},
        {TypeShape::T_SHAPE, Qt::yellow} // Ajoutez ici la couleur pour la forme T
    };

    if (shapeOpt.has_value()) {
        auto it = colorMap.find(shapeOpt.value());
        if (it != colorMap.end()) {
            return it->second;
        }
    }

    return Qt::white; // Couleur par défaut si le paramètre optionnel est vide ou le type de forme est manquant ou invalide
}

void MainWindow::displayBoard(){
    const auto board = game.getGameBoard();
    int height = board.getBoardHeight();
    int width = board.getBoardWidth();
    const auto boardArea = game.getGameBoard().getBoardArea();

    // Ajoute les rectangles à la scène en fonction de la hauteur et de la largeur du plateau
        int rectSize = 20; // Taille de chaque rectangle
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                QRectF rect(col * rectSize, row * rectSize, rectSize, rectSize); // Position et taille du rectangle
                QColor color = getColorForShape(boardArea[row][col]); // Obtient la couleur pour le type de forme
                _scene.addRect(rect, QPen(Qt::black), QBrush(color)); // Ajouter le rectangle à la scène
            }
        }
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


