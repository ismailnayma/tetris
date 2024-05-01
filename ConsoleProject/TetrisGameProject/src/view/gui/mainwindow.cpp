#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(Game& game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(game),
    _scene(this)
{

    // Configurez la scène et la vue graphique
    ui->setupUi(this);
    QRect viewContentsRect = ui->myGraphicsView->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->myGraphicsView->setScene(&_scene);

    // Initialisation supplémentaire si nécessaire
    initialize();
}

void MainWindow::initialize(){
    displayBoard();
    displayCurrentBrick();
    ui->lcdLevel->display(game.getGameLevel().getActualLevel());
    ui->lcdScore->display(game.getGameScore().getScore());
    ui->lcdLines->display(game.getGameLevel().getDeletedLines());
}

QColor MainWindow::getColorForShape(std::optional<TypeShape> shapeOpt) const {
    static const std::unordered_map<TypeShape, QColor> colorMap = {
        {TypeShape::O_SHAPE, Qt::yellow},
        {TypeShape::I_SHAPE, Qt::cyan},
        {TypeShape::S_SHAPE, Qt::green},
        {TypeShape::Z_SHAPE, Qt::red},
        {TypeShape::L_SHAPE, Qt::blue},
        {TypeShape::J_SHAPE, Qt::magenta},
        {TypeShape::T_SHAPE, Qt::gray} // Add color for T shape here
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
    const std::vector<std::vector<std::optional<TypeShape>>> boardArea = game.getGameBoard().getBoardArea();
    int height = boardArea.size();
    int width = boardArea.at(0).size();

    // Add rectangles to the scene based on the height and width of the board
    int rectSize = 20; // Size of each rectangle
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            QRectF rect(col * rectSize, row * rectSize, rectSize, rectSize); // Position and size of the rectangle
            std::optional<TypeShape> shape = boardArea[row][col];
            QColor color = getColorForShape(shape); // Get color for the shape type
            _scene.addRect(rect, QPen(Qt::black), QBrush(color)); // Add the rectangle to the scene
        }
    }
}

void MainWindow::displayCurrentBrick(){
    const auto currentBrickBoardPositions = game.getGameBoard().getBrickBoardPositions(game.getGameBoard().getBrick());
    const auto currentBrickTypeShape = game.getGameBoard().getBrick().getTypeShape();
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


MainWindow::~MainWindow()
{
    //delete game;
    delete ui;
}


