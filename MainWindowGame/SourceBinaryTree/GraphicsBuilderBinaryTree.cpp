#include "GraphicsBuilderBinaryTree.h"
#include <QGraphicsLineItem>

GraphicsBuilderBinaryTree::GraphicsBuilderBinaryTree():tree(nullptr)
{

}

void GraphicsBuilderBinaryTree::addGraphicsNodeInTree(GraphicsNode* const newNode)
{
    tree = addGraphicsNodeInTree(newNode,tree,QPointF(500.0,200.0));
}

GraphicsBinaryTree* GraphicsBuilderBinaryTree::addGraphicsNodeInTree
(GraphicsNode* const itemNode, GraphicsBinaryTree* currentNode,
 QPointF startPosNode, qsizetype index)
{
    if(currentNode == nullptr)
    {
        currentNode = new GraphicsBinaryTree(itemNode);
        currentNode->setPosition(startPosNode,array.elementAt(index));
        sceneNode->addItem(currentNode->itemNode());
        sceneNode->addItem(currentNode->itemLeftBranch());
        sceneNode->addItem(currentNode->itemRightBranch());
        return currentNode;
    }
    else if(itemNode->key() < currentNode->key())
    {
        currentNode->itemLeftBranch()->show();
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode,
                                                      currentNode->p2LeftBranch(),
                                                      index+1);
    }
    else if(itemNode->key() > currentNode->key())
    {
        currentNode->itemRightBranch()->show();
        currentNode->rightNode = addGraphicsNodeInTree(itemNode,currentNode->rightNode,
                                                       currentNode->p2RightBranch(),
                                                       index+1);
    }
    return currentNode;
}
