#include "WindowInputData.h"
#include "ui_WindowInputData.h"
#include "ShowWgdCommand.h"
#include "HideWgdCommand.h"
#include "MainWindowGame.h"

WindowInputData::WindowInputData(MainWindowGame* const mainWinGame):
    ui(new Ui::WindowInputData),
    mainWinGame(mainWinGame)
{
    ui->setupUi(this);
    initializeCondition();
    connectToInputData();
    connectToMainWindowGameForTransferInputData();
}

void WindowInputData::initializeCondition()
{
    onNextButton = std::make_unique<ButtonActivityCommand>(ui->nextButton);
    offNextButton = std::make_unique<ButtonActivityCommand>(ui->nextButton);
    inputData = std::make_unique<InputData>(ui->lineEditUserName);
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

void WindowInputData::connectToMainWindowGameForTransferInputData()
{
    QObject::connect(inputData.get(), &InputData::transferInputData,
                     mainWinGame, &MainWindowGame::updateData);
}

void WindowInputData::show()
{
    if(isVisible())
        QWidget::show();
}

 WindowInputData::~WindowInputData()
{
    delete ui;
}
