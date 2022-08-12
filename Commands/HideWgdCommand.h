#ifndef HIDEWGDCOMMAND_H
#define HIDEWGDCOMMAND_H

#include "Command.h"
#include <QWidget>

class HideWgdCommand: public Command
{
    Q_OBJECT

    public:
        HideWgdCommand(QWidget* widget);
        ~HideWgdCommand(){}
    private slots:
         void execute() override ;
    private:
        QWidget* widget;
};

#endif // HIDEWGDCOMMAND_H
