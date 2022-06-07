#ifndef TIME_H
#define TIME_H

class Timer {

private:

  Timer(int millis_since_startup);

  // time between last two frames
  // set to one, because when starting there aren't any previous frames
  int           static _deltaTime;

  int           static  last_millis_since_startup;

public:

  void          static UpdateTimer(int millis_since_startup) 
  {
    _deltaTime = millis_since_startup - last_millis_since_startup;
    last_millis_since_startup = millis_since_startup;
  }
  
  int   const   static GetDeltaTime() { return _deltaTime; }
  int   const   static GetFPS()       { return static_cast<int>(1.00/ (_deltaTime / 1000.00)); }

};

#endif
