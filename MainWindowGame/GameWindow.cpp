#include "GameWindow.h"
#include "ui_GameWindow.h"
#include "HideWgdCommand.h"
#include "ShowWgdCommand.h"
#include "MainWindowGame.h"
#include <QAbstractScrollArea>
#include <QScrollBar>

GameWindow::GameWindow(QWidget* const mainWin):
    managerGameWin(std::make_unique<ManagerGameWindow>(this)),
    linkerMainWindow(std::make_unique<LinkerCommands>()),
    ui(new Ui::GameWindow),
    mainWindow(mainWin)
{
    Q_INIT_RESOURCE(BuildData);
    ui->setupUi(this);
    addCommandsInLinkerMainWindow();
    connectToManagerBuildingTree();
    connectToMainWindow();
    this->move(250,250);
}

void GameWindow::addCommandsInLinkerMainWindow()
{
    linkerMainWindow->addCommand(std::make_unique<HideWgdCommand>(this));
    linkerMainWindow->addCommand(std::make_unique<ShowWgdCommand>(mainWindow));
}

void GameWindow::connectToManagerBuildingTree()
{
    QObject::connect(ui->insertButton, &QPushButton::clicked, managerGameWin.get(), &ManagerGameWindow::insertData);
}

void GameWindow::connectToMainWindow()
{
    QObject::connect(ui->exitButton, &QPushButton::clicked, linkerMainWindow.get(), &LinkerCommands::executeAllCommands);
}

void GameWindow::updateInformationAboutNode(std::pair<QString, QPixmap> node)
{
    ui->unicode->setText(node.first);
    ui->imgNode->setPixmap(node.second);
}

void GameWindow::updateGraphicsView(QGraphicsScene *const scene)
{
    ui->graphicsView->setScene(scene);
}

void GameWindow::completionConstruction()
{
   ui->insertButton->setCheckable(true);
   ui->insertButton->setChecked(false);
   ui->imgNode->setPixmap(QString(":/bobNotFound.png"));
   ui->unicode->setText(QString("There in no more data"));
}

void GameWindow::updateStatyManager(GraphicsBuilder *builder)
{
    setMethodBuild(builder->methodBuild());
    managerGameWin->updateBuilder(builder);
}

void GameWindow::updateStatyManager(Array * const newTypeArray)
{
    managerGameWin->updateArray(newTypeArray);
}

void GameWindow::setNameBuilder(const QString nameBuilder)
{
    ui->name->setText(nameBuilder);
}

void GameWindow::setMethodBuild(const QString methodBuild)
{
    ui->method->setText(methodBuild);
}

GameWindow::~GameWindow()
{
    delete ui;
}
