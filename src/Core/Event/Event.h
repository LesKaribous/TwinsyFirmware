#pragma once

#include "EventBase.h"
#include <vector>

namespace Event{

    extern std::vector<EventBase> events;

    void fire(String descriptor);
    void fire(EventBase& event);

    bool hasEvent();
    bool hasEvent(String desc);

    EventBase& getEvent();
    EventBase& getEvent(String desc);

    void flush();
}