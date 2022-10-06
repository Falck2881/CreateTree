#include "Archive.h"
#include "GameWindow.h"
#include <utility>

Archive::Archive(GameWindow* const gameWin):
    array(nullptr),
    gameWin(gameWin)
{
}

bool Archive::empty()
{
    return array->empty();
}

void Archive::updateArrayNodes(ArrayNodes *newArrayNodes)
{
    if(array != nullptr)
    {
        delete array;
        array = newArrayNodes;
        newArrayNodes = nullptr;
    }
    else if(array == nullptr)
    {
        array = newArrayNodes;
        newArrayNodes = nullptr;
    }
}

GraphicsNode* Archive::nextElement()
{
    GraphicsNode* node = array->moveData();
    std::pair<QString,QPixmap> pair(node->keyNameLetter(),node->image());
    gameWin->updateInformationAboutNode(pair);
    return node;
}

Archive::~Archive()
{
    delete array;
    qDebug() << "Archive::~Archive()";
}
