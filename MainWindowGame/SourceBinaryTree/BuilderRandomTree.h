#ifndef BUILDERRANDOMTREE_H
#define BUILDERRANDOMTREE_H

#include "Builder.h"
#include "SimpleBinaryTree.h"

class BuilderRandomTree: public Builder
{
    public:
        BuilderRandomTree();
        void addNodeInTree(GraphicsNode* const newNode) override final;
    private:
        SimpleBinaryTree* addNodeInTree(GraphicsNode* const itemNode,
                                        SimpleBinaryTree* currentNode);
        SimpleBinaryTree* tree;
};
#endif // BUILDERRANDOMTREE_H
