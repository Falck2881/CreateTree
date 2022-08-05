#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QString>
#include <QJsonObject>

class Node: public QGraphicsItem
{
    public:
        Node();
        const char16_t key() const;
        void setData(const QJsonObject obj);
    private:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override final;
        QRectF boundingRect() const override final;
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override final;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override final;
        QPixmap imageNode;
        QString _key;
};

#endif // NODE_H
