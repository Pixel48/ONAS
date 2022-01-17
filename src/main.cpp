#include <iostream>
#include "isfml.hpp"
#include "area.hpp"

#define VW 1920
#define VH 1080

int main() {
  sf::RenderWindow window(sf::VideoMode(VW, VH), "ONAS Project", sf::Style::Close | sf::Style::Fullscreen);
  
  //menu
  
sf::RectangleShape m(sf::Vector2f(VW, VH));
  sf::Texture mTexture;
  sf::Vector2u mSize = mTexture.getSize();
  mSize.x = mSize.x / 4;
  mTexture.loadFromFile("img.m/menu-bg1.png");
  m.setPosition(0, 0);
  m.setTexture(&mTexture);
  m.setTextureRect(sf::IntRect(0, 0, VW, VH));
  
  /*sf::RectangleShape z(sf::Vector2f(VW, VH));
  sf::Texture zTexture;
  sf::Vector2u zSize = zTexture.getSize();
  zTexture.loadFromFile("img.m/zêbatka (1).png");
  z.setPosition(0, 0);
  z.setTexture(&zTexture);
  z.setTextureRect(sf::IntRect(0, 0, VW, VH));
  
   sf::RectangleShape s(sf::Vector2f(VW, VH));
  sf::Texture sTexture;
  sf::Vector2u sSize = sTexture.getSize();
  sTexture.loadFromFile("img.m/Statystyka.png");
  s.setPosition(0, 0);
  s.setTexture(&sTexture);
  s.setTextureRect(sf::IntRect(0, 0, VW, VH));
  
  sf::RectangleShape d(sf::Vector2f(VW, VH));
  sf::Texture dTexture;
  sf::Vector2u dSize = dTexture.getSize();
  dTexture.loadFromFile("img.m/DŸwiêk.png");
  d.setPosition(0, 0);
  d.setTexture(&dTexture);
  d.setTextureRect(sf::IntRect(0, 0, VW, VH));*/
  //

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

    #ifdef DEV
      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        text.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      }
    #endif


    window.clear();
    window.draw(bg);
    window.draw(m);
    
    //buttons
    Area przycisk1(785, 200, 171, 133);

Area przycisk2(785, 349, 171, 133);

Area przycisk3(785, 540, 171, 133);

Area przyciskstatys(2770, 295, 189, 146);

Area przyciskdzwiek(2770, 450, 187, 187);

Area przyciskplus(6177, 400, 230, 220);

Area przyciskminus(7061, 400, 230, 220);

Area przyciskglosnosc(6606, 778, 230, 200);
    
    switch(screenView) {
    	
    	case -4:
    		window.clear();
    		m.setTextureRect(sf::IntRect(-4*VW,0, VW, VH));
    		if(przyciskplus.isClicked())
    		{
    			//turn the volume up
			}
			else if(przyciskminus.isClicked())
			{
				//turn the vulome down
			}
			else if(przyciskglosnosc.isClicked())
			{
				//turn off or turn on the volume
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
			{
			 screenView=	 -2;
			}
    		break;
    	
    
    	case -2:
    		window.clear();
    		m.setTextureRect(sf::IntRect(-2*VW, 0, VW, VH));
    		if(przyciskstatys.isClicked())
    		{
    			screenView=	 -3;
			}
			else if(przyciskdzwiek.isClicked())
			{
				screenView=	 -4;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
			{
				screenView=	-1;
			}
    		break;
    	case -3:
    		window.clear();
    		m.setTextureRect(sf::IntRect(-3*VW, 0, VW, VH));
    		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
    		{
    			screenView=	 -2;
			}
    		break;
    	case -1:
    		window.clear();
    	  m.setTextureRect(sf::IntRect(-1*VW, 0, VW, VH));	
    	  if(przycisk1.isClicked())
    	  {
    	  	przycisk1.disable();
    	  	przycisk2.disable();
    	  	przycisk3.disable();
    	  	przyciskstatys.disable();
    	  	przyciskdzwiek.disable();
    	  	przyciskplus.disable();
    	  	przyciskminus.disable();
    	  	przyciskglosnosc.disable();
    	  	
    	  	screenView= 0;
    	  	break;
		  }
		  else if(przycisk2.isClicked())
		  {
		  	screenView= -2;
		  }
		  else if(przycisk3.isClicked())
		  {
		  	window.close();
		  	exit(0);
		  }
		  
    	  break;
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
