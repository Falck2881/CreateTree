#ifndef UPDATETREE_H
#define UPDATETREE_H

#include "ConceptUpdateTree.h"

template<typename MethodUpdateTree>
requires IsUpdateTree<MethodUpdateTree>
class UpdateTree
{
    public:
        UpdateTree() = default;
        template<IsRefOnTree Type>
        void updatePositionTree(Type&& tree)
        {
            method.updatePositionTree(tree);
        }
    private:
        MethodUpdateTree method;
};


#endif // UPDATETREE_H
