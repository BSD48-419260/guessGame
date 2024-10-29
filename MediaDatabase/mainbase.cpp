#include <iostream>
#include <cstring>
#include <vector>
#include "Media.cpp"
#include "Game.cpp"
#include "Music.cpp"
#include "Movie.cpp"
using namespace std;

void getStringFromInput(char*, int);

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
    cout<<"Echoes."<<endl;
    getStringFromInput(input, 16);
    cout<<"Function got: "<<endl;
    for(int i=0; i<16; i++){
      cout<<input[i];
    }
    cout<<endl;
    if(strcmp(input,"ADD")==0){

    }else if(strcmp(input,"ADD")==0){

    }else if(strcmp(input,"DELETE")==0){

    }else if(strcmp(input,"PRINT")==0){

    }else if(strcmp(input,"MODIFY")==0){

    }else if(strcmp(input,"SEARCH")==0){

    }else if(strcmp(input,"QUIT")==0){
      notQuit=false;
    }else{
      cout<<"Invalid Command."<<endl;
    }
  }
  return 0;
}

void getStringFromInput(char* inpstring, int size){
  delete inpstring;
  inpstring = new char[16];
  char bufferarray [16];
  bool acin=false;
  for(int i=0;i<size;i++){
    bufferarray[i]='\0';
  }
  while(acin==false){
    cout<<size-1<<" characters or less, please."<<endl;
    cin.getline(bufferarray, sizeof(bufferarray));
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
