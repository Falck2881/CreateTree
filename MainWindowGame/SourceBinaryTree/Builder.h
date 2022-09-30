#ifndef BUILDER_H
#define BUILDER_H

#include "GraphicsTree.h"
#include "SimpleBinaryTree.h"

class Builder
{
    public:
        Builder();
        virtual ~Builder() = default;
        QGraphicsScene* scene() const;
        virtual void addNodeInTree(GraphicsNode* const newItemNode) = 0;
    protected:
        std::unique_ptr<GraphicsTree> graphicsTree;
};

#endif // BUILDER_H
