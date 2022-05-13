#ifndef GAME_ENGINE_H
#def GAME_ENGINE_H

#include <vector>

static class GameEngine() {
private:
  static std::vector<int> loop_routines;
public:
  static void StartGame();

  static void AddStartRoutine();
  static void AddLoopRoutine();
};

#endif
