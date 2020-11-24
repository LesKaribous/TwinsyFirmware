#include "Core.h"
#ifdef STRATEGY

#include "Strategy.h"

String Strategy::homologation =
  "move X100 Y200 R S5000"
  "arm A10"
  "turnGo A90 D100 S1000"
  "arm A0"
  "turnGo A-90 D100 S1000";

String Strategy::match =
  "move X100 Y200 R S5000"
  "arm A10"
  "turnGo A90 D100 S1000"
  "arm A0"
  "turnGo A-90 D100 S1000";

#endif
