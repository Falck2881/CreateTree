#include "InputData.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

InputData::InputData(QLineEdit*& lineUserName)
{
    QRegularExpression regExpInput("[^!-/:-@[-`{-я]{15}");
    QRegularExpressionValidator* valForInputUserName = new QRegularExpressionValidator(regExpInput);
    lineUserName->setValidator(valForInputUserName);
}

void InputData::check(const QString& data)
{
    if(isInputData(data)){
        emit this->transferInputData(data);
    }
}

bool InputData::isInputData(const QString &data)
{
    qsizetype minSizeUserName = 10;
    if(data != "" && data.size() >= minSizeUserName){
        emit this->controlPassed();
        return true;
    }
    else{
        emit this->controlNotPassed();
        return false;
    }
}
