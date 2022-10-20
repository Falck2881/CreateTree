#include "OffsetBinaryBranch.h"

OffsetBinaryBranch::OffsetBinaryBranch()
{
    setPositionRootBranches();
}

void OffsetBinaryBranch::setPositionRootBranches()
{
    const QPointF rootPosNode(500.0,200.0);

    const QPointF p1Begin(rootPosNode.x() + 20.0 , rootPosNode.y() + 40.0);
    const QPointF p2EndLeftBranch(rootPosNode.x() - 200.0, rootPosNode.y() + 60.0);
    const QPointF p2EndRightBranch(rootPosNode.x() + 220.0, rootPosNode.y() + 60.0);
    leftBranch.setPoints(p1Begin,p2EndLeftBranch);
    rightBranch.setPoints(p1Begin,p2EndRightBranch);
}
