#ifndef OFFSETBINARYBRANCH_H
#define OFFSETBINARYBRANCH_H

#include <QLineF>
#include <vector>
#include <QPointF>
#include "GraphicsBinaryTree.h"

class OffsetBinaryBranch
{
public:
    OffsetBinaryBranch();
    template<typename Type>
    void initialize(std::vector<Type>& arrayOffset);
private:
    void setPositionRootBranches();
    QLineF leftBranch;
    QLineF rightBranch;
};

template<typename Type>
void OffsetBinaryBranch::initialize(std::vector<Type>& arrayOffset)
{
    qreal byAxesX{1.6};
    qreal byAxesY{4.0};

    std::pair<qreal,qreal> valuesLeftBranch(leftBranch.length(),60.0);
    std::pair<qreal,qreal> valuesRightBranch(rightBranch.length(),60.0);

    for(quint32 i = 0; i < 10; ++i)
    {

        ValuesBranches valuesBranches{.valueLeftBranch = valuesLeftBranch,.valueRightBranch = valuesRightBranch};
        arrayOffset.push_back(valuesBranches);
        qreal value = valuesLeftBranch.first / byAxesX;
        valuesLeftBranch = std::make_pair(value,valuesLeftBranch.second+byAxesY);
        value = valuesRightBranch.first / byAxesX;
        valuesRightBranch = std::make_pair(value,valuesRightBranch.second+byAxesY);

        byAxesX-=0.02;
        byAxesY+=4.0;
    }
}


#endif // METHODSINITARROFFSETS_H
