#include "GameWindow.h"
#include "ui_GameWindow.h"
#include "HideWgdCommand.h"
#include "ShowWgdCommand.h"

GameWindow::GameWindow(QWidget* const mainWindow):
    managerGameWin(std::make_unique<ManagerGameWindow>(this)),
    linkerMainWindow(std::make_unique<LinkerCommands>()),
    ui(new Ui::GameWindow),
    mainWindow(mainWindow),
    titleStrategy(QString("Strategy: ")),
    titleBuilder(QString("Builder: "))
{
    Q_INIT_RESOURCE(BuildData);
    ui->setupUi(this);
    postAUiTheGameWindow();
    addCommandsInLinkerMainWindow();
    connectToManagerBuildingTree();
    connectToMainWindow();
}

void GameWindow::postAUiTheGameWindow()
{
    ui->formLayoutForLocalUi->addRow(&titleStrategy, &uiGameWin.strategy);
    ui->formLayoutForLocalUi->addRow(&titleBuilder, &uiGameWin.builder);
}

void GameWindow::addCommandsInLinkerMainWindow()
{
    linkerMainWindow->addCommand(std::make_unique<HideWgdCommand>(this));
    linkerMainWindow->addCommand(std::make_unique<ShowWgdCommand>(mainWindow));
}

void GameWindow::connectToManagerBuildingTree()
{
    QObject::connect(ui->insertButton, &QPushButton::clicked, managerGameWin.get(), &ManagerGameWindow::insertNode);
}

void GameWindow::connectToMainWindow()
{
    QObject::connect(ui->exitButton, &QPushButton::clicked, linkerMainWindow.get(), &LinkerCommands::executeAllCommands);
}

void GameWindow::updateUiAboutStrategy(std::unique_ptr<MethodCustomizationUi> method)
{
    method->customizationUi(uiGameWin);
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

void GameWindow::gameEnd()
{
   ui->insertButton->setCheckable(true);
   ui->insertButton->setChecked(false);
   ui->imgNode->setPixmap(QString(":/bobNotFound.png"));
   ui->unicode->setText(QString("There in no more data"));
}

GameWindow::~GameWindow()
{
    delete ui;
}
