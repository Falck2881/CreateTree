#include "GraphicsTree.h"
#include "StreamJson.h"
#include "GameWindow.h"

GraphicsTree::GraphicsTree(GameWindow* const gameWindow):
    gameWin(gameWindow),
    builder(nullptr),
    array(nullptr)
{
}

void GraphicsTree::updateBuilder(std::unique_ptr<GraphicsBuilder> newBuilder)
{
    if(builder != nullptr){
        delete builder.release();
        builder = std::move(newBuilder);
        gameWin->updateGraphicsView(builder->scene());
        newBuilder = nullptr;
    }
    else if(builder == nullptr){
        builder = std::move(newBuilder);
        gameWin->updateGraphicsView(builder->scene());
        newBuilder = nullptr;
    }
}

void GraphicsTree::updateArray(std::unique_ptr<Array> newTypeArray)
{
    if(array != nullptr)
    {
        delete array.release();
        array = std::move(newTypeArray);
        newTypeArray = nullptr;
    }
    else if(array == nullptr)
    {
        array = std::move(newTypeArray);
        newTypeArray = nullptr;
    }
}

void GraphicsTree::insertNode()
{
    try{
        GraphicsNode* node = array->getData();
        builder->addGraphicsNodeInTree(node);
        std::pair<QString, QPixmap> dataNode(node->keyNameLetter(),node->image());
        gameWin->updateInformationAboutNode(dataNode);
    }
    catch(std::runtime_error err){
        qDebug() << err.what();
        gameWin->completionConstruction();
    }
}
