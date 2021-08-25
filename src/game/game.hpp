/*
  University of Bologna
  First cicle degree in Computer Science
  00819 - Programmazione

  Andreea Scrob #989372
  08/07/2021

  game.hpp: declaration of the Game::Game class.
*/

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP
#include "../data/database.hpp"
#include "../engine/screen.hpp"
#include "../world/world.hpp"
#include "combat_manager.hpp"
#include "gameplay_manager.hpp"
namespace Game {
class Game {
private:
  Data::Database db;
  Engine::Screen screen;
  bool running = true;
  int frame = 1;
  static void before_close(int);
  bool loop();
  void handle_keypress();
  GameplayManager gameplay_manager;
  char last_key = '\0';
  CombatManager combat_manager;

public:
  int run();
  Game();
  ~Game();
  ;
};

} // namespace Game

#endif