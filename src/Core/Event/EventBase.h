#pragma once
#include "Core.h"

class EventBase{
public:

    EventBase(String type, String desc);
    String GetDescriptor();
    String GetType();

    void Cancel();
    bool isCanceled();

private:
    String _descriptor, _type;
    bool _canceled;
};