#include "ArrayNodes.h"
#include "StreamJson.h"

ArrayNodes::ArrayNodes(const QString nameBuilder):currentIndex{0}
{
    Q_INIT_RESOURCE(BuildData);
    extractContent(nameBuilder);
    updateArrayBoundaries(0,nodes.size()-1);
}

bool ArrayNodes::empty()
{
    return nodes.empty();
}

void ArrayNodes::extractContent(const QString nameBuilder)
{
    StreamJson stream(QString(":/ContentNode.json"));

        for(auto charecter: nameBuilder)
            nodes.push_back(new Node(stream.getJsonValue(QString(charecter))));
}

void ArrayNodes::updateArrayBoundaries(const qint32 minSize, const qint32 maxSize)
{
    minSizeVector = minSize;
    maxSizeVector = maxSize;
}


void ArrayNodes::clearOldReferenceOnData(const quint32 index)
{
    nodes.erase(std::begin(nodes)+index);
}

void  ArrayNodes::updateIndex()
{
    if(currentIndex < quint32(maxSizeVector))
        ++currentIndex;

    if(currentIndex == quint32(maxSizeVector))
        nodes.clear();
}

quint32 ArrayNodes::getIndex()
{
    return currentIndex;
}


LinearArrayNodes::LinearArrayNodes(const QString nameBuilder):ArrayNodes(nameBuilder)
{
}

Node* LinearArrayNodes::moveData()
{
    const quint32 index = getIndex();
    Node* node = nodes.at(index);
    updateArrayBoundaries(0,nodes.size()-1);
    updateIndex();
    return node;
}

ArrayNodesForRandomTree::ArrayNodesForRandomTree(const QString nameBuilder):ArrayNodes(nameBuilder)
{}

Node* ArrayNodesForRandomTree::moveData()
{
    qint32 index = simplRandom.getNumber(minSizeVector,maxSizeVector);
    Node* node = nodes.at(index);
    clearOldReferenceOnData(index);
    updateArrayBoundaries(0,nodes.size()-1);
    return node;
}

ArrayNodesForPBTTree::ArrayNodesForPBTTree(const QString nameBuilder):ArrayNodes(nameBuilder)
{
    fillArrayAnIndexes(minSizeVector,maxSizeVector);
    sortingByInsertion(nodes);
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

void ArrayNodesForPBTTree::sortingByInsertion(std::vector<Node*> &nodes)
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
                nodes.at(leftEdgeIndex)->keyUtf16() > nodes.at(rightEdgeIndex)->keyUtf16())
                std::swap(nodes[leftEdgeIndex],nodes[rightEdgeIndex]);
            else
                break;
        }
    }
}

Node* ArrayNodesForPBTTree::moveData()
{
    const quint32 index = arrIndex.at(getIndex());
    Node* node = nodes.at(index);
    updateIndex();
    return node;
}

