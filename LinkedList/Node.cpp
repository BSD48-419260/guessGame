#include "Student.h"
#include "Node.h"

Node::Node(){
  refrencedStudent=nullptr;
  prev=nullptr;
  next=nullptr;
}

Node::Node(Student*){
  refrencedStudent=newkid;
  prev=nullptr;
  next=nullptr;
}

Node::Node(Student* newkid, Node*& newPrevious, Node*& newNext){
  refrencedStudent=newkid;
  prev=newPrevious;
  prev->setNext(&this);
  next=newNext;
  next->setPrev(&this);
}

Node::~Node(){
  delete refrencedStudent;
  prev->setNext(this.next);
  next->setPrev(this.prev);
}

Node* Node::getNext(){
  
}
