#include "Core.h"
#ifdef STRATEGY

#include "Menu.h"

#include "Strategy/IHM/Menu.h"
#include "Strategy/IHM/Screen.h"
#include "Strategy/IHM/Input.h"

#include "Strategy/IHM/Menu/Settings.h"
#include "Strategy/IHM/Menu/Match.h"
#include "Strategy/IHM/Menu/Checklist.h"
#include "Strategy/IHM/Menu/BorderCalibration.h"

using namespace Menu;

int Menu::_focus = 0;

void Menu::init(){
    _focus = Menu::DEBUG;

    Screen::init();

    Settings::init();
    Match::init();
    Checklist::init();
    BorderCalibration::init();
}

void Menu::update(){
    switch (_focus){

        case DEBUG:
            Screen::debug();
        break;

        case SETTINGS:
            if (Inputs::buttonChecklist.pressed()) 
                Menu::focus(Menu::BORDER_CALIBRATION);
            else if (Inputs::starter.getState())
                Menu::focus(Menu::MATCH);
            else
                Settings::update();
        break;

        case CHECKLIST:
            if (Checklist::isComplete()){
                Menu::focus(Menu::SETTINGS);
                Settings::reset();
            }else
                Checklist::update();
        break;

        case BORDER_CALIBRATION:
            if (BorderCalibration::isComplete()){
                Menu::focus(Menu::SETTINGS);
                Settings::reset();
            }else
                BorderCalibration::update();
        break;

        case MATCH:
            Match::update();
        break;
    }
}

void Menu::focus(int menu){
    _focus = menu;
}

#endif