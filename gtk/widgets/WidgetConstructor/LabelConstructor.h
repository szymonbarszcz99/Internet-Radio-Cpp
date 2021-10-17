#ifndef UNTITLED2_LABELCONSTRUCTOR_H
#define UNTITLED2_LABELCONSTRUCTOR_H
#include "WidgetConstructor.h"
#include "../AppLabel/AppLabel.h"

class LabelConstructor : public WidgetConstructor{
public:
    AppWidget* FactoryMethod(Event* properEvent, Actions action = LABEL) override;
};


#endif //UNTITLED2_LABELCONSTRUCTOR_H
