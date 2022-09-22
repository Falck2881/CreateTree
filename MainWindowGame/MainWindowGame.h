#ifndef MAINWINDOWGAME_H
#define MAINWINDOWGAME_H

#include "LinkerCommands.h"
#include <QWidget>
#include <memory>
#include <QPixmap>

class GameWindow;
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
    private:
        Ui::MainWindowGame *ui;
        std::unique_ptr<QWidget> winInputData;
        std::unique_ptr<GameWindow> gameWindow;
        std::unique_ptr<LinkerCommands> linkerGameWindow;
        std::unique_ptr<LinkerMethodsBuilds> linkerMethodsBuilds;
};

#endif // MAINWINDOWGAME_H
