#include "WindowInputData.h"
#include "ui_WindowInputData.h"
#include "ShowWgdCommand.h"
#include "HideWgdCommand.h"
#include "MainWindowGame.h"

WindowInputData::WindowInputData
(QWidget* startGameWindow):
    ui(new Ui::WindowInputData),
    startGameWindow{startGameWindow},
    mainWinGame{std::make_unique<MainWindowGame>(this)},
    linkerStartGameWindow{std::make_unique<LinkerCommands>()},
    linkerMainWindowGame{std::make_unique<LinkerCommands>()}

{
    ui->setupUi(this);
    initializeCondition();
    addCommandsInLinkerForDemonstrationStartGameWindow();
    addCommandsInLinkerForDemonstrationMainWindowGame();
    connectToStartWindows();
    connectToInputData();
    connectToMainWWindowGameForTransferInputData();
    connectToMainWindow();
}

void WindowInputData::initializeCondition()
{
    onNextButton = std::make_unique<ButtonActivityCommand>(ui->nextButton);
    offNextButton = std::make_unique<ButtonActivityCommand>(ui->nextButton);
    inputData = std::make_unique<InputData>(ui->lineEditUserName);
}

void WindowInputData::addCommandsInLinkerForDemonstrationStartGameWindow()
{
    using namespace std;
    linkerStartGameWindow->addCommand(make_unique<HideWgdCommand>(this));
    linkerStartGameWindow->addCommand(make_unique<ShowWgdCommand>(startGameWindow));
}

void WindowInputData::addCommandsInLinkerForDemonstrationMainWindowGame()
{
    using namespace std;
    linkerMainWindowGame->addCommand(make_unique<HideWgdCommand>(this));
    linkerMainWindowGame->addCommand(make_unique<ShowWgdCommand>(mainWinGame.get()));
}

void WindowInputData::connectToStartWindows()
{
    QObject::connect(ui->backButton, &QPushButton::clicked,
                     linkerStartGameWindow.get(),
                     &LinkerCommands::executeAllCommands);
}

void WindowInputData::connectToInputData()
{

    QObject::connect(ui->lineEditUserName, &QLineEdit::textEdited,
                     inputData.get(), &InputData::check);

    QObject::connect(inputData.get(), &InputData::controlPassed,
                     onNextButton.get(), &ButtonActivityCommand::on);

    QObject::connect(inputData.get(), &InputData::controlNotPassed,
                     offNextButton.get(), &ButtonActivityCommand::off);

}

void WindowInputData::connectToMainWWindowGameForTransferInputData()
{
    QObject::connect(inputData.get(), &InputData::transferInputData,
                     mainWinGame.get(), &MainWindowGame::loadingConstructionBlocks);
}

void WindowInputData::connectToMainWindow()
{
    QObject::connect(ui->nextButton, &QPushButton::clicked,
                     linkerMainWindowGame.get(),
                     &LinkerCommands::executeAllCommands);
}

 WindowInputData::~WindowInputData()
{
    delete ui;
}
