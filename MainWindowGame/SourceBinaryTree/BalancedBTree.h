#ifndef BALANCEDBTREE_H
#define BALANCEDBTREE_H

#include "Tree.h"

class BalancedBTree: public Tree
{
    public:
        BalancedBTree();
        uint key() override final;
};

#endif // BALANCEDBTREE_H
