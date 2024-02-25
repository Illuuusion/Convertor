#include "logic.h"

bool check(AppContext* context){
    QString strCheckBinary = "01";
    QString strCheckOctal = "01234567";
    QString strCheckDecimal = "0123456789-";
    QString str = QString::number(context->number);
    int count = 0;
    switch(context->currentNumberSystem){
    case BINARY:
        for (int i = 0; i < str.size(); i++){
            if (strCheckBinary.contains(str[i])) count++;
        }
        if (count == str.size()){
            return true;
            break;
        }
        else{
            context->result = "ERROR";
            return false;
            break;
        }
    case OCTAL:
        for (int i = 0; i < str.size(); i++){
            if (strCheckOctal.contains(str[i])) count++;
        }
        if (count == str.size()){
            return true;
            break;
        }
        else{
            context->result = "ERROR";
            return false;
            break;
        }
    case DECIMAL:
        for (int i = 0; i < str.size(); i++){
            if (strCheckDecimal.contains(str[i])) count++;
        }
        if (count == str.size()){
            return true;
            break;
        }
        else{
            context->result = "ERROR";
            return false;
            break;
        }
    }
}

unsigned convertToDecimalStr(QString str){
    unsigned decimal = 0;
    int j = 0;
    QString str1;
    for (int i = 31; i > -1; i--){
        str1 = (QString)str[i];
        decimal += str1.toInt() * pow(BINARY, j);
        j++;
    }
    return decimal;
}

unsigned convertToDecimal(unsigned number, AppContext* context){
    unsigned decimal = 0;
    int i = 0;
    while (number != 0){
        decimal += (number % DECIMAL) * pow(context->currentNumberSystem, i);
        number /= DECIMAL;
        i++;
    }
    return decimal;
}
QString convertFromDecimal(unsigned decimal, int numberSystem){
    QString str;
    while(decimal != 0){
        str = QString::number(decimal % numberSystem).append(str);
        decimal /= numberSystem;
    }
    return str;
}

void convert(AppContext* context){
    unsigned decimal = 0;
    QString str;
    unsigned number = context->number;
    if (context->number >= 0){
        decimal = convertToDecimal(number, context);
        if (context->newNumberSystem == DECIMAL){
            context->result = QString::number(decimal);
        }
        else{
            str = convertFromDecimal(decimal, context->newNumberSystem);
            context->result = str;
        }
    }
    else{
        if(context->currentNumberSystem != BINARY){
            number = abs(context->number);
            decimal = ~convertToDecimal(number, context);
            decimal++;
            str = convertFromDecimal(decimal, BINARY);
            if (context->newNumberSystem == BINARY) context->result = str;
            if(context->currentNumberSystem == context->newNumberSystem) context->result = QString::number(context->number);
            else{
                decimal = convertToDecimalStr(str);
                context->result = convertFromDecimal(decimal, context->newNumberSystem);
            }
        }
        else{
            str = QString::number(context->number);
            number = ~convertToDecimalStr(str);
            number--;
            context->result = convertFromDecimal(number, context->newNumberSystem);
        }
    }
}

void updateNumber(AppContext* context, AppParams* params){
    context->number = params->numberValue;
}

void updateCurrentNumberSystem(AppContext* context, AppParams* params){
    context->currentNumberSystem = params->system1Value;
}

void updateNewNumberSystem(AppContext* context, AppParams* params){
    context->newNumberSystem = params->system2Value;
}
void defaultInitialization(AppContext* context, AppParams* params){
    context->number = params->numberValue;
    context->currentNumberSystem = params->system1Value;
    context->newNumberSystem = params->system2Value;
}
