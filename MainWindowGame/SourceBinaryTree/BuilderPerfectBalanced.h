#ifndef BUILDERPERFECTBALANCED_H
#define BUILDERPERFECTBALANCED_H

#include "Builder.h"
#include "SimpleBinaryTree.h"

class BuilderPerfectBalanced: public Builder
{
    public:
        BuilderPerfectBalanced();
        void addNodeInTree(Node* const newNode) override final;
    private:
        SimpleBinaryTree* addNodeInTree(Node* const newNode,
                                        SimpleBinaryTree* const currentNode);
        SimpleBinaryTree* addNodeInTree(Node* const newNode,
                                        SimpleBinaryTree* const currentNode,
                                        QGraphicsLineItem*& itemLine);

        SimpleBinaryTree* tree;
};
#endif // BUILDERPERFECTBALANCED_H
