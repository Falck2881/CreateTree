#include "GraphicsBuilderAvlTree.h"

GraphicsBuilderAvlTree::GraphicsBuilderAvlTree():tree(nullptr)
{

}

void GraphicsBuilderAvlTree::addGraphicsNodeInTree(GraphicsNode* const newNode)
{
    tree = addGraphicsNodeInTree(newNode,tree);
    updatePositionAllItems(tree, QPointF(500.0,200.0));
}

SimpleBinaryTree* GraphicsBuilderAvlTree::addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                SimpleBinaryTree* currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(itemNode);
        currentNode->setPositionGraphicsItems(QPointF(500.0,200.0),array.element());
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

    fixBalanced(currentNode);

    return currentNode;
}


SimpleBinaryTree* GraphicsBuilderAvlTree::addGraphicsNodeInTree(GraphicsNode* const itemNode,
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

    fixBalanced(currentNode);

    return currentNode;
}

void GraphicsBuilderAvlTree::fixBalanced(SimpleBinaryTree *&currentNode)
{
    fixHeight(currentNode);

    if(learnBalance(currentNode) == 2)
    {
        if(learnBalance(currentNode->rightNode) == -1)
            currentNode->rightNode = rotateOnRight(currentNode->rightNode);

        currentNode = rotateOnLeft(currentNode);
    }
    else if(learnBalance(currentNode) == -2)
    {
        if(learnBalance(currentNode->leftNode) == 1)
            currentNode->leftNode = rotateOnLeft(currentNode->leftNode);

        currentNode = rotateOnRight(currentNode);
    }
}

void GraphicsBuilderAvlTree::fixHeight(SimpleBinaryTree *&currentNode)
{
    qint32 heightByLeftSide = learnHeightNode(currentNode->leftNode);
    qint32 heightByRightSide = learnHeightNode(currentNode->rightNode);

    if(heightByLeftSide > heightByRightSide){
        heightByLeftSide+=1;
        currentNode->setHeight(heightByLeftSide);
    }else if(heightByLeftSide < heightByRightSide){
        heightByRightSide+=1;
        currentNode->setHeight(heightByRightSide);
    }else if (heightByLeftSide == heightByRightSide){
        heightByLeftSide+=1;
        currentNode->setHeight(heightByLeftSide);
    }
}

qint32 GraphicsBuilderAvlTree::learnHeightNode(SimpleBinaryTree *const node)
{
    return node != nullptr ? node->height():0;
}

qint32 GraphicsBuilderAvlTree::learnBalance(SimpleBinaryTree *currentNode)
{
    qint32 heightByLeftSide = learnHeightNode(currentNode->leftNode);
    qint32 heightByRightSide = learnHeightNode(currentNode->rightNode);

    return heightByRightSide - heightByLeftSide;
}

SimpleBinaryTree* GraphicsBuilderAvlTree::rotateOnLeft(SimpleBinaryTree *currentNode)
{
    SimpleBinaryTree* newCurrentNode = currentNode->rightNode;
    currentNode->rightNode = newCurrentNode->leftNode;
    newCurrentNode->leftNode = currentNode;

    fixHeight(currentNode);
    fixHeight(newCurrentNode);

    return newCurrentNode;
}

SimpleBinaryTree* GraphicsBuilderAvlTree::rotateOnRight(SimpleBinaryTree *currentNode)
{
    SimpleBinaryTree* newCurrentNode = currentNode->leftNode;
    currentNode->leftNode = newCurrentNode->rightNode;
    newCurrentNode->rightNode = currentNode;

    fixHeight(currentNode);
    fixHeight(newCurrentNode);

    return newCurrentNode;
}

void GraphicsBuilderAvlTree::updatePositionAllItems(SimpleBinaryTree*& currentNode,
                                                    const QPointF posBranchXY2,
                                                    QGraphicsLineItem* const branch)
{
    if(currentNode == nullptr){
        branch->hide();
        return;
    }
    else
    {
        updateItemsTree(currentNode, posBranchXY2);
        array.increment();
        currentNode->itemLeftBranch()->show();
        updatePositionAllItems(currentNode->leftNode,
                               currentNode->itemLeftBranch()->line().p2(),
                               currentNode->itemLeftBranch());
        currentNode->itemRightBranch()->show();
        updatePositionAllItems(currentNode->rightNode,
                               currentNode->itemRightBranch()->line().p2(),
                               currentNode->itemRightBranch());
        array.decriment();
    }
}

void GraphicsBuilderAvlTree::updateItemsTree(SimpleBinaryTree *&currentNode, const QPointF newPosNode)
{
    const QPointF currentPosNode = updatePositionNode(currentNode->itemNode(), newPosNode);

    auto offsetBranch = array.element();

    const QPointF beginXY1(currentPosNode.x() + qreal(20.0),
                           currentPosNode.y() + qreal(40.0));
    const QPointF leftEndXY2(currentPosNode.x() - offsetBranch.first.x(),
                             currentPosNode.y() + offsetBranch.first.y());

    const QPointF rightEndXY2(currentPosNode.x() + offsetBranch.second.x(),
                             currentPosNode.y() + offsetBranch.second.y());

    currentNode->itemLeftBranch()->setLine(QLineF(beginXY1,leftEndXY2));
    currentNode->itemRightBranch()->setLine(QLineF(beginXY1,rightEndXY2));
    currentNode->itemLeftBranch()->hide();
    currentNode->itemRightBranch()->hide();
}

QPointF GraphicsBuilderAvlTree::updatePositionNode(GraphicsNode *&node, const QPointF newPosNode)
{
    node->setPos(QPointF(newPosNode.x()-qreal(20.0), newPosNode.y()));
    return node->pos();
}
