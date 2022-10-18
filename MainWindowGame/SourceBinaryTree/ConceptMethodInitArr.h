#ifndef CONCEPTMETHODINITARR_H
#define CONCEPTMETHODINITARR_H

#include <QPointF>
#include <utility>
#include <vector>

template<typename MethodInit, typename Element>
concept IsInitializeOffsetBranch =
    requires(MethodInit methodInit, std::vector<Element>& arr)
    {
        methodInit.initialize(arr);
    };

template<typename TypeElement>
concept IsAcceptableTypeVector = std::same_as<TypeElement, std::pair<QPointF,QPointF>> ||
                                 std::same_as<TypeElement, QPointF>;

#endif // CONCEPTMETHODINITARR_H
