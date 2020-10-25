#include "Core.h"
#ifdef STRATEGY

#include "Strategy/IHM/Menu/BorderCalibration.h"
#include "Strategy/IHM/Input.h"
#include "Strategy/IHM/Screen.h"

BorderCalibration::State BorderCalibration::state;
bool BorderCalibration::needDraw;
long BorderCalibration::completeTime = 0;

long test_timer = 0; //remove when calibration method is implemented

void BorderCalibration::init()
{
    state = (BorderCalibration::State)0;
    needDraw = true;
    
}

void BorderCalibration::update()
{
    if (state == WAITING){
        if (Inputs::buttonChecklist.pressed()){
            state = WORKING;
            needDraw = true;

            test_timer = millis();
        }
    }

    // this condition exists because of test REMOVE after
    if (state == WORKING && millis() - test_timer > 7000){
        BorderCalibration::done();
    }
    draw();
}

void BorderCalibration::draw()
{
    if (needDraw)
    {
        Screen::lcd.clearBuffer();
        Screen::prepare();

        //Affichage du Titre
        Screen::lcd.setFont(u8g2_font_logisoso16_tf); //Changer la font pour la titre
        Screen::lcd.drawStr(12, 5, "CALIBRATION");

        for (int j = 0; j <= 128; j = j + 4)
            Screen::lcd.drawBox(j, 30, 2, 1); //Ligne de séparation texte - tirets

        //Affichage du message
        Screen::lcd.setFont(u8g2_font_6x12_tf);
        Screen::lcd.drawStr(2, 40, toMessage(state));
        Screen::lcd.sendBuffer();
        delay(100);

        needDraw = false;
    }
}



const char *BorderCalibration::toMessage(State s)
{
    switch (s)
    {
    case WAITING:
        return "Appuyer pour demarrer";
        break;
    case WORKING:
        return "Recalage en cours";
        break;
    case DONE:
        return "Recalage termine";
        break;
    }
}

/**
 * @brief This function has to be called when the Calibration is done. It cannot be used in a condition. 
 * It helps to print on the screen the final message of the calibration.
 * 
 */
void BorderCalibration::done()
{
    completeTime = millis();
    needDraw = true;
    state = DONE;
}

bool BorderCalibration::isComplete()
{
    return state >= DONE && millis() - completeTime > 1500;
}

#endif