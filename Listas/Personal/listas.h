#ifndef LISTAS_H
#define LISTAS_H
#include <iostream>

struct Node {
  int data;
  Node* next;
};

class List{
private:
  Node* head;
  Node* nodo; 
public:
  List();
  void insert(int);
  bool isEmpty();
  int remove(int);
  bool search();
  void display();
 };

enum class Option{
  INSERT=1, 
  REMOVE, 
  SEARCH, 
  DISPLAY,
  EXIT 
};

Option enterOption();
void menu(); 
#endif
