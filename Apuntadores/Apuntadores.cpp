#include "Apuntadores.h"

void Apuntador::Ejemplo_1(){
  int var1;
  int* ap_var1;

  std::cout << "Dime un valor entero: ";
  std::cin >> var1;

  ap_var1 = &var1;

  // Primera opción: Sin apuntadores

  std::cout << std::endl << "==Primera opción==" << std::endl;
  std::cout << "El nombre de la variable es: var1" << std::endl;
  std::cout << "El valor de la variable es: " << var1 << std::endl;
  std::cout << "La dirección de la variable es: " << &var1 << std::endl << std::endl;

  // Segunda opción: Empleando apuntadores
  
  std::cout << std::endl << "==Segunda opción==" << std::endl;
  std::cout << "El nombre de la variable es: var1" << std::endl;
  std::cout << "El valor de la variable es: " << *ap_var1 << std::endl;
  std::cout << "La dirección de la variable es: " << ap_var1 << std::endl << std::endl;  
}

void Apuntador::Ejemplo_2(){
  int lista[6] = {10, 20, 30};
  std::cout << "lista: " << lista << std::endl;
  std::cout << "lista + 1: " << lista + 1 << std::endl;
  std::cout << "lista: " << *lista << std::endl;
  std::cout << "lista + 1 o lista[1]: " << *(lista + 1) << std::endl;
  
}

void Apuntador::Ejemplo_3(){
  int lista[] = {10, 20, 30};
  int* plista = new int[3];
  plista = lista;
  std::cout << "plista: " << plista << std::endl;
  std::cout << "plista + 1: " << plista + 1 << std::endl;
  std::cout << "plista: " << *plista << std::endl;
  std::cout << "plista + 1 o lista[1]: " << *(plista + 1) << std::endl;
  delete [] plista;
}

void Apuntador::AsignacionEst(int n){ 
  // int* arr = new int[n];
  int* arr = (int*) malloc(n*sizeof(int));
  
  for(int i = 0; i < n; i++){
    std::cout << "Ingrese el valor: \n? ";
    std::cin >> *(arr + i);
  }
  for(int i = 0; i < n; i++){
    std::cout << "\t" << *(arr + i);
  }
  std::cout << std::endl;
  free(arr);
  // delete []arr;
}
