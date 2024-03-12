#include "ejercicio8.h"

Estructura::Estructura(){
  final = principio = -1;
  minimo = 0;
  maximo = TAM - 1;
  for(int i = 0; i < TAM; i++){
    cola[i] = "- -";
  }
}

int Estructura::insertar(std::string nuevo){
  // Paso 1: Validamos que el arreglo no este lleno
  if(maximo == final){
    return -1;
  }
  // Paso 2: Aumentamos el valor de final y en caso de que principio sea -1 lo aumentamos 1 también
  final++;
  if(principio == -1){
    principio++;
  }
  // Paso 3: Colocamos el valor nuevo en la posición final
  cola[final] = nuevo;
  return 0;
}

std::string Estructura::extraer(){

  std::string aux;
  // Paso 1: Verificamos si está lleno
  if(final < minimo && principio < minimo){
    return "vacio";
  }
  if(principio > final) return "vacio";
  // Paso 2: Pasamos nuestros datos a nuestra variable auxiliar
  aux = cola[principio];
  // Paso 3: Pasamos nuestro valor de la posición extraída por nuestro valor por default
  cola[principio] = "- -";
  // Paso 4: Aumentamos nuestro valor de principio
  principio++;
  return aux;
}

void Estructura::mostrar(){
  for(int i = 0; i < TAM; i++){
    std::cout << "\t" << cola[i];
    if(i == principio) std::cout << " <= Principio";
    if(i == final) std::cout << " <= Final";
    if(i == maximo) std::cout << " <= Maximo";
    if(i == minimo) std::cout << " <= Mínimo";
    std::cout << std::endl;
  }
}

void menu(){
  Estructura palabras;
  int opc;
  std::string ret;
  int temp;
  do {
    std::cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Salir \n" << std::endl;
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Ingrese la palabra que desea insertar a la cola: \n? ";
      std::cin >> ret;
      temp = palabras.insertar(ret);
      if(temp == -1) std::cout << "La cola está llena" << std::endl;
      if(temp == 0) std::cout << "Se añadío el valor con éxito" << std::endl;
      break;
    case 2:
      ret = palabras.extraer();
      if(ret == "vacio") std::cout << "La cola está vacía" << std::endl;
      if(ret == "vacio") std::cout << "La cola está vacía" << std::endl;
      if(ret != "vacio") std::cout << "Se extrajo el valor con éxito" << std::endl;
      std::cout << "La palabra extraída es: \"" << ret << "\"" << std::endl; 
      break;
    case 3:
      palabras.mostrar();
      break;
    case 4:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ha ingresado valor válido" << std::endl;
      break;
    }
  }while (opc != 4);
  
}
