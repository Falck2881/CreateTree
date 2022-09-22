#ifndef BUILDERAVLTREE_H
#define BUILDERAVLTREE_H

#include "Builder.h"
#include "SimpleBinaryTree.h"

class BuilderAvlTree: public Builder
{
    public:
        BuilderAvlTree() = default;
        void addNodeInTree(Node* const newNode) override final;

};

#endif // BUILDERAVLTREE_H
