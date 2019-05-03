#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

struct event_listener {
  // Window events
  virtual void on_close() {}
  virtual void on_gain_focus() {}
  virtual void on_lose_focus() {}
  virtual void on_resize(sf::Event::SizeEvent) {}

  // Keyboard events
  virtual void on_key_press(sf::Event::KeyEvent) {}
  virtual void on_key_release(sf::Event::KeyEvent) {}
};

/// The event source notifies one or more listeners
/// about events.
///
/// FIXME: This is a bad name for a class.
struct event_source {
  event_source(sf::Window &w) : window(&w) {}

  void listen(event_listener &l) { listeners.push_back(&l); }

  // Notify listeners of queued events.
  void poll() {
    sf::Event e;
    while (window->pollEvent(e))
      process(e);
  }

  // Notify listeners of a single event.
  void process(sf::Event const &e) {
    switch (e.type) {
    case Event::Closed:
      return notify([e](event_listener *l) { l->on_close(); });
    case Event::Resized:
      return notify([e](event_listener *l) { l->on_resize(e.size); });

    case Event::KeyPressed:
      return notify([e](event_listener *l) { l->on_key_press(e.key); });
    case Event::KeyReleased:
      return notify([e](event_listener *l) { l->on_key_press(e.key); });
    default:
      break;
    }
  }

  template <typename F> void notify(F fn) {
    for (event_listener *l : listeners)
      fn(l);
  }

  // The window that we can poll for events.
  sf::Window *window;

  // A list of listeners to notify about particular
  // events.
  std::vector<event_listener *> listeners;
};

#endif