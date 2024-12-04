#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>

class Student{
  //this student only has a name for testing purposes.
 public:
  char* name;
  Student(char* newname){
    name=newname;
  }
};
#endif
