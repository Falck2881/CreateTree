#ifndef LINKERCOMMANDS_H
#define LINKERCOMMANDS_H

#include <memory>
#include <QList>
#include "Command.h"

class LinkerCommands: public QObject
{
    Q_OBJECT

    public:
        LinkerCommands(){}
        virtual ~LinkerCommands(){}
        virtual void addCommand(std::unique_ptr<Command> command);
    public slots:
        virtual void executeAllCommands();
    protected:
        QList<std::shared_ptr<Command>> allCommands;
};

#endif // LINKERCOMMANDS_H
