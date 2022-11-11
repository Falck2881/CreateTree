#ifndef MAINWINDOWGAME_H
#define MAINWINDOWGAME_H

#include "ButtonActivityCommand.h"
#include "LinkerCommands.h"
#include <memory>
#include <QPixmap>
#include <QWidget>

class GameWindow;
class WindowInputData;
class LinkerMethodsBuilds;

namespace Ui {
class MainWindowGame;
}

class MainWindowGame : public QWidget
{
    Q_OBJECT

    public:
        MainWindowGame();
        ~MainWindowGame();
    public slots:
        void updateStateObjects(const QString nameBuilder);

    private:
        void setStatyStartButton();
        void setAnimation();
        void connectToWindowInputData() const;
        void connectToGameWindow() const;
        void disconect() const;
        void updateTitleNameBuilder(const QString& nameBuilder);
        void addCommandsInLinkerShowGameWindow();
        void addMethodBuildInLinkerMethodsBuilds();
        void updateStatyStartButton(const QString& nameBuilder);
        void windowPlacementInParentPos();
    private:
        Ui::MainWindowGame *ui;
        std::shared_ptr<GameWindow> gameWindow;
        std::unique_ptr<WindowInputData> winInputData;
        std::unique_ptr<LinkerCommands> linkerGameWindow;
        std::unique_ptr<LinkerMethodsBuilds> linkerMethodsBuilds;
        std::unique_ptr<ButtonActivityCommand> startButton;
};

#endif // MAINWINDOWGAME_H
