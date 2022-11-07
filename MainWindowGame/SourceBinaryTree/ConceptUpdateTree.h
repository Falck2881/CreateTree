#ifndef CONCEPTPOSITIONTREE_H
#define CONCEPTPOSITIONTREE_H

#include <QPointF>
#include <utility>
#include <vector>
#include <concepts>

class GraphicsBinaryTree;
class GraphicsBTree;
class UpdateBinaryTree;
class UpdateBTree;

template<typename MethodUpdateTree>
concept IsUpdateTree = std::same_as<MethodUpdateTree, UpdateBinaryTree> ||
                       std::same_as<MethodUpdateTree, UpdateBTree>;


template<typename TypeTree>
concept IsRefOnTree = std::same_as<TypeTree, GraphicsBinaryTree*> ||
                                 std::same_as<TypeTree, GraphicsBTree*>;

#endif // CONCEPTPOSITIONTREE_H
