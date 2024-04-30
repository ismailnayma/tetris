#include "controller/ConsoleController.h"
#include <QApplication>

#include "model/Game.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    //Game model = Game();
    //ConsoleController controller = ConsoleController(model);
    //controller.playTetris();

    QApplication application(argc, argv);
    Game model = Game(15, 30, false);

    MainWindow guiView (model);


    guiView.show();

    return application.exec();
}
