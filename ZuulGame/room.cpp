#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class room{
  public:
    //constructors and destructors
    room(char* newlongdesc, char* newshortdesc){
        delete[] longDesc;
        longDesc = new char[201];
        strncpy(longDesc,newlongdesc, 200);
        longDesc[200]= '\0';
        delete[] shortDesc;
        shortDesc = new char [21];
        strncpy(shortDesc,newshortdesc, 20);
        shortDesc[20]= '\0';
    }
    
    //don't think I'll ever call this but better safe than sorry.
    ~room(){
        delete[] longDesc;
        delete[] shortDesc;
    }
    
    //getters and setters
    void setLongDesc(char* newlongdesc){
        strncpy(longDesc,newlongdesc, 200);
        longDesc[200]= '\0';
    }
    void printLongDesc(){
        for(int i=0; i<200; i++){
            cout<<longDesc[i];
        }
        cout<<endl;
    }
    void printShortDesc(){
        for(int i=0; i<20; i++){
            cout<<shortDesc[i];
        }
        cout<<endl;
    }
    void setShortDesc(char* newshortdesc){
        strncpy(shortDesc,newshortdesc, 20);
        shortDesc[20]= '\0';
    }
    void setExit(char* newfromdir, room* newexitto){
        exits[newfromdir] = newexitto;
    }
    room* getExit(char* fromdir){
        map<char*, room*, memCompare>::iterator it = exits.begin();
        // Iterate through the map and print the elements
        while (it != exits.end()) {
            if (strcmp((it->first),fromdir)==0){
                return exits[fromdir];
            }
            ++it;
        }
        return nullptr;
    }
    void printExits(){
        map<char*, room*, memCompare>::iterator it = exits.begin();
        // Iterate through the map and print the elements
        while (it != exits.end()) {
            cout << "Direction: " << it->first << ", Room: " << it->second->shortDesc << endl;
            ++it;
        }
    }
    
    //I got the idea for this from chatGPT which means it's explaining time
    //the operator() function allows memCompare to be used as a comparison operator for char*s
    //I need it because without it the map would compare the pointers, not their contents.
    //the <0 is due to maps needing to keep things in a specific order, and using an == would prevent that from occuring.
    //the consts are to make absolutely certain that nothing is changed in the process of comparison.
    struct memCompare{
        bool operator()(const char* lockkey, const char* key) const{
            return strcmp(lockkey,key) < 0;
        }
    };
    
    //variables
    map<char*, room*, memCompare> exits;
    char* longDesc;
    char* shortDesc;
};
