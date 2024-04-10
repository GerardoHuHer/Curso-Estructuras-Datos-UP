#include "listas.h"

List::List(): head(NULL){}
 
bool List::isEmpty(){
  return head == NULL;
}

void List::insert(int aux){
  nodo = new Node;
  nodo->next = head;
  head = nodo;
}

int List::remove(int value){
  int aux;
  if(isEmpty()){
    return -1;
  }
  Node* current = head;
  Node* prev = NULL;
  while(current != NULL && current->data != value){
    prev = current;
    current = current->next;
  }
  if(current == NULL){
    return -2;
  }
  if(prev == NULL){
    head = current->next;
  } else {
    prev -> next = current->next;
  }
  aux = current->data;
  delete current;
  return aux;
}

Option enter_option(){
  std::cout << "\nEnter your choice\n"
    << "1 - Insert\n"
    << "2 - Remove\n"
    << "3 - Search\n"
    << "4 - Display\n"
    << "5 - Exit\n?";
  int menuChoice;
  std::cin >> menuChoice;
  return static_cast<Option>(menuChoice);
}

void menu(){
  Option choice;
  while((choice = enter_option()) != Option::EXIT){
    switch (choice) {
      case Option::INSERT:
        break;
      case Option::REMOVE:
        break;
      case Option::SEARCH:
        break;
      case Option::DISPLAY:
        break;
      case Option::EXIT:
        break;
      default:
        std::cout << "No se ingresó una opción válida" << std::endl;
        break;
  
    }
  }
}
