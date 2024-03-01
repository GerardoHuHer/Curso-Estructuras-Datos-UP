#include "Tarea4.h"

Pilas::Pilas(){
  min = 0;
  tope = min - 1;
  max = TAM - 1;
  original = new int[TAM];
  for(int i = 0; i < TAM; i++){
    *(original + i) = 0;
  }
}

int Pilas::push(int num){
  // In case it returns -1, means that the stack is full
  if(tope >= max){
    return -1;
  } 
  tope++;
  *(original + tope) = num;
  // In case it returns 0, means that we have pushed the number
  return 0;
}

int Pilas::pop(){
  // If it returns -1, means that the stack is empty
  if(tope < min){
    return -1;
  }
  int ret = original[tope];
  original[tope] = 0;
  tope--;
  return ret;
}

int depurar(Pilas original, Pilas dep, int num){
  int ret;

  for(int i = 0; i < TAM; i++){
    ret = original.pop();
    if(ret > num)
      dep.push(ret); continue;
  }
  return 0;
}

void Pilas::mostrar(){
    for(int i = max; i >= 0; i--){
    std::cout << "\t" << original[i];
    if(i == min) std::cout << "\t <=Mínimo"; 
    if(i == max) std::cout << "\t <=Máximo"; 
    if(i == tope) std::cout << "\t <=Tope"; 
    std::cout << std::endl;
  }
  std::cout << std::endl;

}

void menu(){
  int opc;
  int ingreso;
  int ret;
  Pilas ori, depurada;
  while(opc != 6){
    std::cout << "\n1) Insertar Original \n2) Eliminar Original \n3) Mostrar Original \n4) Depurar Original \n5) Mostrar Depurada \n6) Salir" << std::endl;
    std::cout << "Ingrese la opción deseada: \n? "; std::cin >> opc;
    switch (opc) {
      case 1:
      std::cout << "Ingrese el número que desea insertar: \n? ";
      std::cin >> ingreso;
      ret = ori.push(ingreso);
      if(ret == -1) std::cout << "La pila está llena. No se ingresó" << std::endl;
      if(ret == 0) std::cout << "Se ha ingresado correctamente" << std::endl;
      break;
      case 2:
      ret = ori.pop();
      if(ret == -1) std::cout << "La pila está vacia" << std::endl;
      if(ret != -1) std::cout << "Se ha eliminado el elemento"<< ret << std::endl;
      break;
      case 3:
      ori.mostrar();
      break;
      case 4:
      std::cout << "Ingrese un número: \n? "; std::cin >> ingreso;
      ret = depurar(ori, depurada, ingreso);
      if(ret == 0) std::cout << "Se ha depurado correctamente" << std::endl;
      break;
      case 5:
      depurada.mostrar();
      break;    
      case 6:
      std::cout << "Hasta luego" << std::endl;
      break;
      default:
      std::cout << "No se ha ingresado una opción válida" << std::endl;
      break;
    }
  }
}
