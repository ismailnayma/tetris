#include "startwindow.h"

#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow),
    _scene(this)
{
    ui->setupUi(this);

    connect(ui->playButton, SIGNAL(clicked(bool)), this, SLOT(playButton()));
}

void StartWindow::playButton(){
    int width = ui->groupBox->findChild<QSpinBox *>("widthSpinBox") -> value();
    int height = ui->groupBox->findChild<QSpinBox *>("heightSpinBox")  -> value();
    bool prefilled = ui->groupBox->findChild<QCheckBox *>("checkBoxPrefilled")->isChecked();

    this->close();

    Game* game = new Game(width, height, !prefilled); // Créer Game sur le tas
    MainWindow* mainWindow = new MainWindow(game); // Créer MainWindow sur le tas
    game->registerObserver(mainWindow);
    mainWindow->show();
}

StartWindow::~StartWindow()
{
    delete ui;
}
