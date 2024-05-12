#include "controller/ConsoleController.h"
#include <QApplication>

#include "model/Game.h"
#include "controller/GUIController.h"

int main(int argc, char *argv[])
{

    //To execute the console project you can decomment that and comment the next code
    //Game model = Game();
    //ConsoleController controller = ConsoleController(model);
    //controller.playTetris();

    QApplication application(argc, argv);

    GUIController guiController;

    return application.exec();
}
