#ifndef MANAGERBUILDER_H
#define MANAGERBUILDER_H

#include "NodeProxy.h"
#include <QPushButton>
#include <vector>

class MainWindowGame;

class ManagerBuilder
{
    public:
        ManagerBuilder(MainWindowGame* const mainWindow);
        void setBinaryTreeConstractionsStrategy(const std::vector<QPushButton*&> refOnButtonStrategy);
        void updateDataInNodeProxy(const QString string);
    public slots:
        void build();
    private:
        void setStrategy();
        void (*arrStrategy[5])(QPushButton* button);
        std::vector<std::unique_ptr<NodeProxy>> nodesProxy;
        std::vector<QPushButton*&> buttonsStrategy;
        MainWindowGame* const mainWindow;
};

#endif // MANAGERBUILDER_H
