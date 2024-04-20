#include "controller/ConsoleController.h"
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Game model = Game();
    //ConsoleController controller = ConsoleController(model);
    //controller.playTetris();

    QApplication application(argc, argv);
    MainWindow myWindow;
    myWindow.show();

    return application.exec();

}
