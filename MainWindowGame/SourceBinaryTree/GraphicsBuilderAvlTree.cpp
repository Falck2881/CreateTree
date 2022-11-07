#include "GraphicsBuilderAvlTree.h"

GraphicsBuilderAvlTree::GraphicsBuilderAvlTree(const QString methodBuild):
    GraphicsBuilder(methodBuild),tree(nullptr)
{

}

void GraphicsBuilderAvlTree::addGraphicsNodeInTree(GraphicsNode* const newNode)
{
    tree = addGraphicsNodeInTree(newNode,tree);
    tree->update();
}

GraphicsBinaryTree* GraphicsBuilderAvlTree::addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                                  GraphicsBinaryTree* currentNode)
{
    if(currentNode == nullptr){
        currentNode = new GraphicsBinaryTree(itemNode);
        sceneDisplayTree->addItem(currentNode->itemNode());
        sceneDisplayTree->addItem(currentNode->itemLeftBranch());
        sceneDisplayTree->addItem(currentNode->itemRightBranch());
    }
    else if(itemNode->key() < currentNode->key())
        currentNode->leftNode = addGraphicsNodeInTree(itemNode,currentNode->leftNode);
    else if(itemNode->key() > currentNode->key())
        currentNode->rightNode = addGraphicsNodeInTree(itemNode, currentNode->rightNode);

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

GraphicsBuilderAvlTree::~GraphicsBuilderAvlTree()
{
    delete tree;
}
