#include "Event.h"
#include "Core.h"
#include <string.h>

std::vector<EventBase*> Event::events;

void Event::fire(EventBase* event){
    events.push_back(event);
}

bool Event::hasEvent(){
    return events.size() > 0;
}

bool Event::hasEvent(String desc){
    for (size_t i = 0; i < events.size(); i++){ //May be optimized using constructor
        if(events[i]->GetDescriptor() == desc){
            return true;
        }
    }
    return false;
}

EventBase* Event::getEvent(){
    return events.front();
}

EventBase* Event::getEvent(String desc){
    for (size_t i = 0; i < events.size(); i++) {
        if(events[i]->GetDescriptor() == desc && !events[i]->isCanceled()) return events[i];
    }
    return 0;
}

void Event::flush(){
    for (size_t i = 0; i < events.size();){ //May be optimized using constructor
        if(events[i]->isCanceled()){
            delete events[i];
            events.erase(events.begin() + i);
        }else i++;
    }
}

