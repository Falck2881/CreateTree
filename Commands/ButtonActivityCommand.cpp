#include "ButtonActivityCommand.h"

ButtonActivityCommand::ButtonActivityCommand(QAbstractButton* button):button(button)
{

}

void ButtonActivityCommand::off()
{
    button->setEnabled(false);
}

void ButtonActivityCommand::on()
{
    button->setEnabled(true);
}
