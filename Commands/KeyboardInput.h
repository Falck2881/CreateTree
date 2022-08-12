#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include <QLineEdit>
#include <QObject>
#include "Command.h"

class KeyboardInput: public QObject
{
    Q_OBJECT

    public:
        explicit KeyboardInput(QLineEdit*& lineNameBuild);
    signals:
        void transferInputData(const QString& data);
        void controlPassed();
        void controlNotPassed();
    public slots:
        void transferData(const QString &data);
        void clearLineEdit();
    private:
        bool checkInputData(const QString &data);
        QLineEdit*& lineNameBuild;
};

#endif // KEYBOARDINPUT_H
