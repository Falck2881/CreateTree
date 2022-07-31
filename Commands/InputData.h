#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QLineEdit>
#include <QObject>

class InputData: public QObject
{
    Q_OBJECT

    public:
        explicit InputData(QLineEdit*& lineUserName);
    signals:
        void transferInputData(const QString& data);
        void controlPassed();
        void controlNotPassed();
    public slots:
        void check(const QString &data);
    private:
        bool isInputData(const QString& data);
        QString saveInputData;
};

#endif // INPUTDATA_H
