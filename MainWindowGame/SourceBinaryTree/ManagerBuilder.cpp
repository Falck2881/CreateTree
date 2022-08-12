#include "ManagerBuilder.h"
#include "StreamJson.h"
#include "MainWindowGame.h"

ManagerBuilder::ManagerBuilder(MainWindowGame* const mainWindow):
    mainWindow(mainWindow)
{
    Q_INIT_RESOURCE(JsonData);
    setStrategy();
}

void ManagerBuilder::setStrategy()
{

}

void ManagerBuilder::setBinaryTreeConstractionsStrategy(const std::vector<QPushButton *&> refOnButtonStrategy)
{
    buttonsStrategy = refOnButtonStrategy;
}

void ManagerBuilder::updateDataInNodeProxy(const QString string)
{
    StreamJson streamJson(":/ContentNode.json");

    foreach(auto charecter, string)
        nodesProxy.push_back(std::make_unique<NodeProxy>(streamJson.getJsonValue(charecter)));

    mainWindow->updateDataInGameWindow(nodesProxy);
}

void ManagerBuilder::build()
{

}
