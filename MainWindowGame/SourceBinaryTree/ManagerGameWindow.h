#ifndef MANAGERGAMEWINDOW_H
#define MANAGERGAMEWINDOW_H

#include <QRadioButton>
#include <QObject>
#include <QGraphicsView>
#include "GraphicsBuilder.h"
#include "MethodBuild.h"
#include "Array.h"

class GameWindow;

class ManagerGameWindow: public QObject
{
    Q_OBJECT

    public:
        ManagerGameWindow(GameWindow* const gameWindow);
        void updateBuilder(GraphicsBuilder* newBuilder);
        void updateArray(Array* newTypeArray);
    public slots:
        void insertData();
    private:
        GameWindow* const gameWin;
        GraphicsBuilder* builder;
        Array* array;
};

#endif // MANAGERGAMEWINDOW_H
