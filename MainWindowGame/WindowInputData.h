#ifndef WindowInputData_H
#define WindowInputData_H

#include "LinkerCommands.h"
#include "KeyboardInput.h"
#include "ButtonActivityCommand.h"
#include <vector>

class MainWindowGame;

namespace Ui {
class  WindowInputData;
}

class  WindowInputData : public QWidget
{
    Q_OBJECT

    public:
        WindowInputData(MainWindowGame* const mainWinGame);
        ~WindowInputData();
    public slots:
        void show();
    private:
        void initializeCondition();
        void addCommandsInDevelopmentConstructionBlocks();
        void connectToInputData();
        void connectWithCurrentWindow();
    private:
        Ui::WindowInputData *ui;
        MainWindowGame* const mainWinGame;
        std::unique_ptr<ButtonActivityCommand> onNextButton;
        std::unique_ptr<ButtonActivityCommand> offNextButton;
        std::unique_ptr<KeyboardInput> inputData;
};

#endif //  WindowInputData
