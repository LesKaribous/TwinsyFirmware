#include "EventBase.h"

EventBase::EventBase(String desc){
    _descriptor = desc;
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
