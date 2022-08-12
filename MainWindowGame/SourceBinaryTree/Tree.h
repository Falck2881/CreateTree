#ifndef TREE_H
#define TREE_H

#include "NodeProxy.h"
#include <QString>

class Tree
{
    public:
        Tree() = default;
        virtual ~Tree() = default;
        virtual const Node* searchNode(QStringView viewKey) = 0;
};

#endif // TREE_H
