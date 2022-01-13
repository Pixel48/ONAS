#include "area.hpp"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

Area::Area(int x, int y, int width, int height, bool relative) {
  x_ = x;
  y_ = y;
  relative_ = relative;
  if(relative) {
    width_ = width;
    height_ = height;
  } else {
    width_ = width - x_;
    height_ = height - y_;
  }
  // private
  hasEntered_ = false;
  // hasExited_ = false;
  // hasReleased_ = false;
  // hasPressed_ = false;
  // hasHovered_ = false;
}

Area::~Area() {}

bool Area::isHovered() {
  if(x_ < sf::Mouse::getPosition().x && sf::Mouse::getPosition().x < x_ + width_ &&
     y_ < sf::Mouse::getPosition().y && sf::Mouse::getPosition().y < y_ + height_) return true;
  else return false;
}

bool Area::isEntering() {
  if(isHovered()) {
    if(hasEntered_) return false;
    else {
      hasEntered_ = true;
      return true;
    }
  } else {
    hasEntered_ = false;
    return false;
  }
}

// bool Area::() {}

bool Area::isClicked() {
  if(isHovered() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) return true;
  else return false;
}

// bool Area::isReleased() {}

// bool Area::isPressed() {}



// bool onEnter(int mouseX, int mouseY, int x, int y, int width, int height) {
//   bool hasEntered = false;
//   if(mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height) {
//     if(!hasEntered) {
//       hasEntered = true;
//       return true;
//     } else {
//       return false;
//     }
//   } else {
//     hasEntered = false;
//     return false;
//   }
// }