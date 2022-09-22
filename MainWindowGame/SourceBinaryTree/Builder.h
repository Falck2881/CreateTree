#ifndef BUILDER_H
#define BUILDER_H

#include "GraphicsSceneNode.h"
#include "SimpleBinaryTree.h"

class Builder
{
    public:
        Builder();
        virtual ~Builder() = default;
        QGraphicsScene* scene() const;
        virtual void addNodeInTree(Node* const newItemNode) = 0;
    protected:
        std::unique_ptr<GraphicsSceneNode> graphicsScene;
};

#endif // BUILDER_H
