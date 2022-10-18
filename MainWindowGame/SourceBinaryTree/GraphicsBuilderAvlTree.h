#ifndef BUILDERAVLTREE_H
#define BUILDERAVLTREE_H

#include "GraphicsBuilder.h"
#include "SimpleBinaryTree.h"
#include "MethodsInitArrOffsets.h"

class PositionItems
{
public:
    PositionItems(QPointF oldPos,
                  std::pair<QLineF, QLineF> branchParent,
                  std::pair<QLineF,QLineF> branchChild);
    PositionItems(PositionItems& oldPosItems);
    QPointF oldPosParentNode;
    std::pair<QLineF, QLineF> branchesParendNode;
    std::pair<QLineF, QLineF> branchesChildNode;
};

class GraphicsBuilderAvlTree: public GraphicsBuilder
{
    public:
        GraphicsBuilderAvlTree();
        ~GraphicsBuilderAvlTree() = default;
        void addGraphicsNodeInTree(GraphicsNode* const newNode) override final;

    private:
        SimpleBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                SimpleBinaryTree* currentNode);
        SimpleBinaryTree* addGraphicsNodeInTree(GraphicsNode* const itemNode,
                                                SimpleBinaryTree* currentNode,
                                                const QPointF newPosNode);
        void fixBalanced(SimpleBinaryTree*& currentNode);
        void fixHeight(SimpleBinaryTree*& currentNode);
        qint32 learnHeightNode(SimpleBinaryTree* const node);
        qint32 learnBalance(SimpleBinaryTree* currentNode);
        SimpleBinaryTree* rotateOnLeft(SimpleBinaryTree* currentNode);
        SimpleBinaryTree* rotateOnRight(SimpleBinaryTree* currentNode);
        void updatePositionAllItems(SimpleBinaryTree*& currentNode,
                                    const QPointF posBranchXY2 = QPointF(0.0,0.0),
                                    QGraphicsLineItem* const branch = nullptr);
        void updateItemsTree(SimpleBinaryTree*& currentNode, const QPointF newPosNode);
        QPointF updatePositionNode(GraphicsNode*& node, const QPointF newPosNode);
        SimpleBinaryTree* tree;
        ArrayOffsets<OffsetsBranchForAvlTree, std::pair<QPointF,QPointF>> array;
};

#endif // BUILDERAVLTREE_H
