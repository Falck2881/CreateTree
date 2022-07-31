#include "MainWindowGame.h"
#include "ShowWgdCommand.h"
#include "HideWgdCommand.h"
#include "ui_MainWindowGame.h"
#include <QPainter>


MainWindowGame::MainWindowGame(QWidget *winInputDataUser):
    ui(new Ui::MainWindowGame),
    winInputDataUser(winInputDataUser),
    linkerWindowInputData(std::make_unique<LinkerCommands>())
{
    Q_INIT_RESOURCE(Images);
    ui->setupUi(this);
    addCommandToLinkerWindowInputData();
    connectWithWindowsInputData();
}

void MainWindowGame::addCommandToLinkerWindowInputData()
{
    linkerWindowInputData.get()->addCommand(std::make_unique<HideWgdCommand>(this));
    linkerWindowInputData.get()->addCommand(std::make_unique<ShowWgdCommand>(winInputDataUser));
}

void MainWindowGame::connectWithWindowsInputData()
{
    QObject::connect(ui->backButton, &QPushButton::clicked,
                     linkerWindowInputData.get(), &LinkerCommands::executeAllCommands);
}

void MainWindowGame::loadingConstructionBlocks(const QString& str)
{

}

MainWindowGame::~MainWindowGame()
{
    delete ui;
}
