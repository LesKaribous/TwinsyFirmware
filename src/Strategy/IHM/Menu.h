#pragma once

namespace Menu{
    extern int _focus;

    enum List {
        DEBUG                   = 0,
        SETTINGS                = 1,
        CHECKLIST               = 2,
        BORDER_CALIBRATION      = 3,
        MATCH                   = 4
    };

    void init();
    void update();

    void focus(int menu);
}
