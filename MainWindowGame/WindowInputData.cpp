#include "WindowInputData.h"
#include "ui_WindowInputData.h"
#include "ShowWgdCommand.h"
#include "HideWgdCommand.h"
#include "MainWindowGame.h"

WindowInputData::WindowInputData(MainWindowGame* const mainWin):
    ui(new Ui::WindowInputData),
    mainWindow(mainWin)
{
    ui->setupUi(this);
    initializeCondition();
    connectToInputData();
    connectWithCurrentWindow();
}

void WindowInputData::initializeCondition()
{
    onNextButton = std::make_unique<ButtonActivityCommand>(ui->okButton);
    offNextButton = std::make_unique<ButtonActivityCommand>(ui->okButton);
    inputData = std::make_unique<KeyboardInput>(ui->lineEditUserName);
}

void WindowInputData::connectToInputData()
{

    QObject::connect(ui->lineEditUserName, &QLineEdit::textEdited,
                     inputData.get(), &KeyboardInput::transferData);

    QObject::connect(inputData.get(), &KeyboardInput::controlPassed,
                     onNextButton.get(), &ButtonActivityCommand::on);

    QObject::connect(inputData.get(), &KeyboardInput::controlNotPassed,
                     offNextButton.get(), &ButtonActivityCommand::off);

    QObject::connect(inputData.get(), &KeyboardInput::transferInputData,
                     mainWindow, &MainWindowGame::updateStateObjects);

}

void WindowInputData::connectWithCurrentWindow()
{
    QObject::connect(ui->okButton, &QPushButton::clicked,
                     this, &WindowInputData::hide);

    QObject::connect(ui->okButton, &QPushButton::clicked,
                     inputData.get(), &KeyboardInput::clearLineEdit);
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
