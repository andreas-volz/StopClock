#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>

#ifndef _STOPCLOCK_H_
#define _STOPCLOCK_H_

class StopClock
{
protected:
  struct timeval epoch;

public:
  enum TimeUnit
  {
    TIME_UNIT_HOURS,
    TIME_UNIT_MINUTES,
    TIME_UNIT_SECONDS,
    TIME_UNIT_MILISECONDS,
    TIME_UNIT_MIRCOSECONDS
  };

  StopClock ();
  void resetClock ();
  float getElapsedTime (TimeUnit time_unit);
};

#endif	//_STOPCLOCK_H_
