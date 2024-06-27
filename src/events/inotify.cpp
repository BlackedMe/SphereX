#include "events/inotify.hpp"
#include <cstdio>
#include <sys/inotify.h>
#include <sys/time.h>
#include <unistd.h>
#define NAME_MAX 16
#define BUF_LEN sizeof(struct inotify_event)

void InotifyHandler::init(const char* src, uint32_t mask)
{
  fd = inotify_init(); 
  if(fd < 0) perror("fd");

  int wd = inotify_add_watch(fd, src, mask);
  if(wd < 0) perror("inotify_add_watch");
}

bool InotifyHandler::isTriggered()
{
  //stores time
  timeval time;
  //stores a set of read file descriptors
  fd_set rfds;
  //the return value of select
  int retval;
  
  //set the timeout to 0.1s
  time.tv_sec = 0;
  time.tv_usec = 100;
  
  //clears all file descriptors from rfds
  FD_ZERO(&rfds);
  
  //adds the file descriptor fd to rfds
  FD_SET(fd, &rfds);

  retval = select(fd + 1, &rfds, 0, 0, &time);

  if(retval < 0) perror("select");
  else if (retval > 0){
    char buf[BUF_LEN + NAME_MAX];
    read(fd, buf, BUF_LEN + NAME_MAX);
    return true;
  }
  return false;
}

InotifyHandler::~InotifyHandler()
{
  inotify_rm_watch(fd, wd);
  close(fd);
}
