#ifndef GRAPHICSTREE_H
#define GRAPHICSTREE_H

#include <QRadioButton>
#include <QObject>
#include <QGraphicsView>
#include "GraphicsBuilder.h"
#include "MethodBuild.h"
#include "Array.h"

class GameWindow;

class GraphicsTree: public QObject
{
    Q_OBJECT

    public:
        GraphicsTree(GameWindow* const gameWindow);
        void updateBuilder(std::unique_ptr<GraphicsBuilder> newBuilder);
        void updateArray(std::unique_ptr<Array> newTypeArray);
    public slots:
        void insertNode();
    private:
        GameWindow* const gameWin;
        std::unique_ptr<GraphicsBuilder> builder;
        std::unique_ptr<Array> array;
};

#endif // GRAPHICSTREE_H
