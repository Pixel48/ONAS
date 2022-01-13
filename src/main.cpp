#include <iostream>
#include "isfml.hpp"
#include "area.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "ONAS Project", sf::Style::Close | sf::Style::Fullscreen);
  // window.setFramerateLimit(15);

  sf::Texture N;
  if(!N.loadFromFile("img/N.png")) {
    printf("N.png not found!\n");
    return 1;
  }
  sf::Texture E;
  if(!E.loadFromFile("img/E.png")) {
    printf("E.png not found!\n");
    return 1;
  }
  sf::Texture S;
  if(!S.loadFromFile("img/S.png")) {
    printf("S.png not found!\n");
    return 1;
  }
  sf::Texture W;
  if(!W.loadFromFile("img/W.png")) {
    printf("W.png not found!\n");
    return 1;
  }

  // for(int i = 0; i < 4; i++) {
  //   screen[i] = (char*)malloc(sizeof(char) * 11);
  // }
  // screen[0] = "img/N.png";
  // screen[1] = "img/E.png";
  // screen[2] = "img/S.png";
  // screen[3] = "img/W.png";
  int screenView = 0;

  // sf::Texture BackgroundTexture;
  sf::Sprite bg;
  // if(!BackgroundTexture.loadFromFile(screen[screenView])) {
  //   printf("Error loading background.png\n");
  //   return 1;
  // }
  // bg.setTexture(N);

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
        bg.setTexture(N);
        break;
      case 1:
        bg.setTexture(E);
        break;
      case 2:
        bg.setTexture(S);
        break;
      case 3:
        bg.setTexture(W);
        break;
    }

    window.clear();
    window.draw(bg);
    window.display();
  }

  return 0;
}