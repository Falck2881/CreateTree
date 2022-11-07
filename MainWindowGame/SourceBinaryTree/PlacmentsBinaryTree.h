#ifndef METHODSINITARROFFSETS_H
#define METHODSINITARROFFSETS_H

#include <memory>
#include <QLineF>
#include <vector>
#include <math.h>
#include "GraphicsNode.h"
#include "GraphicsBinaryTree.h"

class PlacmentsItemsInBinaryTree
{
public:
    PlacmentsItemsInBinaryTree();
    template<typename TypeTree>
    void placmentAllItemsInTree(TypeTree&& tree, const QPointF posNode);
private:
    QLineF getStartPosLeftBranch(const QPointF startPos);
    QLineF getStartPosRightBranch(const QPointF startPos);
private:
    void setLegsTriangle();
    void updateLegsTriangle(std::pair<qreal,qreal>& pairLegs);
    std::pair<qreal,qreal> legsLeftBranch;
    std::pair<qreal,qreal> legsRightBranch;
    qreal sumX;
};

template<typename TypeTree>
void PlacmentsItemsInBinaryTree::placmentAllItemsInTree(TypeTree&& currentNodeTree,
                                                        const QPointF posNode)
{
    currentNodeTree->itemNode()->setPos(posNode);
    currentNodeTree->updateLeftBranch(getStartPosLeftBranch(posNode));
    currentNodeTree->updateRightBranch(getStartPosRightBranch(posNode));
}

#endif // METHODSINITARROFFSETS_H
