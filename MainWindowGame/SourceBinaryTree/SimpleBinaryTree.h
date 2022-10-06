#ifndef SIMPLYBINARYTREE_H
#define SIMPLYBINARYTREE_H

#include "Tree.h"
#include <QStringView>
#include <utility>

class SimpleBinaryTree: public Tree
{
    public:
        explicit SimpleBinaryTree(GraphicsNode* const data);
        SimpleBinaryTree(SimpleBinaryTree&& oldNode);
        SimpleBinaryTree& operator=(SimpleBinaryTree&& oldNode);
        ~SimpleBinaryTree();
        void setPositionGraphicsItems(const QPointF posNode, std::pair<QPointF,QPointF> offsetBranchesByAxesXY2);
        SimpleBinaryTree* leftNode;
        SimpleBinaryTree* rightNode;
        uint key() override final;
        GraphicsNode*& itemNode();
        QGraphicsLineItem*& itemLeftBranch();
        QGraphicsLineItem*& itemRightBranch();
        qint32 height() const;
        void setHeight(const qint32 newHeight);
    private:
        void createBranches(std::pair<QPointF,QPointF> offsetBranchesByAxesXY2);
        qint32 _height;
        GraphicsNode* node;
        QGraphicsLineItem* leftBranch;
        QGraphicsLineItem* rightBranch;
};

#endif // SIMPLYBINARYTREE_H
