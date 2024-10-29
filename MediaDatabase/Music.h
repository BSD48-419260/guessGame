#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music:public Media{
 public:
  Music();
  Music(char*,char*,int,int,char*);
  char* getArtist();
  void setArtist(char*);
  int getDuration();
  void setDuration(int);
  char* getPublisher();
  void setPublisher(char*);
};
#endif
