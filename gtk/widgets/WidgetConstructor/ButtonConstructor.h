#ifndef UNTITLED2_BUTTONCONSTRUCTOR_H
#define UNTITLED2_BUTTONCONSTRUCTOR_H
#include "WidgetConstructor.h"
#include "../AppButton/AppButton.h"

class ButtonConstructor : public WidgetConstructor{
public:
    AppWidget* FactoryMethod(Event* properEvent) override;
};


#endif //UNTITLED2_BUTTONCONSTRUCTOR_H
