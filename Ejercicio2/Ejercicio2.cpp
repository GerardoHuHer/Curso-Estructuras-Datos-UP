#include "Ejercicio2.h"

int Arreglo::insertar(int num){
  int pos = ocupados;
  // Esta línea verifica que el tamaño del arreglo no se haya excedido
  if(ocupados >= TAM){
    return -2;
  }
  // Buscamos la posición que queremos insertar
  for(int i = 0; i < ocupados; i++){
    if(enteros[i] > num){
      pos = i;
      break;
    }
  }
  for(int i = ocupados - 1; i >= pos; i--){
    enteros[i + 1] = enteros[i];
  }
  enteros[pos] = num;
  ocupados++;
  return 0;
}

void Arreglo::mostrar(){
  for(int i = 0; i < ocupados; i++){
    std::cout << "\t" << enteros[i];
  }
  std::cout << std::endl;
}
