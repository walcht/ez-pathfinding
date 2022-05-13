#ifndef TIME_H
#define TIME_H

class Timer {
private:
  Timer ();

  double _deltaTime;

public:
  void static SetDeltaTime(double deltaTime);
  double static GetDeltaTime();
  int static GetFPS();
};

#endif
