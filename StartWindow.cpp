#include "StartWindow.h"
#include "ui_StartWindow.h"
#include "MainWindowGame.h"
#include "ShowWgdCommand.h"
#include "HideWgdCommand.h"
#include <QMovie>
#include <QPainter>
#include <QImage>
#include <QGraphicsBlurEffect>
#include <QFile>
#include <QDataStream>

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow),
    mainWinGame{std::make_unique<MainWindowGame>()},
    linkerWinSwitching{std::make_unique<LinkerCommands>()}
{
    ui->setupUi(this); 
    connectLogoGif();
    addCommandInLinker();
    connectToWindowInputData();
}

void StartWindow::connectLogoGif()
{
    QMovie* logoGif = new QMovie(":/Image/logo.gif");
    ui->logoGif->setMovie(logoGif);
    logoGif->start();
}

void StartWindow::connectToWindowInputData()
{
    QObject::connect(ui->startButton, &QPushButton::clicked,
                     linkerWinSwitching.get(), &LinkerCommands::executeAllCommands);
}

void StartWindow::addCommandInLinker()
{
    linkerWinSwitching->addCommand(std::make_unique<HideWgdCommand>(this));
    linkerWinSwitching->addCommand(std::make_unique<ShowWgdCommand>(mainWinGame.get()));
}

void StartWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QImage img(QSize(size().width(),size().height()),QImage::Format_ARGB32);
    img.load(":/Image/TreeRead.png");
    painter.drawImage(0,0,img);
}

StartWindow::~StartWindow()
{
    delete ui;
}
