#pragma once
#include <cstdint>


class InotifyHandler{
public:
  ~InotifyHandler();
  
  //initalizes inotify
  void init(const char* src, uint32_t mask);

  //returns true/false depending on whether the event is triggered
  bool isTriggered();
private:
  int fd, wd;
};
