#include <iostream>
#include <cstring>
#include <map>


class room{
  public:
    //constructors and destructors
    room(char* newlongdesc, char* newshortdesc){
        strcpy(longDesc,newlongdesc, 200);
        longDesc[200]= '\0'
        strcpy(shortDesc,newshortdesc, 15);
        shortDesc[15]= '\0'
    }
    
    //don't think I'll ever call this but better safe than sorry.
    ~room{
        delete[] longDesc;
        delete[] shortDesc;
    }
    
    //getters and setters
    void setLongDesc(char* newlongdesc){
        strcpy(longDesc,newlongdesc, 200);
        longDesc[200]= '\0'
    }
    void setShortDesc(char* newshortdesc){
        strcpy(shortDesc,newshortdesc, 15);
        shortDesc[15]= '\0'
    }
    void setExit(char* newfromdir, room* newexitto){
        exits[newfromdir] = newexitto;
    }
    room* getExit(char* fromdir){
        return exits[fromdir];
    }
    void printExits(){
        map<char* room*, memCompare>::iterator it = exits.begin();
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
    char* longDesc = new char[201];
    char* shortDesc = new char [16];
};
