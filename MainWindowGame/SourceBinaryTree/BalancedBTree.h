#ifndef BALANCEDBTREE_H
#define BALANCEDBTREE_H

#include "Tree.h"

class BalancedBTree: public Tree
{
    public:
        BalancedBTree();
        const Node* searchNode(QStringView viewKey) override final;
};

#endif // BALANCEDBTREE_H
