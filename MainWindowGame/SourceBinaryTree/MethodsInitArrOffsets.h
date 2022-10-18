#ifndef METHODSINITARROFFSETS_H
#define METHODSINITARROFFSETS_H

#include <vector>
#include "ConceptMethodInitArr.h"

class OffsetsBranchForAvlTree
{
public:
    OffsetsBranchForAvlTree() = default;
    template<typename TypeElement>
    void initialize(std::vector<TypeElement>& arrayOffset)
    {
        qreal ratioAxesX2 = 2.4;
        qreal ratioAxesY2 = 4.4;
        const quint32 size{10};
        QPointF leftOffsetByAxesXY2(220.0,44.0);
        QPointF rightOffsetByAxesXY2(260.0,44.0);

        for(quint32 index = 0; index < size; ++index)
        {
            arrayOffset.push_back(std::make_pair(leftOffsetByAxesXY2,rightOffsetByAxesXY2));
            leftOffsetByAxesXY2.setX(leftOffsetByAxesXY2.x() / ratioAxesX2);
            leftOffsetByAxesXY2.setY(leftOffsetByAxesXY2.y() + ratioAxesY2);
            rightOffsetByAxesXY2.setX(rightOffsetByAxesXY2.x() / ratioAxesX2);
            rightOffsetByAxesXY2.setY(rightOffsetByAxesXY2.y() + ratioAxesY2);
            ratioAxesX2 -= 0.2;
            ratioAxesY2 += 1.2;
        }
    }
};

class OffsetsBranchForBinaryTree
{
public:
    OffsetsBranchForBinaryTree() = default;
    template<typename TypeElement>
    void initialize(std::vector<TypeElement>& arrayOffset)
    {
        qreal ratioLeft = 14.0;
        qreal ratioRight = 20.0;
        qreal ratioBottom = 4.4;
        const quint32 size{5};
        QPointF leftOffsetByAxesXY2(80.0,44.0);
        QPointF rightOffsetByAxesXY2(100.0,44.0);

        arrayOffset.push_back(std::make_pair(QPointF(180.0,44.0),QPointF(200.0,44.0)));

        for(quint32 index = 0; index < size; ++index)
        {
            arrayOffset.push_back(std::make_pair(leftOffsetByAxesXY2,rightOffsetByAxesXY2));

            leftOffsetByAxesXY2.setX(leftOffsetByAxesXY2.x() - ratioLeft);
            leftOffsetByAxesXY2.setY(leftOffsetByAxesXY2.y() + ratioBottom);
            rightOffsetByAxesXY2.setX(rightOffsetByAxesXY2.x() - ratioRight);
            rightOffsetByAxesXY2.setY(rightOffsetByAxesXY2.y() + ratioBottom);
            ratioLeft -= 2.0;
            ratioRight -= 2.2;
            ratioBottom += 1.2;
        }
    }
};

#endif // METHODSINITARROFFSETS_H
