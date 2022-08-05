#include "StreamJson.h"
#include <QJsonValue>
#include <QFile>

StreamJson::StreamJson(const QString nameFile)
{
    Q_INIT_RESOURCE(JsonData);
    jsonDoc.fromJson(extractDataFromJsonFile(nameFile));
}

const QByteArray StreamJson::extractDataFromJsonFile(const QString nameFile)
{
    QString jsonData;
    QFile file(nameFile);
    if(file.open(QIODeviceBase::ReadOnly))
    {
        jsonData = file.readAll();
        file.close();
    }
    return jsonData.toUtf8();
}

bool StreamJson::isEmpty() const
{
    return jsonDoc.isEmpty();
}

QJsonValue StreamJson::getJsonValue(const QString& index) const
{
    return jsonDoc[index];
}
