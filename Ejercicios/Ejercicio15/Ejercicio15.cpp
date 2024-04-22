#include "Ejercicio15.h"

Lista::Lista(): head(nullptr), final(nullptr), nodo(nullptr){}

void Lista::insertar_inicio(const std::string& nuevo){
  nodo = new Nodo;
  nodo->palabra = nuevo;
  nodo->sig = head;
  if(head  == nullptr){
    final = nodo;
  }else {
    head ->prev = nodo;
  }
  nodo->prev = nullptr;
  head = nodo;
}

void Lista::insertar_final(const std::string& nuevo){
  if(head == nullptr){
    insertar_inicio(nuevo);
    return;
  }
  nodo = new Nodo;
  nodo ->palabra = nuevo;
  nodo -> sig = nullptr;
  nodo ->prev = final;
  final->sig = nodo;
  final = nodo;
}

void Lista::insertar_intermedio(const std::string& nuevo, const std::string& pos){
  if(head == nullptr){
    insertar_inicio(nuevo);
    return;
  }
  bool find = false;
  Nodo* nodo_anterior = head;
  while(nodo_anterior != nullptr){
    if(nodo_anterior->palabra == pos){
      find = true;
      break;
    }
    nodo_anterior = nodo_anterior->sig;
  }
  if(find){
    nodo = new Nodo;
    nodo ->palabra = nuevo;
    nodo->sig = nodo_anterior->sig;
    nodo->prev = nodo_anterior;
    nodo_anterior->sig->prev = nodo;
    nodo_anterior->sig = nodo;
    return;
  }
  if(!find){
    insertar_final(nuevo);
  }
}

std::string Lista::extraer_inicio(){
  std::string extraida;
  if(head == nullptr){
    return "";
  }
  nodo = new Nodo;
  nodo = head;
  extraida = nodo->palabra;
  head = nodo->sig;
  head -> prev = nullptr;
  delete nodo;
  if(final->prev == nullptr){
    final = head = nullptr;
    return "";
  }
  return extraida;
}


void Lista::display(){
  if(head == nullptr){
    std::cout << "LISTA VACÍA" << std::endl;
    return;
  }
  std::cout << "LISTA" << std::endl;
  nodo = head;
  while(nodo != nullptr){
    std::cout << "\t" << nodo ->palabra;
    if(nodo == final) std::cout << " <= FINAL";
    if(nodo == head) std::cout << " <= INICIO";
    std::cout << std::endl;
    nodo = nodo->sig;
  }
}
