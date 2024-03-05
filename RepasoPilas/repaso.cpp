#include "repaso.h"

Pila::Pila(){
  tope = NULL;
}

int Pila::extraer(){
  Estudiante* aux;
  int num;
  // En caso de que tope sea NULL significa que está vacía la Pila
  if(tope == NULL){
    return -1;
  }
  aux = tope;
  tope = tope -> anterior;
  num = aux ->ID;
  delete aux;
  return num;
}

int Pila::insertar(Estudiante stud){
  // Creamos un nodo
  nodo = new Estudiante;
  // Metemos la info en el nodo
  *nodo = stud; 
  // Cambiamos la dirección anterior al tope anterior
  nodo -> anterior = tope;
  // Nuestro nuevo tope es el nuevo nodo
  tope = nodo;
  return 0;
}

void Pila::mostrar(){
  std::cout << "======= PILA =======";
  if(tope == NULL) std::cout << "Pila vacía\n"; return;
  nodo = tope;
  std::cout << "ID\t\t\t NOMBRE \t\t\t EDAD" << std::endl;
  while(nodo != NULL){ std::cout << nodo->ID << "\t\t\t" << nodo->nombre << "\t\t\t" << nodo ->edad;
    if(nodo == tope) std::cout << " <= TOPE";
    std::cout << std::endl;
  }
}

void depurar(Pila calif, Pila noCalif){
  std::cout << "... Depurando ..." << std::endl;
  int ret {0};
  do{
    ret = noCalif.extraer();
  }while(ret != -1);
  std::cout << "Fin del depurado" << std::endl;
}

