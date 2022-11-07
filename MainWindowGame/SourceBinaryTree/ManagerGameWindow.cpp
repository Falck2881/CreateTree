#include "ManagerGameWindow.h"
#include "StreamJson.h"
#include "GameWindow.h"

ManagerGameWindow::ManagerGameWindow(GameWindow* const gameWindow):
    gameWin(gameWindow),
    builder(nullptr),
    array(nullptr)
{
}

void ManagerGameWindow::updateBuilder(GraphicsBuilder* newBuilder)
{
    if(builder != nullptr){
        delete builder;
        builder = newBuilder;
        gameWin->updateGraphicsView(builder->scene());
        newBuilder = nullptr;
    }
    else if(builder == nullptr){
        builder = newBuilder;
        gameWin->updateGraphicsView(builder->scene());
        newBuilder = nullptr;
    }
}

void ManagerGameWindow::updateArray(Array* newTypeArray)
{
    if(array != nullptr)
    {
        delete array;
        array = newTypeArray;
        newTypeArray = nullptr;
    }
    else if(array == nullptr)
    {
        array = newTypeArray;
        newTypeArray = nullptr;
    }
}

void ManagerGameWindow::insertData()
{
    try{
        if(GraphicsNode* node = array->getData(); node != nullptr){
            builder->addGraphicsNodeInTree(node);
            std::pair<QString, QPixmap> dataNode(node->keyNameLetter(),node->image());
            gameWin->updateInformationAboutNode(dataNode);
        }
        else{
            throw std::runtime_error(std::string("GraphicsNode equal to <nullptr>"));
        }
    }
    catch(std::runtime_error err){
        qDebug() << err.what();
        gameWin->completionConstruction();
    }
}
