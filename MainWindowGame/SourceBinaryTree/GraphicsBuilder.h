#ifndef BUILDER_H
#define BUILDER_H

#include "SimpleBinaryTree.h"
#include <QGraphicsScene>

class GraphicsBuilder
{
    public:
        GraphicsBuilder();
        virtual ~GraphicsBuilder() = default;
        QGraphicsScene* scene() const;
        virtual void addGraphicsNodeInTree(GraphicsNode* const newItemNode) = 0;
    protected:
        void incrementIndex();
        void decrimentIndex();
        std::unique_ptr<QGraphicsScene> sceneNode;
        std::vector<std::pair<QPointF,QPointF>> arrayOffsetBranch;
        quint32 index;
    private:
        void initializeArrayOffsetBranch();
};

#endif // BUILDER_H
