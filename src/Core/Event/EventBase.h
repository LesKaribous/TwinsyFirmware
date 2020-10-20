#pragma once
#include "Core.h"

class EventBase{
public:

    EventBase(String desc);
    String GetDescriptor();

    void Cancel();
    bool isCanceled();

private:
    String _descriptor;
    bool _canceled;
};