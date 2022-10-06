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
        currentNode->setPositionGraphicsItems(QPointF(500.0,200.0),arrayOffsetBranch.at(index));
        sceneNode->addItem(currentNode->itemNode());
        sceneNode->addItem(currentNode->itemLeftBranch());
        sceneNode->addItem(currentNode->itemRightBranch());
        return currentNode;
    }
    else if(itemNode->key() < currentNode->key())
    {
        currentNode->itemLeftBranch()->show();
        incrementIndex();
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode,
                                                      currentNode->itemLeftBranch()->line().p2());
        decrimentIndex();
    }
    else if(itemNode->key() > currentNode->key())
    {
        currentNode->itemRightBranch()->show();
        incrementIndex();
        currentNode->rightNode = addGraphicsNodeInTree(itemNode,currentNode->rightNode,
                                                       currentNode->itemRightBranch()->line().p2());
        decrimentIndex();
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
        currentNode->setPositionGraphicsItems(newPosNode,arrayOffsetBranch.at(index));
        sceneNode->addItem(currentNode->itemNode());
        sceneNode->addItem(currentNode->itemLeftBranch());
        sceneNode->addItem(currentNode->itemRightBranch());
    }
    else if(itemNode->key() < currentNode->key())
    {
        currentNode->itemLeftBranch()->show();
        incrementIndex();
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode,
                                                      currentNode->itemLeftBranch()->line().p2());
        decrimentIndex();
    }
    else if(itemNode->key() > currentNode->key())
    {
        currentNode->itemRightBranch()->show();
        incrementIndex();
        currentNode->rightNode = addGraphicsNodeInTree(itemNode, currentNode->rightNode,
                                                       currentNode->itemRightBranch()->line().p2());
        decrimentIndex();
    }

    return currentNode;
}
