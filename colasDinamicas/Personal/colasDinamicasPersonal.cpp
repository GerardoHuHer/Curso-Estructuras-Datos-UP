#include "colasDinamicasPersonal.h"

DynamicQueue::DynamicQueue() : front(nullptr), rear(nullptr) {}

DynamicQueue::~DynamicQueue() {
  while (!isEmpty()) {
    dequeue();
  }
}

bool DynamicQueue::isEmpty() { return front == nullptr; }

// Function to enqueue (add) an element to the queue
void DynamicQueue::enqueue(int value) {
  nodo = new Node;
  nodo->data = value;
  if (isEmpty()) {
    front = rear = nodo;
  } else {
    rear->next = nodo;
    rear = nodo;
  }
}

// Function to dequeue (remove) an element from the queue
int DynamicQueue::dequeue() {
  int num;
  // if (!isEmpty()) {
  //   Node *temp = front;
  //   front = front->next;
  //   delete temp;
  //   if (front == nullptr) {
  //     rear = nullptr;
  //   }
  // } else {
  //   return -1;
  // }
  if(isEmpty()){
    return -1;
  }
  Node* temp = front;
  front = front -> next;
  num = temp->data;
  delete temp;
  return num;
}

// Function to get the front element of the queue
int DynamicQueue::peek() {
  if (!isEmpty()) {
    return front->data;
  } else {
    return -1; // Return a default value indicating empty queue
  }
}

// Function to display the elements of the queue
void DynamicQueue::display() {
  if (!isEmpty()) {
    Node *current = front;
    while (current != nullptr) {
      std::cout << "\t" << current->data;
      if (current == front)
        std::cout << " <= Front";
      if (current == rear)
        std::cout << " <= Rear";
      std::cout << std::endl;
      current = current->next;
    }
    std::cout << std::endl;
  } else {
    std::cout << "Queue is empty.\n";
  }
}

void menu() {
  DynamicQueue cola;
  int ret;
  int opc;
  do {
    std::cout << "\n1) Push \n2) Pop \n3) Peek \n4) Show \n5) Exit"
              << std::endl;
    std::cout << "Enter your choice \n?";
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Enter a number: \n? ";
      std::cin >> ret;
      cola.enqueue(ret);
      break;
    case 2:
      ret = cola.dequeue();
      if(ret == -1) std::cout << "The queue is empty" << std::endl;
      else{
        std::cout << "The value was " << ret << std::endl;
      }
      break;
    case 3:
      ret = cola.peek();
      if(ret == -1) std::cout << "The queue is empty" << std::endl;
      else{
        std::cout << "The front value is " << ret << std::endl;
      }
      break;
    case 4:
      cola.display();
      break;
    case 5:
      std::cout << "Goodbye" << std::endl;
      break;
    default:
      std::cout << "Your value is wrong. Please enter a valid number" << std::endl;
      break;
    }
  } while (opc != 5);
}
