#include "ArrayNodes.h"
#include "StreamJson.h"
#include "GameWindow.h"

ArrayNodes::ArrayNodes(const QString nameBuilder)
{
    Q_INIT_RESOURCE(BuildData);
    extractContent(nameBuilder);
}

bool ArrayNodes::empty()
{
    return nodes.empty();
}

void ArrayNodes::extractContent(const QString nameBuilder)
{
    StreamJson stream(QString(":/ContentNode.json"));

    for(auto charecter: nameBuilder){
       if(charecter != QString(" "))
          nodes.push_back(new GraphicsNode(stream.getJsonValue(QString(charecter))));
    }
}

ArrayNodes::~ArrayNodes()
{
    nodes.clear();
    nodes.shrink_to_fit();
}

LinearArrayNodes::LinearArrayNodes(const QString nameBuilder):ArrayNodes(nameBuilder),currNode(nodes.begin())
{
}

GraphicsNode* LinearArrayNodes::getData()
{
    GraphicsNode* node = nullptr;

    if(currNode != nodes.end()){
        node = *currNode;
        ++currNode;
    }

    return node;
}

ArrayNodesForRandomTree::ArrayNodesForRandomTree(const QString nameBuilder):ArrayNodes(nameBuilder)
{}

GraphicsNode* ArrayNodesForRandomTree::getData()
{
    GraphicsNode* node = nullptr;

    if(!nodes.empty())
    {
        const qint32 index = simplRandom.getNumber(0,nodes.size()-1);
        node = *(nodes.begin()+index);
        nodes.erase(std::begin(nodes)+index);
        nodes.shrink_to_fit();
    }

    return node;
}

ArrayNodesForPBTTree::ArrayNodesForPBTTree(const QString nameBuilder):ArrayNodes(nameBuilder)
{
    fillArrayAnIndexes(0,nodes.size()-1);
    sortingByInsertion(nodes);
    currIndex = arrIndex.begin();
}

void ArrayNodesForPBTTree::fillArrayAnIndexes(const qint32 leftEdge, const qint32 rightEdge)
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

void ArrayNodesForPBTTree::sortingByInsertion(std::vector<GraphicsNode*> &nodes)
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

GraphicsNode* ArrayNodesForPBTTree::getData()
{
    GraphicsNode* node = nullptr;

    if(currIndex != arrIndex.end())
    {
        const quint32 index = *currIndex;
        node = *(nodes.begin()+index);
        ++currIndex;
        return node;
    }

    return node;
}

