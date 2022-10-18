#include "ManagerGameWindow.h"
#include "StreamJson.h"
#include "GameWindow.h"

ManagerGameWindow::ManagerGameWindow(GameWindow* const gameWindow):
    gameWin(gameWindow),
    builder(nullptr),
    arrayNodes(nullptr)
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

void ManagerGameWindow::updateArrayNodes(ArrayNodes* newArrayNodes)
{
    if(arrayNodes != nullptr)
    {
        delete arrayNodes;
        arrayNodes = newArrayNodes;
        newArrayNodes = nullptr;
    }
    else if(arrayNodes == nullptr)
    {
        arrayNodes = newArrayNodes;
        newArrayNodes = nullptr;
    }
}

void ManagerGameWindow::insertNode()
{
    try{
        if(GraphicsNode* node = arrayNodes->getData(); node != nullptr){
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
