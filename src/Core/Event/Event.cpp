#include "Event.h"
#include "Core.h"
#include "Debugger.h"

#include <string.h>

std::vector<EventBase> Event::events;

void Event::fire(EventBase& event){
    Debugger::assert(event.GetDescriptor());
    events.push_back(event);
}

void Event::fire(String desc){
    Debugger::assert(desc);
    events.push_back(EventBase(desc));
}

bool Event::hasEvent(){
    return events.size() > 0;
}

bool Event::hasEvent(String desc){
    for (size_t i = 0; i < events.size(); i++){ //May be optimized using constructor
        if(events[i].GetDescriptor() == desc){
            return true;
        }
    }
    return false;
}

EventBase& Event::getEvent(){
    return events.front();
}

EventBase& Event::getEvent(String desc){
    for (size_t i = 0; i < events.size(); i++) {
        if(events[i].GetDescriptor() == desc && !events[i].isCanceled()) return events[i];
    }
}

void Event::flush(){
    events.clear();
    /*
    for (size_t i = 0; i < events.size();){ //May be optimized using constructor
        if(events[i].isCanceled()){
            events.erase(events.begin() + i);
        }else i++;
    }
    */
}

