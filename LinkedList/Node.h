#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include<iostream>
using namespace std;

//Here's something fun: I'm making it a circular doubly linked list, because it didn't look hard enough.
//Yes, I will almost certainly regret doing this. on the other hand however, Why not?
class Node{
 public:
  Node();
  Node(Student*, Node*&, Node*&);
  ~Node();
  Node* getNext();
  void setNext(Node*);
  Node* getPrev();
  void setPrev(Node*);
  Student* getStudent();
  void setStudent(Student*);
 private:
  Student* refrencedStudent;
  Node* prev;
  Node* next;
};


#endif
