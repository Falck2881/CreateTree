#include "MainWindowGame.h"
#include "ShowWgdCommand.h"
#include "HideWgdCommand.h"
#include "ui_MainWindowGame.h"
#include "SourceBinaryTree/StreamJson.h"
#include "WindowInputData.h"
#include <QMovie>
#include <QPainter>


MainWindowGame::MainWindowGame():
    streamJson(QString(":/ContentNode.json")),
    ui(new Ui::MainWindowGame),
    winInputData(std::make_unique<WindowInputData>(this)),
    linkerWindowInputData(std::make_unique<LinkerCommands>())
{
    Q_INIT_RESOURCE(DifferentImages);
    ui->setupUi(this);
    setAnimation();
    connectToDifferentButton();
}

void MainWindowGame::setAnimation()
{
    QMovie* bobAnimation = new QMovie(":/DiffImg/bobBuilder.gif");
    ui->animation->setMovie(bobAnimation);
    bobAnimation->start();
}

void MainWindowGame::connectToDifferentButton() const
{
    QObject::connect(ui->changeNameButton, &QPushButton::clicked,
                     winInputData.get(), &QWidget::show);

    QObject::connect(ui->endButton, &QPushButton::clicked,
                     this, &QApplication::quit);
}

void MainWindowGame::updateData(const QString nameBuilder)
{
    if(!streamJson.isEmpty())
    {

    }
}

MainWindowGame::~MainWindowGame()
{
    delete ui;
}
