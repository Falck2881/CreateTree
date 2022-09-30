#include "BuilderPerfectBalanced.h"

BuilderPerfectBalanced::BuilderPerfectBalanced():tree(nullptr)
{

}

void BuilderPerfectBalanced::addNodeInTree(GraphicsNode* const newNode)
{
   tree = addNodeInTree(newNode,tree);
}

SimpleBinaryTree* BuilderPerfectBalanced::addNodeInTree(GraphicsNode *const itemNode, SimpleBinaryTree* currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(itemNode);
        currentNode->itemNode()->setPos(graphicsTree->posNode());
        graphicsTree->addItem(currentNode->itemNode());
    }
    else if(itemNode->key() < currentNode->key())
    {
        graphicsTree->addLeftBranch(currentNode);
        graphicsTree->increaseIndex();
        currentNode->leftNode = addNodeInTree(itemNode,currentNode->leftNode);
        graphicsTree->reduceIndex();
    }
    else if(itemNode->key() > currentNode->key())
    {
        graphicsTree->addRightBranch(currentNode);
        graphicsTree->increaseIndex();
        currentNode->rightNode = addNodeInTree(itemNode, currentNode->rightNode);
        graphicsTree->reduceIndex();
    }

    return currentNode;
}
