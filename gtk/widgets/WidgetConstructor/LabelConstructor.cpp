#include "LabelConstructor.h"

AppWidget * LabelConstructor::FactoryMethod(Event* properEvent){
    return new AppLabel(properEvent);
}