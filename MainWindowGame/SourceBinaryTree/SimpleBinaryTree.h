#ifndef SIMPLYBINARYTREE_H
#define SIMPLYBINARYTREE_H

#include "Tree.h"
#include <QStringView>

class SimpleBinaryTree: public Tree
{
    public:
        explicit SimpleBinaryTree(Node* const data);
        SimpleBinaryTree* leftNode;
        SimpleBinaryTree* rightNode;
        const ushort* key() override final;
        Node*& itemNode();
        QGraphicsLineItem*& itemLeftBranch();
        QGraphicsLineItem*& itemRightBranch();
        void setLeftBranch(QGraphicsLineItem* const newLeftBranch);
        void setRightBranch(QGraphicsLineItem* const newRightBranch);
    private:
        Node* node;
        QGraphicsLineItem* leftBranch;
        QGraphicsLineItem* rightBranch;
};

#endif // SIMPLYBINARYTREE_H
