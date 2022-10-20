#include "GraphicsBuilderBTree.h"

GraphicsBuilderBTree::GraphicsBuilderBTree(const quint32 coefficient):
    tree(nullptr),coefficient(coefficient),
    minNumberData(coefficient),minNumberDescendants(coefficient+1),
    refOnTamporaryNode(nullptr)
{

}

void GraphicsBuilderBTree::addGraphicsNodeInTree(GraphicsNode *const newItemNode)
{
    insertNewData(newItemNode);
}

void GraphicsBuilderBTree::insertNewData(GraphicsNode* const newNode)
{
    if(tree == nullptr)
    {
        tree = new GraphicsBTree(coefficient);
        tree->addDataInEnd(newNode);
    }
    else if(tree->isTerminalVertex())
    {
        if(tree->notMaximumSizeData())
            tree->addDataInEnd(newNode);
        else{
            findIntermediateDataInNode(newNode,tree);
            tree = createFirstRootVertex(tree);
            tree->changeHeight(tree->descendants.first()->height());
        }
        return;
    }
    else{
        findNodeForInsertNewData(newNode,tree);
        tryInsertTamporaryDataInCurrentNode(tree);
    }
    tree = reconstruction(tree);
    tree->changeHeight(tree->descendants.first()->height());
}

void GraphicsBuilderBTree::findIntermediateDataInNode(GraphicsNode* const newNode, GraphicsBTree*& currentNode)
{
    auto less{[](GraphicsNode* const firstNode, GraphicsNode* const secondNode)
        {
            return firstNode->key() < secondNode->key();
        }};
    QVector<GraphicsNode*>data{currentNode->nodes};
    data.push_back(newNode);
    std::sort(data.begin(), data.end(),less);
    tamporaryNode = data.at(data.size()/2);
    refOnTamporaryNode = &tamporaryNode;
    data.removeAt(data.size()/2);
    currentNode->nodes = std::move(data);
}

GraphicsBTree* GraphicsBuilderBTree::createFirstRootVertex(GraphicsBTree* rootNode)
{
    const int leftAndRightDescendant{2};
    GraphicsBTree* newRootNode = new GraphicsBTree(coefficient);
    newRootNode->addDataInEnd(refOnTamporaryNode);
    cancelRefOnTamporaryNode();

    for(int i=0; i < leftAndRightDescendant; ++i)
    {
        newRootNode->descendants.push_back(new GraphicsBTree(coefficient));
        for(int iteration=0; iteration < minNumberData; ++iteration){
            newRootNode->descendants.at(i)->addDataInEnd(rootNode->nodes.first());
            rootNode->nodes.removeFirst();
        }
    }
    delete rootNode;
    return newRootNode;
}

void GraphicsBuilderBTree::findNodeForInsertNewData(GraphicsNode* const newNode, GraphicsBTree*& currentNode)
{
    auto less{[](GraphicsNode* const firstNode, GraphicsNode* const secondNode)
        {
            return firstNode->key() < secondNode->key();
        }};
    QVector<GraphicsNode*> data{currentNode->nodes};
    data.push_back(newNode);
    std::sort(data.begin(), data.end(),less);
    qsizetype numberChildBranch{data.indexOf(newNode)};

    insertNewData(newNode,currentNode->descendants[numberChildBranch], currentNode);
}

void GraphicsBuilderBTree::insertNewData(GraphicsNode* const newNode, GraphicsBTree*& currentNode, GraphicsBTree*& parentNode)
{
    if(currentNode->isTerminalVertex()){
        insert(newNode,currentNode,parentNode);
        return;
    }
    else{
        findNodeForInsertNewData(newNode,currentNode);
        tryInsertTamporaryDataInCurrentNode(currentNode);
    }
    currentNode = reconstruction(currentNode,parentNode);
    currentNode->changeHeight(currentNode->descendants.first()->height());
}

void GraphicsBuilderBTree::insert(GraphicsNode* const newNode, GraphicsBTree *&currentNode, GraphicsBTree *&parentNode)
{
    if(currentNode->notMaximumSizeData())
        currentNode->addDataInEnd(newNode);
    else if(parentNode->notMaximumNumberDescendants())
    {
        findIntermediateDataInNode(newNode,currentNode);
        insertNewTerminalNode(currentNode,parentNode);
    }
}

int findIndexForInsertNewNode(GraphicsBTree*& parentNode, GraphicsNode *&tamporaryData)
{
    auto less{[](GraphicsNode* firstAcc, GraphicsNode* secondAcc)
        {
            return firstAcc->key() < secondAcc->key();
        }};
    QVector<GraphicsNode*> data{parentNode->nodes};
    data.push_back(tamporaryData);
    std::sort(data.begin(),data.end(),less);
    return data.indexOf(tamporaryData);
}

GraphicsBTree* movePieceDataInNewNode(GraphicsBTree*& currentNode, uint64_t coefficient)
{
    GraphicsBTree* newNode{new GraphicsBTree(coefficient)};
    qsizetype quantityIteration{currentNode->nodes.size()/2};
    for(int iteration = 0; iteration < quantityIteration; ++iteration){
        newNode->addDataInEnd(currentNode->nodes.last());
        currentNode->nodes.removeLast();
    }
    return newNode;
}

