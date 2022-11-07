#include "GraphicsBTree.h"
#include <QLinearGradient>

GraphicsBTree::GraphicsBTree(const quint32 coefficient):
    height(1),maxQuantityData(2*coefficient),
    maxQuantityDescendants((2*coefficient)+2),
    rectangle{std::make_unique<QGraphicsRectItem>()}
{
    _items.reserve(maxQuantityData);
    _items.reserve(maxQuantityDescendants);

    rectangle->setPen(QPen(Qt::black,1));
    rectangle->hide();
}

QGraphicsRectItem* GraphicsBTree::node() const
{
    return rectangle.get();
}

QVector<GraphicsNode*> GraphicsBTree::items() const
{
    return _items;
}

GraphicsNode* GraphicsBTree::itemsAt(const qsizetype index) const
{
    return _items.at(index);
}

GraphicsNode* GraphicsBTree::itemsFirst() const
{
    return _items.first();
}

GraphicsNode* GraphicsBTree::itemsLast() const
{
    return _items.last();
}

qsizetype GraphicsBTree::quantityItems() const
{
    return _items.size();
}

auto fromLessToMore{[](GraphicsNode* const firstNode, GraphicsNode* const secondNode)
    {
        return firstNode->key() < secondNode->key();
    }};

void GraphicsBTree::addItem(GraphicsNode* const item)
{
    _items.push_back(item);
    _items.last()->hide();
    std::sort(_items.begin(),_items.end(),fromLessToMore);
}

void GraphicsBTree::updateItems(QVector<GraphicsNode*> updatedItems)
{
    _items = updatedItems;
}

void GraphicsBTree::removeFirstItems()
{
    _items.removeFirst();
}

void GraphicsBTree::removeLastItems()
{
    _items.removeLast();
}

QVector<std::shared_ptr<GraphicsBTree>> GraphicsBTree::descendants()
{
    return _descendants;
}

GraphicsBTree* GraphicsBTree::descendantsAt(const qsizetype index) const
{
    return _descendants.at(index).get();
}

quint32 GraphicsBTree::heightFirstDescendant() const
{
    return _descendants.first().get()->height;
}

quint32 GraphicsBTree::heightLastDescendant() const
{
    return _descendants.last().get()->height;
}

qsizetype GraphicsBTree::quantityDescendants() const
{
    return _descendants.size();
}

std::shared_ptr<GraphicsBTree> GraphicsBTree::descendantFirst() const
{
    return _descendants.first();
}

std::shared_ptr<GraphicsBTree> GraphicsBTree::descendantLast() const
{
    return _descendants.last();
}

void GraphicsBTree::removeFirstDescendant()
{
    _descendants.removeFirst();
}

void GraphicsBTree::removeLastDescendant()
{
    _descendants.removeLast();
}

void GraphicsBTree::addDescendantInEnd(std::shared_ptr<GraphicsBTree>newDescendant)
{
    _descendants.push_back(newDescendant);
}

void GraphicsBTree::addDescendantInBegin(std::shared_ptr<GraphicsBTree>newDescendant)
{
    _descendants.push_front(newDescendant);
}

void GraphicsBTree::insertNewDescendant(const qsizetype index, std::shared_ptr<GraphicsBTree> newNode)
{
    _descendants.insert(index,newNode);
}

QGraphicsLineItem* GraphicsBTree::branchAt(const qsizetype index) const
{
    return _branches.at(index).get();
}

qreal calculateWidthDecendantsNode(const qreal widthCurrentNode,const quint32 quantityDescendants)
{
    return (widthCurrentNode * quantityDescendants) / 2;
}

QPointF GraphicsBTree::branchAtPos2(const qsizetype index) const
{
    const qreal offset = widthNode()/ 2;
    QPointF startPosDescendant = _branches.at(index)->line().p2();
    startPosDescendant.setX(startPosDescendant.x() - offset);
    return startPosDescendant;
}

QGraphicsLineItem* GraphicsBTree::branchLast() const
{
    return _branches.last().get();
}

void GraphicsBTree::addBranch(std::shared_ptr<QGraphicsLineItem> newBranch)
{
    _branches.push_back(newBranch);
    _branches.last()->setPen(QPen(Qt::black,2));
    _branches.last()->hide();
}

void GraphicsBTree::setPosBranch(const QLineF line, const qsizetype index)
{
    _branches.at(index)->setLine(line);
}

void GraphicsBTree::changeHeight(const quint32 newHeight)
{
    height+=newHeight;
}

void GraphicsBTree::update()
{
    tree.updatePositionTree(this);
}

bool GraphicsBTree::isTerminalVertex() const
{
    return height == 1?true:false;
}

bool GraphicsBTree::notMaximumSizeData() const
{
    return _items.size() != maxQuantityData ?true:false;
}

bool GraphicsBTree::notMaximumNumberDescendants() const
{
    return _descendants.size() != maxQuantityDescendants? true:false;
}

bool GraphicsBTree::maximumNumberDescendants() const
{
    return _descendants.size() == maxQuantityDescendants ? true:false;
}

bool GraphicsBTree::maximumSizeData() const
{
    return _items.size() == maxQuantityData ?true:false;
}

QPointF GraphicsBTree::topLeftRect() const
{
    return rectangle->rect().topLeft();
}

QPointF GraphicsBTree::bottomPosItem(const qsizetype index) const
{
    QPointF pos;

    if(index < _items.size())
        pos = _items.at(index)->rectItem().bottomLeft();
    else if(index == _items.size())
        pos = _items.at(index-1)->rectItem().bottomRight();

    return pos;
}

qreal GraphicsBTree::widthNode() const
{
    return rectangle->rect().width();
}

void GraphicsBTree::setSquareRect(const QRectF newSquare)
{
    rectangle->setRect(newSquare);
}
