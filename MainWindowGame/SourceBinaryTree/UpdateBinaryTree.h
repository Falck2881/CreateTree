#ifndef UPDATEBINARYTREE_H
#define UPDATEBINARYTREE_H

#include <QLineF>
#include <vector>
#include <QPointF>
#include "OffsetBranch.h"

class GraphicsBinaryTree;
class QGraphicsLineItem;



class UpdateBinaryTree
{
public:
    UpdateBinaryTree();
    void updatePositionTree(GraphicsBinaryTree* tree);
private:
    void updatePositionTree(GraphicsBinaryTree* tree,
                            const QPointF posNode,
                            const qsizetype index = 0,
                            QGraphicsLineItem* const branch = nullptr);

    void updateNode(GraphicsBinaryTree* currentNode,
                    const QPointF posNode,
                    const qsizetype index);
    void initializeOffsetBranches(std::pair<QLineF,QLineF> );
    std::pair<QLineF,QLineF> getStartOffsetsBranches();
    std::vector<OffsetsBranches> arrayOffset;
};

#endif // UPDATEBINARYTREE_H