void GraphicsBuilderBTree::insertNewTerminalNode(GraphicsBTree*& currentNode, GraphicsBTree*& parentNode)
{
    int index{findIndexForInsertNewNode(parentNode,refOnTamporaryNode)};
    GraphicsBTree* newTerminalNode{movePieceDataInNewNode(currentNode,coefficient)};
    parentNode->descendants.insert(index+1,newTerminalNode);
}

void GraphicsBuilderBTree::tryInsertTamporaryDataInCurrentNode(GraphicsBTree *&currentNode)
{
    if(refOnTamporaryNode != nullptr)
    {
        if(currentNode->notMaximumSizeData()){
            currentNode->addDataInEnd(refOnTamporaryNode);
            cancelRefOnTamporaryNode();
        }
        else
            findIntermediateDataInNode(refOnTamporaryNode,currentNode);
    }
}

void GraphicsBuilderBTree::cancelRefOnTamporaryNode()
{
    refOnTamporaryNode = nullptr;
}

GraphicsBTree* GraphicsBuilderBTree::reconstruction(GraphicsBTree* currentNode, GraphicsBTree *parentNode)
{
    if(isRequiredCreateNewRootNode(currentNode,parentNode))
        currentNode = createNewRootVertex(currentNode);
    else if(isRequiredCreateNewDescendant(currentNode,parentNode)){
        createNewDescendant(currentNode,parentNode);
    }
    return currentNode;
}

GraphicsBTree* GraphicsBuilderBTree::createNewRootVertex(GraphicsBTree* currentNode)
{
    const int leftAndRightDescendant{2};
    GraphicsBTree* newRootVertex{new GraphicsBTree(coefficient)};
    newRootVertex->addDataInEnd(refOnTamporaryNode);
    cancelRefOnTamporaryNode();

    for(int i = 0; i < leftAndRightDescendant; ++i)
    {
        newRootVertex->descendants.push_back(new GraphicsBTree(coefficient));
        for(int j = 0; j < minNumberDescendants; ++j){
            transferingDataAndDescendantsFromOldRootVertexInNewDescendant(newRootVertex->descendants.at(i), currentNode);
        }
    }
    delete currentNode;
    return newRootVertex;
}

void GraphicsBuilderBTree::transferingDataAndDescendantsFromOldRootVertexInNewDescendant(GraphicsBTree *newDescendent,
                                                                                        GraphicsBTree *currentNode)
{
    if(newDescendent->nodes.size() != minNumberData && newDescendent->descendants.size() != minNumberDescendants){
        newDescendent->addDataInEnd(currentNode->nodes.first());
        currentNode->nodes.removeFirst();
        newDescendent->descendants.push_back(currentNode->descendants.first());
        newDescendent->changeHeight(currentNode->descendants.first()->height());
        currentNode->descendants.removeFirst();
    }
    else if(newDescendent->descendants.size() != minNumberDescendants){
        newDescendent->descendants.push_back(currentNode->descendants.first());
        newDescendent->changeHeight(currentNode->descendants.first()->height());
        currentNode->descendants.removeFirst();
    }
}

void GraphicsBuilderBTree::createNewDescendant(GraphicsBTree *&currentNode, GraphicsBTree *&parentNode)
{
    int index{findIndexForInsertNewNode(parentNode,refOnTamporaryNode)};
    GraphicsBTree* newDescendant(new GraphicsBTree(coefficient));
    for(int i = 0; i < minNumberDescendants; ++i){
        transferingDataAndDescendantsFromCurrentNodeInNewDescendant(newDescendant, currentNode);
    }
    parentNode->descendants.insert(index+1,newDescendant);
}

void GraphicsBuilderBTree::transferingDataAndDescendantsFromCurrentNodeInNewDescendant(GraphicsBTree *newDescendant,
                                                                                      GraphicsBTree *currentNode)
{
    if(newDescendant->nodes.size() != minNumberData && newDescendant->descendants.size() != minNumberDescendants)
    {
        newDescendant->addDataInBegin(currentNode->nodes.last());
        currentNode->nodes.removeLast();
        newDescendant->descendants.push_front(currentNode->descendants.last());
        newDescendant->changeHeight(currentNode->descendants.last()->height());
        currentNode->descendants.removeLast();
    }
    else if (newDescendant->descendants.size() != minNumberDescendants)
    {
        newDescendant->descendants.push_front(currentNode->descendants.last());
        newDescendant->changeHeight(currentNode->descendants.last()->height());
        currentNode->descendants.removeLast();
    }
}

bool GraphicsBuilderBTree::isRequiredCreateNewRootNode(GraphicsBTree*& currentNode, GraphicsBTree*& parentNode) const
{
    return parentNode == nullptr &&
           currentNode->maximumSizeData() &&
           currentNode->maximumNumberDescendants() ?true:false;
}

bool GraphicsBuilderBTree::isRequiredCreateNewDescendant(GraphicsBTree*& currentNode,GraphicsBTree*& parentNode) const
{
    return parentNode != nullptr &&
           parentNode->notMaximumNumberDescendants() &&
           currentNode->maximumSizeData() &&
           currentNode->maximumNumberDescendants() ?true:false;
}
