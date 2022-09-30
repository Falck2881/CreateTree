#include "MainWindowGame.h"
#include "GameWindow.h"
#include "ui_MainWindowGame.h"
#include "WindowInputData.h"
#include "HideWgdCommand.h"
#include "ShowWgdCommand.h"
#include "MethodBuild.h"
#include <QMovie>
#include <QPainter>


MainWindowGame::MainWindowGame():
    ui(new Ui::MainWindowGame),
    winInputData(std::make_unique<WindowInputData>(this)),
    gameWindow{std::make_unique<GameWindow>(this)},
    linkerGameWindow{std::make_unique<LinkerCommands>()},
    linkerMethodsBuilds{std::make_unique<LinkerMethodsBuilds>(gameWindow.get())}
{
    Q_INIT_RESOURCE(DifferentImages);
    ui->setupUi(this);
    setAnimation();
    setStatyStartButton();
    addMethodBuildInLinkerMethodsBuilds();
    addCommandsInLinkerShowGameWindow();
    connectToWindowInputData();
    connectToGameWindow();
    disconect();
}

void MainWindowGame::setAnimation()
{
    QMovie* bobAnimation = new QMovie(":/DiffImg/bobBuilder.gif");
    ui->animation->setMovie(bobAnimation);
    bobAnimation->start();
}

void MainWindowGame::setStatyStartButton()
{
   ui->startButton->setEnabled(false);
}

void MainWindowGame::addMethodBuildInLinkerMethodsBuilds()
{
    linkerMethodsBuilds->append(std::make_unique<MethodBuildRandomTree>(ui->randButton));
    linkerMethodsBuilds->append(std::make_unique<MethodBuildPerfectBalancedTree>(ui->pbtButton));
    linkerMethodsBuilds->append(std::make_unique<MethodBuildAvlTree>(ui->avlButton));
}

void MainWindowGame::addCommandsInLinkerShowGameWindow()
{
    linkerGameWindow->addCommand(std::make_unique<HideWgdCommand>(this));
    linkerGameWindow->addCommand(std::make_unique<ShowWgdCommand>(gameWindow.get()));
}


void MainWindowGame::connectToWindowInputData() const
{
    QObject::connect(ui->changeNameButton, &QPushButton::clicked,
                     winInputData.get(), &QWidget::show);
}

void MainWindowGame::connectToGameWindow() const
{
    QObject::connect(ui->startButton, &QPushButton::clicked,
                     linkerMethodsBuilds.get(), &LinkerMethodsBuilds::choiceMethodBuilding);

    QObject::connect(ui->startButton, &QPushButton::clicked,
                     linkerGameWindow.get(), &LinkerCommands::executeAllCommands);

}

void MainWindowGame::disconect() const
{
    QObject::connect(ui->endButton, &QPushButton::clicked,
                     this, &QApplication::quit);
}

void MainWindowGame::updateStateObjects(const QString nameBuilder)
{
    updateTitleNameBuilder(nameBuilder);
    updateStatyStartButton(nameBuilder);
    linkerMethodsBuilds->updateNameBuilder(nameBuilder);
}

void MainWindowGame::updateTitleNameBuilder(const QString &nameBuilder)
{
    ui->titleNameBuilder->setText(nameBuilder);
}

void MainWindowGame::updateStatyStartButton(const QString &nameBuilder)
{
    if(nameBuilder != "")
        ui->startButton->setEnabled(true);
}

MainWindowGame::~MainWindowGame()
{
    delete ui;
}
