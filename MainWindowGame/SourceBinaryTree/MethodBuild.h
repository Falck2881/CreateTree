#ifndef METHODBUILD_H
#define METHODBUILD_H

#include <QObject>
#include <QRadioButton>
#include <vector>
#include <memory>
#include "Builder.h"
#include "MethodCustomizationUi.h"
#include "ArrayNodes.h"

class GameWindow;

class MethodBuild
{
    public:
        virtual ~MethodBuild() = default;
        bool isMethodBuild();
        virtual Builder* methodBuild() = 0;
        virtual std::unique_ptr<MethodCustomizationUi> builderCustomizationUi(const QString nameBuilder) = 0;
        virtual ArrayNodes* managerDefinesTypeArrayInArchive(const QString nameBuilder) = 0;
    protected:
        MethodBuild(QRadioButton* const ptrButton);
        QRadioButton* const button;
};

class MethodBuildRandomTree: public MethodBuild
{
    public:
        MethodBuildRandomTree(QRadioButton* const ptrButton);
    private:
        Builder* methodBuild() override final;
        std::unique_ptr<MethodCustomizationUi> builderCustomizationUi(const QString nameBuilder) override final;
        ArrayNodes* managerDefinesTypeArrayInArchive(const QString nameBuilder) override final;
};

class MethodBuildAvlTree: public MethodBuild
{
    public:
        MethodBuildAvlTree(QRadioButton* const ptrButton);
    private:
        Builder* methodBuild() override final;
        std::unique_ptr<MethodCustomizationUi> builderCustomizationUi(const QString nameBuilder) override final;
        ArrayNodes* managerDefinesTypeArrayInArchive(const QString nameBuilder) override final;
};

class MethodBuildPerfectBalancedTree: public MethodBuild
{
    public:
        MethodBuildPerfectBalancedTree(QRadioButton* const ptrButton);
    private:
        Builder* methodBuild() override final;
        std::unique_ptr<MethodCustomizationUi> builderCustomizationUi(const QString nameBuilder) override final;
        ArrayNodes* managerDefinesTypeArrayInArchive(const QString nameBuilder) override final;
};

class LinkerMethodsBuilds: public QObject
{
    Q_OBJECT

    public:
        LinkerMethodsBuilds(GameWindow * const ptrGameWin);
        void append(std::unique_ptr<MethodBuild> newMethod);
        void updateNameBuilder(const QString newNameBuilder);
    public slots:
        void choiceMethodBuilding();
    private:
        GameWindow* const gameWin;
        std::vector<std::shared_ptr<MethodBuild>> methods;
        QString nameBuilder;
};

#endif // METHODBUILD_H
