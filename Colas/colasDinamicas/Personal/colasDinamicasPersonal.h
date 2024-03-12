#pragma once
#include <iostream>

struct Node {
  int data;
  Node *next;
};

class DynamicQueue {
private:
  Node *front, *rear;
  Node* nodo;
public:
  DynamicQueue();
  ~DynamicQueue();
  bool isEmpty();
  void enqueue(int);
  int dequeue();
  int peek();
  void display();
};

void menu();
