#include "GraphicsBuilderBinaryTree.h"
#include <QGraphicsLineItem>

GraphicsBuilderBinaryTree::GraphicsBuilderBinaryTree(const QString methodBuild):
    GraphicsBuilder(methodBuild),tree(nullptr)
{

}

void GraphicsBuilderBinaryTree::addGraphicsNodeInTree(GraphicsNode* const newNode)
{
    tree = addGraphicsNodeInTree(newNode,tree);
    tree->update();
}

GraphicsBinaryTree* GraphicsBuilderBinaryTree::addGraphicsNodeInTree
(GraphicsNode* const itemNode, GraphicsBinaryTree* currentNode)
{
    if(currentNode == nullptr){
        currentNode = new GraphicsBinaryTree(itemNode);
        sceneDisplayTree->addItem(currentNode->itemNode());
        sceneDisplayTree->addItem(currentNode->itemLeftBranch());
        sceneDisplayTree->addItem(currentNode->itemRightBranch());
    }else if(itemNode->key() < currentNode->key())
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode);
    else if(itemNode->key() > currentNode->key())
        currentNode->rightNode = addGraphicsNodeInTree(itemNode,currentNode->rightNode);

    return currentNode;
}

GraphicsBuilderBinaryTree::~GraphicsBuilderBinaryTree()
{
    delete tree;
}
