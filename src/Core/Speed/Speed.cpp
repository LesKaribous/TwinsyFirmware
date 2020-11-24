#include "Speed.h"

SpeedProfile Speed::currentProfile = DEFAULT_SPEED_PROFILE;
const SpeedProfile Speed::defaultProfile = DEFAULT_SPEED_PROFILE;
const SpeedProfile Speed::emergencyProfile = {EMERGENCY_ACCEL, DEFAULT_SPEED};

inline void Speed::resetProfile(){
    currentProfile = DEFAULT_SPEED_PROFILE ;
}

inline void Speed::setProfile(SpeedProfile sp){
     currentProfile = sp;
}