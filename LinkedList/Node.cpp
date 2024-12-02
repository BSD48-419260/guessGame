#include "Student.h"
#include "Node.h"

Node::Node(){
  refrencedStudent=nullptr;
  prev=nullptr;
  next=nullptr;
}

Node::Node(Student* newkid, ){
  refrencedStudent=newkid;
  prev=nullptr;
  next=nullptr;
}

