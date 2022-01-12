#ifndef _AREAS
#define _AREAS

class Area {
public:
  Area(int x, int y, int width, int height, bool relative = true);
  ~Area();
  bool isHovered();
  bool isEntering();
  // bool isExiting();
  // bool isClicked();
  // bool isReleased();
  // bool isPressed();

private:
  bool hasEntered_;
  bool hasExited_;
  bool hasReleased_;
  bool hasPressed_;
  bool hasHovered_;
  int x_;
  int y_;
  int width_;
  int height_;
  bool relative_;
};

#endif