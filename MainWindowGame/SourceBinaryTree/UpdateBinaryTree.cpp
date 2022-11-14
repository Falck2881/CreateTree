#include "UpdateBinaryTree.h"
#include "GraphicsBinaryTree.h"
#include <QGraphicsLineItem>

UpdateBinaryTree::UpdateBinaryTree()
{
    std::pair<QLineF,QLineF> startOffset = getStartOffsetsBranches();
    initializeOffsetBranches(startOffset);
}

std::pair<QLineF,QLineF> UpdateBinaryTree::getStartOffsetsBranches()
{
    std::pair<QLineF,QLineF> startOffset;

    const QPointF rootPosNode(1000.0,600.0);

    const QPointF p1Begin(rootPosNode.x() + 20.0 , rootPosNode.y() + 40.0);
    const QPointF p2EndLeftBranch(rootPosNode.x() - 240.0, rootPosNode.y() + 60.0);
    const QPointF p2EndRightBranch(rootPosNode.x() + 260.0, rootPosNode.y() + 60.0);
    startOffset.first.setPoints(p1Begin,p2EndLeftBranch);
    startOffset.second.setPoints(p1Begin,p2EndRightBranch);

    return startOffset;
}

void UpdateBinaryTree::initializeOffsetBranches(std::pair<QLineF,QLineF> startOffset)
{
    qreal byAxesX{2};
    qreal byAxesY{4.0};

    std::pair<qreal,qreal> leftOffset(startOffset.first.length(),60.0);
    std::pair<qreal,qreal> rightOffset(startOffset.second.length(),60.0);

    for(quint32 i = 0; i < 10; ++i)
    {

        OffsetsBranches offsetsBranches;
        offsetsBranches.leftOffset = leftOffset;
        offsetsBranches.rightOffset = rightOffset;
        arrayOffset.push_back(offsetsBranches);

        qreal value = leftOffset.first / byAxesX;
        leftOffset = std::make_pair(value,leftOffset.second+byAxesY);
        value = rightOffset.first / byAxesX;
        rightOffset = std::make_pair(value,rightOffset.second+byAxesY);

        byAxesX-=0.02;
        byAxesY+=4.0;
    }
}

void UpdateBinaryTree::updatePositionTree(GraphicsBinaryTree *tree)
{
    updatePositionTree(tree,QPointF(1000.0,600.0));
}

void UpdateBinaryTree::updatePositionTree(GraphicsBinaryTree *currentNode,const QPointF posNode,
                                          const qsizetype index,QGraphicsLineItem *const branch)
{
    if(currentNode == nullptr)
    {
        if(branch != nullptr)
            branch->hide();

        return;
    }
    else{
        updateNode(currentNode,posNode,index);
        currentNode->itemLeftBranch()->show();
        updatePositionTree(currentNode->leftNode,currentNode->p2LeftBranch(),
                           index + 1, currentNode->itemLeftBranch());
        currentNode->itemRightBranch()->show();
        updatePositionTree(currentNode->rightNode,currentNode->p2RightBranch(),
                           index + 1, currentNode->itemRightBranch());

    }
}

void UpdateBinaryTree::updateNode(GraphicsBinaryTree *currentNode, const QPointF startPos, const qsizetype index)
{
    OffsetsBranches offset = arrayOffset.at(index);

    currentNode->setPosItems(startPos);

    const QPointF p1Begin(currentNode->posBottomX(), currentNode->posBottomY());
    const QPointF p2EndLeftBranch(currentNode->posBottomX() - offset.leftOffset.first,
                                  currentNode->posBottomY() + offset.leftOffset.second);
    const QPointF p2EndRightBranch(currentNode->posBottomX() + offset.rightOffset.first,
                                   currentNode->posBottomY() + offset.rightOffset.second);

    currentNode->setPosLeftBranch(QLineF(p1Begin,p2EndLeftBranch));
    currentNode->setPosRightBranch(QLineF(p1Begin,p2EndRightBranch));

}
