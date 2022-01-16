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

  // screenView = 0 -> N
    // bottle
    sf::Texture bottleTexture;
    bottleTexture.loadFromFile("img/bottle.png");
    sf::Vector2u bottleSize = bottleTexture.getSize();
    bottleSize.x /= 5;
    sf::RectangleShape bottle(sf::Vector2f(bottleSize.x, bottleSize.y));
    bottle.setTextureRect(sf::IntRect(0, 0, bottleSize.x, bottleSize.y));
    bottle.setSize(sf::Vector2f(bottleSize.x, bottleSize.y));
    bottle.setTexture(&bottleTexture);
    bottle.setPosition(1616, 470);
    // lightbulb
    sf::Texture lightbulbTexture;
    lightbulbTexture.loadFromFile("img/lightbulb.png");
    sf::Vector2u lightbulbSize = lightbulbTexture.getSize();
    sf::RectangleShape lightbulb(sf::Vector2f(lightbulbSize.x, lightbulbSize.y));
    lightbulb.setTexture(&lightbulbTexture);
    lightbulb.setPosition(878, 343);
    // battery
    sf::Texture batteryTexture;
    batteryTexture.loadFromFile("img/battery.png");
    sf::Vector2u batterySize = batteryTexture.getSize();
    sf::RectangleShape battery(sf::Vector2f(batterySize.x, batterySize.y));
    battery.setTexture(&batteryTexture);
    battery.setPosition(844, 541);
    // paper
    sf::Texture paperTexture;
    paperTexture.loadFromFile("img/paper.png");
    sf::Vector2u paperSize = paperTexture.getSize();
    paperSize.x /= 10;
    sf::RectangleShape paper(sf::Vector2f(paperSize.x, paperSize.y));
    paper.setTextureRect(sf::IntRect( 5*paperSize.x, 0, paperSize.x, paperSize.y));
    paper.setSize(sf::Vector2f(paperSize.x, paperSize.y));
    paper.setTexture(&paperTexture);
    paper.setPosition(61, 151);
    // text
    sf::Texture textTexture;
    textTexture.loadFromFile("img/text.png");
    sf::Vector2u textSize = textTexture.getSize();
    textSize.x /= 6;
    sf::RectangleShape text(sf::Vector2f(textSize.x, textSize.y));
    text.setTextureRect(sf::IntRect(5*textSize.x, 0, textSize.x, textSize.y));
    text.setSize(sf::Vector2f(textSize.x, textSize.y));
    text.setTexture(&textTexture);
    text.setPosition(933, 549);


  // screenView = 1 -> E

  // screenView = 2 -> S

  // screenView = 3 -> W


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
        printf("%d, %d\n", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
      || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) window.close();

      // if(moveLeft.isEntering()) {
      //   printf("Left\n");
      //   screenView += 3;
      //   screenView %= 4;
      // }
      if(moveRight.isEntering()) {
        printf("Right\n");
        screenView++;
        screenView %= 4;
      }
    }

    #ifdef DEV
      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        text.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      }
    #endif


    window.clear();
    window.draw(bg);
    switch(screenView) {
      case 0:
        bg.setTextureRect(sf::IntRect(0*VW, 0, VW, VH));
        window.draw(bottle);
        window.draw(lightbulb);
        // window.draw(battery);
        window.draw(paper);
        window.draw(text);
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
    window.display();
  }

  return 0;
}