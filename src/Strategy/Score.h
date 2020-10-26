#pragma once

namespace Score{
    namespace{
        static int score = 0;
    }
    static void addPoints(int amount){score += amount;}
    static int getScore(){return score;}
}