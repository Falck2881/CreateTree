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
        void updatePos(QPointF point);
        QPointF pos() const;
        qreal topRightX() const;
        qreal topRightY() const;
        QPixmap image() const;
        QRectF rectItem() const;
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
        QRectF boundingRectDisplayItem;
        QRectF _rectItem;
};

#endif // GRAPHICSNODE_H
