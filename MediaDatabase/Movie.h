#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie:public Media{
 public:
  Movie();
  Movie(char*,char*,int,int,char*);
  char* getDirector();
  void setDirector(char*);
  int getDuration();
  void setDuration(int);
  char* getRating();
  void setRating(char*);
};
#endif
