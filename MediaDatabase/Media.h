#ifndef MEDIA_H
#define MEDIA_H

#include<iostream>
#include<cstring>

using namespace std;

class Media{
 public:
  //constructors and destructors
  inline Media();
  inline Media(char*,int);
  inline ~Media();
  inline void setto(Media);
  //getters and setters
  inline char* getTitle();
  inline void setTitle(char*);
  inline int getYear();
  inline void setYear(int);
  inline char getType();
 protected:
  char* title;
  int year;
  char* artist;
  char* director;
  int duration;
  char* publisher;
  char* rating;
  char type;
};

#endif
