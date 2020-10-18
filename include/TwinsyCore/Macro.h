#pragma once
#if defined __MK64FX512__ && defined __arm__ && defined CORE_TEENSY //3.5
    #define STRATEGY
#elif defined __MK20DX256__  && defined __arm__  && defined CORE_TEENSY //3.2
    #define PILOT
#endif