#pragma once

#include "EventBase.h"
#include <vector>

namespace Event{

    extern std::vector<EventBase> events;

    void fire(String type, String descriptor);
    void fire(EventBase& event);

    bool hasEvent();
    bool hasEvent(String type);

    EventBase& getEvent();
    EventBase& getEvent(String desc);

    void flush();
}