#ifndef BUILDERBINARYTREE_H
#define BUILDERBINARYTREE_H

#include "GraphicsBuilder.h"
#include "GraphicsBinaryTree.h"
#include "OffsetBinaryBranch.h"

class GraphicsBuilderBinaryTree: public GraphicsBuilder
{
    public:
        GraphicsBuilderBinaryTree();
        ~GraphicsBuilderBinaryTree() = default;
        void addGraphicsNodeInTree(GraphicsNode* const newNode) override final;
    private:
        GraphicsBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                  GraphicsBinaryTree* currentNode,
                                                  QPointF startPosNode,
                                                  qsizetype index = 0);
        GraphicsBinaryTree* tree;
        ArrayOffsets<OffsetBinaryBranch, ValuesBranches> array;
};
#endif // BUILDERBINARYTREE_H
