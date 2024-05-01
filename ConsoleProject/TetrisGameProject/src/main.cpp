#include "controller/ConsoleController.h"
#include <QApplication>

#include "model/Game.h"
#include "view/gui/mainwindow.h"
#include "view/gui/startwindow.h"

int main(int argc, char *argv[])
{
    //Game model = Game();
    //ConsoleController controller = ConsoleController(model);
    //controller.playTetris();

    QApplication application(argc, argv);
    //Game model = Game(20, 35, false);

    //MainWindow guiView (model);
    StartWindow start;

    //guiView.show();
    start.show();

    return application.exec();
}
