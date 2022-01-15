#include <iostream>
#include "isfml.hpp"
#include "area.hpp"

#define VW 1920
#define VH 1080

int main() {
  sf::RenderWindow window(sf::VideoMode(VW, VH), "ONAS Project", sf::Style::Close | sf::Style::Fullscreen);

  sf::RectangleShape bg(sf::Vector2f(VW, VH));
  sf::Texture bgTexture;
  sf::Vector2u bgSize = bgTexture.getSize();
  bgSize.x = bgSize.x / 4;
  bgTexture.loadFromFile("img/bg.png");
  bg.setPosition(0, 0);
  bg.setTexture(&bgTexture);
  bg.setTextureRect(sf::IntRect(0, 0, VW, VH));

  int screenView = 0;


  Area moveLeft(-1, 0, 101, 1080);
  Area moveRight(1920-100, 0, 101, 1080);

  //! main event loop
  sf::Event evnt;
  while(window.isOpen()) {
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
      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        printf("%d %d\n", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
      || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) window.close();

      if(moveLeft.isEntering()) {
        printf("Left\n");
        screenView += 3;
        screenView %= 4;
      }
      if(moveRight.isEntering()) {
        printf("Right\n");
        screenView++;
        screenView %= 4;
      }
    }

    switch(screenView) {
      case 0:
        bg.setTextureRect(sf::IntRect(0*VW, 0, VW, VH));
        break;
      case 1:
        bg.setTextureRect(sf::IntRect(1*VW, 0, VW, VH));
        break;
      case 2:
        bg.setTextureRect(sf::IntRect(2*VW, 0, VW, VH));
        break;
      case 3:
        bg.setTextureRect(sf::IntRect(3*VW, 0, VW, VH));
        break;
    }

    window.clear();
    window.draw(bg);
    window.display();
  }

  return 0;
}