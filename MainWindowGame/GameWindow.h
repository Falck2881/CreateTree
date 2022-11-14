#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "LinkerCommands.h"
#include "GraphicsTree.h"
#include <memory>
#include <utility>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

    public:
        GameWindow(QWidget* const mainWin);
        ~GameWindow();
        void updateGraphicsView(QGraphicsScene* const scene);
        void updateInformationAboutNode(std::pair<QString,QPixmap> node);
        void completionConstruction();
        void updateStatyTree(std::unique_ptr<GraphicsBuilder> builder);
        void updateStatyTree(std::unique_ptr<Array> newTypeArray);
        void setNameBuilder(const QString nameBuilder);
        void setMethodBuild(const QString methodBuild);
    private slots:
        void updateUi();
    private:
        void addCommandsInLinkerMainWindow();
        void connectToMainWindow();
        void connectToManagerBuildingTree();
        void windowPlacementInParentPos();
    private:
        std::unique_ptr<GraphicsTree> tree;
        std::unique_ptr<LinkerCommands> linkerMainWindow;
        Ui::GameWindow *ui;
        QWidget* const mainWindow;
};

#endif // GAMEWINDOW_H
