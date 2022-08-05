#ifndef STREAMJSON_H
#define STREAMJSON_H

#include <QString>
#include <QByteArray>
#include <QJsonDocument>

class StreamJson
{
    public:
        StreamJson() = default;
        explicit StreamJson(const QString nameFile);
        bool isEmpty() const;
        QJsonValue getJsonValue(const QString& key) const;
    private:
        const QByteArray extractDataFromJsonFile(const QString nameFile);
        QJsonDocument jsonDoc;
};

#endif // STREAMJSON_H
