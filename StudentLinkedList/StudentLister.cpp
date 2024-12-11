/*
 StudentLister Program
 Inteded to work as a prototype database for students
 students are structs kept in student* vector.
 Made by Elliott VanOrman for Jason Galbraith's C++ C++/Data Structures Class
 10/3/2024
 */
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include "Student.cpp"
#include "Node.cpp"
using namespace std;

/* Old student Struct. Kept for conversion purposes
//student struct. no defaults.
struct Student{
  char Firstname[11];
  char Lastname[11];
  int ID;
  float GPA;
};
*/


//signature list
void getStringFromInput(char* inpstring);
void addStudent(Node* head);
void linearAdd(Node* head, Node* current, Node* addme);
void killStudent(Node* head);
void listStudents(Node* head);
void modStudent(Node* head);
void averageGPAS(Node* head);
Student* getStudentByID(int ID,Node* head);
int getID();


int main(){
  Node * head = new Node();
  //opening scrawl
  cout<<"==========================="<<endl;
  cout<<"Welcome to:"<<endl;
  cout<<"  _____         _____           _____         _____        ________ "<<endl;
  cout<<" / ___ \\        \\   /           \\   /         \\   /        \\  ____/ "<<endl;
  cout<<" | | /__\\        | |             | |           | |          | |     "<<endl;
  cout<<" | |___          | |             | |           | |          | |_/|  "<<endl;
  cout<<" \\____ \\         | |             | |           | |          |  _ |  "<<endl;
  cout<<"____ | |         | |             | |           | |          | | \\|  "<<endl;
  cout<<"\\  /_| |         | |___          | |___        | |___       | |___  "<<endl;
  cout<<" \\_____/ tudent /______\\ ister, /______\\ inked /______\\ ist /______\\ dition."<<endl;
  bool notQuit=true;
  cout<<"(Please note this program is incapable of saving data, so don't actually use it for managing students)"<<endl;
  while(notQuit){
    //trying to be robust. Also, Command handler.
    cout<<"Please input a command. (Valid commands: ADD, DELETE, PRINT, MODIFY, AVERAGE, QUIT)"<<endl;
    char inpstring[8];
    cin >> inpstring;
    if(cin.fail()){
      cout<<"I think you did something wrong. please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else if (strcmp(inpstring,"ADD")==0){
      addStudent(head);
    }else if (strcmp(inpstring,"DELETE")==0){
      //killStudent(head);
    }else if (strcmp(inpstring,"PRINT")==0){
      listStudents(head);
    }else if (strcmp(inpstring,"MODIFY")==0){
      //modStudent(head);
    }else if (strcmp(inpstring,"AVERAGE")==0){
      //averageGPAS(head);
    }else if (strcmp(inpstring,"QUIT")==0){
      notQuit=false;
      //no command needed, just quit the loop.
    }else{
      cout<<"Invalid Command."<<endl;
    }
  }
  cout<<"Have a good day."<<endl;
  return 0;
}


void getStringFromInput(char* inpstring){
  char bufferarray [11];
  //make sure it works
  bool acin=false;
  for(int i=0;i<11;i++){
    bufferarray[i]='\0';
  }
  while(acin==false){
    cout<<"10 characters or less, please."<<endl;
    cin.getline(bufferarray, sizeof(bufferarray),'\n');
    //need to try robust.
    if(cin.fail()){
      cout<<"I think you did something wrong. Please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else{
      acin=true;
    }
  }
  strncpy(inpstring, bufferarray, 10);
  inpstring[10]='\0';
  cout<<endl;
  return;
}

//student adding command
void addStudent(Node* head){
  Student* newkid = new Student();
  bool acin=false;
  //name getting
  char* inpstring[11];
  cout<<"Please input First Name"<<endl;
  getStringFromInput(inpstring);
  strncpy(newkid->Firstname,inpstring,11);
  cout<<"Please input Last Name"<<endl;
  getStringFromInput(inpstring);
  strncpy(newkid->Lastname,inpstring,11);
  //ID getting. can recycle getID method here.
  int posid;
  acin=false;
  while(acin==false){
    posid=getID();
    if(getStudentById(posid,head)==nullptr){
      acin=true;
    }else{
      cout<<"A student with that ID already exists!"<<endl;
    }
  }
  newkid->ID=posid;
  //GPA getting
  float newGPA;
  acin=false;
  while (acin==false){
    cout<<"Please Enter GPA: "<<endl;
    cin>>newGPA;
    if(cin.fail()){
      cout<<"I think you did something wrong. please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
    }else{
      acin=true;
    }
  }
  acin=false;
  newkid->GPA=newGPA;
  
  linearAdd(head,head, Node* addme);
  return;
}

Student* getStudentByID(int ID,Node* head){
  if(head->getStudent()->ID==ID){
    return head->getStudent(); 
  }else{
    if (head->getNext()==nullptr){
      return nullptr;
    }else{
      return getStudentByID(ID,head->getNext());
    }
  }
}


