#include "LabelConstructor.h"

AppWidget * LabelConstructor::FactoryMethod(Event* properEvent, Actions action){
    return new AppLabel(properEvent);
}