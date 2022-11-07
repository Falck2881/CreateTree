#ifndef METHODBUILD_H
#define METHODBUILD_H

#include <QObject>
#include <QRadioButton>
#include <vector>
#include <memory>
#include "GraphicsBuilder.h"
#include "Array.h"

class GameWindow;

class MethodBuild
{
    public:
        virtual ~MethodBuild() = default;
        bool isMethodBuild();
        virtual GraphicsBuilder* methodBuild() = 0;
        virtual Array* typeArray(const QString data) = 0;
    protected:
        MethodBuild(QRadioButton* const ptrButton);
        QRadioButton* const button;
};

class MethodBuildRandomTree: public MethodBuild
{
    public:
        MethodBuildRandomTree(QRadioButton* const ptrButton);
    private:
        GraphicsBuilder* methodBuild() override final;
        Array* typeArray(const QString data) override final;
};

class MethodBuildAvlTree: public MethodBuild
{
    public:
        MethodBuildAvlTree(QRadioButton* const ptrButton);
    private:
        GraphicsBuilder* methodBuild() override final;
        Array* typeArray(const QString data) override final;
};

class MethodBuildPerfectBalancedTree: public MethodBuild
{
    public:
        MethodBuildPerfectBalancedTree(QRadioButton* const ptrButton);
    private:
        GraphicsBuilder* methodBuild() override final;
        Array* typeArray(const QString data) override final;
};

class MethodBuildBTree: public MethodBuild
{
    public:
        MethodBuildBTree(QRadioButton* const ptrButton);
    private:
        GraphicsBuilder* methodBuild() override final;
        Array* typeArray(const QString data) override final;
};

class LinkerMethodsBuilds: public QObject
{
    Q_OBJECT

    public:
        LinkerMethodsBuilds(GameWindow* const gameWindow);
        void append(std::unique_ptr<MethodBuild> newMethod);
        void updateDataForBuilding(const QString nameBuilder);
    public slots:
        void choiceMethodBuilding();
    private:
        GameWindow* const gameWin;
        std::vector<std::shared_ptr<MethodBuild>> methods;
        QString data;
};

#endif // METHODBUILD_H
