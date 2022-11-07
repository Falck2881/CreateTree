 #include "GraphicsBuilderBTree.h"

GraphicsBuilderBTree::GraphicsBuilderBTree(const QString methodBuild, const quint32 coefficient):
    GraphicsBuilder(methodBuild),
    tree(nullptr),coefficient(coefficient),
    minNumberData(coefficient),minNumberDescendants(coefficient+1),
    refOnIntermediateItem(nullptr)
{

}

void GraphicsBuilderBTree::addGraphicsNodeInTree(GraphicsNode *const newItemNode)
{
    insertNewData(newItemNode);
    tree->update();
}

void GraphicsBuilderBTree::insertNewData(GraphicsNode* const newItem)
{
    if(tree == nullptr)
    {
        tree = new GraphicsBTree(coefficient);
        tree->addItem(newItem);
        sceneDisplayTree->addItem(tree->node());
        sceneDisplayTree->addItem(newItem);
        return;
    }
    else if(tree->isTerminalVertex())
    {
        if(tree->notMaximumSizeData()){
            tree->addItem(newItem);
            sceneDisplayTree->addItem(newItem);
        }else{
            sceneDisplayTree->addItem(newItem);
            findIntermediateItemInNode(newItem,tree);
            tree = createFirstRootVertex(tree);
            tree->changeHeight(tree->heightFirstDescendant());
        }
        return;
    }
    else{
        findNodeForInsertNewItem(newItem,tree);
        tryInsertTamporaryDataInCurrentNode(tree);
    }
    tree = reconstruction(tree);
    tree->changeHeight(tree->heightFirstDescendant());
}

void GraphicsBuilderBTree::findIntermediateItemInNode(GraphicsNode* const newItem, GraphicsBTree* currentNode)
{
    auto fromLessToMore{[](GraphicsNode* const firstItem, GraphicsNode* const secondItem)
        {
            return firstItem->key() < secondItem->key();
        }};
    QVector<GraphicsNode*>items{currentNode->items()};
    items.push_back(newItem);
    std::sort(items.begin(), items.end(),fromLessToMore);
    refOnIntermediateItem = items.at(items.size()/2);
    items.removeAt(items.size()/2);
    currentNode->updateItems(items);
}

GraphicsBTree* GraphicsBuilderBTree::createFirstRootVertex(GraphicsBTree* rootNode)
{
    const int leftAndRightDescendant{2};
    GraphicsBTree* newRootNode = new GraphicsBTree(coefficient);
    sceneDisplayTree->addItem(newRootNode->node());
    newRootNode->addItem(refOnIntermediateItem);
    cancelRefOnIntermediateItem();

    for(int i=0; i < leftAndRightDescendant; ++i)
    {
        newRootNode->addDescendantInEnd(std::make_shared<GraphicsBTree>(coefficient));
        newRootNode->addBranch(std::make_shared<QGraphicsLineItem>());
        sceneDisplayTree->addItem(newRootNode->branchLast());
        sceneDisplayTree->addItem(newRootNode->descendantsAt(i)->node());
        for(int iteration=0; iteration < minNumberData; ++iteration){
            newRootNode->descendantsAt(i)->addItem(rootNode->itemsFirst());
            rootNode->removeFirstItems();
        }
    }
    delete rootNode;
    return newRootNode;
}

void GraphicsBuilderBTree::findNodeForInsertNewItem(GraphicsNode* const newItem, GraphicsBTree* currentNode)
{
    auto fromLessToMore{[](GraphicsNode* const firstItem, GraphicsNode* const secondItem)
        {
            return firstItem->key() < secondItem->key();
        }};
    QVector<GraphicsNode*> items{currentNode->items()};
    items.push_back(newItem);
    std::sort(items.begin(), items.end(),fromLessToMore);
    qsizetype numberChildBranch{items.indexOf(newItem)};

    insertNewData(newItem,currentNode->descendantsAt(numberChildBranch), currentNode);
}

void GraphicsBuilderBTree::insertNewData(GraphicsNode* const newItem, GraphicsBTree* currentNode, GraphicsBTree* parentNode)
{
    if(currentNode->isTerminalVertex()){
        insert(newItem,currentNode,parentNode);
        return;
    }
    else{
        findNodeForInsertNewItem(newItem,currentNode);
        tryInsertTamporaryDataInCurrentNode(currentNode);
    }
    currentNode = reconstruction(currentNode,parentNode);
    currentNode->changeHeight(currentNode->heightFirstDescendant());
}

void GraphicsBuilderBTree::insert(GraphicsNode* const newItem, GraphicsBTree *currentNode, GraphicsBTree *parentNode)
{
    if(currentNode->notMaximumSizeData()){
        currentNode->addItem(newItem);
        sceneDisplayTree->addItem(newItem);
    }
    else if(parentNode->notMaximumNumberDescendants())
    {
        sceneDisplayTree->addItem(newItem);
        findIntermediateItemInNode(newItem,currentNode);
        insertNewTerminalNode(currentNode,parentNode);
    }
}

int findIndexForInsertNewNode(GraphicsBTree* parentNode, GraphicsNode *tamporaryItem)
{
    auto fromLessToMore{[](GraphicsNode* firstItem, GraphicsNode* secondItem)
        {
            return firstItem->key() < secondItem->key();
        }};
    QVector<GraphicsNode*> items{parentNode->items()};
    items.push_back(tamporaryItem);
    std::sort(items.begin(),items.end(),fromLessToMore);
    return items.indexOf(tamporaryItem);
}

