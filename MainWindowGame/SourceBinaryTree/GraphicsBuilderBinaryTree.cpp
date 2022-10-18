#include "GraphicsBuilderBinaryTree.h"
#include <QGraphicsLineItem>

GraphicsBuilderBinaryTree::GraphicsBuilderBinaryTree():tree(nullptr)
{

}

void GraphicsBuilderBinaryTree::addGraphicsNodeInTree(GraphicsNode* const newNode)
{
    tree = addGraphicsNodeInTree(newNode,tree);
}

SimpleBinaryTree* GraphicsBuilderBinaryTree::addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                   SimpleBinaryTree* currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(itemNode);
        currentNode->setPositionGraphicsItems(QPointF(500.0,200.0),array.element());
        sceneNode->addItem(currentNode->itemNode());
        sceneNode->addItem(currentNode->itemLeftBranch());
        sceneNode->addItem(currentNode->itemRightBranch());
        return currentNode;
    }
    else if(itemNode->key() < currentNode->key())
    {
        currentNode->itemLeftBranch()->show();
        array.increment();
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode,
                                                      currentNode->itemLeftBranch()->line().p2());
        array.decriment();
    }
    else if(itemNode->key() > currentNode->key())
    {
        currentNode->itemRightBranch()->show();
        array.increment();
        currentNode->rightNode = addGraphicsNodeInTree(itemNode,currentNode->rightNode,
                                                       currentNode->itemRightBranch()->line().p2());
        array.decriment();
    }
    return currentNode;
}

SimpleBinaryTree* GraphicsBuilderBinaryTree::addGraphicsNodeInTree(GraphicsNode *const itemNode,
                                                                   SimpleBinaryTree* currentNode,
                                                                   const QPointF newPosNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(itemNode);
        currentNode->setPositionGraphicsItems(newPosNode,array.element());
        sceneNode->addItem(currentNode->itemNode());
        sceneNode->addItem(currentNode->itemLeftBranch());
        sceneNode->addItem(currentNode->itemRightBranch());
    }
    else if(itemNode->key() < currentNode->key())
    {
        currentNode->itemLeftBranch()->show();
        array.increment();
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode,
                                                      currentNode->itemLeftBranch()->line().p2());
        array.decriment();
    }
    else if(itemNode->key() > currentNode->key())
    {
        currentNode->itemRightBranch()->show();
        array.increment();
        currentNode->rightNode = addGraphicsNodeInTree(itemNode, currentNode->rightNode,
                                                       currentNode->itemRightBranch()->line().p2());
        array.decriment();
    }

    return currentNode;
}
