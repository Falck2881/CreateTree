#ifndef TREE_H
#define TREE_H

#include "GraphicsNode.h"
#include <QString>
#include <QStringView>
#include <QGraphicsLineItem>

class Tree
{
    public:
        Tree()= default;
        virtual ~Tree() = default;
        virtual uint key() = 0;
};
#endif // TREE_H
