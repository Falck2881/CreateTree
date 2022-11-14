#include "GameWindow.h"
#include "ui_GameWindow.h"
#include "HideWgdCommand.h"
#include "ShowWgdCommand.h"
#include "MainWindowGame.h"
#include <QAbstractScrollArea>
#include <QScrollBar>

GameWindow::GameWindow(QWidget* const mainWin):
    tree(std::make_unique<GraphicsTree>(this)),
    linkerMainWindow(std::make_unique<LinkerCommands>()),
    ui(new Ui::GameWindow),
    mainWindow(mainWin)
{
    Q_INIT_RESOURCE(BuildData);
    ui->setupUi(this);
    addCommandsInLinkerMainWindow();
    connectToManagerBuildingTree();
    connectToMainWindow();
    windowPlacementInParentPos();
}

void GameWindow::addCommandsInLinkerMainWindow()
{
    linkerMainWindow->addCommand(std::make_unique<HideWgdCommand>(this));
    linkerMainWindow->addCommand(std::make_unique<ShowWgdCommand>(mainWindow));
}

void GameWindow::connectToManagerBuildingTree()
{
    QObject::connect(ui->insertButton, &QPushButton::clicked, tree.get(), &GraphicsTree::insertData);
}

void GameWindow::connectToMainWindow()
{
    QObject::connect(ui->exitButton, &QPushButton::clicked, linkerMainWindow.get(), &LinkerCommands::executeAllCommands);
    QObject::connect(ui->exitButton, &QPushButton::clicked, this, &GameWindow::updateUi);
}

void GameWindow::windowPlacementInParentPos()
{
    this->move(100,100);
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
   ui->insertButton->setEnabled(false);
   ui->imgNode->setPixmap(QString(":/bobNotFound.png"));
   ui->unicode->setText(QString("There in no more data"));
}

void GameWindow::updateUi()
{
    ui->insertButton->setEnabled(true);
    ui->imgNode->setPixmap(QString(":/warningImg.jpg"));
    ui->unicode->setText(QString("empty"));
}

void GameWindow::updateStatyTree(std::unique_ptr<GraphicsBuilder> builder)
{
    setMethodBuild(builder->methodBuild());
    tree->updateBuilder(std::move(builder));
}

void GameWindow::updateStatyTree(std::unique_ptr<Array> newTypeArray)
{
    tree->updateArray(std::move(newTypeArray));
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
