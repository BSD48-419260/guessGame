#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>
#include "Media.h"


using namespace std;
class Game : public Media{
 public:
  inline Game();
  inline Game(char*, int, char*, char*);
  inline char* getPublisher();
  inline void setPublisher(char*);
  inline char* getRating();
  inline void setRating(char*);
};
#endif
