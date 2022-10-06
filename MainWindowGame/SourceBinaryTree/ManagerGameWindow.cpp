#include "ManagerGameWindow.h"
#include "StreamJson.h"
#include "GameWindow.h"

ManagerGameWindow::ManagerGameWindow(GameWindow* const gameWin):
    gameWin(gameWin),builder(nullptr),archive(std::make_unique<Archive>(gameWin))
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

void ManagerGameWindow::updateArrayNodes(ArrayNodes*newDataType)
{
    archive->updateArrayNodes(newDataType);
}

void ManagerGameWindow::insertNode()
{
    if(!archive->empty())
        builder->addGraphicsNodeInTree(archive->nextElement());
    else
        gameWin->gameEnd();
}

