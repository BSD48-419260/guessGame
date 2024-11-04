#include <iostream>
#include <cstring>
#include <vector>
#include "Media.cpp"
#include "Game.cpp"
#include "Music.cpp"
#include "Movie.cpp"
using namespace std;

void getStringFromInput(char*, int);
void addMedia(vector<Media*> & MainBase);
void killMedia(vector<Media*> & MainBase);
void listMedia(vector<Media*> MainBase);
void searchMedia(vector<Media*> & MainBase, int index);

int main(){
  vector<Media*> MainBase;
  cout<<"==============================="<<endl;
  cout<<"Welcome to:"<<endl;
  cout<<" ___  ___      __"<<endl;
  cout<<" | \\  / |      |_\\"<<endl;
  cout<<" ||\\\\//||      ||\\\\"<<endl;
  cout<<" || \\/ ||      || \\\\ "<<endl;
  cout<<" ||    ||      || ||"<<endl;
  cout<<" ||    ||      ||//"<<endl;
  cout<<" ||    ||      | /"<<endl;
  cout<<"/__\\  /__\\edia |/atabase"<<endl;
  cout<<"(Please note this program is\nincapable of saving data, so\ndon't actually use it for\nlogging media)"<<endl;
  bool notQuit=true;
  char*input = new char[16];
  while(notQuit){
    cout<<"Please Input Command (ADD, DELETE, PRINT, SEARCH, QUIT)"<<endl;
    getStringFromInput(input, 16);
    cout<<"Function got: "<<endl;
    for(int i=0; i<16; i++){
      cout<<input[i];
    }
    cout<<endl;
    if(strcmp(input,"ADD")==0){
      addMedia(MainBase);
    }else if(strcmp(input,"DELETE")==0){

    }else if(strcmp(input,"PRINT")==0){
      listMedia(MainBase);
    }else if(strcmp(input,"SEARCH")==0){

    }else if(strcmp(input,"QUIT")==0){
      notQuit=false;
    }else{
      cout<<"Invalid Command."<<endl;
    }
  }
  delete[] input;
  return 0;
}

void getStringFromInput(char* inpstring, int size){
  delete inpstring;
  inpstring = new char[size];
  char bufferarray [size];
  bool acin=false;
  for(int i=0;i<size;i++){
    bufferarray[i]='\0';
  }
  while(acin==false){
    cout<<size-1<<" characters or less, please."<<endl;
    cin.getline(bufferarray, sizeof(bufferarray),'\n');
    if(cin.fail()){
      cout<<"I think you did something wrong. Please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else{
      acin=true;
    }
  }
  cout<<"you input: "<<endl;
  for(int i=0; i<size; i++){
    inpstring[i]=bufferarray[i];
    cout<<inpstring[i];
  }
  cout<<endl;
  return;
}

void addMedia(vector<Media*> & MainBase){
  char* inpstring = new char[16];
  cout<<"Please declare which type of media you want to make: (GAME, MUSIC, MOVIE, CANCEL)"<<endl;
  bool acin=false;
  while(acin==false){
    getStringFromInput(inpstring, 16);
    cout<<"Function got: "<<endl;
    for(int i=0; i<16; i++){
      cout<<inpstring[i];
    }
    cout<<endl;
    if(strcmp(inpstring,"GAME")==0){
      acin=true;
      Game* newGame = new Game();
      cout<<"Title? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newGame->setTitle(inpstring);
      cout<<"Year?"<<endl;
      bool sacin=false;
      int nwyear;
      while(sacin==false){
	cin>>nwyear;
	if(cin.fail()){
	  cout<<"I think you did something wrong. Please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  sacin=true;
	}
      }
      cin.ignore(100000,'\n');
      newGame->setYear(nwyear);
      cout<<"Publisher? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newGame->setPublisher(inpstring);
      cout<<"Rating? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newGame->setRating(inpstring);
      MainBase.push_back(newGame);
    }else if(strcmp(inpstring,"MUSIC")==0){
      acin=true;
      Music* newMusic = new Music();
      cout<<"Title? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newMusic->setTitle(inpstring);
      cout<<"Artist? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newMusic->setArtist(inpstring);
      cout<<"Year?"<<endl;
      bool sacin=false;
      int nwyear;
      while(sacin==false){
	cin>>nwyear;
	if(cin.fail()){
	  cout<<"I think you did something wrong. Please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  sacin=true;
	}
      }
      sacin=false;
      cin.ignore(100000,'\n');
      newMusic->setYear(nwyear);
      int nwduration;
      cout<<"Duration?"<<endl;
      while(sacin==false){
	cin>>nwduration;
	if(cin.fail()){
	  cout<<"I think you did something wrong. Please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  sacin=true;
	}
      }
      cin.ignore(100000,'\n');
      newMusic->setDuration(nwduration);
      cout<<"Publisher? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newMusic->setPublisher(inpstring);
      MainBase.push_back(newMusic);
    }else if(strcmp(inpstring,"MOVIE")==0){ //Using
      acin=true;
      Movie* newMovie = new Movie();
      cout<<"Title? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newMovie->setTitle(inpstring);
      cout<<"Director? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newMovie->setDirector(inpstring);
      cout<<"Year?"<<endl;
      bool sacin=false;
      int nwyear;
      while(sacin==false){
	cin>>nwyear;
	if(cin.fail()){
	  cout<<"I think you did something wrong. Please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  sacin=true;
	}
      } sacin=false;
      newMovie->setYear(nwyear);
      int nwduration;
      cout<<"Duration?"<<endl;
      while(sacin==false){
	cin>>nwduration;
	if(cin.fail()){
	  cout<<"I think you did something wrong. Please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  sacin=true;
	}
      }
      newMovie->setDuration(nwduration);
      cin.ignore(100000,'\n');
      cout<<"Rating? (15 chars or less, please)"<<endl;
      getStringFromInput(inpstring,16);
      newMovie->setRating(inpstring);
      MainBase.push_back(newMovie);
    }else if(strcmp(inpstring,"CANCEL")==0){
      return;
    }else{
      cout<<"Invalid Command."<<endl;
    }
  }
}
void killMedia(vector<Media*> & MainBase){

}
void listMedia(vector<Media*> MainBase){
  for(auto i=MainBase.begin(); i!=MainBase.end(); ++i){
    if((*(*i)).getType()=='G'){
      cout<<"Type: GAME, Title:"<<(*i)->getTitle()<<", Year:"<<(*i)->getYear()<<", Publisher:"<<(*i)->getPublisher()<<", Rating:"<<(*i)->getRating()<<endl;
    }else if((*(*i)).getType()=='U'){
      cout<<"Type: MUSIC, Title:"<<(*i)->getTitle()<<", Artist:"<<(*i)->getArtist()<<", Year:"<<(*i)->getYear()<<", Duration:"<<(*i)->getDuration()<<endl;
    }else if((*(*i)).getType()=='O'){
      cout<<"Type: MOVIE, Title:"<<(*i)->getTitle()<<", Director:"<<(*i)->getDirector()<<", Year:"<<(*i)->getYear()<<", Duration:"<<(*i)->getDuration()<<endl;
    }else{
      cout<<"ERROR! UNTYPED MEDIA"<<endl;
    }
  }
  return;
}
void searchMedia(vector<Media*> & MainBase, int index){

}
