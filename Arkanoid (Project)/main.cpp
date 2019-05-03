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
      ++left;
  }
  sf::Window *window;
  std::vector<Event_listener *> listeners;
  Event_source(sf::Window &w) : window(&w) {}
  void listen(Event_listener &left) { listeners.push_back(&left); }
  void process(sf::Event const &e) {
    switch (e.type) {
    case sf::Event::KeyPressed:
      return notify(e);
    case sf::Event::KeyReleased:
      return notify(e);
    default:
      break;
    }
  }
  void poll() {
    sf::Event e;
    while (window->pollEvent(e)) {
      process(e);
    }
  }
};

struct arkanoid_app : Event_listener {
  sf::RenderWindow window;
  arkanoid_app() : window(sf::VideoMode(520, 450), "Arkanoid!") {
    window.setFramerateLimit(60);
  }
  bool is_open() const { return window.isOpen(); }

  void on_close() override { window.close(); }
  void draw(Instance &object, Textures texts) { window.clear(); }
};

int main() {
  srand(time(0));
  Textures images;
  Instance arkGame(images);
  arkGame.difficultySetting();
  arkGame.startGame(images);
  arkanoid_app app;
  Event_listener listening;
  sf::Window window;
  Event_source events(app.window);
  events.listen(app);
  return 0;
}