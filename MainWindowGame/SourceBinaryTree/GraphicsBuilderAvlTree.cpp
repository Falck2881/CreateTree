#include "GraphicsBuilderAvlTree.h"

GraphicsBuilderAvlTree::GraphicsBuilderAvlTree():tree(nullptr)
{

}

void GraphicsBuilderAvlTree::addGraphicsNodeInTree(GraphicsNode* const newNode)
{
    tree = addGraphicsNodeInTree(newNode,tree);
    updatePositionTree(tree,QPointF(500.0,200.0));
}

GraphicsBinaryTree* GraphicsBuilderAvlTree::addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                                  GraphicsBinaryTree* currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new GraphicsBinaryTree(itemNode);
        sceneNode->addItem(currentNode->itemNode());
        sceneNode->addItem(currentNode->itemLeftBranch());
        sceneNode->addItem(currentNode->itemRightBranch());
    }
    else if(itemNode->key() < currentNode->key())
    {
        currentNode->itemLeftBranch()->show();
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode);
    }
    else if(itemNode->key() > currentNode->key())
    {
        currentNode->itemRightBranch()->show();
        currentNode->rightNode = addGraphicsNodeInTree(itemNode, currentNode->rightNode);
    }

    fixBalanced(currentNode);

    return currentNode;
}

void GraphicsBuilderAvlTree::fixBalanced(GraphicsBinaryTree *&parentNode)
{
    fixHeight(parentNode);

    if(learnBalance(parentNode) == 2)
    {
        if(learnBalance(parentNode->rightNode) == -1){
            parentNode->rightNode = rotateOnRight(parentNode->rightNode);
        }
        parentNode = rotateOnLeft(parentNode);
    }
    else if(learnBalance(parentNode) == -2)
    {
        if(learnBalance(parentNode->leftNode) == 1){
            parentNode->leftNode = rotateOnLeft(parentNode->leftNode);
        }

        parentNode = rotateOnRight(parentNode);
    }
}

void GraphicsBuilderAvlTree::fixHeight(GraphicsBinaryTree *&parentNode)
{
    qint32 heightByLeftSide = learnHeightNode(parentNode->leftNode);
    qint32 heightByRightSide = learnHeightNode(parentNode->rightNode);

    if(heightByLeftSide > heightByRightSide){
        heightByLeftSide+=1;
        parentNode->setHeight(heightByLeftSide);
    }else if(heightByLeftSide < heightByRightSide){
        heightByRightSide+=1;
        parentNode->setHeight(heightByRightSide);
    }else if (heightByLeftSide == heightByRightSide){
        heightByLeftSide+=1;
        parentNode->setHeight(heightByLeftSide);
    }
}

qint32 GraphicsBuilderAvlTree::learnHeightNode(GraphicsBinaryTree *const node)
{
    return node != nullptr ? node->height():0;
}

qint32 GraphicsBuilderAvlTree::learnBalance(GraphicsBinaryTree *parentNode)
{
    qint32 heightByLeftSide = learnHeightNode(parentNode->leftNode);
    qint32 heightByRightSide = learnHeightNode(parentNode->rightNode);

    return heightByRightSide - heightByLeftSide;
}

GraphicsBinaryTree* GraphicsBuilderAvlTree::rotateOnLeft(GraphicsBinaryTree *parentNode)
{
    GraphicsBinaryTree* newParentNode = parentNode->rightNode;
    parentNode->rightNode = newParentNode->leftNode;
    newParentNode->leftNode = parentNode;


    fixHeight(newParentNode->leftNode);
    fixHeight(newParentNode);

    return newParentNode;
}

GraphicsBinaryTree* GraphicsBuilderAvlTree::rotateOnRight(GraphicsBinaryTree *parentNode)
{
    GraphicsBinaryTree* newParentNode = parentNode->leftNode;
    parentNode->leftNode = newParentNode->rightNode;
    newParentNode->rightNode = parentNode;


    fixHeight(newParentNode->rightNode);
    fixHeight(newParentNode);

    return newParentNode;
}

void GraphicsBuilderAvlTree::updatePositionTree(GraphicsBinaryTree *&currentNode,
                                                const QPointF posNode,
                                                QGraphicsLineItem *const branch,
                                                const qsizetype index)
{
    if(currentNode == nullptr)
    {
        branch->hide();
        return;
    }
    else{
        currentNode->setPosition(posNode,array.elementAt(index));
        currentNode->itemLeftBranch()->show();
        updatePositionTree(currentNode->leftNode,currentNode->p2LeftBranch(),
                           currentNode->itemLeftBranch(), index + 1);
        currentNode->itemRightBranch()->show();
        updatePositionTree(currentNode->rightNode,currentNode->p2RightBranch(),
                           currentNode->itemRightBranch(), index + 1);

    }
}
