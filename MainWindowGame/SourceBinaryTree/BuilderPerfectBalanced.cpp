#include "BuilderPerfectBalanced.h"

BuilderPerfectBalanced::BuilderPerfectBalanced():tree(nullptr)
{

}

void BuilderPerfectBalanced::addNodeInTree(Node* const newNode)
{
   tree = addNodeInTree(newNode,tree);
}

SimpleBinaryTree* BuilderPerfectBalanced::addNodeInTree(Node *const newItemNode, SimpleBinaryTree* currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(newItemNode);
        currentNode->itemNode()->setPos(graphicsScene->coordinateNode());
        graphicsScene->addItem(currentNode->itemNode());
    }
    else if(newItemNode->keyUtf16() < currentNode->key())
    {
        graphicsScene->addLeftBranch(currentNode);
        currentNode->leftNode = addNodeInTree(newItemNode,
                                              currentNode->leftNode,
                                              currentNode->itemLeftBranch());
    }
    else if(newItemNode->keyUtf16() > currentNode->key())
    {
        graphicsScene->addRightBranch(currentNode);
        currentNode->rightNode = addNodeInTree(newItemNode,
                                               currentNode->rightNode,
                                               currentNode->itemRightBranch());
    }

    return currentNode;
}

SimpleBinaryTree* BuilderPerfectBalanced::addNodeInTree(Node *const newItemNode,
                                                        SimpleBinaryTree* currentNode,
                                                        QGraphicsLineItem*& lineItem)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(newItemNode);
        currentNode->itemNode()->setPos(graphicsScene->coordinateNode());
        graphicsScene->bindBranchWithNewNode(lineItem,currentNode->itemNode());
        graphicsScene->addItem(currentNode->itemNode());
    }
    else if(newItemNode->keyUtf16() < currentNode->key())
    {
        graphicsScene->addLeftBranch(currentNode,50.0,60.0);
        currentNode->leftNode = addNodeInTree(newItemNode,
                                              currentNode->leftNode,
                                              currentNode->itemLeftBranch());
    }
    else if(newItemNode->keyUtf16() > currentNode->key())
    {
        graphicsScene->addRightBranch(currentNode,80.0,60.0);
        currentNode->rightNode = addNodeInTree(newItemNode,
                                               currentNode->rightNode,
                                               currentNode->itemRightBranch());
    }

    return currentNode;
}
