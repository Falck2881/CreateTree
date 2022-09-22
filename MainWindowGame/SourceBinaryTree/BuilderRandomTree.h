#ifndef BUILDERRANDOMTREE_H
#define BUILDERRANDOMTREE_H

#include "Builder.h"
#include "SimpleBinaryTree.h"

class BuilderRandomTree: public Builder
{
    public:
        BuilderRandomTree();
        void addNodeInTree(Node* const newNode) override final;
    private:
        SimpleBinaryTree* addNodeInTree(Node* const itemNode,
                                        SimpleBinaryTree* currentNode);

        SimpleBinaryTree* addNodeInTree(Node* const itemNode,
                                        SimpleBinaryTree* currentNode,
                                        QGraphicsLineItem*& itemBranch);
        SimpleBinaryTree* tree;
};
#endif // BUILDERRANDOMTREE_H
