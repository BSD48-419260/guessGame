#include <iostream>
#include <cstring>

#include "Media.h"

using namespace std;
inline Media::Media(){
  title=new char[16];
}

inline Media::Media(char* newtitle, int newyear){
  title=new char[16];
  strcpy(title,newtitle);
  year=newyear;
}

inline Media::~Media(){
  delete title;
  delete artist;
  delete director;
  delete publisher;
  delete rating;
  cout<<"Media Deleted"<<endl;
}

inline void Media::setto(Media copiedfrom){
  title=copiedfrom.getTitle();
  year=copiedfrom.getYear();
  artist=copiedfrom.artist;
  director=copiedfrom.director;
  duration=copiedfrom.duration;
  publisher=copiedfrom.publisher;
  rating=copiedfrom.rating;  
}

inline char* Media::getTitle(){
  return title;
}

inline void Media::setTitle(char* newtitle){
  strcpy(title,newtitle);
  return;
}

inline int Media::getYear(){
  return year;
}

inline void Media::setYear(int newyear){
  year=newyear;
  return;
}

inline char Media::getType(){
  return type;
}
