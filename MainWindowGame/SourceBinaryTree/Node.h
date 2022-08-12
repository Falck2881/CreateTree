#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QJsonObject>

class Node: public QGraphicsItem
{
    public:
        explicit Node(const QJsonValue obj);
        const char16_t key() const;
    private:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override final;
        QRectF boundingRect() const override final;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override final;
        QPixmap imageNode;
        QString _key;
};

#endif // NODE_H
