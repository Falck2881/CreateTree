#ifndef BUILDER_H
#define BUILDER_H

#include "ConceptMethodInitArr.h"
#include "ArrayOffsets.h"
#include "SimpleBinaryTree.h"
#include <QGraphicsScene>
#include <stdexcept>

class GraphicsBuilder
{
    public:
        GraphicsBuilder();
        virtual ~GraphicsBuilder() = default;
        QGraphicsScene* scene() const;
        virtual void addGraphicsNodeInTree(GraphicsNode* const newItemNode) = 0;
    protected:
        std::unique_ptr<QGraphicsScene> sceneNode;
};

#endif // BUILDER_H
