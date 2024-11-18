#include <iostream>
#include <cstring>
#include <vector>
#include "room.cpp"
using namespace std;

void getStringFromInpt(char* &);
void moveroom(room* &);
void listexits(room*)

int main()
{
    room* currentroom;
    cout<<"==============================="<<endl;
    cout<<"Welcome to:"<<endl;
    cout<<"           ________ "<<endl;
    cout<<"           \\____  / "<<endl;
    cout<<"               / /  "<<endl;
    cout<<"              / /   "<<endl;
    cout<<"             / /    "<<endl;
    cout<<"            / /     "<<endl;
    cout<<"           / /___   "<<endl;
    cout<<"Elliott's /______\\ uul 3:"<<endl;
    cout<<"FLEE THE MARKET!"<<endl;
    
    cout<<"Your name is Market Fleer. You are curerntly in the megastation"<<endl;
    cout<<"G1A-И7-FL34-M4ЯK-E7"<<endl;
    cout<<"You and your...  'group of friends' have been trying to secure transport off-station for the last two months."<<endl; 
    cout<<"thankfully, your 'group' has finally accquired a spaceship from a family doing a reunion who won't be using it anymore."<<endl;
    cout<<"Unfortunately, station security has a few issues with some of the finer points, and after a hearty chase, you're stuck in a single market hallway. "<<endl;
    cout<<"At one end, the a shut door leads to constantly-patroling security officers. you've sabotaged the door to jam, which bought you a few hours. they may not be able to get in, but you can't go out that way."<<endl;
    cout<<"At the other, sweet freedom. unfortunately behind a jammed former exterior airlock door. if you can get a suit on and through the door, you can radio your 'friends' to pick you up, then finally get out of this place."<<endl;
    cout<<"You grimmace. you only carried in your porta-radio, and most stall owners are too wary for you to steal anything. you're low on opitions, but you've managed to wriggle your way out of worse before."<<endl;
    cout<<"And without further ado, We begin."<<endl;
    
    //setup
    
    
    //main game
    bool notQuit=true;
    char*input = new char[21];
    while(notQuit){
        //command handler.
        cout<<"Please Input Command (GO, LOOK, SURRENDER)"<<endl;
        getStringFromInput(input);
        cout<<"Function got: "<<endl;
        for(int i=0; i<21; i++){
            cout<<input[i];
        }
        cout<<endl;
        if(strcmp(input,"GO")==0){
          moveroom(currentroom);  
        }else if(strcmp(input,"LOOK")==0){
            
        }else if(strcmp(input,"PRINT")==0){
            
        }else if(strcmp(input,"SEARCH")==0){
            
        }else if(strcmp(input,"SURRENDER")==0){
            cout<<"You radio in to your friends that you're stuck, and they'll have to go on without you."<<endl;
            cout<<"Slowly, you walk through the door at the end of the hall, right into the line of sight of eighteen seprate station security officers."<<end;
            cout<<"You put your hands behind your back, and get on your knees. you begin to speak \"I surrend-"<<endl;
            cout<<"You are immediately tackled by at least three security personel, and are executed by the next day."<<endl;
            cout<<"What did you expect? you killed an entire family to steal their ship, and in broad lamplight no less!"<<endl;
            notQuit=false;
        }else{
            cout<<"Invalid Command."<<endl;
        }
    }
    //cleaning up 
    delete[] input;
    return 0;
}

//string handler. I am going to reuse this so many times.
void getStringFromInput(char* & inpstring){
    char bufferarray [21];
    //make sure it works
    bool acin=false;
    for(int i=0;i<21;i++){
        bufferarray[i]='\0';
    }
    while(acin==false){
        cout<<">>"<<endl;
        cin.getline(bufferarray, sizeof(bufferarray),'\n');
        //Error handling.
        if(cin.fail()){
            cout<<"ERROR! Invalid input. please try again. (20 chars or less)"<<endl;
            cout<<"(it is recomended that you press the enter key at least once before retyping your command.)"<<endl;
            cin.clear();
            cin.ignore(100000,'\n');
        }else{
            acin=true;
        }
    }
    strncpy(inpstring, bufferarray, 20);
    inpstring[20]='\0';
    cout<<endl;
    return;
}

void moveroom(room* & currentroom){
    char*input = new char[21];
    //command handler.
    currentroom->printExits();
    cout<<"Which Direction?"<<endl;
    getStringFromInput(input);
    cout<<"Function got: "<<endl;
    for(int i=0; i<21; i++){
        cout<<input[i];
    }
    cout<<endl;
    if(strcmp(input,"GO")==0){
      moveroom(currentroom);  
    }else if(strcmp(input,"DELETE")==0){
        
    }else if(strcmp(input,"PRINT")==0){
        
    }else if(strcmp(input,"SEARCH")==0){
        
    }else if(strcmp(input,"SURRENDER")==0){
        cout<<"You radio in to your friends that you're stuck, and they'll have to go on without you."<<endl;
        cout<<"Slowly, you walk through the door at the end of the hall, right into the line of sight of eighteen seprate station security officers."<<end;
        cout<<"You put your hands behind your back, and get on your knees. you begin to speak \"I surrend-"<<endl;
        cout<<"You are immediately tackled by at least three security personel, and are executed by the next day."<<endl;
        cout<<"What did you expect? you killed an entire family to steal their ship, and in broad lamplight no less!"<<endl;
        notQuit=false;
    }else{
        cout<<"Invalid Command."<<endl;
    }
}
