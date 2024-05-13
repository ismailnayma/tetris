#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(Game& game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(game),
    _scene(this)
{
    // Configure the scene and the graphical view
    ui->setupUi(this);
    QRect viewContentsRect = ui->myGraphicsView->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->myGraphicsView->setScene(&_scene);

}

void MainWindow::initialize(){
    ui->myGraphicsView->scene()->clear();
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
        {TypeShape::T_SHAPE, Qt::darkRed}
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
    int height = game.getGameBoard().getBoardHeight();
    int width = game.getGameBoard().getBoardWidth();

    // Add rectangles to the scene based on the height and width of the board
    int rectSize = computeRectSize();

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

    int rectSize = computeRectSize();
       // Iterate over the positions of the current brick
       for (const auto& position : currentBrickBoardPositions) {
           int x = position.getPosX() * rectSize; // X coordinate of the rectangle
           int y = position.getPosY() * rectSize; // Y coordinate of the rectangle

           // Update the color of the rectangle at position (x, y) in the sceneqq
           QColor color = getColorForShape(currentBrickTypeShape);
           _scene.addRect(x, y, rectSize, rectSize, QPen(Qt::black), QBrush(color));
       }
}

int MainWindow::computeRectSize(){
    int height = game.getGameBoard().getBoardHeight();
    int width = game.getGameBoard().getBoardWidth();
    int rectSize;

    if (height > width) {
        rectSize =ui->myGraphicsView->height() / height * 0.85;
    } else {
        rectSize = ui->myGraphicsView->width() / width * 0.85;
    }
    return rectSize;
}

MainWindow::~MainWindow()
{
    delete ui;
}
