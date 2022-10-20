#ifndef GRAPHICSBINARYTREE_H
#define GRAPHICSBINARYTREE_H

#include "GraphicsNode.h"
#include <QStringView>
#include <utility>

struct ValuesBranches
{
    std::pair<qreal,qreal> valueLeftBranch;
    std::pair<qreal,qreal> valueRightBranch;
};

class GraphicsBinaryTree
{
    public:
        explicit GraphicsBinaryTree(GraphicsNode* const data);
        GraphicsBinaryTree(GraphicsBinaryTree&& oldNode);
        GraphicsBinaryTree& operator=(GraphicsBinaryTree&& oldNode);
        ~GraphicsBinaryTree();
        GraphicsBinaryTree* leftNode;
        GraphicsBinaryTree* rightNode;
        uint key();
        GraphicsNode* itemNode() const;
        QGraphicsLineItem* itemLeftBranch() const;
        QGraphicsLineItem* itemRightBranch() const;
        qint32 height() const;
        QPointF p2LeftBranch() const;
        QPointF p2RightBranch() const;
        void setPosition(const QPointF startPos, ValuesBranches valuesOffset);
        void setHeight(const qint32 newHeight);
    private:
        void setPropertyBrances();
        qint32 _height;
        GraphicsNode* grNode;
        QGraphicsLineItem* leftBranch;
        QGraphicsLineItem* rightBranch;
};

#endif // GRAPHICSBINARYTREE_H
