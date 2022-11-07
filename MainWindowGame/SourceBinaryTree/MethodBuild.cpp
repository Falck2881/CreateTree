#include "MethodBuild.h"
#include "GraphicsBuilderBinaryTree.h"
#include "GraphicsBuilderAvlTree.h"
#include "GraphicsBuilderBTree.h"
#include "GameWindow.h"

MethodBuild::MethodBuild(QRadioButton* const ptrButton):button(ptrButton)
{
}

bool MethodBuild::isMethodBuild()
{
    return button->isChecked() ?true:false;
}

MethodBuildRandomTree::MethodBuildRandomTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{
}

GraphicsBuilder* MethodBuildRandomTree::methodBuild()
{
    GraphicsBuilder* builder = nullptr;
    if(button->isChecked())
        builder = new GraphicsBuilderBinaryTree("Random Binary Tree");

    return builder;
}

Array* MethodBuildRandomTree::typeArray(const QString data)
{
    Array* typeArray = nullptr;

    if(button->isChecked())
        typeArray = new ArrayForRandomTree(data);

    return typeArray;
}

MethodBuildPerfectBalancedTree::MethodBuildPerfectBalancedTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{}

GraphicsBuilder* MethodBuildPerfectBalancedTree::methodBuild()
{
    GraphicsBuilder* builder = nullptr;
    if(button->isChecked())
        builder = new GraphicsBuilderBinaryTree(QString("Perfect Balanced Tree"));

    return builder;
}


Array* MethodBuildPerfectBalancedTree::typeArray(const QString data)
{
    Array* typeArray = nullptr;
    if(button->isChecked())
        typeArray = new ArrayForPBTTree(data);

    return typeArray;
}

MethodBuildAvlTree::MethodBuildAvlTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{}

GraphicsBuilder* MethodBuildAvlTree::methodBuild()
{
    GraphicsBuilder* builder = nullptr;
    if(button->isChecked())
        builder = new GraphicsBuilderAvlTree(QString("Avl Tree"));

    return builder;
}

Array* MethodBuildAvlTree::typeArray(const QString data)
{
    Array* typeArray = nullptr;
    if(button->isChecked())
        typeArray = new LinearArray(data);

    return typeArray;
}

MethodBuildBTree::MethodBuildBTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{

}

GraphicsBuilder* MethodBuildBTree::methodBuild()
{
    const quint32 coefficient{2};
    GraphicsBuilder* builder = nullptr;
    if(button->isChecked())
        builder = new GraphicsBuilderBTree(QString("B-Tree"),coefficient);

    return builder;
}

Array* MethodBuildBTree::typeArray(const QString data)
{
    Array* typeArray = nullptr;
    if(button->isChecked())
        typeArray = new LinearArray(data);

    return typeArray;
}

LinkerMethodsBuilds::LinkerMethodsBuilds(GameWindow* const gameWindow):gameWin(gameWindow)
{
}

void LinkerMethodsBuilds::updateDataForBuilding(const QString nameBuilder)
{
    data = nameBuilder;
}

void LinkerMethodsBuilds::append(std::unique_ptr<MethodBuild> newMethod)
{
    methods.push_back(std::move(newMethod));
}

void LinkerMethodsBuilds::choiceMethodBuilding()
{
    for(auto& method: methods)
    {
       if(method->isMethodBuild())
       {
           gameWin->updateStatyManager(method->methodBuild());
           gameWin->updateStatyManager(method->typeArray(data));
           break;
       }
    }
}
