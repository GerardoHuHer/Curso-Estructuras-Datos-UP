#include "ListasCirculares.h"

Option enter_option(){
  int opc;
  std::cout << "Ingrese una opción \n? "; 
  std::cin >> opc;
  return static_cast<Option>(opc);
}

void menu(){
  Option opc;
  Lista lista = Lista();
  std::string status;
  while((opc = enter_option()) != Option::SALIR){
    switch (opc) {
      case Option::INSERTAR:
        int num;
        std::cout << "Ingrese el número que desea ingresar: \n? ";
        std::cin >> num;
        lista.insertar_final(num);
        break;
      case Option::BUSCAR:
        std::cout << "Ingrese el número que desea buscar: \n? ";
        std::cin >> num;
        status = lista.busqueda(num) ? " existe": " no existe";
        std::cout  << "El número " << num << status << std::endl;
        break;
      case Option::MOSTRAR:
        lista.display_inicio();
        break;
      case Option::MOSTRAR_FINAL:
        lista.display_revisado();
        break;
      default:
        std::cout << "No se ingresó una opción válida" << std::endl;
        break;
    
    }

  }
}

Lista::Lista()
    : head(nullptr), final(nullptr), revisado(nullptr), nodo(nullptr) {}

void Lista::insertar_final(const int &nuevo) {
  nodo = new Nodo;
  if (head == nullptr) {
    nodo->dato = nuevo;
    nodo->sig = head;
    head = nodo;
    if (final == nullptr) {
      final = nodo;
    }
  }
  nodo->dato = nuevo;
  nodo->sig = head;
  final->sig = nodo;
  final = nodo;
}

bool Lista::busqueda(const int &buscar) {
  // Caso está vacía
  if (head == nullptr) {
    return false;
  }
  // Caso de la primera búsqueda
  if (revisado == nullptr) {
    nodo = head;
    do{
      if(nodo->dato == buscar){
        revisado = nodo;
        return true;
      }
      nodo = nodo->sig;
    }while(nodo != head);
    return false;
  }
  // Caso de que no sea la primera búsqueda
  else {
    nodo = revisado;
    do{
      if(nodo ->dato == buscar){
        revisado = nodo;
        return true;
      }
      nodo = nodo->sig;
    }while(nodo != revisado);
    return false;
  }
}

void Lista::display_inicio(){
  if(head == nullptr){
    std::cout << "Lista vacía" << std::endl;
    return;
  }
  nodo = head;
  do{
    std::cout << "\t" << nodo ->dato;
    if(nodo == head) std::cout << " <= Inicio";
    if(nodo == final) std::cout << " <= Final";
    std::cout << std::endl;
    nodo = nodo->sig;
  }while(nodo != head);
}

void Lista::display_revisado(){
  if(head == nullptr){
    std::cout << "Lista vacía" << std::endl;
    return;
  }
  nodo = revisado;
  do{
    std::cout << "\t" << nodo ->dato;
    if(nodo == head) std::cout << " <= Inicio";
    if(nodo == final) std::cout << " <= Final";
    if(nodo == revisado) std::cout << " <= Revisado";
    std::cout << std::endl;
    nodo = nodo->sig;
  }while(nodo != revisado);
}
