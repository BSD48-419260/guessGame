#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


struct Student{
  char name[15];
  int ID;
  float GPA;
};

vector<Student*> StudentList;

void addStudent();
void killStudent();
void listStudents();
void modStudent();
Student getStudent(int index);
int getIndex(int ID);
int getID();


int main(){
  cout<<"==========================="<<endl;
  cout<<"Welcome to:"<<endl;
  cout<<"  ____         ___"<<endl;
  cout<<" / ___\\        | |"<<endl;
  cout<<" | | |_\\       | |"<<endl;
  cout<<" | |__         | |"<<endl;
  cout<<" \\___ \\        | |"<<endl;
  cout<<"__  | |        | |"<<endl;
  cout<<"\\ |_| |        | |___"<<endl;
  cout<<" \\____/ tudent |____| ister"<<endl;
  bool notQuit=true;
  cout<<"(Please note this program is incapable of saving data, so don't actually use it for managing students)"<<endl;
  while(notQuit){
    //trying to be robust.
    cout<<"Please input a command. (Valid commands: ADD, DELETE, PRINT, MODIFY, QUIT)"<<endl;
    char inpstring[7];
    cin >> inpstring;
    if(cin.fail()){
      cout<<"I think you did something wrong. please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else if (strcmp(inpstring,"ADD")==0){
      addStudent();
    }else if (strcmp(inpstring,"DELETE")==0){
      killStudent();
    }else if (strcmp(inpstring,"PRINT")==0){
      listStudents();
    }else if (strcmp(inpstring,"MODIFY")==0){
      modStudent();
    }else if (strcmp(inpstring,"QUIT")==0){
      notQuit=false;
    }else{
      cout<<"Invalid Command."<<endl;
    }
  }
  cout<<"Have a wonderful day."<<endl;
  return 0;
}

void addStudent(){
  Student* newkid;
  bool acin=false;
  char inpstring[16];
  for(int i=0; i<16; i++){
    inpstring[i]='\0';
  }
  
  while (acin==false){
    cout<<"Please Enter Name (15 characters or less): "<<endl;
    cin.getline(inpstring,sizeof(inpstring));
    if(cin.fail()){
      cout<<"I think you did something wrong. please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else{
      acin=true;
    }
  }
  cout<<inpstring<<endl;
  for(int i=0; i<15; i++){
    (*newkid).name[i]=inpstring[i];
  }
  (*newkid).ID=getID();
  float newGPA;
  acin=false;
  while (acin==false){
    cout<<"Please Enter GPA: "<<endl;
    cin>>newGPA;
    cout<<"Received GPA"<<endl;
    if(cin.fail()){
      cout<<"I think you did something wrong. please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else{
      cout<<"confirmed GPA"<<endl;
      acin=true;
    }
  }
  acin=false;
  cout<<"out of GPA loop"<<endl;
  (*newkid).GPA=newGPA;
  cout<<"Set Gpa"<<endl;
  StudentList.push_back(newkid);
  cout<<"Pushed Child"<<endl;
  delete newkid;
  cout<<"Deleted holder"<<endl;
  return;
}

void killStudent(){
  int index = getIndex(getID());
  if (index == -1){
    cout<<"INVALID ID"<<endl;
    return;
  }
  //Student* AlmostDeadChild= StudentList.begin()+index;
  //delete *(AlmostDeadChild);
  //StudentList.erase(AlmostDeadChild);
  StudentList.erase(StudentList.begin()+index);
  return;
}

void listStudents(){
  for(auto i=StudentList.begin(); i!=StudentList.end(); ++i){
    cout<<"Name: "<<(*(*i)).name<<", ID: "<<(*(*i)).ID<<", GPA: "<<(round((*(*i)).GPA * 100))/100<<endl;
  }
  return;
}

void modStudent(){
  return;
}

Student getStudent(int index){
  if (index == -1){
    cout<<"ERROR: INVALID STUDENT ID"<<endl;
    Student bob;
    return bob;
  }
  Student kid;
  kid = *(*(StudentList.begin()+index));
  return kid;
}

int getIndex(int ID){
  for(auto i = StudentList.begin(); i!=StudentList.end(); ++i){
    int thisID = (*(*i)).ID;
    if (thisID==ID){
      return (i-StudentList.begin());
    }
  }
  return -1;
}

int getID(){
  bool acin=false;
  int ID;
  while (acin==false){
    cout<<"Please Enter Student ID (Serial Integer): "<<endl;
    cin>>ID;
    if(cin.fail()){
      cout<<"I think you did something wrong. please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else{
      acin=true;
    }
  }
  return ID;
}
