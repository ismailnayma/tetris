#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(this)
{
    ui->setupUi(this);

    // Nous définissons la taille de la scène sur la taille de QGraphicsView pour simplifier le système de coordonnées
    QRect viewContentsRect = ui->myGraphicsView->contentsRect();
    _scene.setSceneRect(viewContentsRect);

    // Associer la scène à la vue
    ui->myGraphicsView->setScene(&_scene);

    // Dessine un rectangle à la position (20, 20) avec une largeur de 100 et une hauteur de 100 (coordonnées en haut à gauche)
    _scene.addRect(20, 20, 100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
