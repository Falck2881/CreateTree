#ifndef BUILDERBINARYTREE_H
#define BUILDERBINARYTREE_H

#include "GraphicsBuilder.h"
#include "GraphicsBinaryTree.h"

class GraphicsBuilderBinaryTree: public GraphicsBuilder
{
    public:
        explicit GraphicsBuilderBinaryTree(const QString methodBuild);
        ~GraphicsBuilderBinaryTree();
        void addGraphicsNodeInTree(GraphicsNode* const newNode) override final;
    private:
        GraphicsBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                  GraphicsBinaryTree* currentNode);
        GraphicsBinaryTree* tree;
};
#endif // BUILDERBINARYTREE_H
