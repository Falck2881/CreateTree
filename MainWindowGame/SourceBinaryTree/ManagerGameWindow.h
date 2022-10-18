#ifndef MANAGERGAMEWINDOW_H
#define MANAGERGAMEWINDOW_H

#include <QRadioButton>
#include <QObject>
#include <QGraphicsView>
#include "GraphicsBuilder.h"
#include "MethodBuild.h"
#include "ArrayNodes.h"

class GameWindow;

class ManagerGameWindow: public QObject
{
    Q_OBJECT

    public:
        ManagerGameWindow(GameWindow* const gameWindow);
        void updateBuilder(GraphicsBuilder* newBuilder);
        void updateArrayNodes(ArrayNodes* newTypeArray);
    public slots:
        void insertNode();
    private:
        GameWindow* const gameWin;
        GraphicsBuilder* builder;
        ArrayNodes* arrayNodes;
};

#endif // MANAGERGAMEWINDOW_H
