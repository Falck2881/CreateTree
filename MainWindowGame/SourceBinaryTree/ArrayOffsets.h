#ifndef ARRAYOFFSETS_H
#define ARRAYOFFSETS_H

#include <vector>
#include "ConceptMethodInitArr.h"

template<typename MethodInit, typename TypeElement>
requires IsAcceptableTypeVector<TypeElement> && IsInitializeOffsetBranch<MethodInit,TypeElement>
class ArrayOffsets
{
    public:
        ArrayOffsets();
        ~ArrayOffsets() = default;
        auto elementAt(const qsizetype index);
    private:
        std::vector<TypeElement> arrayOffsetBranch;
        MethodInit method;
    private:
        void initialize();
};

template<typename MethodInit, typename TypeElement>
requires IsAcceptableTypeVector<TypeElement> && IsInitializeOffsetBranch<MethodInit,TypeElement>
ArrayOffsets<MethodInit,TypeElement>::ArrayOffsets()
{
    initialize();
}

template<typename MethodInit, typename TypeElement>
requires IsAcceptableTypeVector<TypeElement> && IsInitializeOffsetBranch<MethodInit,TypeElement>
void ArrayOffsets<MethodInit,TypeElement>::initialize()
{
    method.initialize(arrayOffsetBranch);
}

template<typename MethodInit, typename TypeElement>
requires IsAcceptableTypeVector<TypeElement> && IsInitializeOffsetBranch<MethodInit,TypeElement>
auto ArrayOffsets<MethodInit,TypeElement>::elementAt(const qsizetype index)
{
    return arrayOffsetBranch.at(index);
}

#endif // ARRAYOFFSETS_H
