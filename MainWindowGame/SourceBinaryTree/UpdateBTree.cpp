#include "UpdateBTree.h"
#include "GraphicsBTree.h"
#include <cmath>
#include <QThread>

void UpdateBTree::updatePositionTree(GraphicsBTree *tree)
{

    updateNode(QPointF(1000.0,500.0),tree);
}

void UpdateBTree::updateNode(const QPointF startPosNode, GraphicsBTree *tree, QGraphicsLineItem *const branch)
{
    if(tree == nullptr)
    {
        if(branch != nullptr)
            branch->hide();
        return ;
    }
    else if(tree->isTerminalVertex())
    {
        changeSquareNode(startPosNode,tree);
        updatePosItemsNode(tree);
    }
    else{
        changeSquareNode(startPosNode,tree);
        updatePosItemsNode(tree);
        updatePosBranches(tree);
        for(quint32 index = 0; index < tree->quantityDescendants(); ++index){
            tree->branchAt(index)->show();
            updateNode(tree->branchAtPos2(index),tree->descendantsAt(index),tree->branchAt(index));
        }
    }
}

void UpdateBTree::changeSquareNode(const QPointF startPosNode, GraphicsBTree *tree)
{
    const quint32 multilplier = tree->quantityItems();
    qreal width{44.0 * multilplier};
    qreal hight{48.0};
    const QRectF newSquare(startPosNode.x(),startPosNode.y(),width,hight);
    tree->setSquareRect(newSquare);
    tree->node()->show();
}

void UpdateBTree::updatePosItemsNode(GraphicsBTree *tree)
{
    QPointF startPosItem(tree->topLeftRect());
    startPosItem.setX(startPosItem.x()+4);
    startPosItem.setY(startPosItem.y()+4);

    for(quint32 index = 0; index < tree->quantityItems(); ++index)
    {

        tree->itemsAt(index)->updatePos(startPosItem);
        tree->itemsAt(index)->show();
        startPosItem.setX(tree->itemsAt(index)->topRightX());
        startPosItem.setY(tree->itemsAt(index)->topRightY());
    }
}

qreal pointOnCircleByX(const qreal x, const qreal radius, quint32 angleDegree)
{
    const qreal newX = x + (radius * cos(angleDegree * (M_PI / 180)));
    return newX;
}

void UpdateBTree::updatePosBranches(GraphicsBTree *tree)
{
    quint32 offset = 160.0;
    quint32 sumOffset = 0;
    QPointF beginPos1{tree->bottomPosItem(0)};
    QPointF endPos2(pointOnCircleByX(beginPos1.x(),180, 180),
                    beginPos1.y() + 40.0);
    tree->setPosBranch(QLineF(beginPos1,endPos2),0);

    for(quint32 index = 1; index < tree->quantityDescendants(); ++index)
    {
        QPointF beginPos1{tree->bottomPosItem(index)};
        QPointF endPos2(beginPos1.x() + sumOffset,beginPos1.y() + 40.0);
        tree->setPosBranch(QLineF(beginPos1,endPos2),index);
        sumOffset+=offset;
        offset+=60.0;
    }
}
