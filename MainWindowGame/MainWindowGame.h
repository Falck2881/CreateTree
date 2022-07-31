#ifndef MAINWINDOWGAME_H
#define MAINWINDOWGAME_H

#include <QWidget>
#include <memory>
#include "LinkerCommands.h"
#include <QPixmap>

namespace Ui {
class MainWindowGame;
}

class MainWindowGame : public QWidget
{
    Q_OBJECT

    public:
        explicit MainWindowGame(QWidget * const winInputDataUser);
        ~MainWindowGame();
    public slots:
        void loadingConstructionBlocks(const QString& data);

    private:
        void connectWithWindowsInputData();
        void addCommandToLinkerWindowInputData();
    private:
        QPixmap background;
        Ui::MainWindowGame *ui;
        QWidget* const winInputDataUser;
        std::unique_ptr<LinkerCommands> linkerWindowInputData;

};

#endif // MAINWINDOWGAME_H
