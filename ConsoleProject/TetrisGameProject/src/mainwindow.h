#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene _scene; // La scène pour QGraphicsView
};
