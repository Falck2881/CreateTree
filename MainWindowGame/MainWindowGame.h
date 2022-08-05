#ifndef MAINWINDOWGAME_H
#define MAINWINDOWGAME_H

#include "SourceBinaryTree/StreamJson.h"
#include "LinkerCommands.h"
#include <QWidget>
#include <memory>
#include <QPixmap>

class WindowInputData;

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
        void updateData(const QString nameBuilder);

    private:
        void setAnimation();
        void connectToDifferentButton() const;

    private:
        StreamJson streamJson;
        Ui::MainWindowGame *ui;
        std::unique_ptr<QWidget> winInputData;
        std::unique_ptr<LinkerCommands> linkerWindowInputData;

};

#endif // MAINWINDOWGAME_H
