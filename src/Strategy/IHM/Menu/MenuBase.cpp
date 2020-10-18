#include "Core.h"
#ifdef STRATEGY
#include "MenuBase.h"

//MenuBase

int MenuBase::lastID = 0;

MenuBase::MenuBase(){
    id = lastID;
    lastID++;
}


#endif