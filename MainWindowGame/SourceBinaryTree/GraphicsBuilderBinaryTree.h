#ifndef BUILDERBINARYTREE_H
#define BUILDERBINARYTREE_H

#include "GraphicsBuilder.h"
#include "SimpleBinaryTree.h"

class GraphicsBuilderBinaryTree: public GraphicsBuilder
{
    public:
        GraphicsBuilderBinaryTree();
        void addGraphicsNodeInTree(GraphicsNode* const newNode) override final;
    private:
        SimpleBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                SimpleBinaryTree* currentNode);
        SimpleBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                SimpleBinaryTree* currentNode,
                                                const QPointF newPosNode);
        SimpleBinaryTree* tree;
};
#endif // BUILDERBINARYTREE_H
