#ifndef BUILDERBINARYTREE_H
#define BUILDERBINARYTREE_H

#include "GraphicsBuilder.h"
#include "SimpleBinaryTree.h"
#include "MethodsInitArrOffsets.h"

class GraphicsBuilderBinaryTree: public GraphicsBuilder
{
    public:
        GraphicsBuilderBinaryTree();
        ~GraphicsBuilderBinaryTree() = default;
        void addGraphicsNodeInTree(GraphicsNode* const newNode) override final;
    private:
        SimpleBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                SimpleBinaryTree* currentNode);
        SimpleBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                SimpleBinaryTree* currentNode,
                                                const QPointF newPosNode);
        SimpleBinaryTree* tree;
        ArrayOffsets<OffsetsBranchForBinaryTree, std::pair<QPointF,QPointF>> array;
};
#endif // BUILDERBINARYTREE_H
