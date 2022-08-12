#ifndef NODEPROXY_H
#define NODEPROXY_H

#include "Node.h"
#include <vector>
#include <memory>
#include <utility>
#include <QJsonValue>

class NodeProxy
{
    public:
        explicit NodeProxy(const QJsonValue value);
    public slots:
        void draw();
    private:
        QString extractKey(const QJsonValue& value);
        QString extractNameFileImg(const QJsonValue& value);
        std::unique_ptr<Node> node;
        std::pair<QString,QString> pair;
};

#endif // NODEPROXY_H
