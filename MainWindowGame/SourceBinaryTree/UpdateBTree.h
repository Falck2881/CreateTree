#ifndef UPDATEBTREE_H
#define UPDATEBTREE_H

class GraphicsBTree;
class QPointF;
class QGraphicsLineItem;

#include <vector>
#include <QTimer>
#include <QObject>


class UpdateBTree: public QObject
{
    Q_OBJECT

    public:
        UpdateBTree() = default;
        void updatePositionTree(GraphicsBTree* tree);
    private:
        void updateNode(const QPointF startPosNode, GraphicsBTree* tree,QGraphicsLineItem* const branch = nullptr);
        void changeSquareNode(const QPointF startPosNode, GraphicsBTree* tree);
        void updatePosItemsNode(GraphicsBTree* tree);
        void updatePosBranches(GraphicsBTree* tree);
        QTimer* timer;
};

#endif // UPDATEBTREE_H
