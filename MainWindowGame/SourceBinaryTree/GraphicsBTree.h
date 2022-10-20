#ifndef GRAPHICSBTREE_H
#define GRAPHICSBTREE_H

#include "GraphicsNode.h"
#include <QVector>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>

class GraphicsBTree
{
    public:
        GraphicsBTree(const quint32 coefficient);
        quint32 height() const;
        void changeHeight(const quint32 newHeight);
        void addDataInEnd(GraphicsNode* const node);
        void addDataInBegin(GraphicsNode* const node);
        bool isTerminalVertex() const ;
        bool notMaximumSizeData() const;
        bool notMaximumNumberDescendants() const;
        bool maximumNumberDescendants() const;
        bool maximumSizeData() const;
        QVector<GraphicsNode*> nodes;
        QVector<GraphicsBTree*> descendants;
    private:
        quint32 _height;
        const quint32 maxQuantityData;
        const quint32 maxQuantityDescendants;
        QVector<QGraphicsLineItem*> branches;
        QGraphicsRectItem* container;
};

#endif // BALANCEDBTREE_H
