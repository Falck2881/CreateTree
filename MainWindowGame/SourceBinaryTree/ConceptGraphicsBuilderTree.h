#ifndef CONCEPTGRAPHICSBUILDERTREE_H
#define CONCEPTGRAPHICSBUILDERTREE_H

class GraphicsNode;
class QPointF;

template<typename MethodPlacment, typename TypeTree>
concept IsMethodPlacmentItemsInTree =
    requires(MethodPlacment method, TypeTree&& tree, const QPointF posNode)
    {
        method.placmentAllItemsInTree(tree, posNode);
    };

template<typename TypeTree>
concept IsBTree =
        requires(TypeTree&& tree)
        {
            tree.isTerminalVertex();
            tree.notMaximumSizeData();
            tree.notMaximumNumberDescendants();
            tree.maximumNumberDescendants();
            tree.maximumSizeData();
        };

template<typename TypeTree>
concept IsBinaryTree =
        requires(TypeTree&& tree)
        {
            tree.itemLeftBranch();
            tree.itemRightBranch();
            tree.pos2LeftBranch();
            tree.pos2RightBranch();
        };

template<typename TypeTree>
concept IsTree = IsBinaryTree<TypeTree> || IsBTree<TypeTree>;

template<typename TypeTree>
concept IsRefBTree =
        requires(TypeTree&& tree)
        {
            tree->isTerminalVertex();
            tree->notMaximumSizeData();
            tree->notMaximumNumberDescendants();
            tree->maximumNumberDescendants();
            tree->maximumSizeData();
        };

template<typename TypeTree>
concept IsRefBinaryTree =
        requires(TypeTree&& tree)
        {
            tree->itemLeftBranch();
            tree->itemRightBranch();
            tree->pos2LeftBranch();
            tree->pos2RightBranch();
        };

template<typename TypeTree>
concept IsRefTree = IsRefBinaryTree<TypeTree> || IsRefBTree<TypeTree>;

#endif // CONCEPTGRAPHICSBUILDERTREE_H
