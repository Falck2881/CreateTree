#include "StartWindow.h"
#include <QFile>
#include <QTextStream>
#include <QApplication>
int main(int argc, char *argv[])
{
    QFile fileStyle(QString(":/Style/Toolery.qss"));
    fileStyle.open(QIODevice::ReadOnly);
    QTextStream streamStyle(&fileStyle);
    QApplication app(argc, argv);
    app.setStyleSheet(streamStyle.readAll());
    StartWindow startWin;
    startWin.show();
    return app.exec();
}
