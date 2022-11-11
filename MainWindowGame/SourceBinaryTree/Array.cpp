#include "Array.h"
#include "StreamJson.h"
#include "GameWindow.h"

Array::Array(const QString nameBuilder)
{
    Q_INIT_RESOURCE(BuildData);

    StreamJson stream(QString(":/ContentNode.json"));

    for(auto charecter: nameBuilder){
       if(charecter != QString(" "))
          arrItems.push_back(new GraphicsNode(stream.getJsonValue(QString(charecter))));
    }
}

bool Array::empty()
{
    return arrItems.empty();
}

Array::~Array()
{
    arrItems.clear();
    arrItems.shrink_to_fit();
}

LinearArray::LinearArray(const QString nameBuilder):Array(nameBuilder)
{
    currItem = arrItems.begin();
}

GraphicsNode* LinearArray::getData()
{

    if(currItem != arrItems.end()){
        GraphicsNode* node = *currItem;
        ++currItem;
        return node;
    }
    else
        throw std::runtime_error(std::string("Array empty"));
}

ArrayForRandomTree::ArrayForRandomTree(const QString nameBuilder):Array(nameBuilder)
{}

GraphicsNode* ArrayForRandomTree::getData()
{

    if(!arrItems.empty())
    {
        const qint32 index = simplRandom.getNumber(0,arrItems.size()-1);
        GraphicsNode* node = *(arrItems.begin()+index);
        arrItems.erase(std::begin(arrItems)+index);
        arrItems.shrink_to_fit();
        return node;
    }
    else
        throw std::runtime_error(std::string("Array empty"));
}

ArrayForPBTTree::ArrayForPBTTree(const QString nameBuilder):Array(nameBuilder)
{
    fillArrayAnIndexes(0,arrItems.size()-1);
    sortingByInsertion(arrItems);
    currIndex = arrIndex.begin();
}

void ArrayForPBTTree::fillArrayAnIndexes(const qint32 leftEdge, const qint32 rightEdge)
{
    if(leftEdge > rightEdge)
        return;
    else{
        qint32 index = (leftEdge + rightEdge)/2;
        arrIndex.push_back(index);
        fillArrayAnIndexes(leftEdge, index - 1);
        fillArrayAnIndexes(index+1, rightEdge);
    }
}

void ArrayForPBTTree::sortingByInsertion(std::vector<GraphicsNode*> &nodes)
{
    for(quint32 jndex = 0; jndex < nodes.size(); ++jndex)
    {
        quint32 leftEdgeIndex = jndex;

        for(quint32 rightEdgeIndex = jndex+1;
            rightEdgeIndex < nodes.size() &&
            rightEdgeIndex > 0;
            --rightEdgeIndex,
            --leftEdgeIndex)
        {
            if( leftEdgeIndex <  rightEdgeIndex &&
                nodes.at(leftEdgeIndex)->key() > nodes.at(rightEdgeIndex)->key())
                std::swap(nodes[leftEdgeIndex],nodes[rightEdgeIndex]);
            else
                break;
        }
    }
}

GraphicsNode* ArrayForPBTTree::getData()
{

    if(currIndex != arrIndex.end())
    {
        const quint32 index = *currIndex;
        GraphicsNode* node = *(arrItems.begin()+index);
        ++currIndex;
        return node;
    }
    else
        throw std::runtime_error(std::string("Array empty"));

}