std::shared_ptr<GraphicsBTree> movePieceItemsInNewNode(GraphicsBTree* currentNode, uint64_t coefficient)
{
    std::shared_ptr<GraphicsBTree> newNode{std::make_shared<GraphicsBTree>(coefficient)};
    qsizetype quantityIteration{currentNode->quantityItems()/2};
    for(int iteration = 0; iteration < quantityIteration; ++iteration){
        newNode->addItem(currentNode->itemsLast());
        currentNode->removeLastItems();
    }
    return newNode;
}

void GraphicsBuilderBTree::insertNewTerminalNode(GraphicsBTree* currentNode, GraphicsBTree* parentNode)
{
    int index{findIndexForInsertNewNode(parentNode,refOnIntermediateItem)};
    parentNode->addBranch(std::make_shared<QGraphicsLineItem>());
    std::shared_ptr<GraphicsBTree> newTerminalNode{movePieceItemsInNewNode(currentNode,coefficient)};
    sceneDisplayTree->addItem(parentNode->branchLast());
    sceneDisplayTree->addItem(newTerminalNode->node());
    parentNode->insertNewDescendant(index+1,newTerminalNode);
}

void GraphicsBuilderBTree::tryInsertTamporaryDataInCurrentNode(GraphicsBTree *currentNode)
{
    if(refOnIntermediateItem != nullptr)
    {
        if(currentNode->notMaximumSizeData()){
            currentNode->addItem(refOnIntermediateItem);
            cancelRefOnIntermediateItem();
        }
        else
            findIntermediateItemInNode(refOnIntermediateItem,currentNode);
    }
}

void GraphicsBuilderBTree::cancelRefOnIntermediateItem()
{
    refOnIntermediateItem = nullptr;
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
    sceneDisplayTree->addItem(newRootVertex->node());
    newRootVertex->addItem(refOnIntermediateItem);
    cancelRefOnIntermediateItem();

    for(int i = 0; i < leftAndRightDescendant; ++i)
    {
        newRootVertex->addDescendantInEnd(std::make_shared<GraphicsBTree>(coefficient));
        newRootVertex->addBranch(std::make_shared<QGraphicsLineItem>());
        sceneDisplayTree->addItem(newRootVertex->branchLast());
        sceneDisplayTree->addItem(newRootVertex->descendantsAt(i)->node());
        for(int j = 0; j < minNumberDescendants; ++j){
            transferingDataAndDescendantsFromOldRootVertexInNewDescendant(newRootVertex->descendantsAt(i), currentNode);
        }
    }
    delete currentNode;
    return newRootVertex;
}

void GraphicsBuilderBTree::transferingDataAndDescendantsFromOldRootVertexInNewDescendant(GraphicsBTree *newDescendent,
                                                                                        GraphicsBTree *currentNode)
{
    if(newDescendent->quantityItems() != minNumberData && newDescendent->quantityDescendants() != minNumberDescendants){
        newDescendent->addItem(currentNode->itemsFirst());
        currentNode->removeFirstItems();
        newDescendent->addDescendantInEnd(currentNode->descendantFirst());
        newDescendent->changeHeight(currentNode->heightFirstDescendant());
        currentNode->removeFirstDescendant();
    }
    else if(newDescendent->quantityDescendants() != minNumberDescendants){
        newDescendent->addDescendantInEnd(currentNode->descendantFirst());
        newDescendent->changeHeight(currentNode->heightFirstDescendant());
        currentNode->removeFirstDescendant();
    }
}

void GraphicsBuilderBTree::createNewDescendant(GraphicsBTree *currentNode, GraphicsBTree *parentNode)
{
    int index{findIndexForInsertNewNode(parentNode,refOnIntermediateItem)};
    parentNode->addBranch(std::make_shared<QGraphicsLineItem>());
    std::shared_ptr<GraphicsBTree> newDescendant(std::make_shared<GraphicsBTree>(coefficient));
    sceneDisplayTree->addItem(newDescendant->node());
    sceneDisplayTree->addItem(parentNode->branchLast());

    for(int i = 0; i < minNumberDescendants; ++i)
        transferingDataAndDescendantsFromCurrentNodeInNewDescendant(newDescendant.get(), currentNode);

    parentNode->insertNewDescendant(index+1,newDescendant);
}

void GraphicsBuilderBTree::transferingDataAndDescendantsFromCurrentNodeInNewDescendant(GraphicsBTree *newDescendant,
                                                                                      GraphicsBTree *currentNode)
{
    if(newDescendant->quantityItems() != minNumberData && newDescendant->quantityDescendants() != minNumberDescendants)
    {
        newDescendant->addItem(currentNode->itemsLast());
        currentNode->removeLastItems();
        newDescendant->addDescendantInBegin(currentNode->descendantLast());
        newDescendant->changeHeight(currentNode->heightLastDescendant());
        currentNode->removeLastItems();
    }
    else if (newDescendant->quantityDescendants() != minNumberDescendants)
    {
        newDescendant->addDescendantInBegin(currentNode->descendantLast());
        newDescendant->changeHeight(currentNode->heightLastDescendant());
        currentNode->removeLastDescendant();
    }
}

bool GraphicsBuilderBTree::isRequiredCreateNewRootNode(GraphicsBTree* currentNode, GraphicsBTree* parentNode) const
{
    return parentNode == nullptr &&
           currentNode->maximumSizeData() &&
           currentNode->maximumNumberDescendants() ?true:false;
}

bool GraphicsBuilderBTree::isRequiredCreateNewDescendant(GraphicsBTree* currentNode,GraphicsBTree* parentNode) const
{
    return parentNode != nullptr &&
           parentNode->notMaximumNumberDescendants() &&
           currentNode->maximumSizeData() &&
           currentNode->maximumNumberDescendants() ?true:false;
}

GraphicsBuilderBTree::~GraphicsBuilderBTree()
{
    delete tree;
}
