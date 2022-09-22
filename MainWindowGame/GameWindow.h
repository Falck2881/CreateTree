#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "LinkerCommands.h"
#include "MethodCustomizationUi.h"
#include "ManagerGameWindow.h"
#include <QWidget>
#include <memory>
#include <utility>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class GameWindow;
}

namespace GW
{
    struct Ui
    {
        QLabel builder;
        QLabel strategy;
        QPushButton* balancedButton;
    };
}

class GameWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit GameWindow(QWidget* const mainWindow);
        ~GameWindow();
        void updateGraphicsView(QGraphicsScene* const scene);
        void updateInformationAboutNode(std::pair<QString,QPixmap> node);
        void updateUiAboutStrategy(std::unique_ptr<MethodCustomizationUi> cusomizationUi);
        void gameEnd();

        const std::unique_ptr<ManagerGameWindow> managerGameWin;
    private:
        void postAUiTheGameWindow();
        void addCommandsInLinkerMainWindow();
        void connectToMainWindow();
        void connectToManagerBuildingTree();
    private:
        std::unique_ptr<LinkerCommands> linkerMainWindow;
        Ui::GameWindow *ui;
        QWidget* const mainWindow;
        QLabel titleStrategy;
        QLabel titleBuilder;
        GW::Ui uiGameWin;
};

#endif // GAMEWINDOW_H
