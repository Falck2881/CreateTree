#ifndef GRAPHICSBUILDERBTREE_H
#define GRAPHICSBUILDERBTREE_H

#include "GraphicsBuilder.h"
#include "GraphicsBTree.h"

class GraphicsBuilderBTree: public GraphicsBuilder
{
    public:
        GraphicsBuilderBTree(const quint32 coefficient);
        void addGraphicsNodeInTree(GraphicsNode *const newItemNode) override final;
    private:
        void insertNewData(GraphicsNode *const newItemNode);
        void insertNewData(GraphicsNode *const newItemNode, GraphicsBTree*& currentNode, GraphicsBTree*& parentNode);
        void insert(GraphicsNode *const newItemNode, GraphicsBTree*& currentNode, GraphicsBTree*& parentNode);
        void tryInsertTamporaryDataInCurrentNode(GraphicsBTree*& currentNode);
        GraphicsBTree* reconstruction(GraphicsBTree* currentNode, GraphicsBTree* parentNode = nullptr);
        void findIntermediateDataInNode(GraphicsNode *const newItemNode,GraphicsBTree*& currentNode);
        void findNodeForInsertNewData(GraphicsNode *const newItemNode,GraphicsBTree*& currentNode);
        void cancelRefOnTamporaryNode();
        GraphicsBTree* createFirstRootVertex(GraphicsBTree* rootNode);
        GraphicsBTree* createNewRootVertex(GraphicsBTree* currentNode);
        void insertNewTerminalNode(GraphicsBTree*& currentNode, GraphicsBTree*& parentNode);
        void createNewDescendant(GraphicsBTree*& currentNode, GraphicsBTree*&parentNode);
        void transferingDataAndDescendantsFromOldRootVertexInNewDescendant(GraphicsBTree* newDescendant,
                                                                           GraphicsBTree* currentNode);
        void transferingDataAndDescendantsFromCurrentNodeInNewDescendant(GraphicsBTree* newDescendant,
                                                                         GraphicsBTree* currentNode);
        bool isRequiredCreateNewRootNode(GraphicsBTree*& currentNode, GraphicsBTree*& parentNode) const;
        bool isRequiredCreateNewDescendant(GraphicsBTree*& currentNode, GraphicsBTree*& parentNode) const;
        GraphicsBTree* tree;
        const quint32 coefficient;
        const int minNumberData;
        const int minNumberDescendants;
        GraphicsNode tamporaryNode;
        GraphicsNode* refOnTamporaryNode;
};

#endif // GRAPHICSBUILDERBTREE_H