void linearAdd(Node* head, Node* current, Node* addme){
  if (current->getStudent()==nullptr){
    head->setStudent(addme->getStudent());
    addme->setStudent(nullptr);
    delete addme;
  }else if (head->getStudent()->ID > addme->getStudent()->ID){
    addme->setNext(head);
    head = addme;
  }else if (current->getNext()==nullptr){
    if (current->getStudent()->ID < addme->getStudent()->ID){
      current->setNext(addme);
    }
  }else if ((current->getStudent()->ID < addme->getStudent()->ID)&&(current->getNext()->getStudent()->ID > addme->getStudent()->ID)){
    addme->setNext(current->getNext());
    current->setNext(addme);
  }else{
    linearAdd(head, current->getNext(), addme);
  }
}

//actual lister function. when called, prints all students
void listStudents(Node* head){
  if(head->getStudent()==nullptr){
    cout<<"There are no students!"<<endl;
  }
  cout<<"Student Name:"<<head->getStudent()->Firstname<<" "<<head->getStudent()->Lastname<<"ID: "<<head->getStudent()->ID<<"GPA: "<<(round(head->getStudent()->GPA * 100))/100<<endl;
  if(head->getNext()!=nullptr){
    listStudents(head->getNext());
  }
}

/*
====================================================
CONVERSION TO LINKEDLIST REQUIRED BEYOND THIS POINT!
====================================================
*/

/*
//student deleter. clears memory and removes from the list.
void killStudent(vector <Student*> & StudentList){
  listStudents(StudentList);
  int index = getIndex(getID(StudentList),StudentList);
  if (index == -1){
    cout<<"INVALID ID"<<endl;
    return;
  }
  //clear the data first. nobody likes a memory leak.
  delete *(StudentList.begin()+index);
  //then clear the part of the list.
  StudentList.erase(StudentList.begin()+index);
  return;
}

//student modifier. because why not?
void modStudent(vector <Student*> & StudentList){
  listStudents(StudentList);
  int index = getIndex(getID(StudentList),StudentList);
  if(index==-1){
    cout<<"INVALID ID"<<endl;
  }
  bool lacin=false;
  //almost all of these are copied directly from the AddStudent function.
  while (lacin==false){
    cout<<"Field to Modify. (Valid commands: FIRSTNAME, LASTNAME, ID, GPA, NEVERMIND)"<<endl;
    char linpstring[10];
    cin >> linpstring;
    lacin=true;
    bool acin=false;
    //Commands should be pretty clear on what is being modified.
    if(cin.fail()){
      cout<<"I think you did something wrong. please try again."<<endl;
      cin.clear();
      cin.ignore(100000,'\n');
      lacin=false;
    }else if (strcmp(linpstring,"FIRSTNAME")==0){
      char inpstring[11];
      for(int i=0; i<11; i++){
	inpstring[i]='\0';
      }
      cin.ignore(100000,'\n');
      while (acin==false){
	cout<<"Please Enter Firstname (10 characters or less): "<<endl;
	cin.getline(inpstring,sizeof(inpstring));
	if(cin.fail()){
	  cout<<"I think you did something wrong. please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  acin=true;
	}
      }
      for(int i=0; i<10; i++){
	(**(StudentList.begin()+index)).Firstname[i]=inpstring[i];
      }
      (**(StudentList.begin()+index)).Firstname[10]='\0';
    }else if (strcmp(linpstring,"LASTNAME")==0){
      char inpstring[11];
      for(int i=0; i<11; i++){
	inpstring[i]='\0';
      }
      cin.ignore(100000,'\n');
      while (acin==false){
	cout<<"Please Enter Lastname (10 characters or less): "<<endl;
	cin.getline(inpstring,sizeof(inpstring));
	if(cin.fail()){
	  cout<<"I think you did something wrong. please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  acin=true;
	}
      }
      for(int i=0; i<10; i++){
	(**(StudentList.begin()+index)).Lastname[i]=inpstring[i];
      }
      (**(StudentList.begin()+index)).Lastname[10]='\0';
    }else if (strcmp(linpstring,"ID")==0){
      int posid;
      acin=false;
      while(acin==false){
	posid=getID(StudentList);
	if(getIndex(posid,StudentList)==-1){
	  acin=true;
	}else{
	  cout<<"A student with that ID already exists!"<<endl;
	}
      }
      (**(StudentList.begin()+index)).ID=posid;
    }else if (strcmp(linpstring,"GPA")==0){
      float newGPA;
      acin=false;
      while (acin==false){
	cout<<"Please Enter GPA: "<<endl;
	cin>>newGPA;
	if(cin.fail()){
	  cout<<"I think you did something wrong. please try again."<<endl;
	  cin.clear();
	  cin.ignore(100000,'\n');
	}else{
	  acin=true;
	}
      }
      acin=false;
      (**(StudentList.begin()+index)).GPA=newGPA;
    }else if (strcmp(linpstring,"NEVERMIND")==0){
      return;
      //no command needed, just quit the function.
    }else{
      cout<<"Invalid Command."<<endl;
      lacin=false;
    }
  }
  return;
}

//for getting index of student in the list
int getIndex(int ID, vector <Student*> & StudentList){
  for(auto i = StudentList.begin(); i!=StudentList.end(); ++i){
    int thisID = (*(*i)).ID;
    if (thisID==ID){
      return (i-StudentList.begin());
    }
  }
  return -1;
}
*/

//for getting IDs.
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
