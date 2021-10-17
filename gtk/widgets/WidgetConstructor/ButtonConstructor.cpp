#include "ButtonConstructor.h"

AppWidget* ButtonConstructor::FactoryMethod(Event *properEvent, Actions action) {
    return new AppButton(properEvent, action);
}