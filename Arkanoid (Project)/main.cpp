#include "Instance.hpp"
#include <vector>

struct Event_listener {
  // Window events
  virtual void on_close() {}
  virtual void on_gain_focus() {}
  virtual void on_lose_focus() {}
  virtual void on_resize(sf::Event::SizeEvent) {}

  // Keyboard events
  virtual void on_key_press(sf::Event::KeyEvent) {}
  virtual void on_key_release(sf::Event::KeyEvent) {}
};

struct Event_source {
  template <typename T> void notify(T funct) {
    for (Event_listener *left : listeners)
      funct(left);
  }
  sf::Window *window;
  std::vector<Event_listener *> listeners;
  Event_source(sf::Window &w) : window(&w) {}
};

int main() {
  srand(time(0));
  Textures images;
  Instance arkGame(images);
  arkGame.difficultySetting();
  arkGame.startGame(images);
  return 0;
}