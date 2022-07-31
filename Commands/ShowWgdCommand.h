#ifndef SHOWWGDCOMMAND_H
#define SHOWWGDCOMMAND_H

#include "Command.h"

class ShowWgdCommand: public Command
{
    Q_OBJECT

    public:
        ShowWgdCommand(QWidget* widget);
        ShowWgdCommand(std::unique_ptr<QWidget> uniqWidget);
        ~ShowWgdCommand(){}
    private slots:
        void execute() override;
    private:
        QWidget* widget;
        std::unique_ptr<QWidget> uniqWidget;
};

#endif // SHOWWGDCOMMAND_H
