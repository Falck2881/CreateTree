#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "ArrayNodes.h"
#include <utility>

class GameWindow;

class Archive
{
    public:
        explicit Archive(GameWindow* const gameWin);
        ~Archive();
        void updateArrayNodes(ArrayNodes* newArrayNodes);
        bool empty();
        GraphicsNode* nextElement();
    private:
        ArrayNodes* array;
        GameWindow* const gameWin;
};

#endif // ARCHIVE_H
