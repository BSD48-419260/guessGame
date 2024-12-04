#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include<iostream>
using namespace std;

//Node class
class Node{
 public:
  Node();
  Node(Student*);
  Node(Student*, Node*&);
  ~Node();
  Node* getNext();
  void setNext(Node*); 
  Student* getStudent();
  void setStudent(Student*);
 private:
  Student* refrencedStudent;
  Node* next;
};


#endif
