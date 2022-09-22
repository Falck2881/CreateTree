#include "MethodCustomizationUi.h"
#include "GameWindow.h"

MethodCustomizationUi::MethodCustomizationUi(const QString methodBuild,const QString nameBuilder):
    methodBuild{methodBuild},nameBuilder{nameBuilder}
{
}

CustomizationUiUnderBalancedTree::CustomizationUiUnderBalancedTree(const QString nameMethod, const QString nameBuilder):
    MethodCustomizationUi(nameMethod,nameBuilder)
{

}

void CustomizationUiUnderBalancedTree::customizationUi(GW::Ui& uiGameWin)
{
    uiGameWin.builder.setText(nameBuilder);
    uiGameWin.strategy.setText(methodBuild);
    uiGameWin.balancedButton->show();
}

CustomizationUiUnderSimpleTree::CustomizationUiUnderSimpleTree(const QString nameMethod, const QString nameBuilder):
    MethodCustomizationUi(nameMethod, nameBuilder)
{

}

void CustomizationUiUnderSimpleTree::customizationUi(GW::Ui& uiGameWin)
{
    uiGameWin.builder.setText(nameBuilder);
    uiGameWin.strategy.setText(methodBuild);
    uiGameWin.balancedButton->hide();
}
