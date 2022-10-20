#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QJsonObject>
#include <QPointF>

class GraphicsNode: public QGraphicsItem
{
    public:
        GraphicsNode() = default;
        explicit GraphicsNode(const QJsonValue obj);
        void setPos(QPointF point);
        QPointF pos() const;
        QPixmap image() const;
        QString keyNameLetter() const;
        uint key() const;
        void setParent(QGraphicsItem* item);
        QRectF boundingRect() const override final;
        GraphicsNode& operator=(GraphicsNode* const);
    private:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override final;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override final;
        QPixmap imageNode;
        QString _keyNameletter;
        QPointF position;
        QRectF rect;
};

#endif // GRAPHICSNODE_H
