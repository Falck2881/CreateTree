#ifndef CONCEPTMETHODINITARR_H
#define CONCEPTMETHODINITARR_H

#include <QPointF>
#include <utility>
#include <vector>
#include "GraphicsBinaryTree.h"

template<typename MethodInit, typename Element>
concept IsInitializeOffsetBranch =
    requires(MethodInit methodInit, std::vector<Element>& arr)
    {
        methodInit.initialize(arr);
    };

template<typename TypeElement>
concept IsAcceptableTypeVector = std::same_as<TypeElement, ValuesBranches> ||
                                 std::same_as<TypeElement, QPointF>;

#endif // CONCEPTMETHODINITARR_H
