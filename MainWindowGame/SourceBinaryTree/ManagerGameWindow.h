#ifndef MANAGERGAMEWINDOW_H
#define MANAGERGAMEWINDOW_H

#include <QRadioButton>
#include <QObject>
#include <QGraphicsView>
#include "Archive.h"
#include "GraphicsBuilder.h"
#include "MethodBuild.h"

class GameWindow;

class ManagerGameWindow: public QObject
{
    Q_OBJECT
    public:
        explicit ManagerGameWindow(GameWindow* const gameWin);
        void updateBuilder(GraphicsBuilder* newBuilder);
        void updateArrayNodes(ArrayNodes* newTypeArray);
    public slots:
        void insertNode();
    private:
        void clearDataManager();
        void deleteDataManager();
    private:
        GameWindow* const gameWin;
        GraphicsBuilder* builder;
        std::unique_ptr<Archive> archive;
};

#endif // MANAGERGAMEWINDOW_H
