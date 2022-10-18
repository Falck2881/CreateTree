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
        void increment();
        void decriment();
        auto element();
    private:
        std::vector<TypeElement> arrayOffsetBranch;
        MethodInit method;
        qint32 index;
    private:
        void initialize();
};

template<typename MethodInit, typename TypeElement>
requires IsAcceptableTypeVector<TypeElement> && IsInitializeOffsetBranch<MethodInit,TypeElement>
ArrayOffsets<MethodInit,TypeElement>::ArrayOffsets():index(0)
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
auto ArrayOffsets<MethodInit,TypeElement>::element()
{
    return arrayOffsetBranch.at(index);
}

template<typename MethodInit, typename TypeElement>
requires IsAcceptableTypeVector<TypeElement> && IsInitializeOffsetBranch<MethodInit,TypeElement>
void ArrayOffsets<MethodInit,TypeElement>::increment()
{
    ++index;
}

template<typename MethodInit, typename TypeElement>
requires IsAcceptableTypeVector<TypeElement> && IsInitializeOffsetBranch<MethodInit,TypeElement>
void ArrayOffsets<MethodInit,TypeElement>::decriment()
{
    if(index != 0)
         --index;
}

#endif // ARRAYOFFSETS_H
