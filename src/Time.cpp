#ifndef TIMER_H
#define TIMER_H

class Timer {

private:

  Timer(int millis_since_startup);

  // useful for determining deltaTime: that is the time between this frame and the frame before
  int last_recorded_millis_since_startup;

public:

  // make sure to call this function at the START of EACH FRAME
  void          static UpdateTimer(int millis_since_startup);
  int   const   static GetDeltaTime();
  int   const   static GetFPS();

};

#endif
