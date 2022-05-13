#ifndef GAME_BEHAVIOUR_H
#define GAME_BEHAVIOUR_H

/// <summarry> Inherit from this class to excecute behaviours
class GameBehaviour {
private:

protected:
  GameBehaviour();  // constructor where Loop() and Start() routines
                    // will be added to the main engine
public:
  virtual void OnStart() { return; }
  virtual void OnLoop() { return; }
};

#endif
