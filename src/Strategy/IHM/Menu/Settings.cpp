#include "Core.h"
#ifdef STRATEGY
#include "Strategy/IHM/Menu/Settings.h"
#include "Strategy/IHM/Input.h"
#include "Strategy/IHM/Screen.h"

Settings::RobotType::Type Settings::RobotType::selected;
Settings::Avoidance::Type Settings::Avoidance::selected;
Settings::TeamColor::Type Settings::TeamColor::selected;
Settings::Strategy::Type Settings::Strategy::selected;

void Settings::init()
{
    RobotType::selected = RobotType::PRIMARY;
    Avoidance::selected = Avoidance::STATIC;
    TeamColor::selected = TeamColor::JAUNE;
    Strategy::selected = Strategy::MATCH;
}

void Settings::update()
{
    //if(Inputs::jumperRobotType.getState())
    if (Inputs::jumperRobotType.getState())
        RobotType::selected = RobotType::PRIMARY;
    else
        RobotType::selected = RobotType::SECONDARY;

    if (Inputs::switchAvoidance.getState())
        Avoidance::selected = Avoidance::STATIC;
    else
        Avoidance::selected = Avoidance::DYNAMIC;

    if (Inputs::switchStrategy.getState())
        Strategy::selected = Strategy::MATCH;
    else
        Strategy::selected = Strategy::HOMOLOGATION;

    if (Inputs::switchTeam.getState())
        TeamColor::selected = TeamColor::JAUNE;
    else
        TeamColor::selected = TeamColor::VIOLET;

    draw();
}

void Settings::draw()
{
    const int ligneDebut = 10;
    const int colonne1 = 14;
    const int colonne2 = 70;

    Screen::lcd.clearBuffer();
    Screen::prepare();

    Screen::lcd.setFont(u8g2_font_4x6_tf);
    // Affichages des titres :
    Screen::lcd.drawStr(colonne1, ligneDebut, "      EQUIPE");
    Screen::lcd.drawStr(colonne1, ligneDebut + 10, "   EVITEMENT");
    Screen::lcd.drawStr(colonne1, ligneDebut + 20, "       ROBOT");
    Screen::lcd.drawStr(colonne1, ligneDebut + 30, "ETAT TIRETTE");
    Screen::lcd.drawStr(colonne1, ligneDebut + 40, "   STRATEGIE");
    // Ligne de séparation
    Screen::lcd.drawBox(colonne2 - 4, ligneDebut, 1, ligneDebut + 37);

    // Etat equipe :
    Screen::lcd.setCursor(colonne2, ligneDebut);
    if (TeamColor::selected == TeamColor::JAUNE)
        Screen::lcd.print("JAUNE");
    else
        Screen::lcd.print("VIOLET");

    // Etat detection:
    Screen::lcd.setCursor(colonne2, ligneDebut + 10);
    if (Avoidance::selected == Avoidance::DISABLED)
        Screen::lcd.print("DISABLED");
    else if (Avoidance::selected == Avoidance::STATIC)
        Screen::lcd.print("STATIC");
    else
        Screen::lcd.print("DYNAMIC");

    // Etat type de robot :
    Screen::lcd.setCursor(colonne2, ligneDebut + 20);
    if (RobotType::selected == RobotType::PRIMARY)
        Screen::lcd.print("PRIMAIRE");
    else
        Screen::lcd.print("SECONDAIRE");

    // Etat tirette :
    Screen::lcd.setCursor(colonne2, ligneDebut + 30);
    if (!Inputs::starter.getState())
        Screen::lcd.print("ATTENTE");
    else
        Screen::lcd.print("OK");

    // Etat strategie :
    Screen::lcd.setCursor(colonne2, ligneDebut + 40);
    if (Strategy::selected == Strategy::HOMOLOGATION)
        Screen::lcd.print("HOMOLOGATION");
    else
        Screen::lcd.print("MATCH");

    Screen::lcd.sendBuffer();
}

std::string Settings::RobotType::enumToText(int i)
{
    switch (i)
    {
    case PRIMARY:
        return "Robot Primaire";
        break;
    case SECONDARY:
        return "Robot Secondaire";
        break;

    default:
        return "errRobotType";
        break;
    }
}

std::string Settings::Avoidance::enumToText(int i)
{
    switch (i)
    {
    case STATIC:
        return "Statique";
        break;
    case DYNAMIC:
        return "Dynamique";
        break;
    case DISABLED:
        return "Off";
        break;

    default:
        return "errAvoidance";
        break;
    }
}

std::string Settings::TeamColor::enumToText(int i)
{
    switch (i)
    {
    case JAUNE:
        return "Jaune";
        break;
    case VIOLET:
        return "Violet";
        break;

    default:
        return "errColor";
        break;
    }
}

std::string Settings::Strategy::enumToText(int i)
{
    switch (i)
    {
    case HOMOLOGATION:
        return "Homologation";
        break;
    case MATCH:
        return "Match";
        break;

    default:
        return "errStrat";
        break;
    }
}

bool Settings::isComplete()
{
    // if (Inputs::buttonChecklist.pressed())
    // {
    //     return true;
    // }
    return false;
}

void Settings::reset(){}

#endif