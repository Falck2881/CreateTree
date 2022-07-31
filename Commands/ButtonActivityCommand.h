#ifndef BUTTONACTIVITYCOMMAND_H
#define BUTTONACTIVITYCOMMAND_H

#include <QObject>
#include <QAbstractButton>

class ButtonActivityCommand: public QObject
{
    Q_OBJECT

    public:
        ButtonActivityCommand(QAbstractButton* button);
    public slots:
        void off();
        void on();
    private:
        QAbstractButton* const button;
};

#endif // BUTTONACTIVITYCOMMAND_h
