#include "EventBase.h"

EventBase::EventBase(String desc){
    _descriptor = desc;
}

bool EventBase::isCanceled(){
    return canceled;
}

void EventBase::Cancel(){
    canceled = true;
}

String EventBase::GetDescriptor(){
    return _descriptor;
}