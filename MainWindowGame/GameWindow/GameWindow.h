#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "NodeProxy.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit GameWindow(QWidget* const mainWindow);
        ~GameWindow();
        void setNodesProxy(const std::vector<std::unique_ptr<NodeProxy>> newNodesProxy);

    private:
        std::vector<std::unique_ptr<NodeProxy>> nodesProxy;
        Ui::GameWindow *ui;
        QWidget* const mainWindow;
};

#endif // GAMEWINDOW_H
