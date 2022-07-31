#include "HideWgdCommand.h"

HideWgdCommand::HideWgdCommand(QWidget* widget):widget{widget}
{
}
void HideWgdCommand::execute() {
    widget->hide();
}
