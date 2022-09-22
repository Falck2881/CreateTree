#ifndef BALANCEDBTREE_H
#define BALANCEDBTREE_H

#include "Tree.h"

class BalancedBTree: public Tree
{
    public:
        BalancedBTree();
        const ushort* key() override final;
};

#endif // BALANCEDBTREE_H
