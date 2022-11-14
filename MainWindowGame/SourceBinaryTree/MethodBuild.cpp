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

std::unique_ptr<GraphicsBuilder> MethodBuildRandomTree::methodBuild()
{
    std::unique_ptr<GraphicsBuilder> builder;
    if(button->isChecked())
        builder = std::make_unique<GraphicsBuilderBinaryTree>("Random Binary Tree");

    return builder;
}

std::unique_ptr<Array> MethodBuildRandomTree::typeArray(const QString data)
{
    std::unique_ptr<Array> typeArray;

    if(button->isChecked())
        typeArray = std::make_unique<ArrayForRandomTree>(data);

    return typeArray;
}

MethodBuildPerfectBalancedTree::MethodBuildPerfectBalancedTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{}

std::unique_ptr<GraphicsBuilder> MethodBuildPerfectBalancedTree::methodBuild()
{
    std::unique_ptr<GraphicsBuilder> builder;
    if(button->isChecked())
        builder = std::make_unique<GraphicsBuilderBinaryTree>(QString("Perfect Balanced Tree"));

    return builder;
}


std::unique_ptr<Array> MethodBuildPerfectBalancedTree::typeArray(const QString data)
{
    std::unique_ptr<Array> typeArray;
    if(button->isChecked())
        typeArray = std::make_unique<ArrayForPBTTree>(data);

    return typeArray;
}

MethodBuildAvlTree::MethodBuildAvlTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{}

std::unique_ptr<GraphicsBuilder> MethodBuildAvlTree::methodBuild()
{
    std::unique_ptr<GraphicsBuilder> builder;
    if(button->isChecked())
        builder = std::make_unique<GraphicsBuilderAvlTree>(QString("Avl Tree"));

    return builder;
}

std::unique_ptr<Array> MethodBuildAvlTree::typeArray(const QString data)
{
    std::unique_ptr<Array> typeArray;
    if(button->isChecked())
        typeArray = std::make_unique<LinearArray>(data);

    return typeArray;
}

MethodBuildBTree::MethodBuildBTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{

}

std::unique_ptr<GraphicsBuilder> MethodBuildBTree::methodBuild()
{
    const quint32 coefficient{2};
    std::unique_ptr<GraphicsBuilder> builder;
    if(button->isChecked())
        builder = std::make_unique<GraphicsBuilderBTree>(QString("B-Tree"),coefficient);

    return builder;
}

std::unique_ptr<Array> MethodBuildBTree::typeArray(const QString data)
{
    std::unique_ptr<Array> typeArray;
    if(button->isChecked())
        typeArray = std::make_unique<LinearArray>(data);

    return typeArray;
}

LinkerMethodsBuilds::LinkerMethodsBuilds(std::shared_ptr<GameWindow> gameWindow):gameWin(gameWindow)
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
           gameWin->updateStatyTree(method->methodBuild());
           gameWin->updateStatyTree(method->typeArray(data));
           break;
       }
    }
}
