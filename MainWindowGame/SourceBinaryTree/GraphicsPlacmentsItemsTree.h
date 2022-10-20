#ifndef GRAPHICSPLACMENTSITEMSTREE_H
#define GRAPHICSPLACMENTSITEMSTREE_H

#include <QPointF>
#include <vector>
#include "ConceptGraphicsBuilderTree.h"
#include "GraphicsNode.h"

template<typename MethodPlacmentItems,typename TypeTree>
requires IsTree<TypeTree> && IsMethodPlacmentItemsInTree<MethodPlacmentItems,TypeTree>
class GraphicsPlacmentsItemsTree
{
    private:
        MethodPlacmentItems method;
    public:
        GraphicsPlacmentsItemsTree() = default;
        ~GraphicsPlacmentsItemsTree() = default;
        template<IsRefTree RefTypeTree>
        void placmentAllItemsInTree(RefTypeTree&& tree, const QPointF posNode)
        {
            method.placmentAllItemsInTree(tree,posNode);
        }
};



#endif // GRAPHICSPLACMENTSITEMSTREE_H
