#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>

#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(512, 512), "ONAS Project", sf::Style::Close | sf::Style::Resize);

  while(window.isOpen()) {
    sf::Event evnt;
    while(window.pollEvent(evnt)) {
      switch(evnt.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::Resized:
          printf("Resized to %dx%d\n", evnt.size.width, evnt.size.height);
          break;
        case sf::Event::TextEntered:
          printf("%c", evnt.text.unicode);
          break;
      }
      if(evnt.type == evnt.Closed) {
        std::cout << "Closing window" << std::endl;
        window.close();
      }
    }
  }
  return 0;
}
