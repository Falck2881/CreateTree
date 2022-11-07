#ifndef BUILDER_H
#define BUILDER_H

#include "GraphicsNode.h"
#include <QGraphicsScene>
#include <stdexcept>

class GraphicsBuilder
{
    public:
        explicit GraphicsBuilder(const QString methodBuild);
        virtual ~GraphicsBuilder() = default;
        QString methodBuild() const;
        QGraphicsScene* scene();
        virtual void addGraphicsNodeInTree(GraphicsNode* const newItemNode) = 0;
    private:
        const QString method;
    protected:
        std::unique_ptr<QGraphicsScene> sceneDisplayTree;
};

#endif // BUILDER_H
