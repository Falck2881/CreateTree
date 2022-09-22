#include "MethodBuild.h"
#include "BuilderRandomTree.h"
#include "BuilderAvlTree.h"
#include "BuilderPerfectBalanced.h"
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

Builder* MethodBuildRandomTree::methodBuild()
{
    Builder* builder = nullptr;
    if(button->isChecked())
        builder = new BuilderRandomTree;

    return builder;
}

std::unique_ptr<MethodCustomizationUi> MethodBuildRandomTree::builderCustomizationUi(const QString nameBuilder)
{
    std::unique_ptr<MethodCustomizationUi> method;
    if(button->isChecked())
        method = std::make_unique<CustomizationUiUnderSimpleTree>(QString("Random Build Tree"), nameBuilder);

    return method;
}

ArrayNodes* MethodBuildRandomTree::managerDefinesTypeArrayInArchive(const QString nameBuilder)
{
    ArrayNodes* dataType = nullptr;

    if(button->isChecked())
        dataType = new ArrayNodesForRandomTree(nameBuilder);

    return dataType;
}

MethodBuildPerfectBalancedTree::MethodBuildPerfectBalancedTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{}

Builder* MethodBuildPerfectBalancedTree::methodBuild()
{
    Builder* builder = nullptr;
    if(button->isChecked())
        builder = new BuilderPerfectBalanced;

    return builder;
}

std::unique_ptr<MethodCustomizationUi> MethodBuildPerfectBalancedTree::
    builderCustomizationUi(const QString nameBuilder)
{
    std::unique_ptr<MethodCustomizationUi> method;
    if(button->isChecked())
        method = std::make_unique<CustomizationUiUnderSimpleTree>(QString("Perfect Balanced Tree"),nameBuilder);

    return method;
}

ArrayNodes* MethodBuildPerfectBalancedTree::managerDefinesTypeArrayInArchive(const QString nameBuilder)
{
    ArrayNodes* dataType = nullptr;
    if(button->isChecked())
        dataType = new ArrayNodesForPBTTree(nameBuilder);

    return dataType;
}

MethodBuildAvlTree::MethodBuildAvlTree(QRadioButton* const ptrButton):MethodBuild(ptrButton)
{}

Builder* MethodBuildAvlTree::methodBuild()
{
    Builder* builder = nullptr;
    if(button->isChecked())
        builder = new BuilderAvlTree;

    return builder;
}


std::unique_ptr<MethodCustomizationUi> MethodBuildAvlTree::builderCustomizationUi(const QString nameBuilder)
{
    std::unique_ptr<MethodCustomizationUi> method;
    if(button->isChecked())
        method = std::make_unique<CustomizationUiUnderBalancedTree>(QString("Avl Tree"), nameBuilder);

    return method;
}
ArrayNodes* MethodBuildAvlTree::managerDefinesTypeArrayInArchive(const QString nameBuilder)
{
    ArrayNodes* dataType = nullptr;
    if(button->isChecked())
        dataType = new LinearArrayNodes(nameBuilder);

    return dataType;
}

LinkerMethodsBuilds::LinkerMethodsBuilds(GameWindow* const ptrGameWin):gameWin{ptrGameWin}
{

}

void LinkerMethodsBuilds::updateNameBuilder(const QString newNameBuilder)
{
    nameBuilder = std::move(newNameBuilder);
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
           gameWin->managerGameWin->updateBuilder(method->methodBuild());
           gameWin->updateUiAboutStrategy(method->builderCustomizationUi(nameBuilder));
           gameWin->managerGameWin->updateArrayNodes(method->managerDefinesTypeArrayInArchive(nameBuilder));
           break;
       }
    }
}
