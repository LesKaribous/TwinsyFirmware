#include "EventBase.h"

EventBase::EventBase(String type, String desc){
    _descriptor = desc;
    _type = type;
}

bool EventBase::isCanceled(){
    return _canceled;
}

void EventBase::Cancel(){
    _canceled = true;
}

String EventBase::GetDescriptor(){
    return _descriptor;
}

String EventBase::GetType(){
    return _type;
}