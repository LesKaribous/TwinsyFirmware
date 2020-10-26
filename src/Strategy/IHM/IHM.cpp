#include "IHM.h"
#include "Input.h"
#include "Menu.h"
#include "Screen.h"

namespace IHM{
    void init(){
        Inputs::init();
        Menu::init();
        Screen::init();
    }

    void update(){
        Inputs::update();
        Menu::update();
    }
}