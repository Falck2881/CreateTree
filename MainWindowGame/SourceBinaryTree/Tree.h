#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <QString>
#include <QStringView>
#include <QGraphicsLineItem>

class Tree
{
    public:
        Tree() = default;
        virtual ~Tree(){}
        virtual const ushort* key() = 0;
};
#endif // TREE_H
