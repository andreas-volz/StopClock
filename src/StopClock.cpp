#include "../include/StopClock/StopClock.h"

using namespace std;

StopClock::StopClock ()
{
  resetClock ();
}

void StopClock::resetClock ()
{
#ifndef WIN32
  struct timeval now;

  // should generate a exception here if this fails
  gettimeofday(&now, (struct timezone *)0);

  epoch = now;
#endif
}

float StopClock::getElapsedTime (TimeUnit time_unit)
{
  float elapsed_time = 0;
#ifndef WIN32 // not yet ported
  struct timeval now;
  suseconds_t elapsed_time_usec;
  suseconds_t now_usec;
  suseconds_t epoch_usec;

  if (gettimeofday(&now, (struct timezone *)0))
    return 0;

  now_usec = now.tv_usec + now.tv_sec * 1000000;
  epoch_usec = epoch.tv_usec + epoch.tv_sec * 1000000;

  elapsed_time_usec = now_usec - epoch_usec;

  switch (time_unit)
  {
  case TIME_UNIT_HOURS:
    elapsed_time = static_cast <float> (elapsed_time_usec) / 1000000 / 60 / 60;
    break;
  case TIME_UNIT_MINUTES:
    elapsed_time = static_cast <float> (elapsed_time_usec) / 1000000 / 60;
    break;
  case TIME_UNIT_SECONDS:
    elapsed_time = static_cast <float> (elapsed_time_usec) / 1000000;
    break;
  case TIME_UNIT_MILISECONDS:
    elapsed_time = static_cast <float> (elapsed_time_usec) / 1000;
    break;
  case TIME_UNIT_MIRCOSECONDS:
    // do nothing
    break;
  }
#endif
  return elapsed_time;
}
