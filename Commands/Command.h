#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>

class Command: public QObject
{
    Q_OBJECT

    public:
        virtual ~Command(){}
    public slots:
        virtual void execute() = 0;
    protected:
        Command(){};
};

#endif // COMMAND_H
