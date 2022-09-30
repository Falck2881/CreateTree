#include "KeyboardInput.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

KeyboardInput::KeyboardInput(QLineEdit*& lineNameBuild):lineNameBuild(lineNameBuild)
{
    QRegularExpression regExpInput("[^!-~]{20}");
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
    qsizetype maxLengthUserName = 20;
    if(data != "" && data.size() <= maxLengthUserName){;
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
