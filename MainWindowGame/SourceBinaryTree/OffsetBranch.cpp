#include "OffsetBranch.h"

OffsetsBranches::OffsetsBranches(const OffsetsBranches& old)
{
    leftOffset = old.leftOffset;
    rightOffset = old.rightOffset;
}

OffsetsBranches& OffsetsBranches::operator=(OffsetsBranches& old)
{
    if(this == &old)
        return *this;

    leftOffset = old.leftOffset;
    rightOffset = old.rightOffset;

    return *this;
}
