#include "WindowBuilder.h"
#include "ui_WindowBuilder.h"

WindowBuilder::WindowBuilder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowBuilder)
{
    ui->setupUi(this);
}

WindowBuilder::~WindowBuilder()
{
    delete ui;
}
