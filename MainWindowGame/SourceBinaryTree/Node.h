#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QJsonObject>
#include <QPointF>

class Node: public QGraphicsItem
{
    public:
        explicit Node(const QJsonValue obj);
        void setPos(QPointF point);
        QPointF pos() const;
        QPixmap image() const;
        QString keyNameLetter() const;
        const ushort* keyUtf16() const;
        void setParentItem(QGraphicsItem* item);
        QRectF boundingRect() const override final;
    private:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override final;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override final;
        QPixmap imageNode;
        QString _keyNameletter;
        QPointF position;
        QRectF rect;
};

#endif // NODE_H
