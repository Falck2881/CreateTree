#include "MainWindowGame.h"
#include "GameWindow/GameWindow.h"
#include "ui_MainWindowGame.h"
#include "WindowInputData.h"
#include "HideWgdCommand.h"
#include "ShowWgdCommand.h"
#include <QMovie>
#include <QPainter>


MainWindowGame::MainWindowGame():
    ui(new Ui::MainWindowGame),
    winInputData(std::make_unique<WindowInputData>(this)),
    managerBuilder{std::make_unique<ManagerBuilder>()},
    gameWindow{std::make_unique<GameWindow>()},
    linkerShowGameWindow{std::make_unique<LinkerCommands>()}
{
    Q_INIT_RESOURCE(DifferentImages);
    ui->setupUi(this);
    setAnimation();
    setBinaryTreeConstructionStrategies();
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

void MainWindowGame::setBinaryTreeConstructionStrategies()
{
    std::vector<QPushButton*&> buttonsStrategy{ui->pbtButton,ui->rtsButton,ui->avlButton,
                                              ui->bTreeButton,ui->tosButton};

    managerBuilder->setBinaryTreeConstractionsStrategy(buttonsStrategy);
}

void MainWindowGame::addCommandsInLinkerShowGameWindow()
{
    linkerShowGameWindow->addCommand(std::make_unique<HideWgdCommand>(this));
    linkerShowGameWindow->addCommand(std::make_unique<ShowWgdCommand>(gameWindow));
}


void MainWindowGame::connectToWindowInputData() const
{
    QObject::connect(ui->changeNameButton, &QPushButton::clicked,
                     winInputData.get(), &QWidget::show);
}

void MainWindowGame::connectToGameWindow() const
{
    std::vector<QPushButton*> buttonsStrategy{ui->pbtButton,ui->rtsButton,ui->avlButton,
                                              ui->bTreeButton,ui->tosButton};

    for(auto button: buttonsStrategy)
        QObject::connect(button, &QPushButton::clicked, gameWindow.get(), &GameWindow::show);
}

void MainWindowGame::disconect() const
{
    QObject::connect(ui->endButton, &QPushButton::clicked,
                     this, &QApplication::quit);
}

void MainWindowGame::updateData(const QString nameBuilder)
{
    updateTitleNameBuilder(nameBuilder);
    managerBuilder->updateDataInNodeProxy(nameBuilder);
}

void MainWindowGame::updateTitleNameBuilder(const QString &nameBuilder)
{
    ui->titleNameBuilder->setText(nameBuilder);
}

void MainWindowGame::updateDataInGameWindow(std::vector<std::unique_ptr<NodeProxy>> nodesProxy)
{
    gameWindow->setNodesProxy(std::move(nodesProxy));
}

MainWindowGame::~MainWindowGame()
{
    delete ui;
}
