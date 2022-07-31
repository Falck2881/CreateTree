#ifndef WindowInputData_H
#define WindowInputData_H

#include "LinkerCommands.h"
#include "InputData.h"
#include "ButtonActivityCommand.h"
#include "MainWindowGame.h"
#include <vector>

namespace Ui {
class  WindowInputData;
}

class  WindowInputData : public QWidget
{
    Q_OBJECT

    public:
        WindowInputData(QWidget* startGameWindow);
        ~WindowInputData();

    private:
        void initializeCondition();
        void addCommandsInLinkerForDemonstrationStartGameWindow();
        void addCommandsInLinkerForDemonstrationMainWindowGame();
        void addCommandsInDevelopmentConstructionBlocks();
        void connectToStartWindows();
        void connectToInputData();
        void connectToMainWWindowGameForTransferInputData();
        void connectToMainWindow();
    private:
        Ui:: WindowInputData *ui;
        QWidget* startGameWindow;
        std::unique_ptr<MainWindowGame> mainWinGame;
        std::unique_ptr<LinkerCommands> linkerStartGameWindow;
        std::unique_ptr<LinkerCommands> linkerMainWindowGame;
        std::unique_ptr<ButtonActivityCommand> onNextButton;
        std::unique_ptr<ButtonActivityCommand> offNextButton;
        std::unique_ptr<InputData> inputData;
};

#endif //  WindowInputData
