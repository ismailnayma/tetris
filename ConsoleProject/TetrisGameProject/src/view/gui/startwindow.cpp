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

    Game game(Game(width, height, !prefilled));
    MainWindow *mainWindow = new MainWindow (game);
    mainWindow->show();
}

StartWindow::~StartWindow()
{
    delete ui;
}
