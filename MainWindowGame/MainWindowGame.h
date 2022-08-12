#ifndef MAINWINDOWGAME_H
#define MAINWINDOWGAME_H

#include "SourceBinaryTree/ManagerBuilder.h"
#include "LinkerCommands.h"
#include <QWidget>
#include <memory>
#include <QPixmap>

class GameWindow;

namespace Ui {
class MainWindowGame;
}

class MainWindowGame : public QWidget
{
    Q_OBJECT

    public:
        MainWindowGame();
        ~MainWindowGame();
        void updateDataInGameWindow(std::vector<std::unique_ptr<NodeProxy>> nodesProxy);
    public slots:
        void updateData(const QString nameBuilder);

    private:
        void setAnimation();
        void connectToWindowInputData() const;
        void connectToGameWindow() const;
        void disconect() const;
        void setBinaryTreeConstructionStrategies();
        void updateTitleNameBuilder(const QString& nameBuilder);
        void addCommandsInLinkerShowGameWindow();
    private:
        Ui::MainWindowGame *ui;
        std::unique_ptr<QWidget> winInputData;
        std::unique_ptr<ManagerBuilder> managerBuilder;
        std::unique_ptr<GameWindow> gameWindow;
        std::unique_ptr<LinkerCommands> linkerShowGameWindow;
};

#endif // MAINWINDOWGAME_H
