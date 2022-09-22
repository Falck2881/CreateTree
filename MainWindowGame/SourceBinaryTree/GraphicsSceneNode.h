#ifndef GRAPHICSSCENENODE_H
#define GRAPHICSSCENENODE_H

#include "SimpleBinaryTree.h"
#include <memory>
#include <QGraphicsScene>

class GraphicsSceneNode
{
    public:
        GraphicsSceneNode();
        QGraphicsScene* scene() const;
        QPointF coordinateNode() const;
        void addItem(QGraphicsItem* const item);
        void addLeftBranch(SimpleBinaryTree*& node,
                           const qreal endPosX2 = 200.0,
                           const qreal endPosY2 = 60.0);
        void addRightBranch(SimpleBinaryTree*& node,
                            const qreal endPosX2 = 200.0,
                            const qreal endPosY2 = 60.0);
        void bindBranchWithNewNode(QGraphicsLineItem*& lineItem,Node*& itemNode);
    private:
        void prepareCoordinateForLeftNode(SimpleBinaryTree*& currentNode);
        void prepareCoordinateForRightNode(SimpleBinaryTree*& currentNode);
        void bindNodeWithBranch(Node*& itemNode, QGraphicsLineItem*& node);
        std::unique_ptr<QGraphicsScene> sceneNode;
        QPointF coordinate;
};

#endif // GRAPHICSSCENENODE_H
