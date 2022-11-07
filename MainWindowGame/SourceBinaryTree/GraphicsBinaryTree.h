#ifndef GRAPHICSBINARYTREE_H
#define GRAPHICSBINARYTREE_H

#include "UpdateTree.h"
#include "UpdateBinaryTree.h"
#include "GraphicsNode.h"
#include <QStringView>
#include <utility>
#include <QGraphicsScene>

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
        qreal posBottomX() const;
        qreal posBottomY() const;
        void setPosLeftBranch(const QLineF line);
        void setPosRightBranch(const QLineF line);
        void setPosItems(const QPointF startPos);
        void setHeight(const qint32 newHeight);
        void update();
    private:
        void setPropertyBrances();
        qint32 _height;
        GraphicsNode* grNode;
        QGraphicsLineItem* leftBranch;
        QGraphicsLineItem* rightBranch;
        UpdateTree<UpdateBinaryTree> tree;
};

#endif // GRAPHICSBINARYTREE_H
