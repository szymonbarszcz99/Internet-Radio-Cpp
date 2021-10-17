#include "ButtonConstructor.h"

AppWidget* ButtonConstructor::FactoryMethod(Event *properEvent) {
    return new AppButton(properEvent);
}