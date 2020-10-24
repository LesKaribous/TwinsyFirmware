#pragma once

#include <U8g2lib.h>
#include <SPI.h>

class Screen{
private:
    Screen(); //Disabling constructor for pure static class
    //Depends on Screen, Menu & Inputs

public:
    static void init();
    static void prepare();
    static void initMsg();
    static void debug();
    static void splashScreen();
    static U8G2_ST7920_128X64_F_SW_SPI lcd;
};
