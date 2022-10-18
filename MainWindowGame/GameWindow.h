#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "LinkerCommands.h"
#include "MethodCustomizationUi.h"
#include "ManagerGameWindow.h"
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
    };
}

class GameWindow : public QWidget
{
    Q_OBJECT

    public:
        GameWindow(QWidget* const mainWin);
        ~GameWindow();
        void updateGraphicsView(QGraphicsScene* const scene);
        void updateInformationAboutNode(std::pair<QString,QPixmap> node);
        void updateUiAboutStrategy(std::unique_ptr<MethodCustomizationUi> cusomizationUi);
        void completionConstruction();
        void updateStatyManager(GraphicsBuilder* builder);
        void updateStatyManager(ArrayNodes* newTypeArray);
    private:
        void postAUiTheGameWindow();
        void addCommandsInLinkerMainWindow();
        void connectToMainWindow();
        void connectToManagerBuildingTree();
    private:
        std::unique_ptr<ManagerGameWindow> managerGameWin;
        std::unique_ptr<LinkerCommands> linkerMainWindow;
        Ui::GameWindow *ui;
        QWidget* const mainWindow;
        QLabel titleStrategy;
        QLabel titleBuilder;
        GW::Ui uiGameWin;
};

#endif // GAMEWINDOW_H
