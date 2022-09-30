#ifndef SIMPLYBINARYTREE_H
#define SIMPLYBINARYTREE_H

#include "Tree.h"
#include <QStringView>

class SimpleBinaryTree: public Tree
{
    public:
        explicit SimpleBinaryTree(GraphicsNode* const data);
        SimpleBinaryTree* leftNode;
        SimpleBinaryTree* rightNode;
        uint key() override final;
        GraphicsNode*& itemNode();
        QGraphicsLineItem*& itemLeftBranch();
        QGraphicsLineItem*& itemRightBranch();
        void setLeftBranch(QGraphicsLineItem* const newLeftBranch);
        void setRightBranch(QGraphicsLineItem* const newRightBranch);
    private:
        GraphicsNode* node;
        QGraphicsLineItem* leftBranch;
        QGraphicsLineItem* rightBranch;
};

#endif // SIMPLYBINARYTREE_H
