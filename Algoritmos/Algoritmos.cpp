#include "Algoritmos.h"

// Arreglo::Arreglo(){
//   ocupados = 0;
// }

int Arreglo::borrar(int num){
  int pos {-1};
  for(int i = 0; i < ocupados; i++){
    if(arr[i] == num){
      pos = i;
      break;
    }
  }
  if(pos == -1){
    return -1;
  }
  for(int i = pos; i < ocupados; i++){
    arr[i] = arr[i + 1];
  }
  arr[ocupados - 1] = 0;
  ocupados--;
  return 0;
}

int Arreglo::insertar(int num){
  int pos = ocupados;
  if(ocupados >= TAM){
    return -1;
  }
  for(int i = 0; i < ocupados; i++){
    if(arr[i] > num){
      pos = i;
    }
  }
  for(int i = ocupados - 1; i >= pos ; i--){
    arr[i + 1] = arr[i];
  }
  arr[pos] = num;
  ocupados++;
  return 0;
}

void Arreglo::mostrar(){
  for(int i = 0; i < ocupados; i++){
    std::cout << "\t" << arr[i];
  } 
  std::cout << std::endl;
}

// void Arreglo::llenado(){
//   int num;
//   do{

//     ocupados++;
//   }while(num != 0);
// }

void Arreglo::bubble_sort(){
  int aux, iter{0};
  bool ordenado = false;
  while(!ordenado){
    ordenado = true;
    for(int i = 0; i < ocupados - iter - 1; i++){
      if(arr[i] > arr[i + 1]){
        aux = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = aux;
        ordenado = false;
      }
    }
    iter++;
  }

}

void menu(){
  int opc;
  int retorno;
  int num;
  Arreglo obj = Arreglo();
  do{
    std::cout << "1) Borrar \n2) Insertar \n3) Mostrar \n4) No terminado Llenado \n5) Ordenar \n6) Salir" << std::endl;
    std::cin >> opc;
    switch (opc) {
      case 1:
        std::cout << "Ingrese el número que desea borrar: \n? ";
        std::cin >> num;
        retorno = obj.borrar(num);
        if(retorno == -1){
          std::cout << "No se encontró el valor ingresado" << std::endl;
        }
        if(retorno == 0){
          std::cout << "Se ha borrado con éxito" << std::endl;
        }
        break;
      case 2:
        std::cout << "Ingrese el número que desea insertar: \n? ";
        std::cin >> num;
        retorno = obj.insertar(num);
        if(retorno == -1){
          std::cout << "El arreglo está lleno" << std::endl;
        }
        if(retorno == 0){
          std::cout << "Se ha ingresado con éxito" << std::endl;
        }
        break;
      case 3:
        obj.mostrar();
        break;
      case 4:
        break;
      case 5:
        obj.bubble_sort();
        break;
      case 6:
        std::cout << "Hasta luego\n";
        break;
      default:
        std::cout << "No se ingresó un valor correcto" << std::endl;
        break;
    }
  }while(opc != 6);
  
}
