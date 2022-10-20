#ifndef BUILDERAVLTREE_H
#define BUILDERAVLTREE_H

#include "GraphicsBuilder.h"
#include "GraphicsBinaryTree.h"
#include "OffsetBinaryBranch.h"

class GraphicsBuilderAvlTree: public GraphicsBuilder
{
    public:
        GraphicsBuilderAvlTree();
        ~GraphicsBuilderAvlTree() = default;
        void addGraphicsNodeInTree(GraphicsNode* const newNode) override final;

    private:
        GraphicsBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                  GraphicsBinaryTree* currentNode);
        void fixBalanced(GraphicsBinaryTree*& currentNode);
        void fixHeight(GraphicsBinaryTree*& currentNode);
        qint32 learnHeightNode(GraphicsBinaryTree* const node);
        qint32 learnBalance(GraphicsBinaryTree* currentNode);
        GraphicsBinaryTree* rotateOnLeft(GraphicsBinaryTree* currentNode);
        GraphicsBinaryTree* rotateOnRight(GraphicsBinaryTree* currentNode);
        void updatePositionTree(GraphicsBinaryTree*& parentNode,
                                const QPointF posNode,
                                QGraphicsLineItem* const branch = nullptr,
                                const qsizetype index = 0);
        GraphicsBinaryTree* tree;
        ArrayOffsets<OffsetBinaryBranch, ValuesBranches> array;
};

#endif // BUILDERAVLTREE_H
