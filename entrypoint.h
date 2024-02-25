#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "logic.h"

enum Operation {
    Default,
    UpdateCurrentNumberSystem,
    UpdateNewNumberSystem,
    UpdateNumber,
    Convert
};


void doOperation(Operation operation, AppContext* context, AppParams* params);

#endif
