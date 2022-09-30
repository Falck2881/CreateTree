#ifndef GRAPHICSTREE_H
#define GRAPHICSTREE_H

#include "SimpleBinaryTree.h"
#include <memory>
#include <utility>
#include <QGraphicsScene>

class GraphicsTree
{
    public:
        GraphicsTree();
        QGraphicsScene* scene() const;
        QPointF posNode() const;
        void addItem(QGraphicsItem* const item);
        void addLeftBranch(SimpleBinaryTree*& node);
        void addRightBranch(SimpleBinaryTree*& node);
        void reduceIndex();
        void increaseIndex();
    private:
        quint32 nextIndex();
        void initializeArrayOffsetBranch();
        void preparePositionNewNode(QPointF endPos2);
        std::unique_ptr<QGraphicsScene> sceneNode;
        std::vector<std::pair<QPointF,QPointF>> arrayOffsetBranch;
        quint32 index;
        QPointF position;

};

#endif // GRAPHICSTREE_H
