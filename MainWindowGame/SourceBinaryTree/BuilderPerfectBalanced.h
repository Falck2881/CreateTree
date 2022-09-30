#ifndef BUILDERPERFECTBALANCED_H
#define BUILDERPERFECTBALANCED_H

#include "Builder.h"
#include "SimpleBinaryTree.h"

class BuilderPerfectBalanced: public Builder
{
    public:
        BuilderPerfectBalanced();
        void addNodeInTree(GraphicsNode* const newNode) override final;
    private:
        SimpleBinaryTree* addNodeInTree(GraphicsNode* const newNode,
                                        SimpleBinaryTree* const currentNode);

        SimpleBinaryTree* tree;
};
#endif // BUILDERPERFECTBALANCED_H
