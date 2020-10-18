#include "Core.h"
#ifdef STRATEGY
#include "Strategy/IHM/Menu/Checklist.h"
#include "Strategy/IHM/Screen.h"
#include "Strategy/IHM/Inputs.h"

Checklist::Type Checklist::current;
bool Checklist::needDraw;
long Checklist::completeTime = 0;

void Checklist::init()
{
    current = (Checklist::Type)0;
    needDraw = true;
}

void Checklist::update()
{
    if (current < CHECKED)
    {
        if (Inputs::buttonChecklist.pressed())
        {
            current = Type((int)current + 1);
            needDraw = true;
            if (Checklist::current == CHECKED)
                completeTime = millis();
        }
    }
    draw();
}

const char *Checklist::toTitle(Type t)
{
    switch (t)
    {
    case SECONDARY_ROBOT:
        return "Twin";
        break;
    case EXPERIMENT:
        return "Phare";
        break;
    case CHECK_ELEMENT:
        return "Gobelet";
        break;
    case CLEAN_TABLE:
        return "Clean";
        break;
    case PLACE_BEACON:
        return "Balise";
        break;
    case CHECKED:
        return "Go !";
        break;
    }
}

const char *Checklist::toText(Type t)
{
    switch (t)
    {
    case SECONDARY_ROBOT:
        return "Robot secondaire";
        break;
    case EXPERIMENT:
        return "Installer le phare";
        break;
    case CHECK_ELEMENT:
        return "Verifier les gobelets";
        break;
    case CLEAN_TABLE:
        return "Nettoyer la table";
        break;
    case PLACE_BEACON:
        return "Placer les balises";
        break;
    case CHECKED:
        return "Pret !";
        break;
    }
}

void Checklist::draw()
{
    if (needDraw)
    {
        int x = 128; //On commence le texte à droite

        Screen::lcd.clearBuffer();

        Screen::lcd.drawBox(22, 0, 2, 33); //Ligne de séparation numéro
        for (int j = 0; j <= 128; j = j + 4)
            Screen::lcd.drawBox(j, 40, 2, 1); //Ligne de séparation texte - tirets

        Screen::lcd.setFont(u8g2_font_logisoso32_tn); //Changer la font pour le numero
        Screen::lcd.setCursor(0, 0);
        Screen::lcd.print(current); //Afficher le numero de l'action

        Screen::lcd.setFont(u8g2_font_courB08_tf); //Changer la font pour la description
        Screen::lcd.drawStr(28, 0, "Action :");    //Afficher le titre de l'action

        Screen::lcd.setFont(u8g2_font_logisoso22_tf);  //Changer la font pour la description
        Screen::lcd.drawStr(25, 10, toTitle(current)); //Afficher le titre de l'action

        Screen::lcd.setFont(u8g2_font_courB08_tf);   //Changer la font pour la description
        Screen::lcd.drawStr(0, 48, toText(current)); //Afficher l'action

        Screen::lcd.sendBuffer();
        delay(100);
        x -= 10; //Scrolling
        needDraw = false;
    }
}

bool Checklist::isComplete()
{
    return current >= CHECKED && millis() - completeTime > 1000;
};

#endif