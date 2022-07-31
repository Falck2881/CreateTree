#include "ShowWgdCommand.h"

ShowWgdCommand::ShowWgdCommand(QWidget* widget):widget{widget}
{
}

ShowWgdCommand::ShowWgdCommand(std::unique_ptr<QWidget> uniqWidget):widget(nullptr),
                                                                    uniqWidget(std::move(uniqWidget))
{

}

void ShowWgdCommand::execute()
{
    if(widget != nullptr)
        widget->show();
    else
        uniqWidget->show();
}
