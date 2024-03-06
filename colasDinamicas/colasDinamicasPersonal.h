#pragma once
#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int);
};

class DynamicQueue {
private:
  Node *front, *rear;
public:
  DynamicQueue();
  ~DynamicQueue();
  bool isEmpty();
  void enqueue();
  void dequeue();
  int peek();
  void display();
};
