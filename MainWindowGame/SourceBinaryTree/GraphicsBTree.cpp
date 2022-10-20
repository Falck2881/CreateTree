#include "GraphicsBTree.h"

GraphicsBTree::GraphicsBTree(const quint32 coefficient):
    _height(1),maxQuantityData(2*coefficient),
    maxQuantityDescendants((2*coefficient)+2),
    container(nullptr)
{
    nodes.reserve(maxQuantityData);
    nodes.reserve(maxQuantityDescendants);
}

void GraphicsBTree::addDataInEnd(GraphicsNode* const node)
{
    nodes.push_back(node);
}

void GraphicsBTree::addDataInBegin(GraphicsNode* const node)
{
    nodes.push_front(node);
}

bool GraphicsBTree::isTerminalVertex() const
{
    return _height == 1?true:false;
}

bool GraphicsBTree::notMaximumSizeData() const
{
    return nodes.size() != maxQuantityData ?true:false;
}

bool GraphicsBTree::notMaximumNumberDescendants() const
{
    return descendants.size() != maxQuantityDescendants? true:false;
}

bool GraphicsBTree::maximumSizeData() const
{
    return nodes.size() == maxQuantityData ?true:false;
}

bool GraphicsBTree::maximumNumberDescendants() const
{
    return descendants.size() == maxQuantityDescendants ? true:false;
}
