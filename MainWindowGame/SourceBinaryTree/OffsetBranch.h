#ifndef OFFSETBRANCH_H
#define OFFSETBRANCH_H

#include <utility>
#include <QtGlobal>

class OffsetsBranches
{
public:
    OffsetsBranches() = default;
    OffsetsBranches(const OffsetsBranches& old);

    OffsetsBranches& operator=(OffsetsBranches& old);
    std::pair<qreal,qreal> leftOffset;
    std::pair<qreal,qreal> rightOffset;
};

#endif // OFFSETBRANCH_H
