#pragma once

#define DEFAULT_SPEED 20000
#define DEFAULT_ACCELERATION 40000

#define EMERGENCY_ACCEL 80000

#define DEFAULT_SPEED_PROFILE               \
    {                                       \
        DEFAULT_ACCELERATION, DEFAULT_SPEED \
    }

//TODO define SlowMode


struct SpeedProfile{
    int acceleration;
    int maxSpeed;
};

//TODO Implement feedrate
namespace Speed{
    extern       SpeedProfile currentProfile;
    extern const SpeedProfile defaultProfile;
    extern const SpeedProfile emergencyProfile;

    void resetProfile();
    void setProfile(SpeedProfile sp);
};
