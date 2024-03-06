#include "repaso.h"
#include <string>

Pila::Pila(){
  tope = NULL;
}

Estudiante Pila::extraer(){
  Estudiante* aux;
  Estudiante num;
    // En caso de que tope sea NULL significa que está vacía la Pila
  if(tope == NULL){
    num.ID = -1;
    return num;
  }
  aux = tope;
  tope = tope -> anterior;
  num = *aux;
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
  std::cout << "\n======= PILA =======\n";
  if(tope == NULL){ 
    std::cout << "Pila vacía\n"; 
    return;
  }
  nodo = tope;
  std::cout << "ID\t\t\t NOMBRE \t\t\t EDAD" << std::endl;
  while(nodo != NULL){ 
    std::cout << nodo->ID << "\t\t\t" << nodo->nombre << "\t\t\t" << nodo ->edad;
    if(nodo == tope) std::cout << " <= TOPE";
    std::cout << std::endl;
    nodo = nodo->anterior;
  }
}

void depurar(Pila calif, Pila noCalif){
  std::cout << "... Depurando ..." << std::endl;
  Estudiante ret; 
  do{
    ret = calif.extraer();
    std::cout << ret.ID << std::endl;
    noCalif.insertar(ret);    
    
  }while(ret.ID != -1);
  std::cout << "Fin del depurado" << std::endl;
}

void menu(){
  int opc;
  Estudiante aux;
  Pila calif, noCalif;
  do{    
    std::cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Depurar \n5) Salir" << std::endl;  
    std::cout << "Ingrese la opción deseada \n? "; std::cin >> opc;
    switch (opc) {
      case 1:
        std::cout << "Ingrese el ID del estudiante \n? "; std::cin >> aux.ID;
        std::cin.ignore();
        std::cout << "Ingrese el nombre del estudiante \n? "; std::getline(std::cin, aux.nombre );
        std::cout << "Ingrese la edad del estudiante \n? "; std::cin >> aux.edad;
        calif.insertar(aux);
        break;
      case 2:
        aux = calif.extraer();
        if(aux.ID == -1) {
          std::cout << "La pila estaba vacía" << std::endl; 
          continue;
        }
        std::cout << "ID extraído: " << aux.ID << std::endl;
        break;
      case 3:
        std::cout << "\n======= CALIFICADOS =======\n" << std::endl;
        calif.mostrar();
        std::cout << "\n======= NO CALIFICADOS =======\n" << std::endl;
        noCalif.mostrar();
        break;
      case 4:
        depurar(calif, noCalif);
        break;
      case 5:
        std::cout << "Hasta luego" << std::endl;
        break;
      default:      
        std::cout << "No se ingresó una opción válida" << std::endl;
        break;    
    }
  }while(opc != 5);
}
