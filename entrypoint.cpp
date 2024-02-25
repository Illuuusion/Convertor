#include "entrypoint.h"
#include <QDebug>

void doOperation(Operation operation, AppContext* context, AppParams* params){
    switch (operation) {
    case Default:
        defaultInitialization(context, params);
    case UpdateCurrentNumberSystem:
        updateCurrentNumberSystem(context, params);
        break;
    case UpdateNewNumberSystem:
        updateNewNumberSystem(context, params);
        break;
    case UpdateNumber:
        updateNumber(context, params);
        break;
    case Convert:
        if (check(context)){
            convert(context);
            break;
        }
    }
}
