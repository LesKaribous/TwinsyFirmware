#pragma once
#include "Core.h"

class EventBase{
public:

    String GetDescriptor();
    void Cancel();
    bool isCanceled();

protected:
    EventBase(String desc);

private:
    String _descriptor;
    bool canceled;
};