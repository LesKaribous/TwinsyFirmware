#pragma once

#include "EventBase.h"
#include <vector>

namespace Event{

    static std::vector<EventBase*> events;

    void fire(EventBase*);

    bool hasEvent();
    bool hasEvent(String desc);

    EventBase* getEvent();
    EventBase* getEvent(String desc);

    void flush();
}