#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include "LinkerCommands.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit StartWindow(QWidget *parent = nullptr);
        ~StartWindow();

    protected:
        void paintEvent(QPaintEvent *event) override;
    private:
        void connectToAnotherWindows();
        void connectLogoGif();
        void connectToWindowInputData();
        void addCommandInLinker();
    private:
        Ui::StartWindow *ui;
        std::unique_ptr<QWidget> windowInput;
        std::unique_ptr<LinkerCommands> linkerWinSwitching;
};

#endif // STARTWINDOW_H
