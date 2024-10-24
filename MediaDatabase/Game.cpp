#include <iostream>
#include <cstring>
#include "Game.h"

using namespace std;
Game::Game(){
  type='G';
  title = new char[16];
  publisher = new char[16];
  rating = new char[6];
}
Game::Game(char* newtitle, int newyear, char* newpublisher, char* newrating){
  type='G';
  title = new char[16];
  strcpy(title,newtitle);
  year=newyear;
  publisher = new char[16];
  strcpy(publisher,newpublisher);
  rating = new char[6];
  strcpy(rating,newrating);
}
char* Game::getPublisher(){
  return publisher;
}
void Game::setPublisher(char* newpublisher){
  strcpy(publisher,newpublisher);
  return;
}
char* Game::getRating(){
  return rating;
}
void Game::setRating(char* newrating){
  strcpy(rating,newrating);
  return;
}
