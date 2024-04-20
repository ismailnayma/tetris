#include "controller/ConsoleController.h"
#include <QApplication>

#include "model/Game.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    //Game model = Game();
    //ConsoleController controller = ConsoleController(model);
    //controller.playTetris();

    Game model = Game();
    MainWindow guiView (model);

    QApplication application(argc, argv);
    guiView.show();

    return application.exec();
}
