#ifndef GRAPHICSBUILDERBTREE_H
#define GRAPHICSBUILDERBTREE_H

#include "GraphicsBuilder.h"
#include "GraphicsBTree.h"

class GraphicsBuilderBTree: public GraphicsBuilder
{
    public:
        GraphicsBuilderBTree(const QString methodBuild,const quint32 coefficient);
        ~GraphicsBuilderBTree();
        void addGraphicsNodeInTree(GraphicsNode *const newItem) override final;
    private:
        void insertNewData(GraphicsNode *const newItem);
        void insertNewData(GraphicsNode *const newItem, GraphicsBTree* const currentNode, GraphicsBTree* const parentNode);
        void insert(GraphicsNode *const newItem, GraphicsBTree* const currentNode, GraphicsBTree* const parentNode);
        void tryInsertTamporaryDataInCurrentNode(GraphicsBTree* const currentNode);
        GraphicsBTree* reconstruction(GraphicsBTree* const currentNode, GraphicsBTree* const parentNode = nullptr);
        void findIntermediateItemInNode(GraphicsNode* const newItem,GraphicsBTree* currentNode);
        void findNodeForInsertNewItem(GraphicsNode* const newItem,GraphicsBTree* currentNode);
        void cancelRefOnIntermediateItem();
        GraphicsBTree* createFirstRootVertex(GraphicsBTree* rootNode);
        GraphicsBTree* createNewRootVertex(GraphicsBTree* currentNode);
        void insertNewTerminalNode(GraphicsBTree* currentNode, GraphicsBTree* parentNode);
        void createNewDescendant(GraphicsBTree* currentNode, GraphicsBTree* parentNode);
        void transferingDataAndDescendantsFromOldRootVertexInNewDescendant(GraphicsBTree* newDescendant,
                                                                           GraphicsBTree* currentNode);
        void transferingDataAndDescendantsFromCurrentNodeInNewDescendant(GraphicsBTree* newDescendant,
                                                                         GraphicsBTree* currentNode);
        bool isRequiredCreateNewRootNode(GraphicsBTree* currentNode, GraphicsBTree* parentNode) const;
        bool isRequiredCreateNewDescendant(GraphicsBTree* currentNode, GraphicsBTree* parentNode) const;
        GraphicsBTree* tree;
        const quint32 coefficient;
        const int minNumberData;
        const int minNumberDescendants;
        GraphicsNode intermediateItem;
        GraphicsNode* refOnIntermediateItem;
};

#endif // GRAPHICSBUILDERBTREE_H
