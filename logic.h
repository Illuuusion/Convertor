#ifndef LOGIC_H
#define LOGIC_H

#include "appcontext.h"
#include "appparams.h"
#include "cmath"
#include "QString"

#define BINARY 2
#define OCTAL 8
#define DECIMAL 10
#define LENGTH 32

bool check(AppContext* context);
unsigned convertToDecimalStr(QString str);
unsigned convertToDecimal(unsigned number, AppContext* context);
QString convertFromDecimal(unsigned decimal, int numberSystem);
QString convertFromDecimalToBinary(unsigned decimal);
void convert(AppContext* context);
void updateNumber(AppContext* context, AppParams* params);
void updateCurrentNumberSystem(AppContext* context, AppParams* params);
void updateNewNumberSystem(AppContext* context, AppParams* params);
void defaultInitialization(AppContext* context, AppParams* params);
#endif // LOGIC_H
