#include <gtest/gtest.h>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QDebug>

TEST(File, DesignerProgram)
{
    //Arrange
    QVector<QString> arrNameCase;
    arrNameCase << "Style QRC" << "Logo Game" << "Background Main Menu";
    foreach(QString nameCase, arrNameCase)
        qDebug() << "Start case '" + nameCase + "' \n";

    QVector<QString> arrPathToRCC;
    arrPathToRCC << ":/Style/SyNet.qss" << ":/Image/logo.gif" << ":/Image/RedFon.jpg";

    bool value = false;
    QFile file;

    //Act
    foreach(auto path, arrPathToRCC)
    {
        file.setFileName(path);
        value = file.open(QIODevice::ReadOnly);
        ASSERT_TRUE(value);
    }
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
