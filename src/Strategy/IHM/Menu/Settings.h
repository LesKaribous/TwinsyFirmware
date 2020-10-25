#ifndef IHM_SETTINGS_H
#define IHM_SETTINGS_H

#include <string>

class Settings
{

public:
    //enums

    static void init();
    static void update();
    static void draw();
    static bool isComplete();
    static void reset();

    class RobotType
    {
    public:
        static enum Type {
            PRIMARY,
            SECONDARY,
            SIZE //Use for array readding only
        } selected;

        static std::string enumToText(int i);
    };

    class Avoidance
    {
    public:
        static enum Type {
            STATIC,
            DYNAMIC,
            DISABLED,
            SIZE //Use for array readding only
        } selected;

        static std::string enumToText(int i);
    };

    class TeamColor
    {
    public:
        static enum Type {
            JAUNE,
            VIOLET,
            SIZE //Use for array readding only
        } selected;

        static std::string enumToText(int i);
    };

    class Strategy
    {
    public:
        static enum Type {
            HOMOLOGATION,
            MATCH,
            SIZE //Use for array readding only
        } selected;

        static std::string enumToText(int i);
    };
};

#endif