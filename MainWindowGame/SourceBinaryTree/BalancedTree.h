#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "Tree.h"

class BalancedTree: public Tree
{
    public:
        BalancedTree();
        BalancedTree* leftNode;
        BalancedTree* rightNode;
        virtual const Node* searchNode(QStringView viewKey) override final;
    private:
        std::unique_ptr<NodeProxy> nodeProxy;
};

#endif // BALANCEDTREE_H
