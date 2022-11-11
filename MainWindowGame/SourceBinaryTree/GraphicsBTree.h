#ifndef GRAPHICSBTREE_H
#define GRAPHICSBTREE_H

#include "UpdateBTree.h"
#include "UpdateTree.h"
#include "GraphicsNode.h"
#include <QVector>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class GraphicsBTree
{
    public:
        GraphicsBTree(const quint32 coefficient);
        QGraphicsRectItem* node() const;
        QVector<GraphicsNode*> items() const;
        GraphicsNode* itemsAt(const qsizetype index) const;
        GraphicsNode* itemsFirst() const;
        GraphicsNode* itemsLast() const;
        qsizetype quantityItems() const;
        void addItem(GraphicsNode* const item);
        void updateItems(QVector<GraphicsNode*> updatedItems);
        void removeFirstItems();
        void removeLastItems();
        QVector<std::shared_ptr<GraphicsBTree>> descendants();
        GraphicsBTree* descendantsAt(const qsizetype index) const;
        quint32 heightFirstDescendant() const;
        quint32 heightLastDescendant() const;
        qsizetype quantityDescendants() const;
        std::shared_ptr<GraphicsBTree> descendantFirst() const;
        std::shared_ptr<GraphicsBTree> descendantLast() const;
        void removeFirstDescendant();
        void removeLastDescendant();
        void addDescendantInEnd(std::shared_ptr<GraphicsBTree> newDescendant);
        void addDescendantInBegin(std::shared_ptr<GraphicsBTree> newDescendant);
        void insertNewDescendant(const qsizetype index, std::shared_ptr<GraphicsBTree> newNode);
        QGraphicsLineItem* branchAt(const qsizetype index) const;
        QPointF branchAtPos2(const qsizetype index) const;
        QGraphicsLineItem* branchLast() const;
        void addBranch(std::shared_ptr<QGraphicsLineItem> newBranch);
        void setPosBranch(const QLineF line,const qsizetype index);
        void changeHeight(const quint32 newHeight);
        void update();
        bool isTerminalVertex() const ;
        bool notMaximumSizeData() const;
        bool notMaximumNumberDescendants() const;
        bool maximumNumberDescendants() const;
        bool maximumSizeData() const;
        QPointF topLeftRect() const;
        QPointF bottomPosItem(const qsizetype index) const;
        qreal widthNode() const;
        void setSquareRect(const QRectF newSquare);
    private:
        QVector<GraphicsNode*> _items;
        QVector<std::shared_ptr<GraphicsBTree>> _descendants;
        QVector<std::shared_ptr<QGraphicsLineItem>> _branches;
        quint32 height;
        const quint32 maxQuantityData;
        const quint32 maxQuantityDescendants;
        std::unique_ptr<QGraphicsRectItem> rectangle;
        UpdateTree<UpdateBTree> tree;
};

#endif // BALANCEDBTREE_H
