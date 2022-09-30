#ifndef METHODCUSTOMIZATIONUI_H
#define METHODCUSTOMIZATIONUI_H

#include <QString>

namespace GW {
struct Ui;
};

class MethodCustomizationUi
{
    public:
        virtual ~MethodCustomizationUi() = default;
        virtual void customizationUi(GW::Ui& uiGameWin) = 0;
    protected:
        MethodCustomizationUi(const QString methodBuild, const QString nameBuilder);
        const QString methodBuild;
        const QString nameBuilder;
};

class CustomizationUiUnderBalancedTree: public MethodCustomizationUi
{
    public:
        CustomizationUiUnderBalancedTree(const QString methodBuild, const QString nameBuilder);
    private:
        void customizationUi(GW::Ui& uiGameWin) override final;
};

class CustomizationUiUnderSimpleTree: public MethodCustomizationUi
{
    public:
        CustomizationUiUnderSimpleTree(const QString methodBuild, const QString nameBuilder);
    private:
        void customizationUi(GW::Ui& uiGameWin) override final;
};

#endif // METHODCUSTOMIZATIONUI_H
