#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.cpp"
using namespace std;

void getStringFromInput(char* &);
void moveroom(room* &,vector<item*>);
void describe(room*,vector<item*>);
void takeitem(room*, vector<item*>&);
void listInventory(vector<item*>);

int main()
{
    room* currentroom;
    vector<item*> inventory;
    cout<<"==============================="<<endl;
    cout<<"Welcome to:"<<endl;
    cout<<"           ________     ____ "<<endl;
    cout<<"           \\____  /    / __ \\"<<endl;
    cout<<"               / /    /_/  \\ |"<<endl;
    cout<<"              / /       ___/ / "<<endl;
    cout<<"             / /       |___ |"<<endl;
    cout<<"            / /       __   \\ \\"<<endl;
    cout<<"           / /___     \\ \\__/ |"<<endl;
    cout<<"Elliott's /______\\ uul \\____/ : "<<endl;
    cout<<"FLEE THE MARKET!"<<endl;
    
    cout<<"Your name is Market Fleer. You are curerntly in the megastation"<<endl;
    cout<<"G1A-И7-FL34-M4ЯK-E7"<<endl;
    cout<<"You and your...  'group of friends' have been trying to secure transport off-station for the last few months."<<endl; 
    cout<<"thankfully, your 'group' has finally accquired a spaceship from a family doing a reunion who won't be using it anymore."<<endl;
    cout<<"Unfortunately, station security has a few issues with some of the finer points, and after a hearty chase, you're stuck in a single market hallway. "<<endl;
    cout<<"At one end, the a shut door leads to constantly-patroling security officers. you've sabotaged the door to jam, which bought you a few hours. they may not be able to get in, but you can't go out that way."<<endl;
    cout<<"At the other, sweet freedom. unfortunately behind a jammed former exterior airlock door. if you can get a suit on and through the door, you can radio your 'friends' to pick you up, then finally get out of this place."<<endl;
    cout<<"You grimmace. you only carried in your porta-radio, and most stall owners are too wary for you to steal anything. you're low on opitions, but you've managed to wriggle your way out of worse before."<<endl;
    cout<<"And without further ado, We begin."<<endl;
    
    //room setup
    char* roomlong = new char[201];
    char* roomshort = new char[21];
    //strncpy(roomlong,, 200);
    //strncpy(roomshort,, 20);
    
    strncpy(roomlong,"Before you stands a lithoid manning a desk hawking electronics. It asks:\nD I D Y O U G E T M Y L E A D ?\nYou remember that your 'group' agreed to exchange it some lead dust for a curious gyroscope. \0", 200);
    strncpy(roomshort,"Electronics Stand", 20);
    room* a1 = new room(roomlong,roomshort);
    strncpy(roomlong,"You're at what was formerly the exterior door of the airlock.\nfunny to think the only thing that stands between you and freedom is a single integrated circuit.\0", 200);
    strncpy(roomshort,"Airlock Door\0", 20);
    room* b1 = new room(roomlong,roomshort);
    
    delete[] roomlong;
    delete[] roomshort;
    
    //exits
    char* exitDirection = new char[21];
    //strncpy(exitDirection,, 20);
    
    strncpy(exitDirection,"STERN", 20);
    a1->setExit(exitDirection,b1);
    strncpy(exitDirection,"BOW", 20);
    b1->setExit(exitDirection,a1);
    
    delete[] exitDirection;
    
    //adding items
    char* itemName = new char[21];
    //strncpy(itemName,, 20);
    
    strncpy(itemName,"Deflated Bagpipes", 20);
    b1->addItem(itemName);
    
    delete[] itemName;
    
    currentroom = b1;
    //main game
    bool notQuit=true;
    char*input = new char[21];
    while(notQuit){
        //command handler.
        cout<<"Please Input Command (GO, LOOK, TAKE, DROP, SURRENDER(meaning Quit.))"<<endl;
        getStringFromInput(input);
        cout<<"Function got: "<<endl;
        for(int i=0; i<21; i++){
            cout<<input[i];
        }
        cout<<endl;
        if(strcmp(input,"GO")==0){
            moveroom(currentroom,inventory);  
        }else if(strcmp(input,"LOOK")==0){
            describe(currentroom,inventory);
        }else if(strcmp(input,"TAKE")==0){
            takeitem(currentroom, inventory);
        }else if(strcmp(input,"DROP")==0){
            
        }else if(strcmp(input,"SURRENDER")==0){
            cout<<"You radio in to your 'group' that you're stuck, and they'll have to go on without you."<<endl;
            cout<<"Slowly, you walk through the door at the end of the hall, right into the line of sight of twenty-eight seprate station security officers."<<endl;
            cout<<"You put your hands behind your back, and get on your knees. you begin to speak \"I surrend-"<<endl;
            cout<<"You are immediately tackled by at least five security personel, and are executed via decopmression within the hour."<<endl;
            cout<<"What did you expect? you and your gang killed an entire family reunion's worth of people to steal their ship, and in broad lamplight no less!"<<endl;
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

void moveroom(room* & currentroom, vector<item*> inventory){
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
    room* moveto=currentroom->getExit(input);
    if(moveto==nullptr){
        cout<<"There is no exit that way."<<endl;
    }else{
        currentroom = moveto;
    }
    describe(currentroom,inventory);
    delete[] input;
}

void describe(room* currentroom,vector<item*> inventory){
    cout<<"You are in: ";
    currentroom->printShortDesc();
    currentroom->printLongDesc();
    
    currentroom->printExits();
    listInventory(inventory);
    currentroom->printItems();
}

void takeitem(room* currentroom, vector<item*>& inventory){
    listInventory(inventory);
    currentroom->printItems();
    char * input = new char[21];
    cout<<"Which Item?"<<endl;
    getStringFromInput(input);
    cout<<"Function got: "<<endl;
    for(int i=0; i<21; i++){
        cout<<input[i];
    }
    cout<<endl;
    item* gottenitem=currentroom->getItem(input);
    if(gottenitem==nullptr){
        cout<<"There is no item by that name."<<endl;
    }else{
        inventory.push_back(gottenitem);
    }
    delete[] input;
}

void listInventory(vector<item*> inventory){
    if(!(inventory.empty())){
        cout<<"ITEMS IN INVENTORY:"<<endl;
        //not technically an item but it fits the fluff.
        cout<<"Porta-Radio (You are unwilling to part with)"<<endl;
        vector<item*>::iterator it = inventory.begin();
        // List every item in the vector
        while (it != inventory.end()) {
            cout << (*it)->name << endl;
            ++it;
        }
    }else{
        //Not technically an item, just a bit of fluff.
        cout<<"The only thing in your pockets is your porta-radio, which you're unwilling to part with."<<endl;
    }
}
