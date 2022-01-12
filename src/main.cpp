#include <iostream>
#include "isfml.hpp"
#include "area.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "ONAS Project", sf::Style::Close | sf::Style::Fullscreen);
  sf::Texture BackgroundTexture;
  sf::Sprite BackgroundSprite;
  if(!BackgroundTexture.loadFromFile("./img/N.png")) {
    printf("Error loading background.png\n");
    return 1;
  }
  BackgroundSprite.setTexture(BackgroundTexture);

  sf::Texture texture;
  texture.loadFromFile("./img/N.png");

  Area moveLeft(-1, 0, 101, 1080);
  Area moveRight(1920-100, 0, 101, 1080);

  // printf("Starting main loop...\n");
  //! main event loop
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
          if(evnt.text.unicode < 128) printf("%c", evnt.text.unicode);
          break;
      }
    }
    if(window.hasFocus()) {
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
      || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) window.close();

      if(moveLeft.isEntering()) printf("Left\n");
      if(moveRight.isEntering()) printf("Right\n");
    }

    window.clear();
    window.draw(BackgroundSprite);
    window.display();
  }

  return 0;
}