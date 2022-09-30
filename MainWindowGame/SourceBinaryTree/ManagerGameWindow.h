#ifndef MANAGERGAMEWINDOW_H
#define MANAGERGAMEWINDOW_H

#include <QRadioButton>
#include <QObject>
#include <QGraphicsView>
#include "Archive.h"
#include "Builder.h"
#include "MethodBuild.h"

class GameWindow;

class ManagerGameWindow: public QObject
{
    Q_OBJECT
    public:
        explicit ManagerGameWindow(GameWindow* const gameWin);
        void updateBuilder(Builder* newBuilder);
        void updateArrayNodes(ArrayNodes* newTypeArray);
    public slots:
        void insertNode();
    private:
        void clearDataManager();
        void deleteDataManager();
    private:
        GameWindow* const gameWin;
        Builder* builder;
        std::unique_ptr<Archive> archive;
};

#endif // MANAGERGAMEWINDOW_H
