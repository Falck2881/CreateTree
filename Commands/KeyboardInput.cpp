#include "KeyboardInput.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

KeyboardInput::KeyboardInput(QLineEdit*& lineNameBuild):lineNameBuild(lineNameBuild)
{
    QRegularExpression regExpInput("[^!-~]{15}");
    QRegularExpressionValidator* valForInputUserName = new QRegularExpressionValidator(regExpInput);
    lineNameBuild->setValidator(valForInputUserName);
}

void KeyboardInput::transferData(const QString& data)
{
    if(checkInputData(data))
        emit this->transferInputData(data);
}

bool KeyboardInput::checkInputData(const QString &data)
{
    qsizetype minSizeUserName = 12;
    if(data != "" && data.size() >= minSizeUserName){;
        emit this->controlPassed();
        return true;
    }
    else{
        emit this->controlNotPassed();
        return false;
    }
}

void KeyboardInput::clearLineEdit()
{
    lineNameBuild->clear();
}
